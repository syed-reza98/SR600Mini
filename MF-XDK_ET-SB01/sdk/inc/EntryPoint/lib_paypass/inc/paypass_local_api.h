#ifndef __RF_PAYPASS_LOCAL_API__
#define __RF_PAYPASS_LOCAL_API__

#include "define.h"
#include "data.h"
#include "emv_interface.h"

/*****paypass���������ӿ�********/
/* ����Ԫ�ṹ */
typedef struct ST_DATA_ELEMENT
{
	uchar   ucTag[3+1];		// ���ݱ�ǩ(��󳤶�3�ֽ�)
	uchar   ucLenTag;		// ���ݱ�ǩ��ʵ�ʳ���
	uchar   ucLenCheck;		// ����У���־		0---��У�鳤��  1--У�鳤��
	ushort  usLenMin;		// ���ݵ���С���� 
	ushort  usLenMax;		// ���ݵ���󳤶� 
	uchar   ucState;		// ����Ԫ״̬(0---������  1---Emtpy 2--Not Empty)
	uchar	cTempType;		// ����Ԫ�������ڵ�ģ��
	uchar   ucIsSupportRA;	// �Ƿ�֧��RA��������
}ST_Element;

/* ����Ԫ�ṹ */
typedef struct ST_DATA_ELEMENT_TM
{
	uchar   ucTag[3+1];		// ���ݱ�ǩ(��󳤶�3�ֽ�)
	uchar   ucLenTag;		// ���ݱ�ǩ��ʵ�ʳ���
}ST_TM_Element;

//RRPָ�ƬӦ������
typedef struct 
{
	uchar ucRRP_Entropy[4];
	uchar ucRRP_MinTimeAPDU[2];
	uchar ucRRP_MaxTimeAPDU[2];
	uchar ucRRP_EstimatedTimeRADDU[2];
}RRP_RESP_DATA;


int PP_Init_App();
void PP_ProcessRestrict_Step(void);
int PayPass_Read_AppData(uchar ucTransMode,uchar ucActiveSfiSign);
int paypass_recover_ac_proc(char *pOutRespData,int *piOutDataLen);
int paypass_rrp_proc(char *pUnNumber,RRP_RESP_DATA *pRespData,int *piTakenTime);
int PP_PutIccDataByAPDU(uchar *pTag,uint uiValueLen, uchar *pValueData);
int pappass_ccc_proc(void);
int PayPass_Ch_Verify(int iType,int *piCvmFlag);
int PayPass_term_act_analy(E_GAC *pTermAcType);
int PayPass_card_act_analy(E_GAC eGacType,uint iIsPackDsDol,int iIsReqCda,char *pOutRespData,int *piOutDataLen);
int PayPass_OffAuth_CDA_First();
int CDA_AC_PAYPASS(int nGacStep, char *pszGacRes, int nGacLen);
int PP_GetData(char * pTag);
int PP_GetCardBalance(int iType);
int PP_ADF_iSelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);
int PP_PPSE_iSelectIcFile(char cSelMode,char *pszFileName,int nLenFileName,ST_ICFILE *stIcFile);


/*------------------------------------>paypass_flow.h<--------------------------��ؽӿ�����*/
/**
**���Խ���Э��,L1��ʱ�������ݶ�-2,��������޸�
*/
#define PP_ERR_L1_TIME_OUT	-2

/*******************PAYPASS�ڲ�����*****************************************************/
#define PP_LOCAL_SUCC	0
#define PP_LOCAL_FAIL	1
#define PP_LOCAL_NEXT_FLOW	2


#define PP_BALANCE_PRE_GAC1		0
#define PP_BALANCE_POST_GAC1	1
#define PP_PRE_PUT_DATA			2
#define PP_POST_PUT_DATA		3

/* ������Ϣ����*/
typedef struct
{
	uchar ucL1;       // L1����󣬲ο��궨��:�������Ͷ�λ��ʶ
	uchar ucL2;       // L2����󣬲ο��궨��:�������Ͷ�λ��ʶ
	uchar ucL3;       // L3����󣬲ο��궨��:�������Ͷ�λ��ʶ
	uchar ucMsgID;    // Message ID���ο��궨��:��Ϣ��ʶ Message ID
	ushort usSW12;    // APDU��Ƭ����״̬��
}PP_tErrorID;

