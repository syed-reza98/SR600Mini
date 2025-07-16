#include "lvgl/lvgl.h"
#include "pages/pages.h"
#include "page_pub.h"
#include "func_pay.h"
#include "../player_proc.h"
#include "libapi_xpos/inc/emvapi.h"
#include "libapi_xpos/inc/mfsdk_tms.h"
#include "libapi_xpos/inc/mfsdk_emv.h"


static lv_obj_t* base_win  = NULL;
static st_pay_data *pay_data_pay = NULL;
static st_read_card_in card_in = {0};
static st_read_card_out card_out = { 0 };
//static st_card_info card_info = { 0 };
static int lock_flag = 0;
static int card_tick = -1;

static void LedControlCLose()
{
	MfSdkNfcLed(MFSDK_NFC_LED_BLUE, MFSDK_NFC_LED_OFF);
	MfSdkNfcLed(MFSDK_NFC_LED_YELLOW, MFSDK_NFC_LED_OFF);
	MfSdkNfcLed(MFSDK_NFC_LED_GREEN, MFSDK_NFC_LED_OFF);
	MfSdkNfcLed(MFSDK_NFC_LED_RED, MFSDK_NFC_LED_OFF);
	return;
}

st_pay_data * get_card_pay_data()
{
	return pay_data_pay;
}

int getTransacationStatus()
{
	int ret = 0;

	if(1 == lock_flag && NULL != pay_data_pay 
		&& (TRANSTYPE_RF == pay_data_pay->mode 
		|| TRANSTYPE_IC == pay_data_pay->mode))
	{
		APP_TRACE("pay_data_pay->mode = %d\r\n", pay_data_pay->mode);	
		ret = -1;
	}
	APP_TRACE("lock_flag :%d, ret = %d\r\n", lock_flag, ret);	
	return ret;
}

s32 PayPagePowerLock(char *sfun)
{
	if(lock_flag == 0)
	{
		lock_flag = 1;
		APP_TRACE("<%s> [%s]\r\n", __FUNCTION__, sfun);
		return AppPowerLockApp(sfun);
	}
	return -1;
}

void PayPagePowerUnlock(char *sfun)
{
	if(lock_flag == 1)
	{
		lock_flag = 0;
		APP_TRACE("<%s> [%s]\r\n", __FUNCTION__, sfun);
		AppPowerUnlockApp(sfun);
	}
	return;
}

static int _pay_close_page(int ret, lv_obj_t* obj)
{
	char *msg = NULL;
	LedControlCLose();

	//Type:2:free icc card data; 3:free rfic card data
	if(TRANSTYPE_IC == pay_data_pay->mode)
	{
		MfSdkEmvCardFree(2);
	}
	if(TRANSTYPE_RF == pay_data_pay->mode)
	{
		MfSdkEmvCardFree(3);
	}

	APP_TRACE("%s step = %d, ret = %d\r\n", __FUNCTION__, pay_data_pay->step, ret );
	if (base_win != 0) 
	{
		if(ret < 0)
		{
			PubMultiPlay((const s8*)TTS_VOLUME_BEEP);
			APP_TRACE("error ret = %d\r\n", ret );
			if(ret == PAGE_RET_RECV_FAIL)
			{
				msg = "Receve Fail";
			}
			else if(ret == PAGE_RET_CONN_FAIL)
			{
				msg = "Connect Fail";
			}
			else if(ret == -18)
			{
				msg = "Not Support";
			}
			else
			{
				msg = "Transaction cancel";
			}
			page_text_show(get_subpage(), pay_data_pay->title, msg, 3000);
		}
		if(pay_data_pay)
		{
			MfSdkMemFree(pay_data_pay);
			pay_data_pay = 0;
		}
		lv_obj_del(base_win);
		base_win = 0;
	}
	
	set_amt_timer(1);
	LedShowMessage("WELCOME");
	PayPagePowerUnlock("func_pay end");
	MfSdkPowerSupertimeReset();
	APP_TRACE("====power_switch_reset_tick====");
	//power_switch_reset_tick();
	MfSdkTmsAppBusy(MFSDK_TMS_APP_NOT_BUSY);
	
	return ret;
}

