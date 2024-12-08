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