//���ݽṹ��
typedef struct
{
	char auData[512];
	int uiDataLen;
}PP_tTLVString;

//���ݽṹ��2
typedef struct
{
	char auData[256+1];
	int uiDataLen;
}PP_tTLVString_256;

//���ݽṹ��3
typedef struct
{
	char auData[128+1];
	int uiDataLen;
}PP_tTLVString_128;

//���ݽṹ��4
typedef struct
{
	char auData[64+1];
	int uiDataLen;
}PP_tTLVString_64;

//���ݽṹ��4
typedef struct
{
	char auData[32+1];
	int uiDataLen;
}PP_tTLVString_32;

//�������ݽṹ��
typedef struct
{
	uchar auData[512+1024];	//��԰���3M50-0111������¼ 1045
	uint uiDataLen;
}PP_TORN_tTLVString;

//IDS״̬
typedef enum {
	IDS_NULL,
	IDS_READ,
	IDS_WRITE,
}PP_DE_IDS_STATUS;

//IDS״̬
typedef enum {
	IDS_SUMMARY_NULL,
	IDS_SUMMARY_READ,
	IDS_SUMMARY_WRITE,
}PP_DE_IDS_SUMMARY_STATUS;

//DS ODS Info For Reader ��Ϣ
typedef enum {
	USE_FOR_TC,
	USE_FOR_ARQC,
	USE_FOR_AAC,
	STOP_NO_DS_ODS_TERM,
	STOP_WRITE_FAILED
}PP_DE_DS_ODS_INFO_READER;

typedef struct
{
	uchar ucPANLen;
	char  szPAN[20];    // ���˻�
	char szExpiry[5];  // ��Ч��
	char szService[4]; // ������
	uchar ucDDLen;      // discretionary data Length
	uchar auDData[56];  // discretionary data
	int nPUNATC;      // PUNATC �з�0λ�ĸ���
	int nPCVC3;       // PCVC3  �з�0λ�ĸ���
	int nATC;         // ATC �з�0λ�ĸ���
	uchar nUN;          // UN    nPUNATC-nATC
	uchar ucPCVC3_S;    // Start Point of bit 1  �ӵ�λ����λ,�״γ���Bit'1'��λ��
	uchar ucPCVC3_E;    // End Point of bit 1 �ӵ�λ����λ,������Bit'1'��λ��
	uchar auBitMap_PCVC3[48];//��i�ֽڵ�ֵ����PCVC3��0λ��PCVC�е�����
	uchar ucPUNATC_S;   // Start Point of bit 1�ӵ�λ����λ,�״γ���Bit'1'��λ��
	uchar ucPUNATC_E;   // End Point of bit 1 �ӵ�λ����λ,������Bit'1'��λ��
	uchar auBitMap_PUNATC[48];//��i�ֽڵ�ֵ����PUNATC��0λ��PUNATC�е�����
}PayPass_tTrackData;

