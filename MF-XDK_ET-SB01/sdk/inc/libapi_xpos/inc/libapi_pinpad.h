#ifndef __LIBAPI_PINPAD_HEADER__
#define __LIBAPI_PINPAD_HEADER__

#include "libapi_pub.h"
#include "mfsdk_mag.h"
#include "mfsdk_define.h"
#include "mfsdk_icc.h"
#include "emvapi.h"
/**
 * @brief Wake up the Pinpad
 *
 */
LIB_EXPORT int Pinpad_PowerOn(void);

/**
 * @brief Close the Pinpad
 *
 */
LIB_EXPORT void Pinpad_PowerOff(void);

/**
 * @brief Check the connection status between pinpad and host
 *
 * @param[in] timeoutMs check time out min is 100ms
 * @return  -1, Host send failed 
 * @return	0, Connection is ok
 * @return  1, Connection is broken
 * @return	2, The recv data format error, serial port baud may be error
 */
LIB_EXPORT int Pinpad_CheckState(int timeoutMs);

/**
 * @brief set input keyboard
 *
 * @param[in] mod 1:external Pinpad,0:device's Pinpad

 */
LIB_EXPORT void Pinpad_set_mode(int mod);
LIB_EXPORT int Pinpad_set_mode_ex(s32 mod);
/**
 * @brief get input keyboard
 *
 * @return  1:external Pinpad, 0:device's Pinpad

 */
LIB_EXPORT int Pinpad_get_mode();

LIB_EXPORT int Pinpad_sync_ui(unsigned char* buff, unsigned int len);
LIB_EXPORT int PinpadSetPinMod(int min, int max);
LIB_EXPORT int PinpadSyncSlavePin(int* len, char* pinBuf);
LIB_EXPORT int PinpadEmvIccPowerUp();
LIB_EXPORT int PinpadEmvIccPowerDown();
LIB_EXPORT int PinpadEmvIccApdu(const unsigned char* s, int ns, unsigned char* r, int* nr);
LIB_EXPORT int PinpadEmvRfApdu(const unsigned char* s, int ns, unsigned char* r, int* nr);
LIB_EXPORT int PinpadEmvRfPowerDown();
LIB_EXPORT int PinpadUtilLed(int num, int type);
LIB_EXPORT int PinpadMagtekFlush();
LIB_EXPORT int PinpadIccInsertDetect();
LIB_EXPORT int PinpadMagtekStrDetect(MfSdkMagTraceInfo_T* trackinfo);
LIB_EXPORT int PinpadNfcDetect();
LIB_EXPORT int PinpadIccGetCardAtr(s32 iCardType, MfSdkIccSlot_E iSlotType, u8* psATR, s32* pnATRLen);
LIB_EXPORT int PinpadNfcPowerUpAndSeek(int iCardType, char* psUID);
LIB_EXPORT int PinpadUtilBeep(int hz, int timeMs);
LIB_EXPORT void Pinpad_init();
LIB_EXPORT int Pinpad_GetVersion(char *buf, int bufSize);
LIB_EXPORT int Pinpad_GetExInfo(char* buf,int bufSize);
LIB_EXPORT int PinpadUpdate(void* cb);
LIB_EXPORT int PinpadRebootCmd();
LIB_EXPORT int PinpadGotoMainPage();
enum
{
	SLAVER_INPUT_PIN = 0,
	SLAVER_PRESS_OK,
	SLAVER_PRESS_ESC,
};
#endif /*__LIBAPI_PINPAD_HEADER__*/