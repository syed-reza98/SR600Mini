@echo off
del /q *.mp4
"../../tools/wget.exe" http://www.morefun-et.com/Uploads/sdk/pro_guidance/MF-XDK_ET/SR600mini_Dip.mp4
"../../tools/wget.exe" http://www.morefun-et.com/Uploads/sdk/pro_guidance/MF-XDK_ET/SR600mini_DQR.mp4
"../../tools/wget.exe" http://www.morefun-et.com/Uploads/sdk/pro_guidance/MF-XDK_ET/SR600mini_Tap.mp4
"../../tools/wget.exe" http://www.morefun-et.com/Uploads/sdk/pro_guidance/MF-XDK_ET/ET389Pro_wifiList.mp4
"../../tools/wget.exe" http://www.morefun-et.com/Uploads/sdk/pro_guidance/MF-XDK_ET/ET_CatchLog.mp4
echo download success!

pause