typedef struct
{
	unsigned long long  ulTranLimit;		//�����޶�
	unsigned long long  ulTranAmount;		//���׽��
	uchar ucOPS[8];							//Outcome Parameter Set
	uchar ucUIRD[22];						//User Interface Request Data
	uchar ucTempUIRD[22];					//User Interface Request Data Temp
	int PP_iCurrentTranMode;				//��ǰ����ģʽ
	ulong ulMeasureTime;					//RRP MeasureTime
	PP_tErrorID stErrorID;					//M_TAG_DF8115_TM_ERR_INDI ������Ϣ�ṹ�� 
	uchar auMsgHoldTime[3];					//Hold Time Value default:\x00\x00\x13
	uchar ucIsSupportIds;					//�Ƿ�֧��Ids
	uchar ucIDS_Status;						//IDS Status
	uchar ucDSSummaryStatus;				//DS Summary Status
	uchar ucPreGacPutDataStatus;			//Pre gac put data status
	uchar ucPostGacPutDataStatus;			//Post gac put data status
	uchar ucIsExecPutdataApdu;				//�ж��Ƿ�ִ��putdata����
	uchar ucIsExecPutDataPost;				//�ж��Ƿ�ִ��post putdata����
	uchar ucODAStatus;
	uchar ucGac1CdaSign;					//gac1�Ƿ�ִ��CDA
	uchar ucIsGacPackDsDol;
	RRP_RESP_DATA tRRPRespData;
	uchar ucRRPUn[4+1];						//RRP UNֵ
	int	iRRPCounter;						//RRP ������
	PayPass_tTrackData tTrack1;
	PayPass_tTrackData tTrack2;			
	E_GAC eCardGacType;						//��Ƭ����GAC actype
	int iIsStopSignal;						//�Ƿ����û���ֹ�ź�
	int iIsExecGetDataPostGPO;				//GPO���Ƿ�ִ��GETDATA����
	int IsTermRecvDetInfo;					//�ն��յ�HostDet��־
	int iCheckExistCDOL1Sign;				//ÿ������¼����CDOL1
	int iCheckExistDSDOLSign;				//ÿ������¼����DSDOL
	int iCheckExistUDOLSign;				//ÿ������¼����UDOL
	int iTornGac2Sign;						//�������ط�9000ִ�еڶ���gac2��־
	int iIsSubmitTornRecord;				//�Ƿ��ύ������¼�����GAC2-Invalid���
	PP_TORN_tTLVString tTornRecord;				//�ָ�����������

}PayPass_tParam;


typedef struct
{
	char acDataNeeded[128];
	int iDataNeededLen;
	//char acDataToSend[128];
	char acDataToSend[1024];		//DE������--3MX4-4650 update by rsjian at 2018627
	int iDataToSendLen;
	char acTagsToReadYet[128];
	int iTagsToReadYetLen;
	int iMissPdolDataFlag;
	char acTagsToWritePreGac1Yet[512+512+256];			//3MX4-4650 CASE1
	int iTagsToWritePreGac1YetLen;
	char acTagsToWritePostGac1Yet[512+512+256];			//3MX4-8750 CASE1
	int iTagsToWritePostGac1YetLen;
	int iGetDataTagNum;				//Getdata Tag count
	char acGetDataPreGac[128];	
	int iGetDataPreGacLen;
}PayPass_DE_tParam;


/****************PAYPASS���ײ���************************/
int PP_iPayPassFlow(STEMVPROC *stProc);

int PP_iReadRecord_Step(uchar ucTransMode,uint iActiveSFi);
int PP_iReadBalance_Step(int iType);
int PP_CardHolderVerify_Step(int *piCvmFlag);
int PP_CardActAnaly_Step(E_GAC eGacType,uint iIsPackDsDol,int iIsReqCda,int iCvmFlag);
int PP_CCC_Step();
int PP_RRP_Step(void);
int PP_iRecover_AC_Step(int iCvmFlag);
int PP_CardActAnaly_Ex_Step(E_GAC eGacType,uint iIsPackDsDol,int iIsReqCda,int iCvmFlag);


int PP_MAGModeTrancProc(uint iActiveSFi);
int PP_EMVModeTrancProc(uint iActiveSFi);
//�жϱ�ǩ�Ƿ����
int PP_TAG_iIsNotPresent(char *pTag);
//Table 4.3��Configuration Data in TLV Database that Require Default Value
uchar PP_ucSetDefaultConfigData(void);