void PayClosePage()
{
	SetPowerLock(QRPAGE_LOCK_DEF);
	LedControlCLose();

	APP_TRACE("%s \r\n", __FUNCTION__);
	if (base_win != 0) 
	{
		lv_obj_del(base_win);
		base_win = 0;
		if(pay_data_pay)
		{
			MfSdkMemFree(pay_data_pay);
			pay_data_pay = 0;
		}
	}
	MfSdkTmsAppBusy(MFSDK_TMS_APP_NOT_BUSY);
	return;
}

char *get_card_title()
{
	char *title = NULL;
	
	if(strlen(pay_data_pay->title)>0)
	{
		title = pay_data_pay->title; 
	}
	else
	{
		title = "Sale";
	}
	
	return title;
}

static int _getval(const char *data, const char *key, char *outbuff, int size)
{
    char temp[256] = {0};
    char *pstart, *pend;

    sprintf(temp, "\"%s\":", key);

    pstart = (char *) strstr(data, temp);

    if ( pstart != 0)
    {
        int vallen;

        pstart += strlen(temp);
        pend =  (char *)strstr(pstart, ",");

        if ( pend == 0 )
        {
            pend = (char *) strstr(data, "}");
        }

		//delete space
		if (*pstart == ' ')
		{
			pstart++;
		}

        //delete "
        if ( *pstart == '\"' &&  *(pend - 1) == '\"' )
        {
            pstart++;
            pend--;
        }
        vallen = pend - pstart;
		if (vallen > size)
			vallen = size;
        memcpy(outbuff, pstart, vallen);
        outbuff[vallen] = 0;
        return vallen;
    }
	
    return 0;
}

static int MessagePackData()
{
	int index = 0;
	char sn[33] = {0};
	int port = HTTP_PORT;
	char ip[64] = { 0 };
	char sendData[SEND_BUFF_SIZE] = {0};
	char* sbuff = pay_data_pay->comm_data.sbuff;;

	memset(&pay_data_pay->comm_data, 0 ,sizeof(st_comm_data));

	#ifdef TEST_SN
	strcpy(sn, TEST_SN);
	#else
	MfSdkSysGetTermSn(sn);
	#endif

	get_setting_str(COMM_HTTP_IP, ip, sizeof(ip));
	if (strlen(ip) < 3)
	{
		strcpy(ip, HTTP_HOST);
		port = HTTP_PORT;
	}
	else
	{
		port = get_setting_int(COMM_HTTP_PORT);
	}

	snprintf(sendData, sizeof(sendData), "device_id=%s&request_data=%0.2f", sn, ATOLL(pay_data_pay->amount) / 100.0);
	index += sprintf(sbuff + index , "POST /api/Iotmsgtest/createQrMf?%s HTTP/1.1\r\n", sendData);
	index += sprintf(sbuff + index , "Host: %s:%d\r\n\r\n", ip, port);	
	pay_data_pay->comm_data.slen = strlen(sbuff);

	APP_TRACE("[%s][%s]\r\n",__FUNCTION__, sbuff);
	APP_TRACE_BUFF_TIP(pay_data_pay->comm_data.sbuff, pay_data_pay->comm_data.slen, "send:");
	return 0;
}

