#define __INLINE_ISEQUAL_GUID 1
#define CINTERFACE	// I need C interface for DDraw for lpVtbl member
#include "dllyact_def.h"
#include "comobject_def.h"
#include <windows.h>
#include <util.h>
#include <regredir.h>
#include <ShlGuid.h>
#include <ShlDisp.h>
#include "callbacks.h"

#include "Exdisp.h"

#define INITGUID
#include "guiddef.h"

//DEFINE_FUNC2(RegisterDragDrop)
EXTERN_C DW STUB_EXPORT yact_RegisterDragDrop(DW *R)
{
	// TODO: Not implemented
	return S_OK;
}

//DEFINE_COMFUNC5(AC,IAutoComplete2Vtbl,Init);
EXTERN_C DW COMSTUB_EXPORT AC_Init(DW *R)
{
	// TODO: Not implemented
	return -1;
}
DEFINE_COMFUNC2(AC,IAutoComplete2Vtbl,Enable);
DEFINE_COMFUNC2(AC,IAutoComplete2Vtbl,SetOptions);
DEFINE_COMFUNC2(AC,IAutoComplete2Vtbl,GetOptions);


DEFINE_COMFUNC2(IE, DWebBrowserEvents2Vtbl, GetTypeInfoCount);
DEFINE_COMFUNC4(IE, DWebBrowserEvents2Vtbl, GetTypeInfo);
DEFINE_COMFUNC6(IE, DWebBrowserEvents2Vtbl, GetIDsOfNames);
DEFINE_COMFUNC9(IE, DWebBrowserEvents2Vtbl, Invoke);

DEFINE_GUID(DIID_DWebBrowserEvents2_, 0x8856f961,0x340a,0x11d0,0xa9,0x6b,0x00,0xc0,0x4f,0xd7,0x05,0xa2);

EXTERN_C DW STUB_EXPORT yact_CoCreateInstanceNT(DW *R)
{
	DW Ret=REGDB_E_CLASSNOTREG;
	REFCLSID rclsid=*(IID*)p1;
	LPUNKNOWN pUnkOuter=(LPUNKNOWN)p2;
	DWORD dwClsContext=p3;
	REFIID riid=*(IID*)p4;
	LPVOID * ppv=(LPVOID*)p5;

	if(rclsid==CLSID_AutoComplete)
	{
		Ret=CoCreateInstance(
		rclsid,
		pUnkOuter,
		dwClsContext,
		riid,
		ppv);
		if(Ret==S_OK)
		{
			ICallbackUnknown<IAutoComplete2Vtbl> *AC=new ICallbackUnknown<IAutoComplete2Vtbl>(*ppv);
			*ppv=AC;
			DEFINE_CALLBACK5(AC,IAutoComplete2Vtbl,Init);
			DEFINE_CALLBACK2(AC,IAutoComplete2Vtbl,Enable);
			DEFINE_CALLBACK2(AC,IAutoComplete2Vtbl,SetOptions);
			DEFINE_CALLBACK2(AC,IAutoComplete2Vtbl,GetOptions);
		}
		return Ret;
	} else {
		Ret = CoCreateInstance(
			rclsid,
			pUnkOuter,
			dwClsContext,
			riid,
			ppv);
		if (Ret == S_OK)
		{
			ICallbackDispatch<DWebBrowserEvents2Vtbl>* defaultobj = new ICallbackDispatch<DWebBrowserEvents2Vtbl>(*ppv);
			*ppv = defaultobj;
			return Ret;
		}
		else { Ret = REGDB_E_CLASSNOTREG; }
		//return Ret;
	}


	LogWarn("Not implemented CLSID: {%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
             rclsid.Data1, rclsid.Data2, rclsid.Data3,
             rclsid.Data4[0], rclsid.Data4[1], rclsid.Data4[2], rclsid.Data4[3],
             rclsid.Data4[4], rclsid.Data4[5], rclsid.Data4[6], rclsid.Data4[7]);
	LogWarn("Not implemented IID: {%08x-%04x-%04x-%02x%02x-%02x%02x%02x%02x%02x%02x}",
             riid.Data1, riid.Data2, riid.Data3,
             riid.Data4[0], riid.Data4[1], riid.Data4[2], riid.Data4[3],
             riid.Data4[4], riid.Data4[5], riid.Data4[6], riid.Data4[7]);

	/*DW Ret=CoCreateInstance(
		rclsid,
		pUnkOuter,
		dwClsContext,
		riid,
		ppv);*/

	*ppv=0;
	return Ret;
}