int PP_iCheckPdolIsNeedEx2(void);
void PP_vSetStopSignal(void);
int PP_DE_iUpdateTagToRead(char *pData, int iLen);
int PP_DE_iUpdateTagsToWriteData(int iType,char *pData, int iLen);
int PP_iUpateTornData(char *pData, int iLen);
int PP_iDeleteCurrentTornRecord(void);
uint PP_EMV_iSupportCDA(void);
uchar PP_TLV_ucGetTermCapBit(int uiByteIndex, uchar ucBit);
uchar PP_TLV_ucGetAIPBit(int uiByteIndex, uchar ucBit);
uchar PP_ucGetDataBit(uchar ucData, uchar ucBit);
void PP_vSetActiveAFL(uint iTranMode,uint *ipUseActiveSFI);
void PP_vSetTranLimitAmount(void);
uchar PP_TLV_ucGetKernelCofigBit(int uiByteIndex, uchar ucBit);
uchar PP_TLV_ucGetTmCapBit(int uiByteIndex, uchar ucBit);
uint PP_EMV_bCheckCdaMandatoryData(void);
int PP_iFindCAPKDataBy(void);
int PP_iSetTmCap(int iType);
int PP_iCheckFloorLimit(void);
int PP_iPutData(int iType);
int PP_vInitData(void);
uint PP_bCheckIccMandatoryData(uint uiTranMode);
uint PP_iSupportRRP(void);
int PP_iSupportRecover(void);
int PP_CheckAIPAndAFL(void);
uint PP_iSupportOdv(void);
uint PP_uiGetEmvData(uchar *ucTag,PP_tTLVString *pTlvString);
uint PP_uiGetEmvData_32(uchar *ucTag,PP_tTLVString_32 *pTlvString);
void PrepareGAC1_Flow_D(E_GAC *pTermAcType);
int PrepareGAC1(E_GAC *pTermAcType);
int PP_iCheckCid(E_GAC eGacType,uchar ucCid);
int PP_iSendOutMsg(int iMsgId);
int PP_TORN_iGetTLV(char *pTag,int iTagLen,PP_tTLVString *pOutTlv);
int PP_TORN_iGetTLV_64(char *pTag,int iTagLen,PP_tTLVString_64 *pOutTlv);
int PP_iS910_CDA(int iFlowType,char *pOutGACData,uint uiOutLen);
int PP_iS910_NOCDA(int iFlowType,E_GAC eReqGacType,int iIsReqCda);
uchar PP_vAddTornCardRecord(void);
E_GAC PP_iGetActypeMacroByCid(uchar ucCid);
void PP_vConvertTrackDData(uchar ucTrackFlag,  uchar ucCoverFlag, char *paCoverStr);
void PP_vSetRRPPerForm(int iType);		//����RRP״̬
int PP_vStoreRefTornRecord(char *pcTlvData,int iTlvDataLen);		//�ָ������������
int PP_ucCalPower(int ucCount);
int PP_iPackEmvData(char * packData, char * psTag,YESORNO iIsFlag,int *pnLen);
int PP_DE_uiCheckDataReadYet();
int PP_DE_uiCheckDataReadYetEx();
int PP_DE_iCheck_DEK_Condition();
int PP_DE_iCheck_DEK_Condition_EX();
int PP_DE_iCheck_DEK_Condition_EX2();
void PP_DE_vSetIdsStatus(PP_DE_IDS_STATUS ucIdsStatus);
uint PP_uiIsDolIncludeTag(uint iDolType,uchar *pTag,uint uiTagLen);
int PP_TAG_IsNotEmpty(char *pTag);
void PP_vAddToList(char *pTag,int iTagLen,int iListType);
int PP_TAG_IsPresent(char *pTag);
int PP_iSendDEK(int iIsWait);
int PP_vAddToListEx2(char *pTag,int iTagLen,int iListType);
int PP_DE_vCheckPdolTimerFunc();
void PP_vCheckDekCondition(int iTypeDek);
void PP_vCheckDekCondition_EX(int iTypeDek);
void PP_vCheckDekCondition_EX2(int iTypeDek);
void PP_DE_vSetDsSummaryStatus(PP_DE_IDS_SUMMARY_STATUS ucIdsStatus);
int PP_DE_iGetDsOdsReaderStatus(PP_DE_DS_ODS_INFO_READER ucDsOdsStatus);
int PP_iCheckFirstWriteFlag(void);
int PP_iIsExistStopSignal(void);
void PP_Str_itoa(int num,char *str,int iCount);
int PP_vStoreReferTornRecord(char *pcTlvData,int iTlvDataLen);
/************************************************************************/
/*OUTCOME ��غ��Լ�api�ӿ�*/
/************************************************************************/
#define EMV_UI_MSG_ID                        0x01
#define EMV_UI_STATUS                        0x02
#define EMV_UI_HOLD_TIME                     0x03
#define EMV_UI_LANGUAGE_PRE                  0x04
#define EMV_UI_VALUE_QUAL                    0x05
#define EMV_UI_VALUE                         0x06
#define EMV_UI_CURRENCY_CODE                 0x07

