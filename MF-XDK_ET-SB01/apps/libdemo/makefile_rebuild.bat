@echo off
del /f/q ..\..\sdk\et389_lib\dev.map
rd /s/q ..\..\sdk\et389_lib\dep
rd /s/q ..\..\sdk\et389_lib\obj
echo del succ

call makefile.bat