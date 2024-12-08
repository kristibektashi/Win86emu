#include "dllstub_def.h"

static const char DLL_NAME[] = "avifil32.nt.dll";

DEFINE_FUNC3(AVIBuildFilter)
DEFINE_FUNC3(AVIBuildFilterA)
DEFINE_FUNC3(AVIBuildFilterW)
DEFINE_FUNC0(AVIClearClipboard)
DEFINE_FUNC1(AVIFileAddRef)
DEFINE_FUNC3(AVIFileCreateStream)
DEFINE_FUNC3(AVIFileCreateStreamA)
DEFINE_FUNC3(AVIFileCreateStreamW)
DEFINE_FUNC1(AVIFileEndRecord)
DEFINE_FUNC0(AVIFileExit)
DEFINE_FUNC4(AVIFileGetStream)
DEFINE_FUNC3(AVIFileInfo)
DEFINE_FUNC3(AVIFileInfoA)
DEFINE_FUNC3(AVIFileInfoW)
DEFINE_FUNC0(AVIFileInit)
DEFINE_FUNC4(AVIFileOpen)
DEFINE_FUNC4(AVIFileOpenA)
DEFINE_FUNC4(AVIFileOpenW)
DEFINE_FUNC4(AVIFileReadData)
DEFINE_FUNC1(AVIFileRelease)
DEFINE_FUNC4(AVIFileWriteData)
DEFINE_FUNC1(AVIGetFromClipboard)
DEFINE_FUNC4(AVIMakeCompressedStream)
DEFINE_FUNC3(AVIMakeFileFromStreams)
DEFINE_FUNC3(AVIMakeStreamFromClipboard)
DEFINE_FUNC1(AVIPutFileOnClipboard)
//DEFINE_FUNC_CB6(AVISave,3,5)
static const ModuleDef str_AVISave = { DLL_NAME,"AVISave" };
EXTERN_C DW __declspec(dllexport) stub_AVISave(DW p1, ...) {
	DW *p=&p1;
	__asm { mov eax,p }
	__asm { jmp f1 }
	__asm { mov eax,offset str_AVISave }
f1:	__asm { in eax,0xe5 }
	__asm { mov p,eax }
	return (DW)p;
}
//DEFINE_FUNC_CB6(AVISaveA,3,5)
static const ModuleDef str_AVISaveA = { DLL_NAME,"AVISaveA" };
EXTERN_C DW __declspec(dllexport) stub_AVISaveA(DW p1, ...) {
	DW *p=&p1;
	__asm { mov eax,p }
	__asm { jmp f1 }
	__asm { mov eax,offset str_AVISaveA }
f1:	__asm { in eax,0xe5 }
	__asm { mov p,eax }
	return (DW)p;
}
DEFINE_FUNC5(AVISaveOptions)
DEFINE_FUNC2(AVISaveOptionsFree)
DEFINE_FUNC6(AVISaveV, 3, 5)
DEFINE_FUNC6(AVISaveVA, 3, 5)
DEFINE_FUNC6(AVISaveVW, 3, 5)
//DEFINE_FUNC_CB6(AVISaveW,3,5)
static const ModuleDef str_AVISaveW = { DLL_NAME,"AVISaveW" };
EXTERN_C DW __declspec(dllexport) stub_AVISaveW(DW p1, ...) {
	DW *p=&p1;
	__asm { mov eax,p }
	__asm { jmp f1 }
	__asm { mov eax,offset str_AVISaveW }
f1:	__asm { in eax,0xe5 }
	__asm { mov p,eax }
	return (DW)p;
}
DEFINE_FUNC1(AVIStreamAddRef)
DEFINE_FUNC4(AVIStreamBeginStreaming)
DEFINE_FUNC4(AVIStreamCreate)
DEFINE_FUNC1(AVIStreamEndStreaming)
DEFINE_FUNC3(AVIStreamFindSample)
DEFINE_FUNC2(AVIStreamGetFrame)
DEFINE_FUNC1(AVIStreamGetFrameClose)
DEFINE_FUNC2(AVIStreamGetFrameOpen)
DEFINE_FUNC3(AVIStreamInfo)
DEFINE_FUNC3(AVIStreamInfoA)
DEFINE_FUNC3(AVIStreamInfoW)
DEFINE_FUNC1(AVIStreamLength)
DEFINE_FUNC6(AVIStreamOpenFromFile)
DEFINE_FUNC6(AVIStreamOpenFromFileA)
DEFINE_FUNC6(AVIStreamOpenFromFileW)
DEFINE_FUNC7(AVIStreamRead)
DEFINE_FUNC4(AVIStreamReadData)
DEFINE_FUNC4(AVIStreamReadFormat)
DEFINE_FUNC1(AVIStreamRelease)
DEFINE_FUNC2(AVIStreamSampleToTime)
DEFINE_FUNC4(AVIStreamSetFormat)
DEFINE_FUNC1(AVIStreamStart)
DEFINE_FUNC2(AVIStreamTimeToSample)
DEFINE_FUNC8(AVIStreamWrite)
DEFINE_FUNC4(AVIStreamWriteData)
DEFINE_FUNC2(CreateEditableStream)
DEFINE_FUNC2(EditStreamClone)
DEFINE_FUNC4(EditStreamCopy)
DEFINE_FUNC4(EditStreamCut)
DEFINE_FUNC6(EditStreamPaste)
DEFINE_FUNC3(EditStreamSetInfo)
DEFINE_FUNC3(EditStreamSetInfoA)
DEFINE_FUNC3(EditStreamSetInfoW)
DEFINE_FUNC2(EditStreamSetName)
DEFINE_FUNC2(EditStreamSetNameA)
DEFINE_FUNC2(EditStreamSetNameW)