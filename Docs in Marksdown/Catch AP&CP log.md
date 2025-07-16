**Catch AP&CP log**

1. Set command

Open tool sscom.exe,

select port “Quectel USB AT Port”, connect to the device and send the command “AT+QDBGCFG="tracecfg",0,2”. when the tool shows OK, it is success.

![Step 1 screenshot](Catch_AP&CP_log_images/image1.png)

1. Open the tool coolwatcher\_usb.exe,

Find the "Quectel USB Ap Log Port" and set the corresponding port for lastport.Click ok button.

![Step 10 screenshot](Catch_AP&CP_log_images/image10.png)

1. View Trace

As follow, Click <Plugins> —> <Activate Tracer> on menu bar, and activate Trace, shown as Figure

In the middle of the interface, Trace Index, Time that Trace Received by PC, Levels, and Descriptions can be obtained.

![Step 11 screenshot](Catch_AP&CP_log_images/image11.png)

1. Trace Levels Setting

Click the forth button , which located at the trace main interface, set Trace Levels. ![Step 12 screenshot](Catch_AP&CP_log_images/image12.png)

Click “save Pcap”

![Step 13 screenshot](Catch_AP&CP_log_images/image13.png)

Click start button to start log .

![Step 2 screenshot](Catch_AP&CP_log_images/image2.png)

**Keep** the tool coolwatcher\_usb.exe running and catch cp log.

**Catch CP log**

1. Set command

Open tool sscom.exe,select port “Quectel USB AT Port”, connect to the device and send the command “at+cfun=0”.

![Step 3 screenshot](Catch_AP&CP_log_images/image3.png)

2.open the tool V6.2.8\_User\ArmTracer.exe,device port select “Quectel USB CP Log port”，click “ok”.

![Step 4 screenshot](Catch_AP&CP_log_images/image4.png)

1. click “start trace function” button, set the log path and click “OK”。

![Step 5 screenshot](Catch_AP&CP_log_images/image5.png)

1. Keep tool ArmTracer running，Send “at+cfun=1” instruction through SSCOM tool，Log will output as following figure。

![Step 6 screenshot](Catch_AP&CP_log_images/image6.png)

1. Test the IP. Send the follow commands through SSCOM tool.
2. AT+QPING=1,"8.8.8.8"
3. AT+QPING=1,"sg-mqtt.funicom.com.cn"
4. Save the log

![Step 7 screenshot](Catch_AP&CP_log_images/image7.png)

Share the cap folder under this path, as follow.

![Step 8 screenshot](Catch_AP&CP_log_images/image8.png)

Stop ArmTracer log，share the .tra file under the set retention path。

![Step 9 screenshot](Catch_AP&CP_log_images/image9.png)