static int MessageUnpackData()
{
	int ret = -1;
    char temp[256] = { 0 };
	char recvdata[RECV_BUFF_SIZE] = {0};
	cJSON* rootobj = NULL;
	cJSON* dataobj = NULL;

	APP_TRACE_BUFF_TIP(pay_data_pay->comm_data.rbuff, pay_data_pay->comm_data.rlen, "recv:");
	if (pay_data_pay->comm_data.rlen > 0 && pay_data_pay->comm_data.rlen < RECV_BUFF_SIZE) 
	{
		memcpy(recvdata, pay_data_pay->comm_data.rbuff, pay_data_pay->comm_data.rlen);
		rootobj = cJSON_Parse(recvdata);
		if (rootobj != NULL) 
		{
			if (json_getval(rootobj, "code", temp, sizeof(temp)-1) > 0 && 0 == strcmp(temp, "0000"))
			{
				APP_TRACE("code:%s\r\n", temp);
				memset(temp, 0, sizeof(temp));
				dataobj = cJSON_GetObjectItem(rootobj, "data");
				if (dataobj)
				{
					if (json_getval(dataobj, "order_sn", pay_data_pay->orderSn, sizeof(pay_data_pay->orderSn)) > 0)
					{
						//op=4:IC, op=2:rf, op=1:qrcdeo
						APP_TRACE("OrderSn:%s transtype = %d\r\n", pay_data_pay->orderSn, pay_data_pay->mode);
						ret = 0;
					}
				}
			}
			else
			{
				if (json_getval(rootobj, "msg", temp, sizeof(temp)) > 0)
				{
					APP_TRACE("msg: %s\r\n", temp);
					//page_text_show(get_mainpage(), pay_data_pay->title, temp, 3000);
				}
				APP_TRACE("error!\r\n");
			}
			cJSON_Delete(rootobj);
		}
	}
	else 
	{
		APP_TRACE("_unpack_data error length!");
	}

	return ret;
}


#if 0
#include "emv_tag.h"
static const char * cEmvTag[]=
{
	EMV_TAG_82_IC_AIP,              EMV_TAG_9F36_IC_ATC,           EMV_TAG_9F27_IC_CID,          EMV_TAG_9F34_TM_CVMRESULT,     EMV_TAG_9F1E_TM_IFDSN, 
	EMV_TAG_9F10_IC_ISSAPPDATA,     EMV_TAG_9F33_TM_CAP,           EMV_TAG_9F35_TM_TERMTYPE,     EMV_TAG_9F37_TM_UNPNUM,
	EMV_TAG_9F01_TM_ACQID,          EMV_TAG_9F03_TM_OTHERAMNTN,    EMV_TAG_81_TM_AUTHAMNTB ,     EMV_TAG_9F02_TM_AUTHAMNTN ,    EMV_TAG_5F24_IC_APPEXPIREDATE ,
	EMV_TAG_5F25_IC_APPEFFECTDATE,  EMV_TAG_5A_IC_PAN ,            EMV_TAG_5F34_IC_PANSN ,       EMV_TAG_99_TM_ONLINEPIN ,      EMV_TAG_9F15_TM_MCHCATCODE ,    
	EMV_TAG_9F16_TM_MCHID	,       EMV_TAG_9F1A_TM_CNTRYCODE,     EMV_TAG_9F1C_TM_TERMID,       EMV_TAG_57_IC_TRACK2EQUDATA,   EMV_TAG_5F2A_TM_CURCODE,
	EMV_TAG_9F21_TM_TRANSTIME,		EMV_TAG_9C_TM_TRANSTYPE,       EMV_TAG_8E_IC_CVMLIST,        EMV_TAG_9F0D_IC_IAC_DEFAULT,
	EMV_TAG_9F0E_IC_IAC_DENIAL,     EMV_TAG_91_TM_ISSAUTHDT,       EMV_TAG_9F40_TM_CAP_AD,       
	EMV_TAG_9F26_IC_AC   ,          EMV_TAG_9F07_IC_AUC ,          EMV_TAG_9A_TM_TRANSDATE,      EMV_TAG_5F28_IC_ISSCOUNTRYCODE,EMV_TAG_9F09_TM_APPVERNO,
	EMV_TAG_9F41_TM_TRSEQCNTR,      EMV_TAG_9F0F_IC_IAC_ONLINE ,   EMV_TAG_9F5D_IC_RF_BALANCE,   EMV_TAG_5F20_IC_HOLDERNAME,    EMV_TAG_95_TM_TVR,       
	EMV_TAG_9B_TM_TSI,				EMV_TAG_9F63_IC_IDENTIFY_INFOR,EMV_TAG_9F24_IC_PAR,				EMV_TAG_9F19_IC_TOKEN,
	EMV_TAG_9F06_TM_AID,
};