//UIRD
#define EMV_UI_M_CARD_READ_OK				 "\x17"
#define EMV_UI_M_TRY_AGAIN					 "\x21"
#define EMV_UI_M_APPROVED					 "\x03"
#define EMV_UI_M_APPROVED_SIGN			 	 "\x1A"
#define EMV_UI_M_DECLINED				     "\x07"
#define EMV_UI_M_ERR_OTH_CARD			     "\x1C"
#define EMV_UI_M_INSERT_CARD				 "\x1D"
#define EMV_UI_M_SEE_PHONE					 "\x20"
#define EMV_UI_M_AUTH_WAIT					 "\x1B"
#define EMV_UI_M_CLEAR_DISPLAY				 "\x1E"

#define EMV_UI_S_NOT_READY                   "\x00"
#define EMV_UI_S_IDLE                        "\x01"
#define EMV_UI_S_READY_TO_READ               "\x02"
#define EMV_UI_S_PROCESSING                  "\x03"
#define EMV_UI_S_CARD_READ_SUCC              "\x04"
#define EMV_UI_S_PROCESS_ERR                 "\x05"

#define EMV_UI_V_NONE                        "\x00"
#define EMV_UI_V_AMOUNT                      "\x10"
#define EMV_UI_V_BALANCE                     "\x20"


/*L1 Error ID*/
#define PP_L1_ERR_TIMEOUT					  0x01	//TIME OUT ERROR
#define PP_L1_ERR_TRANSERR					  0x02	//TRANSMISSION ERROR
#define PP_L1_ERR_PROERR					  0x03	//PROTOCOL ERROR 

/*L2 Error ID*/
#define PP_L2_ERR_ICC_DATA_MISS			  0x01 // ��Ƭ����ȱʧ / ICC Data missing
#define PP_L2_ERR_CAM_FAILED				  0x02 // CAMʧ��  / CAM Fail
#define PP_L2_ERR_ICC_STATUS				  0x03 // APDU״̬����� / APDU Status Error
#define PP_L2_ERR_PARSING					  0x04 // �������� / ICC data parsing error.
#define PP_L2_ERR_MAX_EXCEEDED		      	  0x05 // �������� / Exceed max limit.
#define PP_L2_ERR_ICC_DATA			 	  	  0x06 // ��Ƭ���ݴ��� / ICC data error.
#define PP_L2_ERR_MAG_NOT_SUP			      0x07 // ����ģʽ��֧�� / Don��t support magnetic
#define PP_L2_ERR_NO_PPSE				      0x08 // PPSE��֧�� / Don��t support PPSE
#define PP_L2_ERR_PPSE_FAULT			      0x09 // PPSE����  / PPSE fault
#define PP_L2_ERR_NO_CAND_AID			      0x0A // û�к�ѡAID / Candidate AID list is empty.
#define PP_L2_ERR_TERM_DATA			      0x0F // �ն����ݴ��� / Terminate parameter error
/*DE*/
#define PP_L2_ERR_IDS_READ			   		  0x0B // DE----IDS READ ERROR
#define PP_L2_ERR_IDS_WRITE			      0x0C // DE----IDS WRITE ERROR
#define PP_L2_ERR_IDS_DATA			   		  0x0D // DE----IDS DATA ERROR
#define PP_L2_ERR_IDS_NO_MATCH_AC   		  0x0E // DE----IDS NO MATCHING


/*L3 Error ID*/
#define PP_L3_ERR_TIMEOUT					  0x01 // ͨѶ��ʱ / Time out
#define PP_L3_ERR_STOP						  0x02 // ��ֹ���� / Transaction being terminated
#define PP_L3_ERR_AMOUNT					  0x03 // ������ / Amount is absent


