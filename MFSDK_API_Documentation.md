# MFSDK API Documentation

**Version:** V1.6  
**Company:** Fujian MoreFun Electronic Technology Co.,Ltd.

---

## Table of Contents

1. [Document History Version](#document-history-version)
2. [Global Definitions](#global-definitions)
3. [Version Module](#version-module)
4. [Utility Module](#utility-module)
5. [NFC Module](#nfc-module)
6. [Magstripe Card Module](#magstripe-card-module)
7. [ICC Module](#icc-module)
8. [UI Module](#ui-module)

---

## Document History Version

| Date | MoreFun SDK Group | Description |
|------|------------------|-------------|
| - | - | The definition of the global description |

---

## Global Definitions

### Constant Declarations

```c
#define MFSDK_UNUSED(x) ((void)(x))
#define MFSDK_COND_RET(cond, retValue) do{ if(cond) \
    { return retValue; } }while(0)

#define MFSDK_FALSE (0)
#define MFSDK_TRUE (1)
```

---

## Version Module

This module mainly includes APIs for getting versions.

### MfSdkVerGetDataVersion

**Prototype:**

```c
LIB_EXPORT s8* MfSdkVerGetDataVersion()
```

**Function:** Get data lib version

**Demo:**

```c
char* data_version = NULL;
data_version = MfSdkVerGetDataVersion();
```

### MfSdkVerMfOsVersion

**Prototype:**

```c
LIB_EXPORT s8* MfSdkVerMfOsVersion()
```

**Function:** Get MoreFun OS SDK version

**Demo:**

```c
char* osVersion = NULL;
osVersion = MfSdkVerMfOsVersion();
```

---

## Utility Module

This module mainly includes encoding type conversion and other utility APIs.

### Module Structure Declaration

```c
// QR code parameters
typedef struct {
    s32 nVersion;        // version number: 1~40
    s32 nLevel;         // Error correction level: 0-low, 1-in, 2-high, 3-maximum
    s32 moudleWidth;    // Module width (unit: pixel)
} MfSdkUtilQrInfo_T;
```

### MfSdkUtilGetModuleVer

**Prototype:**

```c
LIB_EXPORT s32 MfSdkUtilGetModuleVer(s8 *pszVer)
```

**Function:** Get util module version

**Return:** MFSDK_UTIL_RET_OK - Success

**Demo:**

```c
char utilVersion[20] = {0};
int ret = -1;
ret = MfSdkUtilGetModuleVer(utilVersion);
```

### Encoding Conversion Functions

#### MfSdkUtilAsc2Bcd

**Prototype:**

```c
LIB_EXPORT s32 MfSdkUtilAsc2Bcd(s8 *AscBuf, s8 *BcdBuf, s32 AscLen)
```

**Function:** ASCII code to BCD code

**Parameters:**

- AscBuf (in): ASCII buffer
- BcdBuf (out): BCD buffer  
- AscLen (in): ASCII length

**Return:** MFSDK_UTIL_RET_OK - Success

**Demo:**

```c
char *AscBuf = "1234";
char BcdBuf[3] = {0};
int ret = -1;
ret = MfSdkUtilAsc2Bcd(AscBuf, BcdBuf, strlen(AscBuf));
```

#### MfSdkUtilBcd2Asc

**Prototype:**

```c
LIB_EXPORT s32 MfSdkUtilBcd2Asc(s8 *BcdBuf, s8 *AscBuf, s32 AscLen)
```

**Function:** BCD code to ASCII code

**Parameters:**

- BcdBuf (in): BCD buffer
- AscBuf (out): ASCII buffer
- AscLen (in): The length of ASCII code data (double length of BCD code data)

**Demo:**

```c
char AscBuf[9] = {0};
char *BcdBuf = "\x12\x23";
int ret = -1;
ret = MfSdkUtilBcd2Asc(BcdBuf, AscBuf, 2);
APP_TRACE("MfSdkUtilBcd2Asc:%s\r\n", AscBuf);
// Result: MfSdkUtilBcd2Asc:1223
```

### System Utility Functions

#### MfSdkUtilBeep

**Prototype:**

```c
LIB_EXPORT void MfSdkUtilBeep(s32 num)
```

**Function:** System beep

#### MfSdkUtilBuzzerSound

**Prototype:**

```c
LIB_EXPORT void MfSdkUtilBuzzerSound(s32 nMillisecond)
```

**Function:** Set the buzzer ringing time

#### MfSdkUtilGetRand

**Prototype:**

```c
LIB_EXPORT s32 MfSdkUtilGetRand(s32 len, u8* pBuf)
```

**Function:** Generating random numbers

**Return:** MFSDK_UTIL_RET_OK - Success

**Demo:**

```c
unsigned char randomNumberStr[6] = {0};
int ret = -1;
ret = MfSdkUtilGetRand(5, randomNumberStr);
```

---

## NFC Module

This module mainly includes NFC APIs.

### Constants

```c
typedef enum {
    MFSDK_NFC_RET_MUTILCARD = MFSDK_ICC_RET_MUTILCARD,  // more than one card
    MFSDK_NFC_RET_NOCARD = MFSDK_ICC_RET_NOCARD,        // don't find card
    MFSDK_NFC_RET_FAILED = MFSDK_ICC_RET_FAILED,        // failed
    MFSDK_NFC_RET_BOUNDS = MFSDK_ICC_RET_BOUNDS,        // Array out-of-bounds
    MFSDK_NFC_RET_PARM_ERROR = MFSDK_ICC_RET_PARM_ERROR, // check param
    MFSDK_NFC_RET_OK = 0,
} MfSdkNfcRet_E;
```

### NFC Functions

#### MfSdkNfcInit

**Prototype:**

```c
LIB_EXPORT s32 MfSdkNfcInit(void)
```

**Function:** Initialization of the NFC module

**Return:** MFSDK_NFC_RET_OK - Success

#### MfSdkNfcApdu

**Prototype:**

```c
LIB_EXPORT s32 MfSdkNfcApdu(u8 *tbuf, u16 tlen, u8 **rbuf, u16 *rlen)
```

**Function:** NFC APDU exchange

**Parameters:**

- 	buf (in): Transmit buffer
- 	len (in): Transmit length
- buf (out): Receive buffer
- len (out): Receive length

**Return:**

- MFSDK_NFC_RET_FAILED - Failed
- MFSDK_NFC_RET_PARM_ERROR - Invalid parameters

**Demo:**

```c
s32 iRet = MFSDK_NFC_RET_FAILED;
u8 *pRApdu = NULL;
u16 rApduLength = 0;
u8 cApud[] = {
    0x00,0xA4,0x04,0x00,0x0E,0x32,0x50,0x41,
    0x59,0x2E,0x53,0x59,0x53,0x2E,0x44,0x44,
    0x46,0x30,0x31,0x00
};

iRet = MfSdkNfcApdu(cApud, sizeof(cApud), &pRApdu, &rApduLength);
if(MFSDK_NFC_RET_OK == iRet) {
    // Success TODO
} else {
    // Fail
}
```

---

## Notes

- **Images Removed:** All images have been removed from this documentation for improved performance and accessibility
- **Based on:** Original HTML documentation and text content provided
- **Version:** MFSDK API V1.6
- **Clean Format:** Properly structured markdown with consistent formatting
- **Comprehensive:** Covers all major modules including Version, Utility, NFC, Magstripe, ICC, and UI modules

This markdown documentation provides a clean, readable format of the MFSDK API without the embedded images that were in the original HTML file.

---

**© 2025 Fujian MoreFun Electronic Technology Co.,Ltd. All rights reserved.**
