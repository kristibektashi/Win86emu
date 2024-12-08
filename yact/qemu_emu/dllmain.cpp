// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"

#include <unicorn/unicorn.h>
#include <string.h>

#include "callbacks.h"
#include "peldr.h"
#include "util.h"
#include "classes.h"

#pragma warning(disable : 4996)

#define EMU_STACK_SIZE (1024*1024*2)

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}



typedef DWORD __fastcall func(DWORD*);

DWORD GetHookAddress(char* Dll, char* FuncName)
{
    char DllPath[1024];
    char Buff[1024];
    strcpy(DllPath, PeLdrGetSystemDirectoryA());
    int tmp = strlen(DllPath);
    strcpy(DllPath + tmp - 2, "NT\\");
    strcat(DllPath, Dll);
    if ((DWORD)FuncName > 65545)
    {
#ifdef _ARM_
        sprintf(Buff, "yact_%s", FuncName);
#else
        sprintf(Buff, "@yact_%s@4", FuncName);
#endif
    }
    else
    {
#ifdef _ARM_
        sprintf(Buff, "yact_Ord%", (int)FuncName);
#else
        sprintf(Buff, "@yact_Ord%d4", (int)FuncName);
#endif
    }
    HMODULE H = LoadLibraryA(DllPath);
    if (H == 0)
    {
#ifdef _DEBUG
        printf("Error %d loading '%s'\n", GetLastError(), Dll);
#endif
        LogErr("Error %d loading '%s'\n", GetLastError(), Dll);
    }
#ifdef _DEBUG
    LogPrint("Binding %s from %s\n", Buff, Dll);
#endif
    DWORD R = (DWORD)GetProcAddress(H, Buff);
    return R;
}

unsigned int ProcessCallback(unsigned int reg_eax, unsigned int reg_eip)
{
    DWORD* Param = (DWORD*)reg_eax;
    DWORD Func = *(DWORD*)(reg_eip - 4);

    if ((0x80000000 & Func) == 0)
    {
        Func = 0x80000000 | (DWORD)GetHookAddress(((char**)Func)[0], ((char**)Func)[1]);
#if 1 //def _DEBUG
        if (0x80000000 == Func)
        {
            Func = *(DWORD*)(reg_eip - 4);
            char* Dll = ((char**)Func)[0];
            char* Name = ((char**)Func)[1];
#ifdef _DEBUG
            printf("Func %s not found in %s\n", Name, Dll);
#endif
            LogErr("Func %s not found in %s\n", Name, Dll);
            exit(0);
        }
#endif
        * (DWORD*)(reg_eip - 4) = Func;
    }

    int tmp = 0;
    if (0x80000000 == Func)
#ifndef _DEBUG
        goto Skip;
#else
        exit(0);
#endif
    __try {
        tmp = ((func*)(0x7fffffff & Func))(Param);
    }
    __except (EXCEPTION_EXECUTE_HANDLER)
    {
#ifdef _DEBUG
        LogInfo("Exception in callback!");
#endif
    }
Skip:
    reg_eax = tmp;
    return reg_eax;
}

extern "C" __declspec(dllexport) BOOL EmuInitialize(void) {
    return true;
}

CList StackList;

