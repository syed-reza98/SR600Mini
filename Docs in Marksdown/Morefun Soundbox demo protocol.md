**Morefun Soundbox Demo Protocol**

1. **Mqtt Protocol**

Mqtt ip & port:

# define MQTT\_HOST "sg-mqtt.funicom.com.cn"

# define MQTT\_PORT 32517

MQTT connection parameters, as follow:

data.keepAliveInterval = g\_keepAliveInterval; // Set the default heartbeat time to 300s

data.cleansession = 0; //Create a persistent session that persists even after the client disconnects, until the session times out and logs out

data.clientID.cstring = cid;//set clientID, use device sn

data.username.cstring = cid;//Set user name, use device sn

data.password.cstring = mqPassword;//Set Password

The subscribe topic: "/ota/<product key>/<device sn>/update"

For example: "/ota/pFppbioOCKlo5c8E/202302060000001/update"

1. The Mqtt Message for broadcasting (json format):

{"broadcast\_type":1,"money":"1.23","request\_id":"2022081951495648","datetime":"20220819144051","ctime":1660891251}

1. The Mqtt Message for displaying QRcode (json format):

{"money":"1.23","request\_id":"2022081910050555","order\_sn":"2022081910050102","datetime":"20220819143957","ctime":1660891197}

order\_sn: the content displayed the QR code

broadcast\_type: broadcast type,default set value 1

money: the amount string

request\_id: request id, must be unique, max lenth is 32

datetime: time stamp(date format)

ctime: Unix time stamp

1. **http Protocol**

Http ip & port:

# define HTTP\_HOST "sg-iot.morefun-et.com"

# define HTTP\_PORT 80

1. Request qrcode content

Send Message:

POST sg-iot.morefun-et.com/api/Iotmsgtest/createQrMf?device\_id=<device\_sn>&request\_data=<amoumt>

For example:

POST sg-iot.morefun-et.com/api/Iotmsgtest/createQrMf?device\_id=202302060000001&request\_data=1

The Response Message:

HTTP/1.1 200 OK

Server: nginx

Date: Wed, 29 May 2024 15:25:38 GMT

Content-Type: application/json; charset=utf-8

Transfer-Encoding: chunked

Connection: keep-alive

5a

{"code":"0000","msg":"Success","time":"1724809951","data":{"order\_sn":"2024082810257991"}}

0
