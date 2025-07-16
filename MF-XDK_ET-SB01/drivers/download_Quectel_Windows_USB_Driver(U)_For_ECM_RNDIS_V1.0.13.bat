@echo off
set filename=Quectel_Windows_USB_Driver(U)_For_ECM_RNDIS_V1.0.13.rar
del /q %filename%
rd /s/q Quectel_Windows_USB_Driver(U)_For_ECM_RNDIS_V1.0.13
"../tools/wget.exe" http://download.morefun-et.com/sdk/compiler/MF-XDK_ET/%filename%
echo download success!

echo decompression in progress, please wait...
"..\apps\build\Rar.exe" x -inul %filename%
echo unzip success!

echo begin install, please wait...
".\Quectel_Windows_USB_Driver(U)_For_ECM_RNDIS_V1.0.13\Quectel_Windows_USB_Driver(U)_For_ECM_RNDIS_V1.0.13_Beta0314\setup.exe"
echo installed successfully
pause