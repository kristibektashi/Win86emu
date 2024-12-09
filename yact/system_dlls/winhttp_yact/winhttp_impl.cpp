struct IUnknown; // Workaround for "combaseapi.h(229): error C2187: syntax error: 'identifier' was unexpected here" when using /permissive- with the Windows 8.1 SDK
#include "dllyact_def.h"
#include <windows.h>
#include <util.h>
#include "callbacks.h"
#include "x86emul.h"
#include <winhttp.h>

//DEFINE_FUNC4(WinHttpSetStatusCallback)
EXTERN_C DW STUB_EXPORT yact_WinHttpSetStatusCallback(DW* R)
{
	return (DWORD)WinHttpSetStatusCallback((HINTERNET)p1, (WINHTTP_STATUS_CALLBACK)CbCreateNativeStdcallCallback((DWORD)p2, 5),p3,p4);
}