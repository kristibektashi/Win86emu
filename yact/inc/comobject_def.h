/* 
 * Yet Another Code Translator (c) mamaich, 2011
 *
 * Macros for DirectX and other COM stub DLLs (native code, function implementation)
 *
 */

#ifndef __DLLCOMOBJECT_H
#define __DLLCOMOBJECT_H

#define COMSTUB_EXPORT __fastcall
#define COMFUNC_EXPORT __stdcall
#ifdef __cplusplus
#define EXTERN_C extern "C"
#endif

#ifdef _WINDEF_
#error Do not include this file after windows.h
#endif

#include <windows.h>
#include <string.h>
#include <stddef.h>
#include "callbacks.h"

typedef unsigned int DW;

template <class IVtbl> class ICallbackDispatch
{
private:
	ICallbackDispatch() {}
	ICallbackDispatch(const ICallbackDispatch&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackDispatch<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackDispatch<IVtbl>* This, void* riid, ICallbackDispatch<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_GetTypeInfoCount(ICallbackDispatch<IVtbl>* This, UINT* pctinfo);
	typedef unsigned int COMFUNC_EXPORT t_GetTypeInfo(ICallbackDispatch<IVtbl>* This, UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo);
	typedef unsigned int COMFUNC_EXPORT t_GetIDsOfNames(ICallbackDispatch<IVtbl>* This, REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId);
	typedef unsigned int COMFUNC_EXPORT t_Invoke(ICallbackDispatch<IVtbl>* This, DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr);
	typedef unsigned int COMFUNC_EXPORT t_UserDef(ICallbackDispatch<IVtbl>* This, DW, DW, DW, DW, DW, DW, DW, DW, DW);
	DW CallingOther(DW idofinv, DW* R)
	{
		t_UserDef* Func = (t_UserDef*)((void**)This->IOriginal->Vtbl)[idofinv];
		return Func(((ICallbackDispatch<IVtbl>*)p1)->IOriginal, p2, p3, p4, p5, p6, p7, p8, p9, p10);
	}
public:
	IVtbl* Vtbl;
	DW Vtblxpi[255];
	ICallbackDispatch<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackDispatch<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackDispatch<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackDispatch<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackDispatch<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackDispatch<IVtbl>* This, void* riid, ICallbackDispatch<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[0];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackDispatch<IVtbl>(*Obj);
		return Ret;
		//*Obj = This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackDispatch<IVtbl>*)p1, (void*)p2, (ICallbackDispatch<IVtbl>**)p3);
	}

	static unsigned int _GetTypeInfoCount(ICallbackDispatch<IVtbl>* This, UINT* pctinfo)
	{
		t_GetTypeInfoCount* Func = (t_GetTypeInfoCount*)((void**)This->IOriginal->Vtbl)[3];
		return Func(This->IOriginal, pctinfo);
	}
	static DW COMSTUB_EXPORT GetTypeInfoCount(DW* R)
	{
		return _GetTypeInfoCount((ICallbackDispatch<IVtbl>*)p1, (UINT*)p2);
	}

	static unsigned int _GetTypeInfo(ICallbackDispatch<IVtbl>* This, UINT iTInfo, LCID lcid, ITypeInfo** ppTInfo)
	{
		t_GetTypeInfo* Func = (t_GetTypeInfo*)((void**)This->IOriginal->Vtbl)[4];
		return Func(This->IOriginal, iTInfo, lcid, ppTInfo);
	}
	static DW COMSTUB_EXPORT GetTypeInfo(DW* R)
	{
		return _GetTypeInfo((ICallbackDispatch<IVtbl>*)p1, (UINT)p2, (LCID)p3, (ITypeInfo**)p4);
	}

	static unsigned int _GetIDsOfNames(ICallbackDispatch<IVtbl>* This, REFIID riid, LPOLESTR* rgszNames, UINT cNames, LCID lcid, DISPID* rgDispId)
	{
		t_GetIDsOfNames* Func = (t_GetIDsOfNames*)((void**)This->IOriginal->Vtbl)[5];
		return Func(This->IOriginal, riid, rgszNames, cNames, lcid, rgDispId);
	}
	static DW COMSTUB_EXPORT GetIDsOfNames(DW* R)
	{
		return _GetIDsOfNames((ICallbackDispatch<IVtbl>*)p1, (REFIID)p2, (LPOLESTR*)p3, (UINT)p4, (LCID)p5, (DISPID*)p6);
	}

	static unsigned int _Invoke(ICallbackDispatch<IVtbl>* This, DISPID dispIdMember, REFIID riid, LCID lcid, WORD wFlags, DISPPARAMS* pDispParams, VARIANT* pVarResult, EXCEPINFO* pExcepInfo, UINT* puArgErr)
	{
		t_Invoke* Func = (t_Invoke*)((void**)This->IOriginal->Vtbl)[6];
		return Func(This->IOriginal, dispIdMember, riid, lcid, wFlags, pDispParams, pVarResult, pExcepInfo, puArgErr);
	}
	static DW COMSTUB_EXPORT Invoke(DW* R)
	{
		return _Invoke((ICallbackDispatch<IVtbl>*)p1, (DISPID)p2, (REFIID)p3, (LCID)p4, (WORD)p5, (DISPPARAMS*)p6, (VARIANT*)p7, (EXCEPINFO*)p8, (UINT*)p9);
	}
	static char* AddMethod(DW numberoffunc) {
		DWORD Tmp = 0;
#ifdef _ARM_
		/*
		ldr r1,[pc,8]
		nop
		ldr pc,[pc,0]

		0000:02 49
		0002:00 BF
		0004:DF F8 00 F0
		0008:00 00 00 00
		000c:00 00 00 00

		*/
		char Methodopc[] = { 0x02 ,0x49 ,0x00 ,0xBF ,0xDF ,0xF8 ,0x00 ,0xF0 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 ,0x00 };
		char* Methodopcx = (char*)malloc(sizeof(Methodopc));
		memcpy(Methodopcx, &Methodopc, sizeof(Methodopc));
		VirtualProtect(Methodopcx, sizeof(Methodopc), PAGE_EXECUTE_READWRITE, &Tmp);
		*((DWORD*)(((DWORD)&Methodopcx) + 0x8)) = numberoffunc;
		*((DWORD*)(((DWORD)&Methodopcx) + 0xc)) = (DWORD)&CallingOther;
#else
		/*
		mov eax,[esp]
		mov [esp-4],eax
		mov eax,[esp+4]
		mov [esp],eax
		mov eax,0x12345678
		mov [esp+4],eax
		sub esp,4
		jmp dword ptr [0xaabbccdd]

		0000:8B 04 24
		0003:89 44 24 FC
		0007:8B 44 24 04
		000b:89 04 24
		000e:B8 78 56 34 12
		0013:89 44 24 04
		0017:83 EC 04
		001a:FF 25 DD CC BB AA


		*/
		char Methodopc[] = { 0x8B ,0x04 ,0x24 ,0x89 ,0x44 ,0x24 ,0xFC ,0x8B ,0x44 ,0x24 ,0x04 ,0x89 ,0x04 ,0x24 ,0xB8 ,0x78 ,0x56 ,0x34 ,0x12 ,0x89 ,0x44 ,0x24 ,0x04 ,0x83 ,0xEC ,0x04 ,0xFF ,0x25 ,0xDD ,0xCC ,0xBB ,0xAA };
		char* Methodopcx = (char*)malloc(sizeof(Methodopc));
		memcpy(Methodopcx, &Methodopc, sizeof(Methodopc));
		VirtualProtect(Methodopcx, sizeof(Methodopc), PAGE_EXECUTE_READWRITE, &Tmp);
		*((DWORD*)(((DWORD)&Methodopcx) + 0x0f)) = numberoffunc;
		*((DWORD*)(((DWORD)&Methodopcx) + 0x1c)) = (&CallingOther);
#endif
		FlushInstructionCache(GetCurrentProcess(), Methodopcx, sizeof(Methodopc));
		return Methodopcx;
	}
	ICallbackDispatch(void* _IOriginal) : IOriginal((ICallbackDispatch<IVtbl>*)_IOriginal)
	{
		Data = 0;//((ICallbackDispatch<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackDispatch::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackDispatch::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackDispatch::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackDispatch::GetTypeInfoCount, 2);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackDispatch::GetTypeInfo, 4);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackDispatch::GetIDsOfNames, 6);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackDispatch::Invoke, 9);
		for (int cnt = 0; cnt < 255; cnt++) { Vtblxpi[cnt] = IOriginal->Vtblxpi[cnt]; }
		//for (int cnt = 0; cnt < 7; cnt++) { *((DWORD*)Vtbl + cnt) = (DWORD)(((DWORD)(&Vtbls)) + (cnt * 4)); }
		//for (int cnt = 0; cnt < (sizeof(IVtbl) / sizeof(DWORD)) - 7; cnt++) { *((DWORD*)Vtbl + 7 + cnt) = CbCreateX86StdcallCallback(AddMethod(7 + cnt), 10); }
		for (int cnt = 0; cnt < (sizeof(IVtbl) / sizeof(DWORD)); cnt++) { if ((*((DWORD*)IOriginal->Vtbl + cnt)) == 0) { *((DWORD*)Vtbl + cnt) = 0; } }
	}
	~ICallbackDispatch()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackUnknown
{
private:
	//ICallbackUnknown() {}
	//ICallbackUnknown(const ICallbackUnknown&) {}
    typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackUnknown<IVtbl> *This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackUnknown<IVtbl>* This, void* riid, ICallbackUnknown<IVtbl>** Obj);
public:
	IVtbl *Vtbl;
	ICallbackUnknown<IVtbl> *IOriginal;
	void *Data;		// may be used to store some data. Data should be freed by caller
	ICallbackUnknown() {}
	ICallbackUnknown(const ICallbackUnknown&) {}
	static unsigned int _AddRef(ICallbackUnknown<IVtbl> *This)
    {
		t_RefFunc *Func=(t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
    	return Func(This->IOriginal);
    }
	static DW COMSTUB_EXPORT AddRef(DW *R)
	{
		return _AddRef((ICallbackUnknown<IVtbl>*)p1);
	}
    static unsigned int _Release(ICallbackUnknown<IVtbl> *This)
    {
		t_RefFunc *Func=(t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
    	unsigned int Ret=Func(This->IOriginal);
    	if(Ret<=0)
    		delete This;
    	return Ret;
    }
	static DW COMSTUB_EXPORT Release(DW *R)
	{
		return _Release((ICallbackUnknown<IVtbl>*)p1);
	}
    static unsigned int _QueryInterface(ICallbackUnknown<IVtbl> *This, void *riid, ICallbackUnknown<IVtbl>**Obj)
    {
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal,riid,Obj);
		*Obj = new ICallbackUnknown<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
    	_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
    	return 0;   // S_OK
    }
	static DW COMSTUB_EXPORT QueryInterface(DW *R)
	{
		return _QueryInterface((ICallbackUnknown<IVtbl>*)p1,(void*)p2,(ICallbackUnknown<IVtbl>**)p3);
	}
	ICallbackUnknown(void *_IOriginal) : IOriginal((ICallbackUnknown<IVtbl>*)_IOriginal)
	{		
		Data=0;//((ICallbackUnknown<IVtbl>*)_IOriginal)->Data;
		Vtbl=(IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl,0,sizeof(IVtbl));
		*((DWORD*)Vtbl+0)=CbCreateX86StdcallCallback(ICallbackUnknown::QueryInterface,3);
		*((DWORD*)Vtbl+1)=CbCreateX86StdcallCallback(ICallbackUnknown::AddRef,1);
		*((DWORD*)Vtbl+2)=CbCreateX86StdcallCallback(ICallbackUnknown::Release,1);
	}
	~ICallbackUnknown()
	{
		for(int i=0; i<sizeof(IVtbl)/sizeof(void*); i++)
			if(*((DWORD*)Vtbl+i))
			{
//				if(i==2)	// This function is called from Release, so we can't free it
//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
//				else
//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl+i)=0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackEnumString
{
private:
	ICallbackEnumString() {}
	ICallbackEnumString(const ICallbackEnumString&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackEnumString<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackEnumString<IVtbl>* This, void* riid, ICallbackEnumString<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackEnumString<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackEnumString<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackEnumString<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackEnumString<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackEnumString<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackEnumString<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackEnumString<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackEnumString<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackEnumString<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackEnumString<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackEnumString<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackEnumString<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackEnumString<IVtbl>* This, void* riid, ICallbackEnumString<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackEnumString<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackEnumString<IVtbl>*)p1, (void*)p2, (ICallbackEnumString<IVtbl>**)p3);
	}

	static unsigned int _Next(ICallbackEnumString<IVtbl>* This, void* celt, void* rgelt, void* pceltFetched) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, celt, rgelt, pceltFetched); }
	static DW COMSTUB_EXPORT Next(DW* R)
	{
		return _Next((ICallbackEnumString<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _Skip(ICallbackEnumString<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT Skip(DW* R)
	{
		return _Skip((ICallbackEnumString<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _Reset(ICallbackEnumString<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal); }
	static DW COMSTUB_EXPORT Reset(DW* R)
	{
		return _Reset((ICallbackEnumString<IVtbl>*)p1);
	}
	static unsigned int _Clone(ICallbackEnumString<IVtbl>* This, ICallbackEnumString<IVtbl>* ppenum) { ICallbackEnumString<IVtbl>* ppenumtmp; UINT32 RET = ((t_callarg1*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, ppenumtmp); *ppenum = new ICallbackEnumString<IVtbl>(*ppenumtmp); return RET; }
	static DW COMSTUB_EXPORT Clone(DW* R)
	{
		return _Clone((ICallbackEnumString<IVtbl>*)p1, (ICallbackEnumString<IVtbl>*)p2);
	}
	ICallbackEnumString(void* _IOriginal) : IOriginal((ICallbackEnumString<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackEnumString<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackEnumString::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackEnumString::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackEnumString::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackEnumString::Next, 4);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackEnumString::Skip, 2);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackEnumString::Reset, 1);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackEnumString::Clone, 2);
	}
	~ICallbackEnumString()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template<typename ICallbackRunningObjectTable> class ICallbackRunningObjectTablex;

template <class IVtbl> class ICallbackStream
{
private:
	ICallbackStream() {}
	ICallbackStream(const ICallbackStream&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackStream<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackStream<IVtbl>* This, void* riid, ICallbackStream<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackStream<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackStream<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackStream<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackStream<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackStream<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackStream<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackStream<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackStream<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackStream<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackStream<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackStream<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackStream<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackStream<IVtbl>* This, void* riid, ICallbackStream<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackStream<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackStream<IVtbl>*)p1, (void*)p2, (ICallbackStream<IVtbl>**)p3);
	}

	static unsigned int _Read(ICallbackStream<IVtbl>* This, void* pv, void* cb, void* pcbRead) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, pv, cb, pcbRead); }
	static DW COMSTUB_EXPORT Read(DW* R)
	{
		return _Read((ICallbackStream<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _Write(ICallbackStream<IVtbl>* This, void* pv, void* cb, void* pcbRead) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, pv, cb, pcbRead); }
	static DW COMSTUB_EXPORT Write(DW* R)
	{
		return _Write((ICallbackStream<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _Seek(ICallbackStream<IVtbl>* This, void* pv, void* cb, void* pcbRead) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, pv, cb, pcbRead); }
	static DW COMSTUB_EXPORT Seek(DW* R)
	{
		return _Seek((ICallbackStream<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _SetSize(ICallbackStream<IVtbl>* This, void* pv) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, pv); }
	static DW COMSTUB_EXPORT SetSize(DW* R)
	{
		return _SetSize((ICallbackStream<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _CopyTo(ICallbackStream<IVtbl>* This, ICallbackStream<IVtbl>* pstm, void* cb, void* pcbRead, void* pcbWritten) { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal, pstm->IOriginal, cb, pcbRead, pcbWritten); }
	static DW COMSTUB_EXPORT CopyTo(DW* R)
	{
		return _CopyTo((ICallbackStream<IVtbl>*)p1, (ICallbackStream<IVtbl>*)p2, (void*)p3, (void*)p4, (void*)p5);
	}
	static unsigned int _Commit(ICallbackStream<IVtbl>* This, void* pv) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, pv); }
	static DW COMSTUB_EXPORT Commit(DW* R)
	{
		return _Commit((ICallbackStream<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _Revert(ICallbackStream<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal); }
	static DW COMSTUB_EXPORT Revert(DW* R)
	{
		return _Revert((ICallbackStream<IVtbl>*)p1);
	}
	static unsigned int _LockRegion(ICallbackStream<IVtbl>* This, void* pv, void* cb, void* pcbRead) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[10])(This->IOriginal, pv, cb, pcbRead); }
	static DW COMSTUB_EXPORT LockRegion(DW* R)
	{
		return _LockRegion((ICallbackStream<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _UnlockRegion(ICallbackStream<IVtbl>* This, void* pv, void* cb, void* pcbRead) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[11])(This->IOriginal, pv, cb, pcbRead); }
	static DW COMSTUB_EXPORT UnlockRegion(DW* R)
	{
		return _UnlockRegion((ICallbackStream<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _Stat(ICallbackStream<IVtbl>* This, void* pstm, void* cb) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[12])(This->IOriginal, pstm, cb); }
	static DW COMSTUB_EXPORT Stat(DW* R)
	{
		return _Stat((ICallbackStream<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _Clone(ICallbackStream<IVtbl>* This, void* pv) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[13])(This->IOriginal, pv); }
	static DW COMSTUB_EXPORT Clone(DW* R)
	{
		return _Clone((ICallbackStream<IVtbl>*)p1, (void*)p2);
	}
	ICallbackStream(void* _IOriginal) : IOriginal((ICallbackStream<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackStream<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackStream::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackStream::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackStream::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackStream::Read, 4);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackStream::Write, 4);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackStream::Seek, 4);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackStream::SetSize, 2);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackStream::CopyTo, 5);
		*((DWORD*)Vtbl + 8) = CbCreateX86StdcallCallback(ICallbackStream::Commit, 2);
		*((DWORD*)Vtbl + 9) = CbCreateX86StdcallCallback(ICallbackStream::Revert, 1);
		*((DWORD*)Vtbl + 10) = CbCreateX86StdcallCallback(ICallbackStream::LockRegion, 4);
		*((DWORD*)Vtbl + 11) = CbCreateX86StdcallCallback(ICallbackStream::UnlockRegion, 4);
		*((DWORD*)Vtbl + 12) = CbCreateX86StdcallCallback(ICallbackStream::Stat, 3);
		*((DWORD*)Vtbl + 13) = CbCreateX86StdcallCallback(ICallbackStream::Clone, 2);
	}
	~ICallbackStream()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackAdviseSink
{
private:
	ICallbackAdviseSink() {}
	ICallbackAdviseSink(const ICallbackAdviseSink&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackAdviseSink<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackAdviseSink<IVtbl>* This, void* riid, ICallbackAdviseSink<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackAdviseSink<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackAdviseSink<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackAdviseSink<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackAdviseSink<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackAdviseSink<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackAdviseSink<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackAdviseSink<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackAdviseSink<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackAdviseSink<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackAdviseSink<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackAdviseSink<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackAdviseSink<IVtbl>* This, void* riid, ICallbackAdviseSink<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackAdviseSink<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackAdviseSink<IVtbl>*)p1, (void*)p2, (ICallbackAdviseSink<IVtbl>**)p3);
	}

	static unsigned int _OnDataChange(ICallbackAdviseSink<IVtbl>* This, void* pFormatetc, void* pStgmed) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, pFormatetc, pStgmed); }
	static DW COMSTUB_EXPORT OnDataChange(DW* R)
	{
		return _OnDataChange((ICallbackAdviseSink<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _OnViewChange(ICallbackAdviseSink<IVtbl>* This, void* pFormatetc, void* pStgmed) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, pFormatetc, pStgmed); }
	static DW COMSTUB_EXPORT OnViewChange(DW* R)
	{
		return _OnViewChange((ICallbackAdviseSink<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _OnRename(ICallbackAdviseSink<IVtbl>* This, void* pFormatetc) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, pFormatetc); }
	static DW COMSTUB_EXPORT OnRename(DW* R)
	{
		return _OnRename((ICallbackAdviseSink<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _OnSave(ICallbackAdviseSink<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal); }
	static DW COMSTUB_EXPORT OnSave(DW* R)
	{
		return _OnSave((ICallbackAdviseSink<IVtbl>*)p1);
	}
	static unsigned int _OnClose(ICallbackAdviseSink<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal); }
	static DW COMSTUB_EXPORT OnClose(DW* R)
	{
		return _OnClose((ICallbackAdviseSink<IVtbl>*)p1);
	}
	ICallbackAdviseSink(void* _IOriginal) : IOriginal((ICallbackAdviseSink<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackAdviseSink<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackAdviseSink::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackAdviseSink::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackAdviseSink::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackAdviseSink::OnDataChange, 3);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackAdviseSink::OnViewChange, 3);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackAdviseSink::OnRename, 2);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackAdviseSink::OnSave, 1);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackAdviseSink::OnClose, 1);
	}
	~ICallbackAdviseSink()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackDataObject
{
private:
	ICallbackDataObject() {}
	ICallbackDataObject(const ICallbackDataObject&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackDataObject<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackDataObject<IVtbl>* This, void* riid, ICallbackDataObject<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackDataObject<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackDataObject<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackDataObject<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackDataObject<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackDataObject<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackDataObject<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackDataObject<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackDataObject<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackDataObject<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackDataObject<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackDataObject<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackDataObject<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackDataObject<IVtbl>* This, void* riid, ICallbackDataObject<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackDataObject<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (ICallbackDataObject<IVtbl>**)p3);
	}

	static unsigned int _GetData(ICallbackDataObject<IVtbl>* This, void* pformatetcIn, void* pmedium) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, pformatetcIn, pmedium); }
	static DW COMSTUB_EXPORT GetData(DW* R)
	{
		return _GetData((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _GetDataHere(ICallbackDataObject<IVtbl>* This, void* pformatetcIn, void* pmedium) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, pformatetcIn, pmedium); }
	static DW COMSTUB_EXPORT GetDataHere(DW* R)
	{
		return _GetDataHere((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _QueryGetData(ICallbackDataObject<IVtbl>* This, void* pformatetcIn) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, pformatetcIn); }
	static DW COMSTUB_EXPORT QueryGetData(DW* R)
	{
		return _QueryGetData((ICallbackDataObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _GetCanonicalFormatEtc(ICallbackDataObject<IVtbl>* This, void* pformatetcIn, void* pmedium) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, pformatetcIn, pmedium); }
	static DW COMSTUB_EXPORT GetCanonicalFormatEtc(DW* R)
	{
		return _GetCanonicalFormatEtc((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _SetData(ICallbackDataObject<IVtbl>* This, void* pformatetcIn, void* pmedium, void* fRelease) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal, pformatetcIn, pmedium, fRelease); }
	static DW COMSTUB_EXPORT SetData(DW* R)
	{
		return _SetData((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _EnumFormatEtc(ICallbackDataObject<IVtbl>* This, void* pformatetcIn, void* pmedium) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, pformatetcIn, pmedium); }
	static DW COMSTUB_EXPORT EnumFormatEtc(DW* R)
	{
		return _EnumFormatEtc((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _DAdvise(ICallbackDataObject<IVtbl>* This, void* pformatetc, void* advf, ICallbackAdviseSink<IAdviseSinkVtbl>* pAdvSink, void* pdwConnection) { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal, pformatetc, advf, (void*)pAdvSink->IOriginal, pdwConnection); }
	static DW COMSTUB_EXPORT DAdvise(DW* R)
	{
		return _DAdvise((ICallbackDataObject<IVtbl>*)p1, (void*)p2, (void*)p3, (ICallbackAdviseSink<IAdviseSinkVtbl>*)p4, (void*)p5);
	}
	static unsigned int _DUnadvise(ICallbackDataObject<IVtbl>* This, void* pformatetcIn) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[10])(This->IOriginal, pformatetcIn); }
	static DW COMSTUB_EXPORT DUnadvise(DW* R)
	{
		return _DUnadvise((ICallbackDataObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _EnumDAdvise(ICallbackDataObject<IVtbl>* This, void* pformatetcIn) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[11])(This->IOriginal, pformatetcIn); }
	static DW COMSTUB_EXPORT EnumDAdvise(DW* R)
	{
		return _EnumDAdvise((ICallbackDataObject<IVtbl>*)p1, (void*)p2);
	}
	ICallbackDataObject(void* _IOriginal) : IOriginal((ICallbackDataObject<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackDataObject<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackDataObject::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackDataObject::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackDataObject::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackDataObject::GetData, 3);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackDataObject::GetDataHere, 3);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackDataObject::QueryGetData, 2);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackDataObject::GetCanonicalFormatEtc, 3);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackDataObject::SetData, 4);
		*((DWORD*)Vtbl + 8) = CbCreateX86StdcallCallback(ICallbackDataObject::EnumFormatEtc, 3);
		*((DWORD*)Vtbl + 9) = CbCreateX86StdcallCallback(ICallbackDataObject::DAdvise, 5);
		*((DWORD*)Vtbl + 10) = CbCreateX86StdcallCallback(ICallbackDataObject::DUnadvise, 2);
		*((DWORD*)Vtbl + 11) = CbCreateX86StdcallCallback(ICallbackDataObject::EnumDAdvise, 2);
	}
	~ICallbackDataObject()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <typename IVtbl> class ICallbackBindCtx;
template <typename IVtbl> class ICallbackEnumMoniker;

template <class IVtbl> class ICallbackMoniker
{
private:
	//ICallbackMoniker() {}
	//ICallbackMoniker(const ICallbackMoniker&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackMoniker<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackMoniker<IVtbl>* This, void* riid, ICallbackMoniker<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackMoniker<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackMoniker<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackMoniker<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackMoniker<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackMoniker<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackMoniker<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackMoniker<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackMoniker<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	ICallbackMoniker() {}
	ICallbackMoniker(const ICallbackMoniker&) {}
	static unsigned int _AddRef(ICallbackMoniker<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackMoniker<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackMoniker<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackMoniker<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackMoniker<IVtbl>* This, void* riid, ICallbackMoniker<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackMoniker<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackMoniker<IVtbl>*)p1, (void*)p2, (ICallbackMoniker<IVtbl>**)p3);
	}

	static unsigned int _GetClassID(ICallbackMoniker<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT GetClassID(DW* R)
	{
		return _GetClassID((ICallbackMoniker<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _IsDirty(ICallbackMoniker<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal); }
	static DW COMSTUB_EXPORT IsDirty(DW* R)
	{
		return _IsDirty((ICallbackMoniker<IVtbl>*)p1);
	}
	static unsigned int _Load(ICallbackMoniker<IVtbl>* This, ICallbackStream<IStreamVtbl>* pStm) { if (pStm == NULL) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, NULL); } else { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, pStm->IOriginal); } }
	static DW COMSTUB_EXPORT Load(DW* R)
	{
		return _Load((ICallbackMoniker<IVtbl>*)p1, (ICallbackStream<IStreamVtbl>*)p2);
	}
	static unsigned int _Save(ICallbackMoniker<IVtbl>* This, ICallbackStream<IStreamVtbl>* pStm, void* fClearDirty) { if (pStm == NULL) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, NULL, fClearDirty); } else{ return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, pStm->IOriginal, fClearDirty); } }
	static DW COMSTUB_EXPORT Save(DW* R)
	{
		return _Save((ICallbackMoniker<IVtbl>*)p1, (ICallbackStream<IStreamVtbl>*)p2, (void*)p3);
	}
	static unsigned int _GetSizeMax(ICallbackMoniker<IVtbl>* This, void* pcbSize) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal, pcbSize); }
	static DW COMSTUB_EXPORT GetSizeMax(DW* R)
	{
		return _GetSizeMax((ICallbackMoniker<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _BindToObject(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, ICallbackMoniker<IMonikerVtbl>* pmkToLeft, void* riidResult, void* ppvResult) { if (pmkToLeft == NULL) { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, pbc->IOriginal, 0, riidResult, ppvResult); } else { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, pbc->IOriginal, pmkToLeft->IOriginal, riidResult, ppvResult); } }
	static DW COMSTUB_EXPORT BindToObject(DW* R)
	{
		return _BindToObject((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (void*)p4, (void*)p5);
	}
	static unsigned int _BindToStorage(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, ICallbackMoniker<IMonikerVtbl>* pmkToLeft, void* riidResult, void* ppvResult) { if (pmkToLeft == NULL) { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal, pbc->IOriginal, 0, riidResult, ppvResult); } else { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal, pbc->IOriginal, pmkToLeft->IOriginal, riidResult, ppvResult); } }
	static DW COMSTUB_EXPORT BindToStorage(DW* R)
	{
		return _BindToStorage((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (void*)p4, (void*)p5);
	}
	static unsigned int _Reduce(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, void* dwReduceHowFar, ICallbackMoniker<IMonikerVtbl>* ppmkToLeft, ICallbackMoniker<IMonikerVtbl>* ppmkReduced) { void* icmprmabc[2] = { 0 , 0 }; if (pbc != NULL) { icmprmabc[0] = pbc->IOriginal; } if (ppmkToLeft != NULL) { icmprmabc[1] = ppmkToLeft->IOriginal; } UINT32 RET = ((t_callarg4*)((void**)This->IOriginal->Vtbl)[10])(This->IOriginal, icmprmabc[0], dwReduceHowFar, icmprmabc[1], ppmkReduced); if (ppmkToLeft != NULL) { *ppmkToLeft = new ICallbackMoniker<IMonikerVtbl>((ICallbackMoniker<IMonikerVtbl>*)icmprmabc[1]); } if (ppmkReduced != NULL) { *ppmkReduced = new ICallbackMoniker<IMonikerVtbl>(*ppmkReduced); } return RET; }
	static DW COMSTUB_EXPORT Reduce(DW* R)
	{
		return _Reduce((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (void*)p3, (ICallbackMoniker<IMonikerVtbl>*)p4, (ICallbackMoniker<IMonikerVtbl>*)p5);
	}
	static unsigned int _ComposeWith(ICallbackMoniker<IVtbl>* This, ICallbackMoniker<IMonikerVtbl>* pmkRight, void* fOnlyIfNotGeneric, ICallbackMoniker<IMonikerVtbl>* ppmkComposite) { void* icmprmabc = 0; if (pmkRight != NULL) { icmprmabc = pmkRight->IOriginal; } UINT32 RET = ((t_callarg3*)((void**)This->IOriginal->Vtbl)[11])(This->IOriginal, icmprmabc, fOnlyIfNotGeneric, ppmkComposite); if (ppmkComposite != NULL) { *ppmkComposite = new ICallbackMoniker<IMonikerVtbl>(*ppmkComposite); } return RET; }
	static DW COMSTUB_EXPORT ComposeWith(DW* R)
	{
		return _ComposeWith((ICallbackMoniker<IVtbl>*)p1, (ICallbackMoniker<IMonikerVtbl>*)p2, (void*)p3, (ICallbackMoniker<IMonikerVtbl>*)p4);
	}
	static unsigned int _Enum(ICallbackMoniker<IVtbl>* This, void* fForward, ICallbackEnumMoniker<IEnumMonikerVtbl>* ppenumMoniker) { if (ppenumMoniker == NULL) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[12])(This->IOriginal, fForward, NULL); } else { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[12])(This->IOriginal, fForward, ppenumMoniker); } }
	static DW COMSTUB_EXPORT Enum(DW* R)
	{
		return _Enum((ICallbackMoniker<IVtbl>*)p1, (void*)p2, (ICallbackEnumMoniker<IEnumMonikerVtbl>*)p3);
	}
	static unsigned int _IsEqual(ICallbackMoniker<IVtbl>* This, ICallbackMoniker<IMoniker>* pmkOtherMoniker) { if (pmkOtherMoniker == NULL) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[13])(This->IOriginal, NULL); } else { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[13])(This->IOriginal, pmkOtherMoniker); } }
	static DW COMSTUB_EXPORT IsEqual(DW* R)
	{
		return _IsEqual((ICallbackMoniker<IVtbl>*)p1, (ICallbackMoniker<IMoniker>*)p2);
	}
	static unsigned int _Hash(ICallbackMoniker<IVtbl>* This, void* pdwHash) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[14])(This->IOriginal, pdwHash); }
	static DW COMSTUB_EXPORT Hash(DW* R)
	{
		return _Hash((ICallbackMoniker<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _IsRunning(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, ICallbackMoniker<IMonikerVtbl>* pmkToLeft, ICallbackMoniker<IMonikerVtbl>* pmkNewlyRunning) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[15])(This->IOriginal, ((pbc==NULL) ? NULL:pbc->IOriginal), ((pmkToLeft == NULL) ? NULL : pmkToLeft->IOriginal), ((pmkNewlyRunning == NULL) ? NULL : pmkNewlyRunning->IOriginal));  }
	static DW COMSTUB_EXPORT IsRunning(DW* R)
	{
		return _IsRunning((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (ICallbackMoniker<IMonikerVtbl>*)p4);
	}
	static unsigned int _GetTimeOfLastChange(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, ICallbackMoniker<IMonikerVtbl>* pmkToLeft, void* pFileTime) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[16])(This->IOriginal, ((pbc == NULL) ? NULL : pbc->IOriginal), ((pmkToLeft == NULL) ? NULL : pmkToLeft->IOriginal), pFileTime); }
	static DW COMSTUB_EXPORT GetTimeOfLastChange(DW* R)
	{
		return _GetTimeOfLastChange((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (void*)p4);
	}
	static unsigned int _Inverse(ICallbackMoniker<IVtbl>* This, ICallbackMoniker<IMonikerVtbl>* ppmk) { UINT32 RET = ((t_callarg1*)((void**)This->IOriginal->Vtbl)[17])(This->IOriginal, ppmk); if (ppmk != NULL) { *ppmk = new ICallbackMoniker<IMonikerVtbl>(*ppmk); } return RET; }
	static DW COMSTUB_EXPORT Inverse(DW* R)
	{
		return _Inverse((ICallbackMoniker<IVtbl>*)p1, (ICallbackMoniker<IMonikerVtbl>*)p2);
	}
	static unsigned int _CommonPrefixWith(ICallbackMoniker<IVtbl>* This, ICallbackMoniker<IMonikerVtbl>* pmkOther, ICallbackMoniker<IMonikerVtbl>* ppmkPrefix) { UINT32 RET = ((t_callarg2*)((void**)This->IOriginal->Vtbl)[18])(This->IOriginal, ((pmkOther == NULL) ? NULL : pmkOther->IOriginal), ppmkPrefix); if (ppmkPrefix != NULL) { *ppmkPrefix = new ICallbackMoniker<IMonikerVtbl>(*ppmkPrefix); } return RET; }
	static DW COMSTUB_EXPORT CommonPrefixWith(DW* R)
	{
		return _CommonPrefixWith((ICallbackMoniker<IVtbl>*)p1, (ICallbackMoniker<IMonikerVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3);
	}
	static unsigned int _RelativePathTo(ICallbackMoniker<IVtbl>* This, ICallbackMoniker<IMonikerVtbl>* pmkOther, ICallbackMoniker<IMonikerVtbl>* ppmkPrefix) { UINT32 RET = ((t_callarg2*)((void**)This->IOriginal->Vtbl)[19])(This->IOriginal, ((pmkOther == NULL) ? NULL : pmkOther->IOriginal), ppmkPrefix); if (ppmkPrefix != NULL) { *ppmkPrefix = new ICallbackMoniker<IMonikerVtbl>(*ppmkPrefix); } return RET; }
	static DW COMSTUB_EXPORT RelativePathTo(DW* R)
	{
		return _RelativePathTo((ICallbackMoniker<IVtbl>*)p1, (ICallbackMoniker<IMonikerVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3);
	}
	static unsigned int _GetDisplayName(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, ICallbackMoniker<IMonikerVtbl>* pmkToLeft, void* ppszDisplayName) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[20])(This->IOriginal, ((pbc == NULL) ? NULL : pbc->IOriginal), ((pmkToLeft == NULL) ? NULL : pmkToLeft->IOriginal), ppszDisplayName); }
	static DW COMSTUB_EXPORT GetDisplayName(DW* R)
	{
		return _GetDisplayName((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (void*)p4);
	}
	static unsigned int _ParseDisplayName(ICallbackMoniker<IVtbl>* This, ICallbackBindCtx<IBindCtxVtbl>* pbc, ICallbackMoniker<IMonikerVtbl>* pmkToLeft, void* ppszDisplayName, void* pchEaten, ICallbackMoniker<IVtbl>* ppmkOut) { return ((t_callarg5*)((void**)This->IOriginal->Vtbl)[21])(This->IOriginal, ((pbc == NULL) ? NULL : pbc->IOriginal), ((pmkToLeft == NULL) ? NULL : pmkToLeft->IOriginal), ppszDisplayName, pchEaten, ppmkOut); if (ppmkOut != NULL) { *ppmkOut = new ICallbackMoniker<IVtbl>(*ppmkOut); } }
	static DW COMSTUB_EXPORT ParseDisplayName(DW* R)
	{
		return _ParseDisplayName((ICallbackMoniker<IVtbl>*)p1, (ICallbackBindCtx<IBindCtxVtbl>*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (void*)p4, (void*)p5, (ICallbackMoniker<IVtbl>*)p6);
	}
	static unsigned int _IsSystemMoniker(ICallbackMoniker<IVtbl>* This, void* pdwHash) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[22])(This->IOriginal, pdwHash); }
	static DW COMSTUB_EXPORT IsSystemMoniker(DW* R)
	{
		return _IsSystemMoniker((ICallbackMoniker<IVtbl>*)p1, (void*)p2);
	}
	ICallbackMoniker(void* _IOriginal) : IOriginal((ICallbackMoniker<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackMoniker<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackMoniker::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackMoniker::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackMoniker::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackMoniker::GetClassID, 2);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackMoniker::IsDirty, 1);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackMoniker::Load, 2);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackMoniker::Save, 3);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackMoniker::GetSizeMax, 2);
		*((DWORD*)Vtbl + 8) = CbCreateX86StdcallCallback(ICallbackMoniker::BindToObject, 5);
		*((DWORD*)Vtbl + 9) = CbCreateX86StdcallCallback(ICallbackMoniker::BindToStorage, 5);
		*((DWORD*)Vtbl + 10) = CbCreateX86StdcallCallback(ICallbackMoniker::Reduce, 5);
		*((DWORD*)Vtbl + 11) = CbCreateX86StdcallCallback(ICallbackMoniker::ComposeWith, 4);
		*((DWORD*)Vtbl + 12) = CbCreateX86StdcallCallback(ICallbackMoniker::Enum, 3);
		*((DWORD*)Vtbl + 13) = CbCreateX86StdcallCallback(ICallbackMoniker::IsEqual, 2);
		*((DWORD*)Vtbl + 14) = CbCreateX86StdcallCallback(ICallbackMoniker::Hash, 2);
		*((DWORD*)Vtbl + 15) = CbCreateX86StdcallCallback(ICallbackMoniker::IsRunning, 4);
		*((DWORD*)Vtbl + 16) = CbCreateX86StdcallCallback(ICallbackMoniker::GetTimeOfLastChange, 4);
		*((DWORD*)Vtbl + 17) = CbCreateX86StdcallCallback(ICallbackMoniker::Inverse, 2);
		*((DWORD*)Vtbl + 18) = CbCreateX86StdcallCallback(ICallbackMoniker::CommonPrefixWith, 3);
		*((DWORD*)Vtbl + 19) = CbCreateX86StdcallCallback(ICallbackMoniker::RelativePathTo, 3);
		*((DWORD*)Vtbl + 20) = CbCreateX86StdcallCallback(ICallbackMoniker::GetDisplayName, 4);
		*((DWORD*)Vtbl + 21) = CbCreateX86StdcallCallback(ICallbackMoniker::ParseDisplayName, 6);
		*((DWORD*)Vtbl + 22) = CbCreateX86StdcallCallback(ICallbackMoniker::IsSystemMoniker, 2);
	}
	~ICallbackMoniker()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackEnumMoniker
{
private:
	//ICallbackEnumMoniker() {}
	//ICallbackEnumMoniker(const ICallbackEnumMoniker&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackEnumMoniker<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackEnumMoniker<IVtbl>* This, void* riid, ICallbackEnumMoniker<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackEnumMoniker<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackEnumMoniker<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackEnumMoniker<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackEnumMoniker<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackEnumMoniker<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackEnumMoniker<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackEnumMoniker<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackEnumMoniker<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	ICallbackEnumMoniker() {}
	ICallbackEnumMoniker(const ICallbackEnumMoniker&) {}
	static unsigned int _AddRef(ICallbackEnumMoniker<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackEnumMoniker<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackEnumMoniker<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackEnumMoniker<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackEnumMoniker<IVtbl>* This, void* riid, ICallbackEnumMoniker<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackEnumMoniker<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackEnumMoniker<IVtbl>*)p1, (void*)p2, (ICallbackEnumMoniker<IVtbl>**)p3);
	}

	static unsigned int _Next(ICallbackEnumMoniker<IVtbl>* This, void* celt, ICallbackMoniker<IMonikerVtbl>* rgelt, void* pceltFetched) { UINT32 RET = ((t_callarg3*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, celt, rgelt, pceltFetched); if (rgelt != NULL) { *rgelt = new ICallbackMoniker<IMonikerVtbl>(*rgelt); } return RET; }
	static DW COMSTUB_EXPORT Next(DW* R)
	{
		return _Next((ICallbackEnumMoniker<IVtbl>*)p1, (void*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3, (void*)p4);
	}
	static unsigned int _Skip(ICallbackEnumMoniker<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT Skip(DW* R)
	{
		return _Skip((ICallbackEnumMoniker<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _Reset(ICallbackEnumMoniker<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal); }
	static DW COMSTUB_EXPORT Reset(DW* R)
	{
		return _Reset((ICallbackEnumMoniker<IVtbl>*)p1);
	}
	static unsigned int _Clone(ICallbackEnumMoniker<IVtbl>* This, ICallbackEnumMoniker<IVtbl>* ppenum) { ICallbackEnumMoniker<IVtbl>* ppenumtmp; UINT32 RET = ((t_callarg1*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, ppenumtmp); *ppenum = new ICallbackEnumMoniker<IVtbl>(*ppenumtmp); return RET; }
	static DW COMSTUB_EXPORT Clone(DW* R)
	{
		return _Clone((ICallbackEnumMoniker<IVtbl>*)p1, (ICallbackEnumMoniker<IVtbl>*)p2);
	}
	ICallbackEnumMoniker(void* _IOriginal) : IOriginal((ICallbackEnumMoniker<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackEnumMoniker<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::Next, 4);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::Skip, 2);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::Reset, 1);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackEnumMoniker::Clone, 2);
	}
	~ICallbackEnumMoniker()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackRunningObjectTable
{
private:
	//ICallbackRunningObjectTable() {}
	//ICallbackRunningObjectTable(const ICallbackRunningObjectTable&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackRunningObjectTable<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackRunningObjectTable<IVtbl>* This, void* riid, ICallbackRunningObjectTable<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackRunningObjectTable<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackRunningObjectTable<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackRunningObjectTable<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackRunningObjectTable<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackRunningObjectTable<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackRunningObjectTable<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackRunningObjectTable<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackRunningObjectTable<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	ICallbackRunningObjectTable() {}
	ICallbackRunningObjectTable(const ICallbackRunningObjectTable&) {}
	static unsigned int _AddRef(ICallbackRunningObjectTable<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackRunningObjectTable<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackRunningObjectTable<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackRunningObjectTable<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackRunningObjectTable<IVtbl>* This, void* riid, ICallbackRunningObjectTable<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackRunningObjectTable<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackRunningObjectTable<IVtbl>*)p1, (void*)p2, (ICallbackRunningObjectTable<IVtbl>**)p3);
	}

	static unsigned int _Register(ICallbackRunningObjectTable<IVtbl>* This, void* grfFlags, ICallbackUnknown<IVtbl>* punkObject, ICallbackMoniker<IVtbl>* pmkObjectName, void* pdwRegister) { return ((t_callarg4*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, grfFlags, punkObject->IOriginal, pmkObjectName->IOriginal, pdwRegister); }
	static DW COMSTUB_EXPORT Register(DW* R)
	{
		return _Register((ICallbackRunningObjectTable<IVtbl>*)p1, (void*)p2, (ICallbackUnknown<IVtbl>*)p3, (ICallbackMoniker<IVtbl>*)p4, (void*)p5);
	}
	static unsigned int _Revoke(ICallbackRunningObjectTable<IVtbl>* This, void* grfFlags) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, grfFlags); }
	static DW COMSTUB_EXPORT Revoke(DW* R)
	{
		return _Revoke((ICallbackRunningObjectTable<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _IsRunning(ICallbackRunningObjectTable<IVtbl>* This, ICallbackMoniker<IVtbl>* pmkObjectName) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, pmkObjectName->IOriginal); }
	static DW COMSTUB_EXPORT IsRunning(DW* R)
	{
		return _IsRunning((ICallbackRunningObjectTable<IVtbl>*)p1, (ICallbackMoniker<IVtbl>*)p2);
	}
	static unsigned int _GetObject(ICallbackRunningObjectTable<IVtbl>* This, ICallbackMoniker<IMonikerVtbl>* pmkObjectName, ICallbackUnknown<IVtbl>* punkObject) { UINT32 RET = ((t_callarg2*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, pmkObjectName->IOriginal, punkObject); if (punkObject != NULL) { *punkObject = new ICallbackUnknown<IVtbl>(*punkObject); } return RET; }
	static DW COMSTUB_EXPORT GetObject(DW* R)
	{
		return _GetObject((ICallbackRunningObjectTable<IVtbl>*)p1, (ICallbackMoniker<IMonikerVtbl>*)p2, (ICallbackUnknown<IVtbl>*)p3);
	}
	static unsigned int _NoteChangeTime(ICallbackRunningObjectTable<IVtbl>* This, void* dwRegister, void* pfiletime) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal, dwRegister, pfiletime); }
	static DW COMSTUB_EXPORT NoteChangeTime(DW* R)
	{
		return _NoteChangeTime((ICallbackRunningObjectTable<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _GetTimeOfLastChange(ICallbackRunningObjectTable<IVtbl>* This, void* dwRegister, void* pfiletime) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, dwRegister, pfiletime); }
	static DW COMSTUB_EXPORT GetTimeOfLastChange(DW* R)
	{
		return _GetTimeOfLastChange((ICallbackRunningObjectTable<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _EnumRunning(ICallbackRunningObjectTable<IVtbl>* This, ICallbackEnumMoniker<IVtbl>* ppenumMoniker) { UINT32 RET = ((t_callarg1*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal, ppenumMoniker); *ppenumMoniker = new ICallbackEnumMoniker<IVtbl>(*ppenumMoniker); return RET; }
	static DW COMSTUB_EXPORT EnumRunning(DW* R)
	{
		return _EnumRunning((ICallbackRunningObjectTable<IVtbl>*)p1, (ICallbackEnumMoniker<IVtbl>*)p2);
	}
	ICallbackRunningObjectTable(void* _IOriginal) : IOriginal((ICallbackRunningObjectTable<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackRunningObjectTable<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::Register, 5);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::Revoke, 2);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::IsRunning, 2);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::GetObject, 3);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::NoteChangeTime, 3);
		*((DWORD*)Vtbl + 8) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::GetTimeOfLastChange, 3);
		*((DWORD*)Vtbl + 9) = CbCreateX86StdcallCallback(ICallbackRunningObjectTable::EnumRunning, 2);
	}
	~ICallbackRunningObjectTable()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackBindCtx
{
private:
	ICallbackBindCtx() {}
	ICallbackBindCtx(const ICallbackBindCtx&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackBindCtx<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackBindCtx<IVtbl>* This, void* riid, ICallbackBindCtx<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackBindCtx<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackBindCtx<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackBindCtx<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackBindCtx<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg5(ICallbackBindCtx<IVtbl>* This, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackBindCtx<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackBindCtx<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackBindCtx<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackBindCtx<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackBindCtx<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackBindCtx<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackBindCtx<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackBindCtx<IVtbl>* This, void* riid, ICallbackBindCtx<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackBindCtx<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackBindCtx<IVtbl>*)p1, (void*)p2, (ICallbackBindCtx<IVtbl>**)p3);
	}

	static unsigned int _RegisterObjectBound(ICallbackBindCtx<IVtbl>* This, ICallbackUnknown<IUnknownVtbl>* punk) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal, punk->IOriginal); }
	static DW COMSTUB_EXPORT RegisterObjectBound(DW* R)
	{
		return _RegisterObjectBound((ICallbackBindCtx<IVtbl>*)p1, (ICallbackUnknown<IUnknownVtbl>*)p2);
	}
	static unsigned int _RevokeObjectBound(ICallbackBindCtx<IVtbl>* This, ICallbackUnknown<IUnknownVtbl>* punk) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, punk->IOriginal); }
	static DW COMSTUB_EXPORT RevokeObjectBound(DW* R)
	{
		return _RevokeObjectBound((ICallbackBindCtx<IVtbl>*)p1, (ICallbackUnknown<IUnknownVtbl>*)p2);
	}
	static unsigned int _ReleaseBoundObjects(ICallbackBindCtx<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal); }
	static DW COMSTUB_EXPORT ReleaseBoundObjects(DW* R)
	{
		return _ReleaseBoundObjects((ICallbackBindCtx<IVtbl>*)p1);
	}
	static unsigned int _SetBindOptions(ICallbackBindCtx<IVtbl>* This, void* pbindopts) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, pbindopts); }
	static DW COMSTUB_EXPORT SetBindOptions(DW* R)
	{
		return _SetBindOptions((ICallbackBindCtx<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _GetBindOptions(ICallbackBindCtx<IVtbl>* This, void* pbindopts) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal, pbindopts); }
	static DW COMSTUB_EXPORT GetBindOptions(DW* R)
	{
		return _GetBindOptions((ICallbackBindCtx<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _GetRunningObjectTable(ICallbackBindCtx<IVtbl>* This, ICallbackRunningObjectTable<IRunningObjectTableVtbl>* pprot) { UINT32 RET = ((t_callarg1*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, pprot); *pprot = new ICallbackRunningObjectTable<IRunningObjectTableVtbl>(*pprot); return RET; }
	static DW COMSTUB_EXPORT GetRunningObjectTable(DW* R)
	{
		return _GetRunningObjectTable((ICallbackBindCtx<IVtbl>*)p1, (ICallbackRunningObjectTable<IRunningObjectTableVtbl>*)p2);
	}
	static unsigned int _RegisterObjectParam(ICallbackBindCtx<IVtbl>* This, void* pszKey, ICallbackUnknown<IUnknownVtbl>* punk) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal, pszKey, punk->IOriginal); }
	static DW COMSTUB_EXPORT RegisterObjectParam(DW* R)
	{
		return _RegisterObjectParam((ICallbackBindCtx<IVtbl>*)p1, (void*)p2, (ICallbackUnknown<IUnknownVtbl>*)p3);
	}
	static unsigned int _GetObjectParam(ICallbackBindCtx<IVtbl>* This, void* pszKey, ICallbackUnknown<IVtbl>* punk) { UINT32 RET = ((t_callarg2*)((void**)This->IOriginal->Vtbl)[10])(This->IOriginal, pszKey, punk); *punk = ICallbackUnknown<IVtbl>(*punk); return RET; }
	static DW COMSTUB_EXPORT GetObjectParam(DW* R)
	{
		return _GetObjectParam((ICallbackBindCtx<IVtbl>*)p1, (void*)p2, (ICallbackUnknown<IVtbl>*)p3);
	}
	static unsigned int _EnumObjectParam(ICallbackBindCtx<IBindCtxVtbl>* This, ICallbackEnumString<IEnumStringVtbl>* ppenum) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[11])(This->IOriginal, ppenum->IOriginal); }
	static DW COMSTUB_EXPORT EnumObjectParam(DW* R)
	{
		return _EnumObjectParam((ICallbackBindCtx<IBindCtxVtbl>*)p1, (ICallbackEnumString<IEnumStringVtbl>*)p2);
	}
	static unsigned int _RevokeObjectParam(ICallbackBindCtx<IBindCtxVtbl>* This, void* pbindopts) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[12])(This->IOriginal, pbindopts); }
	static DW COMSTUB_EXPORT RevokeObjectParam(DW* R)
	{
		return _RevokeObjectParam((ICallbackBindCtx<IBindCtxVtbl>*)p1, (void*)p2);
	}
	ICallbackBindCtx(void* _IOriginal) : IOriginal((ICallbackBindCtx<IBindCtxVtbl>*)_IOriginal)
	{
		Data = ((ICallbackBindCtx<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackBindCtx::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackBindCtx::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackBindCtx::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackBindCtx::RegisterObjectBound, 2);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackBindCtx::RevokeObjectBound, 2);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackBindCtx::ReleaseBoundObjects, 1);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackBindCtx::SetBindOptions, 2);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackBindCtx::GetBindOptions, 2);
		*((DWORD*)Vtbl + 8) = CbCreateX86StdcallCallback(ICallbackBindCtx::GetRunningObjectTable, 2);
		*((DWORD*)Vtbl + 9) = CbCreateX86StdcallCallback(ICallbackBindCtx::RegisterObjectParam, 3);
		*((DWORD*)Vtbl + 10) = CbCreateX86StdcallCallback(ICallbackBindCtx::GetObjectParam, 3);
		*((DWORD*)Vtbl + 11) = CbCreateX86StdcallCallback(ICallbackBindCtx::EnumObjectParam, 2);
		*((DWORD*)Vtbl + 12) = CbCreateX86StdcallCallback(ICallbackBindCtx::RevokeObjectParam, 2);
	}
	~ICallbackBindCtx()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};

