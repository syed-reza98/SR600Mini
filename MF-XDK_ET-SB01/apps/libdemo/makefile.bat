@echo off
set "lj=%~p0"
set "lj=%lj:\= %"
for %%a in (%lj%) do set wjj=%%a
echo lib:%wjj%
cd ..\..\


SET TARGET_NAME=%wjj%

set filename=.

call %filename%\apps\build\SetPathEC100Y.bat %filename%

SET ENV_PATH=%filename%/apps/build
SET DRIVER_PATH=%filename%\\sdk\\yq06d_lib

make -f %filename%\apps\build\makefile_lib

if %ERRORLEVEL% equ 0 (
	copy %DRIVER_PATH%\%TARGET_NAME%.a %filename%\apps\%TARGET_NAME%\ /y
)
pause