//OUTCOME  PARAMETER SET
#define EMV_OP_S_APPROVED                    0x0010
#define EMV_OP_S_DECLINED                    0x0020
#define EMV_OP_S_ONLINE_REQ                  0x0030
#define EMV_OP_S_END                         0x0040
#define EMV_OP_S_SELECT_NEXT                 0x0050
#define EMV_OP_S_TRY_OTH_IFC                 0x0060
#define EMV_OP_S_TRY_AGAIN                   0x0070

#define EMV_OP_START_A					  	 0x0100
#define EMV_OP_START_B					     0x0110
#define EMV_OP_START_C					     0x0120
#define EMV_OP_START_D					     0x0130

#define EMV_OP_CVM_NOCVM                     0x0300
#define EMV_OP_CVM_SIGNATURE                 0x0310
#define EMV_OP_CVM_ONLINE_PIN                0x0320
#define EMV_OP_CVM_CCV                       0x0330
#define EMV_OP_CVM_MAG_REQ                   0x03FA
#define EMV_OP_CVM_MAG_NOREQ                 0x03FB

#define EMV_OP_FLAG_UI_OUTCOME               0x0480
#define EMV_OP_FLAG_UI_RESTART               0x0440
#define EMV_OP_FLAG_DATA_RECORD              0x0420
#define EMV_OP_FLAG_DISCRETIONARY            0x0410
#define EMV_OP_FLAG_RECEIPT                  0x0408

#define EMV_OP_FIELDOFF                      0x0600
#define EMV_OP_FIELDOFF_NA                   0x06FF

#define EMV_DDATA_NORMAL                     0x00
#define EMV_DDATA_ERRID                      0x01
#define EMV_DDATA_ERRID_TORN				 0x02

#define EMV_INVALIDRSP_S3                    0x01
#define EMV_INVALIDRSP_S13_14                0x02
#define EMV_INVALIDRSP_S910_1                0x03
#define EMV_INVALIDRSP_S910_2                0x04		//S910 invalid-2  S910.ED61/S910.ED61 ---s11.invalid-2  S11.ED101/S11.ED101
#define EMV_VALIDRSP_S910                    0x01

#define EMV_SEND_OPS                         0x01
#define EMV_SEND_RECORD                      0x02
#define EMV_SEND_DISCRE                      0x03
#define EMV_SEND_OUT_UIRD                    0x04
#define EMV_SEND_MSG_UIRD					 0x05
#define EMV_SEND_SW12                        0x06
#define EMV_SEND_RRP_MEASURE_TIME			 0x07


void PP_vCreateDataRecord(int iType,uchar *pucBuffer,uint *piLen);
void PP_vInitSendOutData(void);
void PP_vSendOut(uchar ucType, uchar ucFlag);
void PP_vSendOut_EX(uchar ucType, uchar ucFlag);
void PP_vSetUIRD(uchar ucFlag, const void *pauValue);
void PP_vSetUIRD_EX(uchar ucFlag, const void *pauValue);
void PP_vSetOPS(ushort usFlag);
void PP_vCreateEMVDiscretionaryData(uchar ucFlag, uchar *pauData, uint *puiDataLen);
uchar PP_bGetApduError_L1(int iErrCode);
PP_tErrorID *PP_pGetErrorId(void);
void PP_vInvalidResponse(uchar ucFlag);
int PP_iValidResponse(uchar ucFlag, E_GAC ucACType);

int  PP_iParseAndStoreCardResponse(char *pTemp,int iTempLen,TlvData elem);
void PP_UpdateParamForSelectNextApp(char *pActParam,int iActParamLen);
int  PP_iSaveDetInfo(char *pTlvList,int iListLen);
void PP_vSetStopSignal(void);
int PP_iUpateTornData(char *pData, int iLen);

void PP_iSetRecvDETSign(void);
int PayPass_DE_iPostReadRecord(int iTranMode);
int PayPass_DE_iPreReadRecord(int iTranMode);
int PayPass_iIsExecGetDataApdu(void);
int PP_iIsPermitDetUpate(char *pTag,int iTagLen);
int PayPass_IsKnownTag(char *pTag,int iTagLen);
int PP_iInitTable(void);
void PP_vFreeTableData(void);

#endif