template <class IVtbl> class ICallbackOleObject
{
private:
	ICallbackOleObject() {}
	ICallbackOleObject(const ICallbackOleObject&) {}
	typedef unsigned int COMFUNC_EXPORT t_RefFunc(ICallbackOleObject<IVtbl>* This);
	typedef unsigned int COMFUNC_EXPORT t_QueryInterface(ICallbackOleObject<IVtbl>* This, void* riid, ICallbackOleObject<IVtbl>** Obj);
	typedef unsigned int COMFUNC_EXPORT t_callarg1(ICallbackOleObject<IVtbl>* This, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg2(ICallbackOleObject<IVtbl>* This, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg3(ICallbackOleObject<IVtbl>* This, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg4(ICallbackOleObject<IVtbl>* This, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg6(ICallbackOleObject<IVtbl>* This, void*, void*, void*, void*, void*, void*);
	typedef unsigned int COMFUNC_EXPORT t_callarg7(ICallbackOleObject<IVtbl>* This, void*, void*, void*, void*, void*, void*, void*);
public:
	IVtbl* Vtbl;
	ICallbackOleObject<IVtbl>* IOriginal;
	void* Data;		// may be used to store some data. Data should be freed by caller
	static unsigned int _AddRef(ICallbackOleObject<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[1];
		return Func(This->IOriginal);
	}
	static DW COMSTUB_EXPORT AddRef(DW* R)
	{
		return _AddRef((ICallbackOleObject<IVtbl>*)p1);
	}
	static unsigned int _Release(ICallbackOleObject<IVtbl>* This)
	{
		t_RefFunc* Func = (t_RefFunc*)((void**)This->IOriginal->Vtbl)[2];
		unsigned int Ret = Func(This->IOriginal);
		if (Ret <= 0)
			delete This;
		return Ret;
	}
	static DW COMSTUB_EXPORT Release(DW* R)
	{
		return _Release((ICallbackOleObject<IVtbl>*)p1);
	}
	static unsigned int _QueryInterface(ICallbackOleObject<IVtbl>* This, void* riid, ICallbackOleObject<IVtbl>** Obj)
	{
		t_QueryInterface* Func = (t_QueryInterface*)((void**)This->IOriginal->Vtbl)[1];
		unsigned int Ret = Func(This->IOriginal, riid, Obj);
		*Obj = new ICallbackOleObject<IVtbl>(*Obj);
		return Ret;
		//*Obj=This;	// dirty hack in the case if QueryInterface is not specially implemented
		_AddRef(This);
#ifdef _DEBUG
		__debugbreak();
#endif
		return 0;   // S_OK
	}
	static DW COMSTUB_EXPORT QueryInterface(DW* R)
	{
		return _QueryInterface((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (ICallbackOleObject<IVtbl>**)p3);
	}

	static unsigned int _SetClientSite(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[3])(This->IOriginal,pClientSite); }
	static DW COMSTUB_EXPORT SetClientSite(DW* R)
	{
		return _SetClientSite((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _GetClientSite(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[4])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT GetClientSite(DW* R)
	{
		return _GetClientSite((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _SetHostNames(ICallbackOleObject<IVtbl>* This, void* szContainerApp, void* szContainerObj) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[5])(This->IOriginal, szContainerApp, szContainerObj); }
	static DW COMSTUB_EXPORT SetHostNames(DW* R)
	{
		return _SetHostNames((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _Close(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[6])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT Close(DW* R)
	{
		return _Close((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _SetMoniker(ICallbackOleObject<IVtbl>* This, void* szContainerApp, ICallbackMoniker<IMonikerVtbl>* pmk) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[7])(This->IOriginal, szContainerApp, ((pmk == NULL) ? NULL : pmk->IOriginal)); }
	static DW COMSTUB_EXPORT SetMoniker(DW* R)
	{
		return _SetMoniker((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (ICallbackMoniker<IMonikerVtbl>*)p3);
	}
	static unsigned int _GetMoniker(ICallbackOleObject<IVtbl>* This, void* szContainerApp, void* szContainerObj, ICallbackMoniker<IMonikerVtbl>* ppmk) { UINT32 RET = ((t_callarg3*)((void**)This->IOriginal->Vtbl)[8])(This->IOriginal, szContainerApp, szContainerObj, ppmk); if (ppmk != NULL) { *ppmk = new ICallbackMoniker<IMonikerVtbl>(*ppmk); } return RET; }
	static DW COMSTUB_EXPORT GetMoniker(DW* R)
	{
		return _GetMoniker((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3, (ICallbackMoniker<IMonikerVtbl>*)p4);
	}
	static unsigned int _InitFromData(ICallbackOleObject<IVtbl>* This, ICallbackDataObject<IDataObjectVtbl>* pDataObject, void* szContainerObj, void* ppmk) { return ((t_callarg3*)((void**)This->IOriginal->Vtbl)[9])(This->IOriginal, ((pDataObject == NULL) ? NULL : pDataObject->IOriginal), szContainerObj, ppmk); }
	static DW COMSTUB_EXPORT InitFromData(DW* R)
	{
		return _InitFromData((ICallbackOleObject<IVtbl>*)p1, (ICallbackDataObject<IDataObjectVtbl>*)p2, (void*)p3, (void*)p4);
	}
	static unsigned int _GetClipboardData(ICallbackOleObject<IVtbl>* This, void* szContainerApp, ICallbackDataObject<IDataObjectVtbl>** ppDataObject) { ICallbackDataObject<IDataObjectVtbl>** pppDataObject; UINT32 RET = ((t_callarg2*)((void**)This->IOriginal->Vtbl)[10])(This->IOriginal, szContainerApp, (ICallbackDataObject<IDataObjectVtbl>**)pppDataObject); if (pppDataObject != NULL) { *ppDataObject = new ICallbackDataObject<IDataObjectVtbl>(*pppDataObject); } return RET; }
	static DW COMSTUB_EXPORT GetClipboardData(DW* R)
	{
		return _GetClipboardData((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (ICallbackDataObject<IDataObjectVtbl>**)p3);
	}
	static unsigned int _DoVerb(ICallbackOleObject<IVtbl>* This, void* iVerb, void* lpmsg, void* pActiveSite, void* lindex, void* hwndParent, void* lprcPosRect) { return ((t_callarg6*)((void**)This->IOriginal->Vtbl)[11])(This->IOriginal, iVerb, lpmsg, pActiveSite, lindex, hwndParent, lprcPosRect); }
	static DW COMSTUB_EXPORT DoVerb(DW* R)
	{
		return _DoVerb((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3, (void*)p4, (void*)p5, (void*)p6, (void*)p7);
	}
	static unsigned int _EnumVerbs(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[12])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT EnumVerbs(DW* R)
	{
		return _EnumVerbs((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _Update(ICallbackOleObject<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[13])(This->IOriginal); }
	static DW COMSTUB_EXPORT Update(DW* R)
	{
		return _Update((ICallbackOleObject<IVtbl>*)p1);
	}
	static unsigned int _IsUpToDate(ICallbackOleObject<IVtbl>* This) { return ((t_RefFunc*)((void**)This->IOriginal->Vtbl)[14])(This->IOriginal); }
	static DW COMSTUB_EXPORT IsUpToDate(DW* R)
	{
		return _IsUpToDate((ICallbackOleObject<IVtbl>*)p1);
	}
	static unsigned int _GetUserClassID(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[15])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT GetUserClassID(DW* R)
	{
		return _GetUserClassID((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _GetUserType(ICallbackOleObject<IVtbl>* This, void* szContainerApp, void* szContainerObj) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[16])(This->IOriginal, szContainerApp, szContainerObj); }
	static DW COMSTUB_EXPORT GetUserType(DW* R)
	{
		return _GetUserType((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _SetExtent(ICallbackOleObject<IVtbl>* This, void* szContainerApp, void* szContainerObj) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[17])(This->IOriginal, szContainerApp, szContainerObj); }
	static DW COMSTUB_EXPORT SetExtent(DW* R)
	{
		return _SetExtent((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _GetExtent(ICallbackOleObject<IVtbl>* This, void* szContainerApp, void* szContainerObj) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[18])(This->IOriginal, szContainerApp, szContainerObj); }
	static DW COMSTUB_EXPORT GetExtent(DW* R)
	{
		return _GetExtent((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _Advise(ICallbackOleObject<IVtbl>* This, ICallbackAdviseSink<IAdviseSinkVtbl>* pAdvSink, void* szContainerObj) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[19])(This->IOriginal, pAdvSink->IOriginal, szContainerObj); }
	static DW COMSTUB_EXPORT Advise(DW* R)
	{
		return _Advise((ICallbackOleObject<IVtbl>*)p1, (ICallbackAdviseSink<IAdviseSinkVtbl>*)p2, (void*)p3);
	}
	static unsigned int _Unadvise(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[20])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT Unadvise(DW* R)
	{
		return _Unadvise((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _EnumAdvise(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[21])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT EnumAdvise(DW* R)
	{
		return _EnumAdvise((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	static unsigned int _GetMiscStatus(ICallbackOleObject<IVtbl>* This, void* szContainerApp, void* szContainerObj) { return ((t_callarg2*)((void**)This->IOriginal->Vtbl)[22])(This->IOriginal, szContainerApp, szContainerObj); }
	static DW COMSTUB_EXPORT GetMiscStatus(DW* R)
	{
		return _GetMiscStatus((ICallbackOleObject<IVtbl>*)p1, (void*)p2, (void*)p3);
	}
	static unsigned int _SetColorScheme(ICallbackOleObject<IVtbl>* This, void* pClientSite) { return ((t_callarg1*)((void**)This->IOriginal->Vtbl)[23])(This->IOriginal, pClientSite); }
	static DW COMSTUB_EXPORT SetColorScheme(DW* R)
	{
		return _SetColorScheme((ICallbackOleObject<IVtbl>*)p1, (void*)p2);
	}
	ICallbackOleObject(void* _IOriginal) : IOriginal((ICallbackOleObject<IVtbl>*)_IOriginal)
	{
		Data = ((ICallbackUnknown<IVtbl>*)_IOriginal)->Data;
		Vtbl = (IVtbl*)malloc(sizeof(IVtbl));
		memset(Vtbl, 0, sizeof(IVtbl));
		*((DWORD*)Vtbl + 0) = CbCreateX86StdcallCallback(ICallbackOleObject::QueryInterface, 3);
		*((DWORD*)Vtbl + 1) = CbCreateX86StdcallCallback(ICallbackOleObject::AddRef, 1);
		*((DWORD*)Vtbl + 2) = CbCreateX86StdcallCallback(ICallbackOleObject::Release, 1);
		*((DWORD*)Vtbl + 3) = CbCreateX86StdcallCallback(ICallbackOleObject::SetClientSite, 2);
		*((DWORD*)Vtbl + 4) = CbCreateX86StdcallCallback(ICallbackOleObject::GetClientSite, 2);
		*((DWORD*)Vtbl + 5) = CbCreateX86StdcallCallback(ICallbackOleObject::SetHostNames, 3);
		*((DWORD*)Vtbl + 6) = CbCreateX86StdcallCallback(ICallbackOleObject::Close, 2);
		*((DWORD*)Vtbl + 7) = CbCreateX86StdcallCallback(ICallbackOleObject::SetMoniker, 3);
		*((DWORD*)Vtbl + 8) = CbCreateX86StdcallCallback(ICallbackOleObject::GetMoniker, 4);
		*((DWORD*)Vtbl + 9) = CbCreateX86StdcallCallback(ICallbackOleObject::InitFromData, 4);
		*((DWORD*)Vtbl + 10) = CbCreateX86StdcallCallback(ICallbackOleObject::GetClipboardData, 3);
		*((DWORD*)Vtbl + 11) = CbCreateX86StdcallCallback(ICallbackOleObject::DoVerb, 7);
		*((DWORD*)Vtbl + 12) = CbCreateX86StdcallCallback(ICallbackOleObject::EnumVerbs, 2);
		*((DWORD*)Vtbl + 13) = CbCreateX86StdcallCallback(ICallbackOleObject::Update, 1);
		*((DWORD*)Vtbl + 14) = CbCreateX86StdcallCallback(ICallbackOleObject::IsUpToDate, 1);
		*((DWORD*)Vtbl + 15) = CbCreateX86StdcallCallback(ICallbackOleObject::GetUserClassID, 2);
		*((DWORD*)Vtbl + 16) = CbCreateX86StdcallCallback(ICallbackOleObject::GetUserType, 3);
		*((DWORD*)Vtbl + 17) = CbCreateX86StdcallCallback(ICallbackOleObject::SetExtent, 3);
		*((DWORD*)Vtbl + 18) = CbCreateX86StdcallCallback(ICallbackOleObject::GetExtent, 3);
		*((DWORD*)Vtbl + 19) = CbCreateX86StdcallCallback(ICallbackOleObject::Advise, 3);
		*((DWORD*)Vtbl + 20) = CbCreateX86StdcallCallback(ICallbackOleObject::Unadvise, 2);
		*((DWORD*)Vtbl + 21) = CbCreateX86StdcallCallback(ICallbackOleObject::EnumAdvise, 2);
		*((DWORD*)Vtbl + 22) = CbCreateX86StdcallCallback(ICallbackOleObject::GetMiscStatus, 3);
		*((DWORD*)Vtbl + 23) = CbCreateX86StdcallCallback(ICallbackOleObject::SetColorScheme, 2);
	}
	~ICallbackOleObject()
	{
		for (int i = 0; i < sizeof(IVtbl) / sizeof(void*); i++)
			if (*((DWORD*)Vtbl + i))
			{
				//				if(i==2)	// This function is called from Release, so we can't free it
				//					CbCallAtThreadExit(CbFreeCallback,(void*)*((DWORD*)Vtbl+i));	
				//				else
				//					CbFreeCallback(*((DWORD*)Vtbl+i));
				*((DWORD*)Vtbl + i) = 0;
			}
		free(Vtbl);
	}
};



#define DEFINE_CALLBACK(prefix,name,nparams) 	\
*(DWORD*)(&prefix->Vtbl->name)=CbCreateX86StdcallCallback(prefix##_##name,nparams);

#define DEFINE_VER_CALLBACK(ver,prefix,name,nparams) 	\
	*(DWORD*)(&prefix->Vtbl->name)=CbCreateX86StdcallCallback(prefix##ver##_##name,nparams);

#define DEFINE_CALLBACK1(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,1)
#define DEFINE_CALLBACK2(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,2)
#define DEFINE_CALLBACK3(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,3)
#define DEFINE_CALLBACK4(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,4)
#define DEFINE_CALLBACK5(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,5)
#define DEFINE_CALLBACK6(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,6)
#define DEFINE_CALLBACK7(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,7)
#define DEFINE_CALLBACK8(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,8)
#define DEFINE_CALLBACK9(prefix,type,name) 	DEFINE_CALLBACK(prefix,name,9)
#define DEFINE_CALLBACK10(prefix,type,name) DEFINE_CALLBACK(prefix,name,10)

#define DEFINE_VER_CALLBACK1(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,1)
#define DEFINE_VER_CALLBACK2(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,2)
#define DEFINE_VER_CALLBACK3(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,3)
#define DEFINE_VER_CALLBACK4(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,4)
#define DEFINE_VER_CALLBACK5(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,5)
#define DEFINE_VER_CALLBACK6(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,6)
#define DEFINE_VER_CALLBACK7(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,7)
#define DEFINE_VER_CALLBACK8(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,8)
#define DEFINE_VER_CALLBACK9(ver,prefix,type,name) 	DEFINE_VER_CALLBACK(ver,prefix,name,9)
#define DEFINE_VER_CALLBACK10(ver,prefix,type,name) DEFINE_VER_CALLBACK(ver,prefix,name,10)

#define PROTO_COMFUNC1(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc1(void*);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC2(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc2(void*,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC3(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc3(void*,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC4(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc4(void*,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC5(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc5(void*,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC6(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc6(void*,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC7(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc7(void*,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC8(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc8(void*,DW,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC9(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc9(void*,DW,DW,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);

#define PROTO_COMFUNC10(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc10(void*,DW,DW,DW,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R);


#define DEFINE_COMFUNC1(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc1(void*);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc1*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal); 	\
}

#define DEFINE_COMFUNC2(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc2(void*,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc2*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1]); 	\
}

#define DEFINE_COMFUNC3(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc3(void*,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc3*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2]); 	\
}

#define DEFINE_COMFUNC4(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc4(void*,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc4*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3]); 	\
}

#define DEFINE_COMFUNC5(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc5(void*,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc5*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3],R[4]); 	\
}

#define DEFINE_COMFUNC6(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc6(void*,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc6*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3],R[4],R[5]); 	\
}

#define DEFINE_COMFUNC7(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc7(void*,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc7*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3],R[4],R[5],R[6]); 	\
}

#define DEFINE_COMFUNC8(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc8(void*,DW,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc8*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3],R[4],R[5],R[6],R[7]); 	\
}

#define DEFINE_COMFUNC9(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc9(void*,DW,DW,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc9*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3],R[4],R[5],R[6],R[7],R[8]); 	\
}

#define DEFINE_COMFUNC10(prefix,type,name) 	\
typedef DW COMFUNC_EXPORT t_ComFunc10(void*,DW,DW,DW,DW,DW,DW,DW,DW);	\
DW COMSTUB_EXPORT prefix##_##name(DW *R)		\
{	\
	ICallbackUnknown<type> *Tmp=(ICallbackUnknown<type>*)R[0];	\
    return ((t_ComFunc10*)(Tmp->IOriginal->Vtbl->name))(Tmp->IOriginal,R[1],R[2],R[3],R[4],R[5],R[6],R[7],R[8],R[9]); 	\
}

#endif // __DLLYACT_H