int Disp_EMV_Tag(char *pData, int nDataLen)
{
	int ind = 0;
	char* tag= 0;
	int bufflen = 0;
	char buff[128]={0};

	memset(buff, 0, sizeof(buff));
	if (0 == Ex_TLV_GetDataByTag((u8*)EMV_TAG_57_IC_TRACK2EQUDATA, (u8*)pData, nDataLen, (u8*)buff, &bufflen))
	{
		APP_TRACE_BUFF_TIP(buff, bufflen, "EMV_TAG_57_IC_TRACK2EQUDATA");
	}
	else
	{
		APP_TRACE("fail\r\n" );
	}
	return 0;
	
	for(ind = 0; ind < sizeof(cEmvTag)/sizeof(cEmvTag[0]); ind++)
	{
		tag = (char*)cEmvTag[ind];
		APP_TRACE("tag[%s]: \r\n", tag);
		memset(buff, 0, sizeof(buff));
		if (0 == Ex_TLV_GetDataByTag((u8*)tag, (u8*)pData, nDataLen, (u8*)buff, &bufflen))
		{
			APP_TRACE_BUFF_TIP(buff, bufflen, "tagbuf");
		}
		else
		{
			APP_TRACE("fail\r\n" );
		}
	}
	return 0;
}
#endif

static int TransactionCheck(int mode)
{
	int ret = 0;
	char *title = get_trans_title(mode);

    if (MfSdkCommLinkState() == 0)
    {
        APP_TRACE("TransactionProc network fail\n");
        page_text_show(get_subpage(), title, "Network unstable", 3000);
        PubMultiPlay((const s8*)"netf.mp3");
		ret = -1;
    }
    else if (get_mqtt_con_state() == 0)
    {
        APP_TRACE("TransactionProc connect fail\n");
        page_text_show(get_subpage(), title, "Connect fail", 3000);
        mqtt_play_state(0);
		ret = -1;
    }

	if (LCD_IS_128_32 && mode == TRANSTYPE_QR)
	{
        APP_TRACE("not support\n");
        page_text_show(get_subpage(), title, "Not Support", 3000);
		ret = -1;
	}
	return ret;
}

static void play_voice(char* strmoney)
{
	int money = atoi((const char*)strmoney);
	
	pub_tts_play_amt_en(money);
}


static void SendTransResult(lv_obj_t* parent, void* pfunc, st_pay_data* pay_data_pay, int ret)
{
    APP_TRACE("SendTransResult = %d\r\n", ret);
	page_show_image(get_mainpage(), pfunc, pay_data_pay->title, ret, 0, 3000);
	if(ret>=0)
	{
		play_voice(pay_data_pay->amount);
	}
}

void *_read_card_page(void)
{
	APP_TRACE("_read_card_page \r\n");	
	page_read_card_show(get_subpage(), pay_data_pay->title, "read card...", 1000);//"Icc proccess"
}

void AppCompleteProcessing(void)
{
	int ret = 0;

	unsigned char data[512] = {0};
	unsigned char out[512] = {0};
	s32 outLength = 0;

	APP_TRACE("AppSecondTapProcessing\r\n");
	memcpy(data,"8A023030",8);	//pass in field 55 data
	
	ret = MfSdkEmvOnlineRespPack(0, "00",data, "9A9C9F27",out, &outLength);
	
	APP_TRACE("card_contactless_online_res = %d\r\n",ret);
	APP_TRACE_BUFF_TIP(out,outLength,"MfSdkEmvOnlineRespPack out:");

	s32 OutValueLen = 0;
	unsigned char tapIndicate[8] = {0};
	MfSdkEmvGetKernelData(DEF_TAG_TAP_MODE,&OutValueLen,tapIndicate);

	if(OutValueLen > 0)
	{  
		if(tapIndicate[0] == 0x02)
		{
			APP_TRACE("2nd Tap Card \r\n");
		}
	}

	lv_start_lock(1);
	SendTransResult(NULL, _pay_close_page, pay_data_pay, ret);
	lv_start_lock(0);

}

