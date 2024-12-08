#include "dllyact_def.h"

DEFINE_FUNC1(AllowPermLayer)
DEFINE_FUNC4(ApphelpCheckExe)
DEFINE_FUNC1(ApphelpCheckIME)
DEFINE_FUNC2(ApphelpCheckInstallShieldPackage)
DEFINE_FUNC4(ApphelpCheckMsiPackage)
DEFINE_FUNC8(ApphelpCheckRunApp)
DEFINE_FUNC3(ApphelpCheckShellObject)
DEFINE_FUNC5(ApphelpFixMsiPackage)
DEFINE_FUNC5(ApphelpFixMsiPackageExe)
DEFINE_FUNC1(ApphelpFreeFileAttributes)
DEFINE_FUNC3(ApphelpGetFileAttributes)
DEFINE_FUNC6(ApphelpGetNTVDMInfo)
DEFINE_FUNC2(ApphelpShowDialog)
#ifndef _ARM_
DEFINE_FUNC6(ApphelpShowUI)
#endif
DEFINE_FUNC4(ApphelpUpdateCacheEntry)
DEFINE_FUNC4(GetPermLayers)
DEFINE_FUNC1(SdbCloseApphelpInformation)
DEFINE_FUNC1(SdbCloseDatabase)
DEFINE_FUNC3(SdbCreateMsiTransformFile)
DEFINE_FUNC2(SdbDeletePermLayerKeys)
DEFINE_FUNC4(SdbEnumMsiTransforms)
DEFINE_FUNC4(SdbFindFirstMsiPackage)
DEFINE_FUNC4(SdbFindFirstMsiPackage_Str)
DEFINE_FUNC5(SdbFindFirstNamedTag)
DEFINE_FUNC3(SdbFindFirstTag)
DEFINE_FUNC3(SdbFindFirstTagRef)
DEFINE_FUNC2(SdbFindNextMsiPackage)
DEFINE_FUNC3(SdbFindNextTag)
DEFINE_FUNC3(SdbFindNextTagRef)
DEFINE_FUNC1(SdbFreeFlagInfo)
DEFINE_FUNC2(SdbGetBinaryTagData)
DEFINE_FUNC2(SdbGetDatabaseID)
DEFINE_FUNC5(SdbGetDatabaseMatch)
DEFINE_FUNC3(SdbGetDatabaseVersion)
DEFINE_FUNC2(SdbGetEntryFlags)
DEFINE_FUNC2(SdbGetFirstChild)
DEFINE_FUNC3(SdbGetMsiPackageInformation)
DEFINE_FUNC3(SdbGetNextChild)
DEFINE_FUNC4(SdbGetPermLayerKeys)
DEFINE_FUNC2(SdbGetStandardDatabaseGUID)
DEFINE_FUNC2(SdbGetStringTagPtr)
DEFINE_FUNC2(SdbGetTagDataSize)
DEFINE_FUNC2(SdbGetTagFromTagID)
DEFINE_FUNC3(SdbGrabMatchingInfo)
DEFINE_FUNC5(SdbGrabMatchingInfoEx)
DEFINE_FUNC2(SdbInitDatabase)
DEFINE_FUNC1(SdbOpenApphelpDetailsDatabase)
DEFINE_FUNC0(SdbOpenApphelpDetailsDatabaseSP)
DEFINE_FUNC2(SdbOpenApphelpInformation)
DEFINE_FUNC2(SdbOpenDatabase)
DEFINE_FUNC4(SdbQueryApphelpInformation)
DEFINE_FUNC6(SdbQueryData)
DEFINE_FUNC7(SdbQueryDataEx)
DEFINE_FUNC5(SdbQueryFlagInfo)
DEFINE_FUNC3(SdbReadBYTETag)
DEFINE_FUNC3(SdbReadBYTETagRef)
DEFINE_FUNC4(SdbReadBinaryTag)
DEFINE_FUNC3(SdbReadDWORDTag)
DEFINE_FUNC3(SdbReadDWORDTagRef)
DEFINE_FUNC3(SdbReadEntryInformation)
DEFINE_FUNC3(SdbReadMsiTransformInfo)
DEFINE_FUNC4(SdbReadQWORDTag)
DEFINE_FUNC4(SdbReadQWORDTagRef)
DEFINE_FUNC4(SdbReadStringTag)
DEFINE_FUNC4(SdbReadStringTagRef)
DEFINE_FUNC3(SdbReadWORDTag)
DEFINE_FUNC3(SdbReadWORDTagRef)
DEFINE_FUNC2(SdbRegisterDatabase)
DEFINE_FUNC3(SdbRegisterDatabaseEx)
DEFINE_FUNC1(SdbReleaseDatabase)
DEFINE_FUNC4(SdbResolveDatabase)
DEFINE_FUNC3(SdbSetPermLayerKeys)
DEFINE_FUNC4(SdbTagIDToTagRef)
DEFINE_FUNC4(SdbTagRefToTagID)
DEFINE_FUNC1(SdbTagToString)
DEFINE_FUNC1(SdbUnregisterDatabase)
DEFINE_FUNC3(SetPermLayers)
DEFINE_FUNC4(ShimDumpCache)
DEFINE_FUNC4(ShimFlushCache)
