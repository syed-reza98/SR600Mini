# AWS Configuration

1. **Create AWS account.**

   Create and log in to your account on the AWS platform: <https://aws.amazon.com/>.

2. **Create things and download certificates.**

   Select "IoT Core" service.

   ![Step 1 screenshot](AWS_configuration_guidance_images/image1.png)

   Click "create things".

   ![Step 10 screenshot](AWS_configuration_guidance_images/image10.png)

   Choose create single thing for example.

   ![Step 11 screenshot](AWS_configuration_guidance_images/image11.png)

Enter the thing name , click "Next".

![Step 12 screenshot](AWS_configuration_guidance_images/image12.png)

Auto-generate a new certficate, click "Next".

![Step 13 screenshot](AWS_configuration_guidance_images/image13.png)

Click "Create Policy".

![Step 14 screenshot](AWS_configuration_guidance_images/image14.emf)

Enter the policy name, select JSON format, enter policy as follow:

{

"Version": "2012-10-17",

"Statement": [

{

"Effect": "Allow",

"Action": "iot:\*",

"Resource": "\*"

}

]

}

![Step 15 screenshot](AWS_configuration_guidance_images/image15.png)

Click Create.

![Step 16 screenshot](AWS_configuration_guidance_images/image16.png)

Choose the Policy just we created. Create thing.

![Step 17 screenshot](AWS_configuration_guidance_images/image17.png)

Then download certification and key files.

![Step 18 screenshot](AWS_configuration_guidance_images/image18.png)

Download all these 4 files, as follow.

![Step 19 screenshot](AWS_configuration_guidance_images/image19.png)

3. **Set the URL of AWS MQTT server.**

   Click "Connect one device"

   ![1708589224757](AWS_configuration_guidance_images/image2.png)

   Record the URL of AWS MQTT server(a2d911mzqj2e50-ats.iot.us-east-1.amazonaws.com) in the box, as follows.

![Step 3 screenshot](AWS_configuration_guidance_images/image3.png)

Modify the setting.ini file, the value of "hostip" field set to "a2d911mzqj2e50-ats.iot.ap-south-1.amazonaws.com", refer to the following.

![Step 4 screenshot](AWS_configuration_guidance_images/image4.png)![Step 5 screenshot](AWS_configuration_guidance_images/image5.png)

Modify the AWS default URL, Modify the macro definition "AWSMQTT\_URL" in the "player\_proc.c" file of the demo project,rebuild the project.

# define AWSMQTT\_URL “a2d911mzqj2e50-ats.iot.ap-south-1.amazonaws.com”

![Step 6 screenshot](AWS_configuration_guidance_images/image6.png)

## Pack and download OTA package

1. Rename "AmazonRootCA1.pem" to "ca.pem"

2. Rename "xxx-certificate.pem.crt" to "cli.crt"

3. Rename "xxx-private.pem.key" to "pri.key"

   ![Step 7 screenshot](AWS_configuration_guidance_images/image7.png)

4. Package and download the setting.ini file and these three certificate files(ca.pem、cli.crt、pri.key) to the device.

   (How to pack and download data files? Please refer to the document "Developer Environment Manual(ENG Mode).docx", part 4.OTA package(data and bin))

## Broadcast test

1. Subscribe to a topic, set topic: "/ota/\<sn\>/update" (where \<sn\> is the device serial number)

![Step 8 screenshot](AWS_configuration_guidance_images/image8.png)

Publish to a topic, The test message as follow:

(Note: every time you send the message, please ensure that "request\_id" is unique)

{"broadcast\_type":1,"money":"1.23","request\_id":"2022081951495648","datetime":"20220819144051","ctime":1660891251}

![1708599036469](AWS_configuration_guidance_images/image9.png)