void* AllocStack(int Size)
{
    DWORD Tmp;
    void* Ptr = VirtualAlloc(0, Size, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (Ptr == 0)
        return 0;

#ifdef _DEBUG
    memset(Ptr, 0xbe, Size);
    VirtualProtect(Ptr, PeLdrGetPageSize(), PAGE_READWRITE | PAGE_GUARD, &Tmp);
#endif
    return Ptr;
}

void FreeStack(void* Ptr)
{
    VirtualFree(Ptr, 0, MEM_RELEASE);
}

void ReuseStack(void* Ptr)
{
    StackList.AddHead(Ptr);
}

int __declspec(thread) FPU_cw = 0x37F;
extern "C" __declspec(dllexport) int GetFPUCW()
{
    return FPU_cw;
}

extern "C" __declspec(dllexport) void SetFPUCW(int cw)
{
    FPU_cw = cw;
}

static uint32_t hook_in(uc_engine* uc, uint32_t port, int size, void* user_data)
{
    uint32_t eip;

    uc_reg_read(uc, UC_X86_REG_EIP, &eip);

    /*printf("--- reading from port 0x%x, size: %u, address: 0x%x\n", port, size,
        eip);*/
    //printf("%08X:%08X\n", eip, *(DWORD*)(eip-4));

    DWORD my_EAX;

    uc_reg_read(uc, UC_X86_REG_EAX, &my_EAX);

    return ProcessCallback(my_EAX,eip);

    /*switch (size) {
    default:
        return 0; // should never reach this
    case 1:
        // read 1 byte to AL
        return 0xf1;
    case 2:
        // read 2 byte to AX
        return 0xf2;
        break;
    case 4:
        // read 4 byte to EAX
        return 0xf4;
    }*/
}

static bool hook_mem_invalid(uc_engine* uc, uc_mem_type type, uint64_t address,
    int size, int64_t value, void* user_data)
{
    switch (type) {
    default:
        //printf("%08X\n", (address & 0xFFFFF000));
        uc_mem_map(uc, (address & 0xFFFFF000), 4096, UC_PROT_ALL);
        // return true to indicate we want to continue
        return true;
    }
}

static void hook_block(uc_engine* uc, uint64_t address, uint32_t size,
    void* user_data)
{
}

static void UnicornHookAllCallback(uc_engine* uc, uint64_t address, uint32_t size, void* user_data)
{
}

extern "C" __declspec(dllexport) DWORD EmuExecute(DWORD Addr, int NParams, ...) {
#define MAXARGS 8
    DWORD Tmp[MAXARGS];

    va_list argptr;
    va_start(argptr, NParams);
    for (int i = 0; i < NParams; i++)
        Tmp[i] = va_arg(argptr, DWORD);
    va_end(argptr);

    uc_engine* uc;
    uc_err err;
    uint32_t tmp;
    uc_hook trace1, trace2, trace3, trace4;

    err = uc_open(UC_ARCH_X86, UC_MODE_32, &uc);

    if (err) {
        return (-1);
    }

    //uc_ctl_set_cpu_model(uc, UC_CPU_X86_KNIGHTSMILL);

    //uc_hook_add(uc, &trace1, UC_HOOK_BLOCK, hook_block, NULL, 1, 0);
    uc_hook_add(uc, &trace2, UC_HOOK_CODE, UnicornHookAllCallback, NULL, 0x10000, 0x100000000 - 0x10000 - 0x10000);
    uc_mem_map_ptr(uc, 0x10000, 0x100000000 - 0x10000 - 0x10000, UC_PROT_ALL, (void*)0x10000);

    void* Stack = StackList.GetHead();
    if (Stack == 0)
        Stack = AllocStack(EMU_STACK_SIZE);
    CbCallAtThreadExit(ReuseStack, Stack);

    DWORD my_reg_esp = EMU_STACK_SIZE - 128 + (DWORD)Stack;

    uc_reg_write(uc, UC_X86_REG_ESP, &my_reg_esp);

    DWORD my_FPCW= GetFPUCW();
    DWORD my_FPSW = 0x122;
    DWORD my_FPTW = 0xffff;
    uc_reg_write(uc, UC_X86_REG_FPCW, &my_FPCW);
    uc_reg_write(uc, UC_X86_REG_FPSW, &my_FPSW);
    uc_reg_write(uc, UC_X86_REG_FPTAG, &my_FPTW);

    va_list args;
    va_start(args, NParams);

    *(DWORD*)my_reg_esp = CbReturnToHost();

    for (int i = 0; i < NParams; i++)
        ((DWORD*)my_reg_esp)[i + 1] = va_arg(args, int);

    DWORD* TEB = (DWORD*)PeLdrGetCurrentTeb();
    TEB[1] = my_reg_esp;	// Fill stack top and size for Borland
    TEB[2] = EMU_STACK_SIZE;

    DWORD my_FSBASE = (DWORD)PeLdrGetCurrentTeb();

    uc_reg_write(uc, UC_X86_REG_FS_BASE, &my_FSBASE);

    uc_hook_add(uc, &trace3, UC_HOOK_INSN, hook_in, NULL, 1, 0, UC_X86_INS_IN);
    uc_hook_add(uc, &trace4,
        UC_HOOK_MEM_READ_UNMAPPED | UC_HOOK_MEM_WRITE_UNMAPPED,
        hook_mem_invalid, NULL, 1, 0);

    err = uc_emu_start(uc, Addr, (*(DWORD*)my_reg_esp), 0, 0);
    if (err) {
        printf("Failed on uc_emu_start() with error returned %u: %s\n", err,
            uc_strerror(err));
    }

    DWORD my_returnvalue;
    uc_reg_read(uc, UC_X86_REG_EAX, &my_returnvalue);

    CbRemoveCallAtThreadExit(ReuseStack, Stack);
    ReuseStack(Stack);

    uc_close(uc);
    return my_returnvalue;
}

#ifdef _M_ARM
extern "C" UINT64 __rdtsc() { return 0; }
extern "C" void __cpuid(void* lpcpuinfo,UINT32 cpuinfoleafid) {}
extern "C" void __cpuidex(void* lpcpuinfo, UINT32 cpuinfoleafid,UINT32 cpuinfocount) {}
#endif