static void GetEMVMessage(int ret)
{
	if (ret == EMVAPI_RET_ARQC) 
	{
		strcpy(pay_data_pay->retmsg, "arqc online");
	}
	else if (ret == EMVAPI_RET_TC) 
	{
		strcpy(pay_data_pay->retmsg, "approve");
	}
	else if (ret == EMVAPI_RET_AAC) 
	{
		strcpy(pay_data_pay->retmsg, "decline");
	}
	else if (ret == EMVAPI_RET_KERNEL_NOT_SUPPORT) 
	{
		strcpy(pay_data_pay->retmsg, "not support");
	}
	else
	{
		strcpy(pay_data_pay->retmsg, "terminate");
	}

	if (ret >= 0)
	{
		APP_TRACE("ic_data_len[%d]\r\n", card_out.ic_data_len);
		APP_TRACE_BUFF_TIP(card_out.ic_data, card_out.ic_data_len, "card_out:");
		APP_TRACE_BUFF_TIP(card_out.track2, card_out.track2_len, "track2:");
	}
}

static int _pay_return_func(int ret, lv_obj_t* obj)
{
	APP_TRACE("pay_data_pay->step = %d, ret = %d\r\n", pay_data_pay->step, ret);
	if (ret < 0)
	{
		if(pay_data_pay->step == PAY_STEP_READ_CARD)
		{
			pay_data_pay->step = PAY_STEP_EMV;
		}
		else
		{
			pay_data_pay->step = PAY_STEP_MSG;
		}
	}
	else
	{
		if(pay_data_pay->step == PAY_STEP_START)
		{
			pay_data_pay->step = PAY_STEP_INPUT_AMOUNT;
		}
		else if(pay_data_pay->step == PAY_STEP_INPUT_AMOUNT)
		{
			if(TRANSTYPE_QR == pay_data_pay->mode)
			{
				pay_data_pay->step = PAY_STEP_COMM;
			}
			else
			{
				pay_data_pay->step = PAY_STEP_INPUT_CARD;
			}
		}
		else if(pay_data_pay->step == PAY_STEP_INPUT_CARD)
		{
			pay_data_pay->step = PAY_STEP_READ_CARD;
		}
		else if(pay_data_pay->step == PAY_STEP_READ_CARD)
		{
			pay_data_pay->step = PAY_STEP_EMV;
		}
		else if(pay_data_pay->step == PAY_STEP_DISP_CARD)
		{
			pay_data_pay->step = PAY_STEP_INPUT_PIN;
		}
		else if(pay_data_pay->step == PAY_STEP_INPUT_PIN)
		{
			pay_data_pay->step = PAY_STEP_EMV;
		}
		else if(pay_data_pay->step == PAY_STEP_EMV)
		{
			pay_data_pay->step = PAY_STEP_COMM;
		}
		else if(pay_data_pay->step == PAY_STEP_COMM)
		{
			if(TRANSTYPE_QR == pay_data_pay->mode)
			{
				pay_data_pay->step = PAY_STEP_UNPACK;
			}
			else
			{
				pay_data_pay->step = PAY_STEP_MSG;
			}
		}
		else if(pay_data_pay->step == PAY_STEP_UNPACK)
		{
			pay_data_pay->step = PAY_STEP_MSG;
		}
	}
	lv_event_send(base_win, pay_data_pay->step, &ret);
	return 0;
}

// Mask card number 
static int MaskCardNumber(char *cardNo, char *maskedCardNo)
{
	int ret = -1;
	int nLen,i;

	if( NULL == cardNo || NULL == maskedCardNo ) { return ret; }
	strcpy(maskedCardNo, cardNo);

	nLen = strlen(cardNo);
	if( nLen < 10  ) { return ret; }

	for (i = 6; i < nLen - 4; i++)
	{
		maskedCardNo[i] = '*';
	}
	
	return 0;
}

