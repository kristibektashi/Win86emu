#include "dllyact_def.h"

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
EXTERN_C DW __declspec(dllimport) AVISave(DW,DW,DW,DW,DW,DW,...);
EXTERN_C DW __declspec(dllexport) __stdcall yact_AVISave(DW *R){
	R[3] = CbCreateNativeStdcallCallback(R[3], 5);
	return AVISave(R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8], R[9], R[10], R[11], R[12], R[13], R[14], R[15], R[16], R[17], R[18], R[19], R[20], R[21], R[22], R[23], R[24], R[25], R[26], R[27], R[28], R[29], R[30], R[31], R[32], R[33], R[34], R[35], R[36], R[37]);
}
//DEFINE_FUNC_CB6(AVISaveA,3,5)
EXTERN_C DW __declspec(dllimport) AVISaveA(DW,DW,DW,DW,DW,DW,...);
EXTERN_C DW __declspec(dllexport) __stdcall yact_AVISaveA(DW *R){
	R[3] = CbCreateNativeStdcallCallback(R[3], 5);
	return AVISaveA(R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8], R[9], R[10], R[11], R[12], R[13], R[14], R[15], R[16], R[17], R[18], R[19], R[20], R[21], R[22], R[23], R[24], R[25], R[26], R[27], R[28], R[29], R[30], R[31], R[32], R[33], R[34], R[35], R[36], R[37]);
}
DEFINE_FUNC5(AVISaveOptions)
DEFINE_FUNC2(AVISaveOptionsFree)
DEFINE_FUNC_CB6(AVISaveV,3,5)
DEFINE_FUNC_CB6(AVISaveVA,3,5)
DEFINE_FUNC_CB6(AVISaveVW,3,5)
//DEFINE_FUNC_CB6(AVISaveW,3,5)
EXTERN_C DW __declspec(dllimport) AVISaveW(DW,DW,DW,DW,DW,DW,...);
EXTERN_C DW __declspec(dllexport) __stdcall yact_AVISaveW(DW *R){
	R[3] = CbCreateNativeStdcallCallback(R[3], 5);
	return AVISaveW(R[0], R[1], R[2], R[3], R[4], R[5], R[6], R[7], R[8], R[9], R[10], R[11], R[12], R[13], R[14], R[15], R[16], R[17], R[18], R[19], R[20], R[21], R[22], R[23], R[24], R[25], R[26], R[27], R[28], R[29], R[30], R[31], R[32], R[33], R[34], R[35], R[36], R[37]);
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
/*DEFINE_FUNC1(IID_IAVIEditStream)
DEFINE_FUNC1(IID_IAVIFile)
DEFINE_FUNC1(IID_IAVIStream)
DEFINE_FUNC1(IID_IGetFrame)*/
