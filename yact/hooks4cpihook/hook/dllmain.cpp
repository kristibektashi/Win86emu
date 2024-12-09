// dllmain.cpp : DLL アプリケーションのエントリ ポイントを定義します。
#include "pch.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        LoadLibraryA(".\\Windows\\cpihook.dll");
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

LRESULT WINAPI HookProc(int code, WPARAM wParam, LPARAM lParam) {
    return NULL;
}

extern "C" __declspec(dllexport) void Inject() {
    SetWindowsHookEx(WH_CALLWNDPROC, HookProc, GetModuleHandle(__TEXT("hook")), 0);
}