@echo off
del /f/q ..\..\sdk\yq06d_lib\dev.map
rd /s/q ..\..\sdk\yq06d_lib\dep
rd /s/q ..\..\sdk\yq06d_lib\obj
echo del succ

call makefile.bat