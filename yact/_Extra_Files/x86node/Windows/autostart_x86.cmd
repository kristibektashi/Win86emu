@echo off
cls
echo.
echo Restarting explorer...
c:
cd %windir%
taskkill /f /im explorer.exe >nul 2>&1
start explorer.exe
del C:\x86node\win86emu.log  >nul 2>&1
timeout /t 1 >nul 2>&1
echo.
echo Installing hook...
timeout /t 3 >nul 2>&1
cd c:\x86node\Windows\
start AutoHook.exe
