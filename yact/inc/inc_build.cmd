set BUILD=0
for /F "usebackq" %%a in (`type %~dp0buildno`) do set BUILD=%%a
set /a BUILD=%BUILD%+1
echo %BUILD% >%~dp0buildno 
copy %~dp0emversion-template.h  %~dp0emversion.h 
echo #define EM_BUILD %BUILD% >>%~dp0emversion.h 
