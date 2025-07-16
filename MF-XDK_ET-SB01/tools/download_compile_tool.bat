@echo off
set cygwin=cygwin.rar
set compile_tools=compile_tools_ec600u.rar

del /q %cygwin%
del /q %compile_tools%
wget http://download.morefun-et.com/sdk/compiler/%cygwin%
wget http://download.morefun-et.com/sdk/compiler/MF-XDK_ET/%compile_tools%
echo download success!
echo decompression in progress, please wait...

"..\apps\build\Rar.exe" x -inul %cygwin%
"..\apps\build\Rar.exe" x -inul %compile_tools%
echo unzip success!

pause