#include "dllstub_def.h"


#define DEFINE_FUNC19(name) 	\
static const ModuleDef str_##name={DLL_NAME,#name};	\
EXTERN_C DW STUB_EXPORT stub_##name(DW p1,DW p2,DW p3,DW p4,DW p5,DW p6,DW p7,DW p8,DW p9,DW p10,DW p11,DW p12,DW p13,DW p14,DW p15,DW p16,DW p17,DW p18,DW p19)		\
{	\
	DW *p=&p1;	\
	__asm { mov eax,p }	\
	__asm { jmp f1 }	\
	__asm { mov eax,offset str_##name }	\
f1:	__asm { in eax,0xe5 }	\
	__asm { mov p,eax }	\
	return (DW)p;	\
}

#define DEFINE_FUNC_ORD19(name,ord) 	\
DEFINE_FUNC19(name)	\
EXTERN_C DW STUB_EXPORT stub_Ord_##ord(DW p1,DW p2,DW p3,DW p4,DW p5,DW p6,DW p7,DW p8,DW p9,DW p10,DW p11,DW p12,DW p13,DW p14,DW p15,DW p16,DW p17,DW p18,DW p19)		\
{	\
	return stub_##name(p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19);	\
}

static const char DLL_NAME[] = "d3dx9.nt.dll";

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
DEFINE_FUNC11(D3DXComputeIMTFromPerTexelSignal)
DEFINE_FUNC8(D3DXComputeIMTFromPerVertexSignal)
DEFINE_FUNC10(D3DXComputeIMTFromSignal)
DEFINE_FUNC7(D3DXComputeIMTFromTexture)
DEFINE_FUNC6(D3DXComputeNormalMap)
DEFINE_FUNC2(D3DXComputeNormals)
DEFINE_FUNC6(D3DXComputeTangent)
DEFINE_FUNC2(D3DXComputeTangentFrame)
DEFINE_FUNC16(D3DXComputeTangentFrameEx)
DEFINE_FUNC8(D3DXConcatenateMeshes)
DEFINE_FUNC5(D3DXConvertMeshSubsetToSingleStrip)
DEFINE_FUNC7(D3DXConvertMeshSubsetToStrips)
DEFINE_FUNC5(D3DXCreateAnimationController)
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
DEFINE_FUNC9(D3DXCreateEffect)
DEFINE_FUNC7(D3DXCreateEffectCompiler)
DEFINE_FUNC6(D3DXCreateEffectCompilerFromFileA)
DEFINE_FUNC6(D3DXCreateEffectCompilerFromFileW)
DEFINE_FUNC7(D3DXCreateEffectCompilerFromResourceA)
DEFINE_FUNC7(D3DXCreateEffectCompilerFromResourceW)
DEFINE_FUNC10(D3DXCreateEffectEx)
DEFINE_FUNC8(D3DXCreateEffectFromFileA)
DEFINE_FUNC9(D3DXCreateEffectFromFileExA)
DEFINE_FUNC9(D3DXCreateEffectFromFileExW)
DEFINE_FUNC8(D3DXCreateEffectFromFileW)
DEFINE_FUNC9(D3DXCreateEffectFromResourceA)
DEFINE_FUNC10(D3DXCreateEffectFromResourceExA)
DEFINE_FUNC10(D3DXCreateEffectFromResourceExW)
DEFINE_FUNC9(D3DXCreateEffectFromResourceW)
DEFINE_FUNC1(D3DXCreateEffectPool)
DEFINE_FUNC12(D3DXCreateFontA)
DEFINE_FUNC3(D3DXCreateFontIndirectA)
DEFINE_FUNC3(D3DXCreateFontIndirectW)
DEFINE_FUNC12(D3DXCreateFontW)
DEFINE_FUNC8(D3DXCreateKeyframedAnimationSet)
DEFINE_FUNC2(D3DXCreateLine)
DEFINE_FUNC2(D3DXCreateMatrixStack)
DEFINE_FUNC6(D3DXCreateMesh)
DEFINE_FUNC6(D3DXCreateMeshFVF)
DEFINE_FUNC2(D3DXCreateNPatchMesh)
DEFINE_FUNC7(D3DXCreatePMeshFromStream)
DEFINE_FUNC4(D3DXCreatePRTBuffer)
DEFINE_FUNC5(D3DXCreatePRTBufferTex)
DEFINE_FUNC7(D3DXCreatePRTCompBuffer)
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
DEFINE_FUNC3(D3DXFillCubeTexture)
DEFINE_FUNC2(D3DXFillCubeTextureTX)
DEFINE_FUNC3(D3DXFillTexture)
DEFINE_FUNC2(D3DXFillTextureTX)
DEFINE_FUNC3(D3DXFillVolumeTexture)
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
DEFINE_FUNC8(D3DXLoadMeshFromXof)
DEFINE_FUNC7(D3DXLoadMeshHierarchyFromXA)
DEFINE_FUNC8(D3DXLoadMeshHierarchyFromXInMemory)
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
DEFINE_FUNC19(D3DXUVAtlasCreate)
DEFINE_FUNC11(D3DXUVAtlasPack)
DEFINE_FUNC17(D3DXUVAtlasPartition)
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