static void _func_pay_event_cb(lv_obj_t* obj, lv_event_t e)
{
	int ret = -1;
	void *data = lv_event_get_data();

	if(NULL != data) memcpy(&ret, data, sizeof(int));
	APP_TRACE("LV_EVENT = %d, ret = %d\r\n", e, ret);
	
	if (e >= PAY_STEP_START && e <= PAY_STEP_MSG)
	{
		switch(e)
		{
			case PAY_STEP_INPUT_AMOUNT:
			{
				APP_TRACE("PAY_STEP_INPUT_AMOUNT\r\n");
				page_input_show_ex(obj, _pay_return_func, pay_data_pay->title, pay_data_pay->amount, 1, 9, PAGE_INPUT_MODE_AMOUNT, TIMEOVER,0);
				break;
			}
			case PAY_STEP_INPUT_CARD:
			{
				APP_TRACE("PAY_STEP_INPUT_CARD\r\n");
				page_card_showamt(obj, _pay_return_func, pay_data_pay->title, 0, pay_data_pay->amount, pay_data_pay->mode, TIMEOVER, 0);
				break;
			}
			case PAY_STEP_READ_CARD:
			{
				APP_TRACE("PAY_STEP_READ_CARD\r\n");
				strcpy(card_in.title, pay_data_pay->title);
				strcpy(card_in.amt, pay_data_pay->amount);
				if (TRANSTYPE_RF == pay_data_pay->mode) 
				{
					MfSdkNfcLed(MFSDK_NFC_LED_YELLOW, MFSDK_NFC_LED_ON);
					PubMultiPlay((const s8*)TTS_VOLUME_NOR);
					APP_TRACE("CARD_RET_RFIC\r\n");
					card_in.card_mode = EMVCARD_RET_RFID;
				}
				else if (TRANSTYPE_IC == pay_data_pay->mode) 
				{
					APP_TRACE("CARD_RET_ICC\r\n");
					card_in.card_mode = EMVCARD_RET_ICC;
				}
				MfSdkEmvSetReadPageCallback(_read_card_page);
				card_tick = MfSdkSysGetTick();
				//get need tag:9F02 9F03 82
				//strcpy(card_in.ic_tags, "9F029F0382");	//card_in.ic_tags ASCII code; TAGs need get value from card reading			
				MfSdkEmvReadCardPage(obj, _pay_return_func, &card_in, &card_out);			
				break;
			}
			case PAY_STEP_DISP_CARD:
			{
				// Mask card number 
				//char masked[32] = { 0 };
				//MaskCardNumber(pay_data_pay->cardnum, masked);
				APP_TRACE("PAY_STEP_DISP_CARD\r\n");
				page_message_show_ex(obj, _pay_return_func, pay_data_pay->title, pay_data_pay->cardnum, 0, "confirm", OK_TIME_OVER, 3);
				break;
			}
			case PAY_STEP_INPUT_PIN:
			{
				APP_TRACE("PAY_STEP_INPUT_PIN\r\n");
				page_input_show_psw(obj, _pay_return_func, pay_data_pay->title, "input PIN:(4-12)", pay_data_pay->pin, 4, 12, PAGE_INPUT_MODE_PWD, 60000);
				break;
			}
			case PAY_STEP_EMV:
			{
				APP_TRACE_BUFF_TIP(card_out.pin_block, 32, "pin_block");
				APP_TRACE_BUFF_TIP(card_out.ic_data, card_out.ic_data_len, "ic_date");
				APP_TRACE("card process:%d\r\n", MfSdkSysGetTick()-card_tick);
				APP_TRACE("PAY_STEP_EMV\r\n");
				card_close_subpage();
				emvreadcardtiprelease();
				GetEMVMessage(ret);
				if (pay_data_pay->mode == TRANSTYPE_RF)
				{
					if (ret < 0)
					{
						ret = PAGE_RET_EMV_FAIL;
						MfSdkNfcLed(MFSDK_NFC_LED_RED, MFSDK_NFC_LED_ON);
						MfSdkSysDelay(200);
					}
					else
					{
						MfSdkNfcLed(MFSDK_NFC_LED_GREEN, MFSDK_NFC_LED_ON);
					}
				}

				_pay_return_func(ret, obj);
				break;
			}
			case PAY_STEP_COMM:
			{
				APP_TRACE("PAY_STEP_COMM\r\n");
				MessagePackData();
				if(TRANSTYPE_QR == pay_data_pay->mode)
				{
					page_comm_show_auto(obj, _pay_return_func, pay_data_pay->title, &pay_data_pay->comm_data, 2);
				}
				else
				{
					page_comm_show_auto(obj, _pay_return_func, pay_data_pay->title, &pay_data_pay->comm_data, 1);
				}

				break;
			}
			case PAY_STEP_UNPACK:
			{
				int msg_ret = MessageUnpackData();
				APP_TRACE("PAY_STEP_UNPACK msg_ret = %d\r\n", msg_ret);
				_pay_return_func(msg_ret, obj);
				break;
			}
			case PAY_STEP_MSG:
			{
				APP_TRACE("PAY_STEP_MSG ret = %d\r\n", ret);
				if (ret < 0)
				{
					//_pay_close_page(ret, obj);
					SendTransResult(obj, _pay_close_page, pay_data_pay, ret);
				}
				else
				{
					if(TRANSTYPE_QR == pay_data_pay->mode)
					{				
					    char amountStr[16] = { 0 };
					    char orderSn[128] = { 0 };
				        sprintf(amountStr, "%0.2f", ATOLL(pay_data_pay->amount) / 100.0);
						strcat(orderSn, pay_data_pay->orderSn);
						SetPowerLock(QRPAGE_LOCK_OFF);
				        show_page_qrcode(get_mainpage(), _pay_close_page, amountStr, orderSn, TIMEOVER);
					}
					else
					{
						MfSdkSysTaskAppSet(AppCompleteProcessing);
					//if (0 == strcmp(pay_data_pay->retmsg, "arqc online") || 0 == strcmp(pay_data_pay->retmsg, "approve"))
						//SendTransResult(obj, _pay_close_page, pay_data_pay, ret);
					}
				}
				break;
			}
			default:
				_pay_close_page(0, obj);			
				break;
				
		}
	}

}

