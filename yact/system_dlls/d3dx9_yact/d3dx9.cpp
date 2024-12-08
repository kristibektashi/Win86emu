#include "dllyact_def.h"

#define DEFINE_FUNC19(name) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{	\
  DW r=name(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,(R[18]));	\
  LEAVE(19);		\
  return r;		\
}

#define DEFINE_FUNC_CB19(name,cbpos,ncbparams) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{ R[cbpos-1]=CbCreateNativeStdcallCallback(R[cbpos-1],ncbparams);\
  DW r=name(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,(R[18]));	\
  LEAVE(19);		\
  return r;		\
}

#define DEFINE_FUNC_CB10_2(name,cbpos,ncbparams,cbpos2,ncbparams2) 	\
EXTERN_C DW STUB_IMPORT name(DW,DW,DW,DW,DW,DW,DW,DW,DW,DW);	\
EXTERN_C DW STUB_EXPORT yact_##name(DW *R)		\
{ R[cbpos-1]=CbCreateNativeStdcallCallback(R[cbpos-1],ncbparams);\
  R[cbpos2-1]=CbCreateNativeStdcallCallback(R[cbpos2-1],ncbparams2);\
  DW r=name(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10);	\
  LEAVE(10);		\
  return r;		\
}


DEFINE_FUNC7(D3DXAssembleShader)
DEFINE_FUNC6(D3DXAssembleShaderFromFileA)
DEFINE_FUNC6(D3DXAssembleShaderFromFileW)
DEFINE_FUNC7(D3DXAssembleShaderFromResourceA)
DEFINE_FUNC7(D3DXAssembleShaderFromResourceW)
DEFINE_FUNC4(D3DXBoxBoundProbe)
DEFINE_FUNC6(D3DXCheckCubeTextureRequirements)
DEFINE_FUNC7(D3DXCheckTextureRequirements)
DEFINE_FUNC2(D3DXCheckVersion)
DEFINE_FUNC8(D3DXCheckVolumeTextureRequirements)
DEFINE_FUNC6(D3DXCleanMesh)
DEFINE_FUNC3(D3DXColorAdjustContrast)
DEFINE_FUNC3(D3DXColorAdjustSaturation)
DEFINE_FUNC10(D3DXCompileShader)
DEFINE_FUNC9(D3DXCompileShaderFromFileA)
DEFINE_FUNC9(D3DXCompileShaderFromFileW)
DEFINE_FUNC10(D3DXCompileShaderFromResourceA)
DEFINE_FUNC10(D3DXCompileShaderFromResourceW)
DEFINE_FUNC5(D3DXComputeBoundingBox)
DEFINE_FUNC5(D3DXComputeBoundingSphere)
DEFINE_FUNC_CB11(D3DXComputeIMTFromPerTexelSignal, 9, 2)
DEFINE_FUNC_CB8(D3DXComputeIMTFromPerVertexSignal, 6, 2)
DEFINE_FUNC_CB10_2(D3DXComputeIMTFromSignal, 6, 5, 8, 2)
DEFINE_FUNC_CB7(D3DXComputeIMTFromTexture, 5, 2)
DEFINE_FUNC6(D3DXComputeNormalMap)
DEFINE_FUNC2(D3DXComputeNormals)
DEFINE_FUNC6(D3DXComputeTangent)
DEFINE_FUNC2(D3DXComputeTangentFrame)
DEFINE_FUNC16(D3DXComputeTangentFrameEx)
DEFINE_FUNC8(D3DXConcatenateMeshes)
DEFINE_FUNC5(D3DXConvertMeshSubsetToSingleStrip)
DEFINE_FUNC7(D3DXConvertMeshSubsetToStrips)
bool params4keyanimctrleralloced = false;
DW params4keyanimctrler[] = {
3,
1,
1,
1,
1,
1,
1,
6,
2,
2,
1,
3,
3,
4,
1,
1,
3,
3,
3,
3,
3,
4,
3,
3,
3,
2,
1,
8,
8,
6,
5,
7,
2,
2,
1,
3,
1,
3,
2,
2,
3,
6
};
//DEFINE_FUNC5(D3DXCreateAnimationController)
EXTERN_C DW STUB_IMPORT D3DXCreateAnimationController(DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateAnimationController(DW* R)
{
DW r = D3DXCreateAnimationController(p1, p2, p3, p4, p5);
if (p5 != 0) {
	if (params4keyanimctrleralloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4keyanimctrler) / 4); cnt++) {
			params4keyanimctrler[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p5)) + (cnt * 4))), params4keyanimctrler[cnt]);
		}
		params4keyanimctrleralloced = true;
	}
	*(DW*)(p5) = (DW)&params4keyanimctrler;
}
LEAVE(5);
return r;
}
DEFINE_FUNC6(D3DXCreateBox)
DEFINE_FUNC2(D3DXCreateBuffer)
DEFINE_FUNC8(D3DXCreateCompressedAnimationSet)
DEFINE_FUNC7(D3DXCreateCubeTexture)
DEFINE_FUNC3(D3DXCreateCubeTextureFromFileA)
DEFINE_FUNC13(D3DXCreateCubeTextureFromFileExA)
DEFINE_FUNC13(D3DXCreateCubeTextureFromFileExW)
DEFINE_FUNC4(D3DXCreateCubeTextureFromFileInMemory)
DEFINE_FUNC14(D3DXCreateCubeTextureFromFileInMemoryEx)
DEFINE_FUNC3(D3DXCreateCubeTextureFromFileW)
DEFINE_FUNC4(D3DXCreateCubeTextureFromResourceA)
DEFINE_FUNC14(D3DXCreateCubeTextureFromResourceExA)
DEFINE_FUNC14(D3DXCreateCubeTextureFromResourceExW)
DEFINE_FUNC4(D3DXCreateCubeTextureFromResourceW)
DEFINE_FUNC8(D3DXCreateCylinder)
bool params4effectalloced = false;
DW params4effect[] = {
3,
1,
1,
2,
3,
3,
3,
3,
3,
3,
3,
3,
2,
2,
3,
3,
2,
2,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
4,
4,
3,
3,
4,
4,
4,
4,
3,
3,
3,
3,
3,
3,
4,
2,
2,
1,
2,
3,
2,
3,
3,
2,
1,
1,
1,
2,
2,
1,
1,
2,
2,
1,
1,
2,
2,
3,
5
};
//DEFINE_FUNC9(D3DXCreateEffect)
EXTERN_C DW STUB_IMPORT D3DXCreateEffect(DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffect(DW* R)
{
DW r = D3DXCreateEffect(p1, p2, p3, p4, p5, p6, p7, p8, p9);
if (p8 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			params4effect[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p8) = (DW)&params4effect;
}
LEAVE(9);
return r;
}
bool params4effectcompileralloced = false;
DW params4effectcompiler[] = {
3,
1,
1,
2,
3,
3,
3,
3,
3,
3,
3,
3,
2,
2,
3,
3,
2,
2,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
3,
3,
4,
4,
4,
4,
3,
3,
4,
4,
4,
4,
3,
3,
3,
3,
3,
3,
4,
3,
3,
4,
7
};
//DEFINE_FUNC7(D3DXCreateEffectCompiler)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectCompiler(DW,DW,DW,DW,DW,DW,DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectCompiler(DW *R)
{
  DW r= D3DXCreateEffectCompiler(p1,p2,p3,p4,p5,p6,p7);
  if (p6 != 0) {
	  if (params4effectcompileralloced == false) {
		  for (int cnt = 0; cnt < (sizeof(params4effectcompiler) / 4); cnt++) {
			  params4effectcompiler[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p6)) + (cnt * 4))), params4effectcompiler[cnt]);
		  }
		  params4effectcompileralloced = true;
	  }
	  *(DW*)(p6) = (DW)&params4effectcompiler;
  }
  LEAVE(7);
  return r;
}
//DEFINE_FUNC6(D3DXCreateEffectCompilerFromFileA)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectCompilerFromFileA(DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectCompilerFromFileA(DW* R)
{
DW r = D3DXCreateEffectCompilerFromFileA(p1, p2, p3, p4, p5, p6);
if (p5 != 0) {
	if (params4effectcompileralloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effectcompiler) / 4); cnt++) {
			params4effectcompiler[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p5)) + (cnt * 4))), params4effectcompiler[cnt]);
		}
		params4effectcompileralloced = true;
	}
	*(DW*)(p5) = (DW)&params4effectcompiler;
}
LEAVE(6);
return r;
}
//DEFINE_FUNC6(D3DXCreateEffectCompilerFromFileW)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectCompilerFromFileW(DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectCompilerFromFileW(DW* R)
{
	DW r = D3DXCreateEffectCompilerFromFileW(p1, p2, p3, p4, p5, p6);
	if (p5 != 0) {
		if (params4effectcompileralloced == false) {
			for (int cnt = 0; cnt < (sizeof(params4effectcompiler) / 4); cnt++) {
				params4effectcompiler[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p5)) + (cnt * 4))), params4effectcompiler[cnt]);
			}
			params4effectcompileralloced = true;
		}
		*(DW*)(p5) = (DW)&params4effectcompiler;
	}
	LEAVE(6);
	return r;
}
//DEFINE_FUNC7(D3DXCreateEffectCompilerFromResourceA)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectCompilerFromResourceA(DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectCompilerFromResourceA(DW* R)
{
	DW r = D3DXCreateEffectCompilerFromResourceA(p1, p2, p3, p4, p5, p6, p7);
	if (p6 != 0) {
		if (params4effectcompileralloced == false) {
			for (int cnt = 0; cnt < (sizeof(params4effectcompiler) / 4); cnt++) {
				params4effectcompiler[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p6)) + (cnt * 4))), params4effectcompiler[cnt]);
			}
			params4effectcompileralloced = true;
		}
		*(DW*)(p6) = (DW)&params4effectcompiler;
	}
	LEAVE(7);
	return r;
}
//DEFINE_FUNC7(D3DXCreateEffectCompilerFromResourceW)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectCompilerFromResourceW(DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectCompilerFromResourceW(DW* R)
{
	DW r = D3DXCreateEffectCompilerFromResourceW(p1, p2, p3, p4, p5, p6, p7);
	if (p6 != 0) {
		if (params4effectcompileralloced == false) {
			for (int cnt = 0; cnt < (sizeof(params4effectcompiler) / 4); cnt++) {
				params4effectcompiler[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p6)) + (cnt * 4))), params4effectcompiler[cnt]);
			}
			params4effectcompileralloced = true;
		}
		*(DW*)(p6) = (DW)&params4effectcompiler;
	}
	LEAVE(7);
	return r;
}
//DEFINE_FUNC10(D3DXCreateEffectEx)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectEx(DW, DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectEx(DW* R)
{
DW r = D3DXCreateEffectEx(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
if (p9 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			params4effect[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p9)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p9) = (DW)&params4effect;
}
LEAVE(10);
return r;
}
//DEFINE_FUNC8(D3DXCreateEffectFromFileA)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromFileA(DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromFileA(DW* R)
{
DW r = D3DXCreateEffectFromFileA(p1, p2, p3, p4, p5, p6, p7, p8);
if (p7 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p7)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p7) = (DW)&params4effect;
}
LEAVE(8);
return r;
}
//DEFINE_FUNC9(D3DXCreateEffectFromFileExA)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromFileExA(DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromFileExA(DW* R)
{
DW r = D3DXCreateEffectFromFileExA(p1, p2, p3, p4, p5, p6, p7, p8, p9);
if (p8 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p8) = (DW)&params4effect;
}
LEAVE(9);
return r;
}
//DEFINE_FUNC9(D3DXCreateEffectFromFileExW)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromFileExW(DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromFileExW(DW* R)
{
DW r = D3DXCreateEffectFromFileExW(p1, p2, p3, p4, p5, p6, p7, p8, p9);
if (p8 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p8) = (DW)&params4effect;
}
LEAVE(9);
return r;
}
//DEFINE_FUNC8(D3DXCreateEffectFromFileW)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromFileW(DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromFileW(DW* R)
{
DW r = D3DXCreateEffectFromFileW(p1, p2, p3, p4, p5, p6, p7, p8);
if (p7 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p7)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p7) = (DW)&params4effect;
}
LEAVE(8);
return r;
}
//DEFINE_FUNC9(D3DXCreateEffectFromResourceA)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromResourceA(DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromResourceA(DW* R)
{
DW r = D3DXCreateEffectFromResourceA(p1, p2, p3, p4, p5, p6, p7, p8, p9);
if (p8 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			params4effect[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p8) = (DW)&params4effect;
}
LEAVE(9);
return r;
}
//DEFINE_FUNC10(D3DXCreateEffectFromResourceExA)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromResourceExA(DW, DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromResourceExA(DW* R)
{
DW r = D3DXCreateEffectFromResourceExA(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
if (p9 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p9)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p9) = (DW)&params4effect;
}
LEAVE(10);
return r;
}
//DEFINE_FUNC10(D3DXCreateEffectFromResourceExW)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromResourceExW(DW, DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromResourceExW(DW* R)
{
DW r = D3DXCreateEffectFromResourceExW(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10);
if (p9 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p9)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p9) = (DW)&params4effect;
}
LEAVE(10);
return r;
}
//DEFINE_FUNC9(D3DXCreateEffectFromResourceW)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectFromResourceW(DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectFromResourceW(DW* R)
{
DW r = D3DXCreateEffectFromResourceW(p1, p2, p3, p4, p5, p6, p7, p8, p9);
if (p8 != 0) {
	if (params4effectalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect) / 4); cnt++) {
			params4effect[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4effect[cnt]);
		}
		params4effectalloced = true;
	}
	*(DW*)(p8) = (DW)&params4effect;
}
LEAVE(9);
return r;
}
bool params4effect_poolalloced = false;
DW params4effect_pool[] = {
3,
1,
1
};
//DEFINE_FUNC1(D3DXCreateEffectPool)
EXTERN_C DW STUB_IMPORT D3DXCreateEffectPool(DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateEffectPool(DW* R)
{
DW r = D3DXCreateEffectPool(p1);
if (p1 != 0) {
	if (params4effect_poolalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4effect_pool) / 4); cnt++) {
			params4effect_pool[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p1)) + (cnt * 4))), params4effect_pool[cnt]);
		}
		params4effect_poolalloced = true;
	}
	*(DW*)(p1) = (DW)&params4effect_pool;
}
LEAVE(1);
return r;
}
bool params4fontalloced = false;
DW params4font[] = {
3,
1,
1,
2,
2,
2,
2,
2,
1,
5,
3,
3,
3,
3,
7,
7,
1,
1
};
//DEFINE_FUNC12(D3DXCreateFontA)
EXTERN_C DW STUB_IMPORT D3DXCreateFontA(DW, DW, DW, DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateFontA(DW* R)
{
DW r = D3DXCreateFontA(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
if (p12 != 0) {
	if (params4fontalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4font) / 4); cnt++) {
			params4font[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p12)) + (cnt * 4))), params4font[cnt]);
		}
		params4fontalloced = true;
	}
	*(DW*)(p12) = (DW)&params4font;
}
LEAVE(12);
return r;
}
//DEFINE_FUNC3(D3DXCreateFontIndirectA)
EXTERN_C DW STUB_IMPORT D3DXCreateFontIndirectA(DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateFontIndirectA(DW* R)
{
DW r = D3DXCreateFontIndirectA(p1, p2, p3);
if (p3 != 0) {
	if (params4fontalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4font) / 4); cnt++) {
			params4font[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p3)) + (cnt * 4))), params4font[cnt]);
		}
		params4fontalloced = true;
	}
	*(DW*)(p3) = (DW)&params4font;
}
LEAVE(3);
return r;
}
//DEFINE_FUNC3(D3DXCreateFontIndirectW)
EXTERN_C DW STUB_IMPORT D3DXCreateFontIndirectW(DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateFontIndirectW(DW* R)
{
DW r = D3DXCreateFontIndirectW(p1, p2, p3);
if (p3 != 0) {
	if (params4fontalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4font) / 4); cnt++) {
			params4font[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p3)) + (cnt * 4))), params4font[cnt]);
		}
		params4fontalloced = true;
	}
	*(DW*)(p3) = (DW)&params4font;
}
LEAVE(3);
return r;
}
//DEFINE_FUNC12(D3DXCreateFontW)
EXTERN_C DW STUB_IMPORT D3DXCreateFontW(DW, DW, DW, DW, DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateFontW(DW* R)
{
DW r = D3DXCreateFontW(p1, p2, p3, p4, p5, p6, p7, p8, p9, p10, p11, p12);
if (p12 != 0) {
	if (params4fontalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4font) / 4); cnt++) {
			params4font[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p12)) + (cnt * 4))), params4font[cnt]);
		}
		params4fontalloced = true;
	}
	*(DW*)(p12) = (DW)&params4font;
}
LEAVE(12);
return r;
}
bool params4keyframedanimalloced = false;
DW params4keyframedanim[] = {
3,
1,
1,
1,
1,
3,
1,
3,
3,
7,
6,
1,
1,
2,
3,
4,
4,
2,
3,
4,
4,
2,
3,
4,
4,
1,
2,
3,
3,
3,
3,
3,
9,
5,
2
};
//DEFINE_FUNC8(D3DXCreateKeyframedAnimationSet)
EXTERN_C DW STUB_IMPORT D3DXCreateKeyframedAnimationSet(DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateKeyframedAnimationSet(DW* R)
{
DW r = D3DXCreateKeyframedAnimationSet(p1, p2, p3, p4, p5, p6, p7, p8);
if (p2 != 0) {
	if (params4keyframedanimalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4keyframedanim) / 4); cnt++) {
			params4keyframedanim[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4keyframedanim[cnt]);
		}
		params4keyframedanimalloced = true;
	}
	*(DW*)(p2) = (DW)&params4keyframedanim;
}
LEAVE(8);
return r;
}
bool params4linealloced = false;
DW params4line[] = {
3,
1,
1,
2,
1,
4,
5,
2,
1,
2,
1,
2,
1,
2,
1,
2,
1,
1,
1,
1
};
//DEFINE_FUNC2(D3DXCreateLine)
EXTERN_C DW STUB_IMPORT D3DXCreateLine(DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateLine(DW* R)
{
DW r = D3DXCreateLine(p1, p2);
if (p2 != 0) {
	if (params4linealloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4line) / 4); cnt++) {
			params4line[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p2)) + (cnt * 4))), params4line[cnt]);
		}
		params4linealloced = true;
	}
	*(DW*)(p2) = (DW)&params4line;
}
LEAVE(2);
return r;
}
bool params4matrixalloced = false;
DW params4matrix[] = {
3,
1,
1,
1,
2,
2,
2,
1,
1,
3,
3,
4,
4,
4,
4,
4,
4,
1
};
//DEFINE_FUNC2(D3DXCreateMatrixStack)
EXTERN_C DW STUB_IMPORT D3DXCreateMatrixStack(DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateMatrixStack(DW* R)
{
DW r = D3DXCreateMatrixStack(p1, p2);
if (p2 != 0) {
	if (params4matrixalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4matrix) / 4); cnt++) {
			params4matrix[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p2)) + (cnt * 4))), params4matrix[cnt]);
		}
		params4matrixalloced = true;
	}
	*(DW*)(p2) = (DW)&params4matrix;
}
LEAVE(2);
return r;
}
bool params4meshalloced = false;
DW params4mesh[] = {
3,
1,
1,

2,
1,
1,
1,

2,
1,
1,
2,

5,
5,
2,
2,

3,
1,
3,
1,

3,
3,
3,
3,

2,
3,
1,
7,

6,
3

};
//DEFINE_FUNC6(D3DXCreateMesh)
EXTERN_C DW STUB_IMPORT D3DXCreateMesh(DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateMesh(DW* R)
{
DW r = D3DXCreateMesh(p1, p2, p3, p4, p5, p6);
if (p6 != 0) {
	if (params4meshalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4mesh) / 4); cnt++) {
			params4mesh[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p6)) + (cnt * 4))), params4mesh[cnt]);
		}
		params4meshalloced = true;
	}
	*(DW*)(p6) = (DW)&params4mesh;
}
LEAVE(6);
return r;
}
//DEFINE_FUNC6(D3DXCreateMeshFVF)
EXTERN_C DW STUB_IMPORT D3DXCreateMeshFVF(DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXCreateMeshFVF(DW* R)
{
DW r = D3DXCreateMeshFVF(p1, p2, p3, p4, p5, p6);
if (p6 != 0) {
	if (params4meshalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4mesh) / 4); cnt++) {
			params4mesh[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p6)) + (cnt * 4))), params4mesh[cnt]);
		}
		params4meshalloced = true;
	}
	*(DW*)(p6) = (DW)&params4mesh;
}
LEAVE(6);
return r;
}
DEFINE_FUNC2(D3DXCreateNPatchMesh)
DEFINE_FUNC7(D3DXCreatePMeshFromStream)
DEFINE_FUNC4(D3DXCreatePRTBuffer)
DEFINE_FUNC5(D3DXCreatePRTBufferTex)
DEFINE_FUNC_CB7(D3DXCreatePRTCompBuffer,4,2)
DEFINE_FUNC5(D3DXCreatePRTEngine)
DEFINE_FUNC7(D3DXCreatePatchMesh)
DEFINE_FUNC5(D3DXCreatePolygon)
DEFINE_FUNC7(D3DXCreateRenderToEnvMap)
DEFINE_FUNC7(D3DXCreateRenderToSurface)
DEFINE_FUNC5(D3DXCreateSPMesh)
DEFINE_FUNC4(D3DXCreateSkinInfo)
DEFINE_FUNC4(D3DXCreateSkinInfoFVF)
DEFINE_FUNC4(D3DXCreateSkinInfoFromBlendedMesh)
DEFINE_FUNC6(D3DXCreateSphere)
DEFINE_FUNC2(D3DXCreateSprite)
DEFINE_FUNC3(D3DXCreateTeapot)
DEFINE_FUNC8(D3DXCreateTextA)
DEFINE_FUNC8(D3DXCreateTextW)
DEFINE_FUNC8(D3DXCreateTexture)
DEFINE_FUNC3(D3DXCreateTextureFromFileA)
DEFINE_FUNC14(D3DXCreateTextureFromFileExA)
DEFINE_FUNC14(D3DXCreateTextureFromFileExW)
DEFINE_FUNC4(D3DXCreateTextureFromFileInMemory)
DEFINE_FUNC15(D3DXCreateTextureFromFileInMemoryEx)
DEFINE_FUNC3(D3DXCreateTextureFromFileW)
DEFINE_FUNC4(D3DXCreateTextureFromResourceA)
DEFINE_FUNC15(D3DXCreateTextureFromResourceExA)
DEFINE_FUNC15(D3DXCreateTextureFromResourceExW)
DEFINE_FUNC4(D3DXCreateTextureFromResourceW)
DEFINE_FUNC5(D3DXCreateTextureGutterHelper)
DEFINE_FUNC2(D3DXCreateTextureShader)
DEFINE_FUNC7(D3DXCreateTorus)
DEFINE_FUNC9(D3DXCreateVolumeTexture)
DEFINE_FUNC3(D3DXCreateVolumeTextureFromFileA)
DEFINE_FUNC15(D3DXCreateVolumeTextureFromFileExA)
DEFINE_FUNC15(D3DXCreateVolumeTextureFromFileExW)
DEFINE_FUNC4(D3DXCreateVolumeTextureFromFileInMemory)
DEFINE_FUNC16(D3DXCreateVolumeTextureFromFileInMemoryEx)
DEFINE_FUNC3(D3DXCreateVolumeTextureFromFileW)
DEFINE_FUNC4(D3DXCreateVolumeTextureFromResourceA)
DEFINE_FUNC16(D3DXCreateVolumeTextureFromResourceExA)
DEFINE_FUNC16(D3DXCreateVolumeTextureFromResourceExW)
DEFINE_FUNC4(D3DXCreateVolumeTextureFromResourceW)
DEFINE_FUNC1(D3DXDebugMute)
DEFINE_FUNC2(D3DXDeclaratorFromFVF)
DEFINE_FUNC3(D3DXDisassembleEffect)
DEFINE_FUNC4(D3DXDisassembleShader)
DEFINE_FUNC2(D3DXFVFFromDeclarator)
DEFINE_FUNC1(D3DXFileCreate)
DEFINE_FUNC_CB3(D3DXFillCubeTexture,2,4)
DEFINE_FUNC2(D3DXFillCubeTextureTX)
DEFINE_FUNC_CB3(D3DXFillTexture,2,4)
DEFINE_FUNC2(D3DXFillTextureTX)
DEFINE_FUNC_CB3(D3DXFillVolumeTexture,2,4)
DEFINE_FUNC2(D3DXFillVolumeTextureTX)
DEFINE_FUNC4(D3DXFilterTexture)
DEFINE_FUNC4(D3DXFindShaderComment)
DEFINE_FUNC3(D3DXFloat16To32Array)
DEFINE_FUNC3(D3DXFloat32To16Array)
DEFINE_FUNC2(D3DXFrameAppendChild)
DEFINE_FUNC3(D3DXFrameCalculateBoundingSphere)
DEFINE_FUNC2(D3DXFrameDestroy)
DEFINE_FUNC2(D3DXFrameFind)
DEFINE_FUNC1(D3DXFrameNumNamedMatrices)
DEFINE_FUNC2(D3DXFrameRegisterNamedMatrices)
DEFINE_FUNC2(D3DXFresnelTerm)
DEFINE_FUNC2(D3DXGenerateOutputDecl)
DEFINE_FUNC7(D3DXGeneratePMesh)
DEFINE_FUNC1(D3DXGetDeclLength)
DEFINE_FUNC2(D3DXGetDeclVertexSize)
DEFINE_FUNC1(D3DXGetDriverLevel)
DEFINE_FUNC1(D3DXGetFVFVertexSize)
DEFINE_FUNC2(D3DXGetImageInfoFromFileA)
DEFINE_FUNC3(D3DXGetImageInfoFromFileInMemory)
DEFINE_FUNC2(D3DXGetImageInfoFromFileW)
DEFINE_FUNC3(D3DXGetImageInfoFromResourceA)
DEFINE_FUNC3(D3DXGetImageInfoFromResourceW)
DEFINE_FUNC1(D3DXGetPixelShaderProfile)
DEFINE_FUNC2(D3DXGetShaderConstantTable)
DEFINE_FUNC3(D3DXGetShaderConstantTableEx)
DEFINE_FUNC3(D3DXGetShaderInputSemantics)
DEFINE_FUNC3(D3DXGetShaderOutputSemantics)
DEFINE_FUNC3(D3DXGetShaderSamplers)
DEFINE_FUNC1(D3DXGetShaderSize)
DEFINE_FUNC1(D3DXGetShaderVersion)
DEFINE_FUNC1(D3DXGetVertexShaderProfile)
DEFINE_FUNC10(D3DXIntersect)
DEFINE_FUNC11(D3DXIntersectSubset)
DEFINE_FUNC8(D3DXIntersectTri)
DEFINE_FUNC8(D3DXLoadMeshFromXA)
DEFINE_FUNC9(D3DXLoadMeshFromXInMemory)
DEFINE_FUNC10(D3DXLoadMeshFromXResource)
DEFINE_FUNC8(D3DXLoadMeshFromXW)
//DEFINE_FUNC8(D3DXLoadMeshFromXof)
EXTERN_C DW STUB_IMPORT D3DXLoadMeshFromXof(DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXLoadMeshFromXof(DW* R)
{
DW r = D3DXLoadMeshFromXof(p1, p2, p3, p4, p5, p6, p7, p8);
if (p8 != 0) {
	if (params4meshalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4mesh) / 4); cnt++) {
			params4mesh[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4mesh[cnt]);
		}
		params4meshalloced = true;
	}
	*(DW*)(p8) = (DW)&params4mesh;
}
LEAVE(8);
return r;
}
DEFINE_FUNC7(D3DXLoadMeshHierarchyFromXA)
//DEFINE_FUNC8(D3DXLoadMeshHierarchyFromXInMemory)
EXTERN_C DW STUB_IMPORT D3DXLoadMeshHierarchyFromXInMemory(DW, DW, DW, DW, DW, DW, DW, DW);
EXTERN_C DW STUB_EXPORT yact_D3DXLoadMeshHierarchyFromXInMemory(DW* R)
{
DW r = D3DXLoadMeshHierarchyFromXInMemory(p1, p2, p3, p4, p5, p6, p7, p8);
if (p8 != 0) {
	if (params4meshalloced == false) {
		for (int cnt = 0; cnt < (sizeof(params4mesh) / 4); cnt++) {
			params4mesh[cnt] = CbCreateNativeStdcallCallback((*(DW*)((*(DW*)(p8)) + (cnt * 4))), params4mesh[cnt]);
		}
		params4meshalloced = true;
	}
	*(DW*)(p8) = (DW)&params4mesh;
}
LEAVE(8);
return r;
}
DEFINE_FUNC7(D3DXLoadMeshHierarchyFromXW)
DEFINE_FUNC2(D3DXLoadPRTBufferFromFileA)
DEFINE_FUNC2(D3DXLoadPRTBufferFromFileW)
DEFINE_FUNC2(D3DXLoadPRTCompBufferFromFileA)
DEFINE_FUNC2(D3DXLoadPRTCompBufferFromFileW)
DEFINE_FUNC7(D3DXLoadPatchMeshFromXof)
DEFINE_FUNC9(D3DXLoadSkinMeshFromXof)
DEFINE_FUNC8(D3DXLoadSurfaceFromFileA)
DEFINE_FUNC9(D3DXLoadSurfaceFromFileInMemory)
DEFINE_FUNC8(D3DXLoadSurfaceFromFileW)
DEFINE_FUNC10(D3DXLoadSurfaceFromMemory)
DEFINE_FUNC9(D3DXLoadSurfaceFromResourceA)
DEFINE_FUNC9(D3DXLoadSurfaceFromResourceW)
DEFINE_FUNC8(D3DXLoadSurfaceFromSurface)
DEFINE_FUNC8(D3DXLoadVolumeFromFileA)
DEFINE_FUNC9(D3DXLoadVolumeFromFileInMemory)
DEFINE_FUNC8(D3DXLoadVolumeFromFileW)
DEFINE_FUNC11(D3DXLoadVolumeFromMemory)
DEFINE_FUNC9(D3DXLoadVolumeFromResourceA)
DEFINE_FUNC9(D3DXLoadVolumeFromResourceW)
DEFINE_FUNC8(D3DXLoadVolumeFromVolume)
DEFINE_FUNC5(D3DXMatrixAffineTransformation)
DEFINE_FUNC5(D3DXMatrixAffineTransformation2D)
DEFINE_FUNC4(D3DXMatrixDecompose)
DEFINE_FUNC1(D3DXMatrixDeterminant)
DEFINE_FUNC3(D3DXMatrixInverse)
DEFINE_FUNC4(D3DXMatrixLookAtLH)
DEFINE_FUNC4(D3DXMatrixLookAtRH)
DEFINE_FUNC3(D3DXMatrixMultiply)
DEFINE_FUNC3(D3DXMatrixMultiplyTranspose)
DEFINE_FUNC5(D3DXMatrixOrthoLH)
DEFINE_FUNC7(D3DXMatrixOrthoOffCenterLH)
DEFINE_FUNC7(D3DXMatrixOrthoOffCenterRH)
DEFINE_FUNC5(D3DXMatrixOrthoRH)
DEFINE_FUNC5(D3DXMatrixPerspectiveFovLH)
DEFINE_FUNC5(D3DXMatrixPerspectiveFovRH)
DEFINE_FUNC5(D3DXMatrixPerspectiveLH)
DEFINE_FUNC7(D3DXMatrixPerspectiveOffCenterLH)
DEFINE_FUNC7(D3DXMatrixPerspectiveOffCenterRH)
DEFINE_FUNC5(D3DXMatrixPerspectiveRH)
DEFINE_FUNC2(D3DXMatrixReflect)
DEFINE_FUNC3(D3DXMatrixRotationAxis)
DEFINE_FUNC2(D3DXMatrixRotationQuaternion)
DEFINE_FUNC2(D3DXMatrixRotationX)
DEFINE_FUNC2(D3DXMatrixRotationY)
DEFINE_FUNC4(D3DXMatrixRotationYawPitchRoll)
DEFINE_FUNC2(D3DXMatrixRotationZ)
DEFINE_FUNC4(D3DXMatrixScaling)
DEFINE_FUNC3(D3DXMatrixShadow)
DEFINE_FUNC7(D3DXMatrixTransformation)
DEFINE_FUNC7(D3DXMatrixTransformation2D)
DEFINE_FUNC4(D3DXMatrixTranslation)
DEFINE_FUNC2(D3DXMatrixTranspose)
DEFINE_FUNC5(D3DXOptimizeFaces)
DEFINE_FUNC5(D3DXOptimizeVertices)
DEFINE_FUNC3(D3DXPlaneFromPointNormal)
DEFINE_FUNC4(D3DXPlaneFromPoints)
DEFINE_FUNC4(D3DXPlaneIntersectLine)
DEFINE_FUNC2(D3DXPlaneNormalize)
DEFINE_FUNC3(D3DXPlaneTransform)
DEFINE_FUNC6(D3DXPlaneTransformArray)
DEFINE_FUNC6(D3DXPreprocessShader)
DEFINE_FUNC5(D3DXPreprocessShaderFromFileA)
DEFINE_FUNC5(D3DXPreprocessShaderFromFileW)
DEFINE_FUNC6(D3DXPreprocessShaderFromResourceA)
DEFINE_FUNC6(D3DXPreprocessShaderFromResourceW)
DEFINE_FUNC6(D3DXQuaternionBaryCentric)
DEFINE_FUNC2(D3DXQuaternionExp)
DEFINE_FUNC2(D3DXQuaternionInverse)
DEFINE_FUNC2(D3DXQuaternionLn)
DEFINE_FUNC3(D3DXQuaternionMultiply)
DEFINE_FUNC2(D3DXQuaternionNormalize)
DEFINE_FUNC3(D3DXQuaternionRotationAxis)
DEFINE_FUNC2(D3DXQuaternionRotationMatrix)
DEFINE_FUNC4(D3DXQuaternionRotationYawPitchRoll)
DEFINE_FUNC4(D3DXQuaternionSlerp)
DEFINE_FUNC6(D3DXQuaternionSquad)
DEFINE_FUNC7(D3DXQuaternionSquadSetup)
DEFINE_FUNC3(D3DXQuaternionToAxisAngle)
DEFINE_FUNC3(D3DXRectPatchSize)
DEFINE_FUNC4(D3DXSHAdd)
DEFINE_FUNC3(D3DXSHDot)
DEFINE_FUNC9(D3DXSHEvalConeLight)
DEFINE_FUNC3(D3DXSHEvalDirection)
DEFINE_FUNC8(D3DXSHEvalDirectionalLight)
DEFINE_FUNC13(D3DXSHEvalHemisphereLight)
DEFINE_FUNC9(D3DXSHEvalSphericalLight)
DEFINE_FUNC3(D3DXSHMultiply2)
DEFINE_FUNC3(D3DXSHMultiply3)
DEFINE_FUNC3(D3DXSHMultiply4)
DEFINE_FUNC3(D3DXSHMultiply5)
DEFINE_FUNC3(D3DXSHMultiply6)
DEFINE_FUNC16(D3DXSHPRTCompSplitMeshSC)
DEFINE_FUNC6(D3DXSHPRTCompSuperCluster)
DEFINE_FUNC5(D3DXSHProjectCubeMap)
DEFINE_FUNC4(D3DXSHRotate)
DEFINE_FUNC4(D3DXSHRotateZ)
DEFINE_FUNC4(D3DXSHScale)
DEFINE_FUNC5(D3DXSaveMeshHierarchyToFileA)
DEFINE_FUNC5(D3DXSaveMeshHierarchyToFileW)
DEFINE_FUNC7(D3DXSaveMeshToXA)
DEFINE_FUNC7(D3DXSaveMeshToXW)
DEFINE_FUNC2(D3DXSavePRTBufferToFileA)
DEFINE_FUNC2(D3DXSavePRTBufferToFileW)
DEFINE_FUNC2(D3DXSavePRTCompBufferToFileA)
DEFINE_FUNC2(D3DXSavePRTCompBufferToFileW)
DEFINE_FUNC5(D3DXSaveSurfaceToFileA)
DEFINE_FUNC5(D3DXSaveSurfaceToFileInMemory)
DEFINE_FUNC5(D3DXSaveSurfaceToFileW)
DEFINE_FUNC4(D3DXSaveTextureToFileA)
DEFINE_FUNC4(D3DXSaveTextureToFileInMemory)
DEFINE_FUNC4(D3DXSaveTextureToFileW)
DEFINE_FUNC5(D3DXSaveVolumeToFileA)
DEFINE_FUNC5(D3DXSaveVolumeToFileInMemory)
DEFINE_FUNC5(D3DXSaveVolumeToFileW)
DEFINE_FUNC7(D3DXSimplifyMesh)
DEFINE_FUNC4(D3DXSphereBoundProbe)
DEFINE_FUNC9(D3DXSplitMesh)
DEFINE_FUNC6(D3DXTessellateNPatches)
DEFINE_FUNC5(D3DXTessellateRectPatch)
DEFINE_FUNC5(D3DXTessellateTriPatch)
DEFINE_FUNC3(D3DXTriPatchSize)
DEFINE_FUNC_CB19(D3DXUVAtlasCreate,11,2)
DEFINE_FUNC_CB11(D3DXUVAtlasPack,7,2)
DEFINE_FUNC_CB17(D3DXUVAtlasPartition,8,2)
DEFINE_FUNC3(D3DXValidMesh)
DEFINE_FUNC4(D3DXValidPatchMesh)
DEFINE_FUNC6(D3DXVec2BaryCentric)
DEFINE_FUNC6(D3DXVec2CatmullRom)
DEFINE_FUNC6(D3DXVec2Hermite)
DEFINE_FUNC2(D3DXVec2Normalize)
DEFINE_FUNC3(D3DXVec2Transform)
DEFINE_FUNC6(D3DXVec2TransformArray)
DEFINE_FUNC3(D3DXVec2TransformCoord)
DEFINE_FUNC6(D3DXVec2TransformCoordArray)
DEFINE_FUNC3(D3DXVec2TransformNormal)
DEFINE_FUNC6(D3DXVec2TransformNormalArray)
DEFINE_FUNC6(D3DXVec3BaryCentric)
DEFINE_FUNC6(D3DXVec3CatmullRom)
DEFINE_FUNC6(D3DXVec3Hermite)
DEFINE_FUNC2(D3DXVec3Normalize)
DEFINE_FUNC6(D3DXVec3Project)
DEFINE_FUNC9(D3DXVec3ProjectArray)
DEFINE_FUNC3(D3DXVec3Transform)
DEFINE_FUNC6(D3DXVec3TransformArray)
DEFINE_FUNC3(D3DXVec3TransformCoord)
DEFINE_FUNC6(D3DXVec3TransformCoordArray)
DEFINE_FUNC3(D3DXVec3TransformNormal)
DEFINE_FUNC6(D3DXVec3TransformNormalArray)
DEFINE_FUNC6(D3DXVec3Unproject)
DEFINE_FUNC9(D3DXVec3UnprojectArray)
DEFINE_FUNC6(D3DXVec4BaryCentric)
DEFINE_FUNC6(D3DXVec4CatmullRom)
DEFINE_FUNC4(D3DXVec4Cross)
DEFINE_FUNC6(D3DXVec4Hermite)
DEFINE_FUNC2(D3DXVec4Normalize)
DEFINE_FUNC3(D3DXVec4Transform)
DEFINE_FUNC6(D3DXVec4TransformArray)
DEFINE_FUNC7(D3DXWeldVertices)