static void TransactionParamInit(int mode)
{
	char *title = get_trans_title(mode);
	
	pay_data_pay = MfSdkMemMalloc(sizeof(st_pay_data));
	memset(pay_data_pay, 0x00, sizeof(st_pay_data));
	pay_data_pay->step = PAY_STEP_INPUT_AMOUNT;
	pay_data_pay->mode = mode;
	pay_data_pay->comm_data.timeover = 60000;
	pay_data_pay->title = title;	
	
	memset(&card_in, 0, sizeof(card_in));
	memset(&card_out, 0, sizeof(card_out));
	card_in.ic_online_resp = 1;
	card_in.pin_dukpt_gid = -1;
	card_in.data_dukpt_gid = -1;
	card_in.pin_mksk_gid = -1;
}

void func_pay(lv_obj_t * parent, int mode)
{

    APP_TRACE("transType = %d\r\n", mode);
	LedShowMessage("WELCOME");
	if (0 != TransactionCheck(mode))
	{
		return;
	}
	if (mode == TRANSTYPE_RF || mode == TRANSTYPE_IC)
	{
		AppInitEmvCallback();
	}
	if(NULL != base_win)
	{
		PayClosePage();
	}
				
	MfSdkTmsAppBusy(MFSDK_TMS_APP_STATE_BUSY);
	PayPagePowerLock("func_pay");
	TransactionParamInit(mode);
	base_win = page_create_win(parent, _func_pay_event_cb);
				
	lv_event_send(base_win, pay_data_pay->step, 0);
}


