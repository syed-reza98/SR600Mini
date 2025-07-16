#ifndef __EMV_ERR_CODE_
#define __EMV_ERR_CODE_ 
/**************************************/
//���̴���
//static unsigned char gcEmvErrorFLOW = 0;//������
#define EMV_PRE_PROCESS_FLOW			0x00
#define EMV_SEL_APP_FLOW				0x01
#define EMV_INIT_APP_FLOW				0x02
#define EMV_READ_DATA_FLOW				0x03
#define EMV_OFF_AUTH_FLOW				0x04
#define EMV_PROCE_RESTRICT_FLOW			0x05
#define EMV_CARDHOLDER_VERIFY_FLOW		0x06
#define EMV_RISK_MANA_FLOW				0x07
#define EMV_ACT_ANALY_FLOW				0x08
#define EMV_COMPLETE_FLOW				0x09

//���̾��������
//static unsigned int giEmvErrCode[4] ={0};//������
//�Ƕ�Ӧ������Ϣ
/***********************************************************************/
/**<Ԥ�������Pre-processing error code*/
/**< qpboc Ԥ����*/
#define QPBOC_ERR_PRE			            0x0011  //qpboc Ԥ�������qpboc preprocessing error

#define QPBOC_ERR_PRE_AMTLIMIT		        0x0021  //��Ȩ��������ն˷ǽӴ������޶amount substantially transaction limit

#define QPBOC_ERR_PRE_ENTERAMT_CANCLE       0x0031  //������ȡ����Enter amount to cancel


/***********************************************************************/
/**<Ӧ��ѡ�����*/
#define EMV_ERR_SELAPP						  0x0111  //Ӧ��ѡ�����   Application selection error

/**<Ӧ��ѡ��*/
#define EMV_ERR_SELAPP_PSE			          0x0121  //PSEӦ��ѡ�����  PSE application selection error
#define EMV_ERR_SELAPP_PSE_UNSUPPORT          0x0122  //��Ƭ��֧��PSEѡ�� Card does not support PSE selection
#define EMV_ERR_SELAPP_APPLOCK		          0x0123  //Ӧ�ñ�����  is locked
#define EMV_ERR_SELAPP_DIRSEL				  0x0124  //Ŀ¼ѡ�����Dir selection error
#define EMV_ERR_SELAPP_PARSE		  0x0125  //PPSE��������PPSE parsing error

/**<AID�б�*/
#define EMV_ERR_AIDLIST		                  0x0131  //AID�б�ѡ����� AID list method selection error
#define EMV_ERR_AIDLIST_LOCK	              0x0132  //AIDѡ�񣬿�Ƭ������ AID selection, card is locked
#define EMV_ERR_ICCOP_SELECTAID	              0x0134  //����AIDѡ������ظ�ֵ�� Send AID select command to return negative value
#define EMV_ERR_ICCOP_SELECTAID_DATA84        0x0135  //AIDѡ��84���ݳ��ȴ� AID selection tag84 data length error     
#define EMV_ERR_ICCOP_SELECTAID_DATASFI       0x0136  //AIDѡ�����ݷ���û��88 SFI��  AID selection data returned without SFI
#define EMV_ERR_ICCOP_SELECTAID_SFI           0x0137  //AIDѡ�����ݷ���SFI���� AID selection data returned SFI error  
#define EMV_ERR_SELECTAID_NOMATCH			  0X0138  //�ն˺Ϳ�Ƭû��ƥ���AID�� Terminal and card have no matching AID
#define EMV_ERR_SELECTAID_SW1W2_NO_9000		  0X0139  //Select Aid��Ƭ���ط�9000��Select Aid card returns non-9000
#define EMV_ERR_SELECTAID_PARSE_ERROR		  0X013a  //Select Aid��Ƭ�������ݽ�������Select Aid card returns data parsing error
#define EMV_ERR_SELECTAID_DATA_MISS			  0X013b  //Select Aid��Ƭ��������ȱʧ����Select Aid card returns missing data error

/**< qpbocӦ��ѡ��*/ 
#define QPBOC_ERR_APPSEL		            0x0151  //QPBOC��Ӧ��ѡ�����
#define QPBOC_ERR_PPSE                      0x0152  //�ǽ�Ŀ¼ѡ��PPSEʧ��
#define QPBOC_ERR_AMT_CHECK                 0x0153  //���׽����ʧ�� 
#define QPBOC_ERR_APPSEL_PPSE	            0x0154  //QPBOCӦ��ѡ����Ŀ¼ѡ�񷵻ز�Ϊ9000
#define QPBOC_ERR_APPSEL_MISSBFOC		    0x0155  //Ӧ��ѡ��ʧBF0C
#define QPBOC_ERR_APPSEL_UNPACKBFOC		    0x0156  //Ӧ��ѡ��û�д��BF0C
#define QPBOC_ERR_APPSEL_UNPACK61		    0x0157  //QPBOCӦ��ѡ����û�д��61
#define QPBOC_ERR_APPSEL_PPSE6283	        0x0158  //QPBOCӦ��ѡ���з���6283

#define EMV_ERR_INITAPP_EC_MISMATCH			0x0161  // �������ֽ𿨽������Ͳ�ƥ��
#define EMV_ERR_INITAPP_EC_QUIT				0x0162  // �����ֽ�Ӧ��ѡ���˳�

#define EMV_ERR_SIMPLE_PROC_EC              0x0171  // ���������Ǽ������̣����Ǵ������ֽ� 

#define EMV_ERR_SIMPLE_PROC                 0x0181	// ��ȡӦ�����ݽ������ж�Ϊ�߼������� 

#define EMV_ERR_EC_TMLIMIT					0x0191  //�����ֽ����

/**************************************************************************/
/**<��ʼ��Ӧ�ô���*/
#define EMV_ERR_INITAPP_ERR					0x0211  //��ʼ��Ӧ�ô���   Initialization application error

#define EMV_ERR_INITAPP_CHECKGPO			0x0221  //Ӧ�ó�ʼ��ʱGPO�����ȱ�ٱ�Ҫ���ݡ�  GPO command returns missing necessary data
#define EMV_ERR_INITAPP_GPO_UNPACK			0x0222  //GPO�������ݲ�����ȷ������ GPO return data cannot be parsed correctly
#define EMV_ERR_INITAPP_GPO_LEN				0x0223  //GPO ���ݳ��Ȳ���ȷ�� GPO data length is incorrect
#define EMV_ERR_INITAPP_GPO_77				0x0224  //GPO 77 ģ�岻�ܽ����� GPO 77 template cannot be parsed
#define EMV_ERR_INITAPP_GPO_80				0x0225  //GPO 80 ģ�岻�ܽ����� GPO 80 template cannot be parsed
#define EMV_ERR_INITAPP_GPO_NO82            0x0226  //GPO ����77ģ��ʱȱ��82��Ҫ���ݡ� GPO is missing 82 necessary data when parsing 77 templates
#define EMV_ERR_INITAPP_GPO_NO94            0x0227  //GPO ����77ģ��ʱȱ��84��Ҫ���ݡ� GPO is missing 84 necessary data when parsing 77 templates
#define EMV_ERR_INITAPP_GETOP			    0x0228  //Ӧ�ó�ʼ��ʱGPO����ز�Ϊ9000����Ϊ6985�� GPO command returns not 9000, not 6985 during application initialization 
#define EMV_ERR_INITAPP_PACKPDOL		    0x0229  //Ӧ�ó�ʼ��ʱGPO��PDOL���ʱ���� Error in PDOL packaging in GPO during application initialization
#define EMV_ERR_INITAPP_SELACCOUNT			0x022a	//�˻�ѡ�����Account selection error
#define EMV_ERR_INITAPP_6985				0x022b  //ICC����6985 ��ICC returns 6985

/**< qpbocӦ�ó�ʼ��*/
#define	QPBOC_ERR_INITAPP_ERR	            0x0251  //QPBOCӦ�ó�ʼ��ʧ�� 
#define QPBOC_ERR_INITAPP_PACKPDOL	        0x0252  //QPboc�д��DOL���ݳ��� 
#define QPBOC_ERR_INITAPP_PDOLNO9F66	    0x0253  //QPBOC��Dol����û��9F66 
#define QPBOC_ERR_INITAPP_GETGPO            0x0254  //��ȡGPO����ʧ�� 
#define QPBOC_ERR_INITAPP_CHECK_GPO         0x0255  //���GPO����ʧ�� 
#define QPBOC_ERR_INITAPP_GPO6984		    0x0256  //QPboc��GPO����6984��������ֹ 
#define QPBOC_ERR_INITAPP_GPOMISSING82	    0x0257  //QPBOC��GPO��û��82
#define QPBOC_ERR_INITAPP_GETGPO_74         0x0258  //QPBOC��GPO��77ģ����74�������� 
#define QPBOC_ERR_INITAPP_GPO6985		    0x0259  //QPboc��GPO����6985��������ֹ 
#define QPBOC_ERR_INITAPP_GPO6986		    0x025a  //QPboc��GPO����6986��������ֹ 
#define QPBOC_ERR_INITAPP_GPONOLEN		    0x025b  //QPboc��GPO����Ӧ
#define QPBOC_ERR_TURN_PBOC                 0x025c  //QPBOC �����GPO������9F26������֧��PBOC����תPBOC 
#define QPBOC_ERR_INITAPP_GPO6987		    0x9B  //QPboc��GPO����6986��������ֹ <D3>

/**************************************************************************/
/**<��Ӧ�����ݴ���*/
#define EMV_ERR_READAPP					    0x0311  //��Ӧ�����ݴ��� Read application data error

#define EMV_ERR_READAPP_CDOL1				0x0321  //���Ӧ�����ݣ�CDOL1 ȱʧ��  Check application data, CDOL1 is missing
#define EMV_ERR_READAPP_CDOL2				0x0322  //���Ӧ�����ݣ�CDOL2 ȱʧ��  Check application data, CDOL2 is missing
#define EMV_ERR_READAPP_EXPIREDATE		    0x0323  //���Ӧ�����ݣ�Ӧ��ʧЧ����ȱʧ����� Check application data for missing or incorrect application expiration dates     
#define EMV_ERR_READAPP_APPEFFECTDATE	    0x0324  //���Ӧ�����ݣ�Ӧ����Ч����ȱʧ����� Check application data, missing or incorrect application effective date

#define EMV_ERR_READAPP_START				0x0331  //��ȡӦ�����ݣ�����AFL����ʼλΪ0����IC������ Error reading application data because the start bit of AFL is 0 (IC card)
#define EMV_ERR_READAPP_PARAM			    0x0332  //��ȡӦ�����ݣ�����AFL����ʼλ���ڽ���λ����IC������ Reading application data, because the start bit of AFL is larger than the end bit (IC card)

#define EMV_ERR_READAPP_ICCOP_READ		    0x0341  //RR��Read Record��ʱ�������ز�Ϊ9000���� Error while reading record
#define EMV_ERR_READAPP_SFI				    0x0342  //RR ����� ֻ��70ģ��ʱ��SFI�Ż�С�ڵ���10�� When the read data ,the SFI will be less than or equal to 10 only when the template is 70.
#define EMV_ERR_READAPP_PAN				    0x0343  //RR ���ݼ�飬��ȡIC���п��ų��� Data check�� error in obtaining card number in IC card  

#define EMV_ERR_READAPP_TERM_ON_NEXT_APDU   0x0351  //RR Terminate on Next RA

#define	EMV_ERR_EC_NO9F74				    0x0361  //ָʾEC����EC�����д��벻����  
#define EMV_ERR_EC_BLACKLIST			    0x0362  //Ӧ�����ݼ��ʱ��EC�ں�������  
#define EMV_ERR_EC_lEN9F74                  0x0363  //Ӧ�����ݼ��ʱ��9F74�ĳ��Ȳ�Ϊ6 
#define EMV_ERR_EC_NO9F79                   0x0364  //�����ֽ��У�ȱ��9F79��� 
#define EMV_ERR_EC_NO9F6D					0x0365  //�����ֽ��У�ȱ��9F6D�����ֽ�������ֵ

/**< ��Ӧ�ó�ʼ�����ȡ������־ */
#define PBOC_ERR_READLOG_NO_BF0C            0x0371  // PBOC��ȡ������־����Ȧ����־��û��BF0C���޽�����־��������ֹ  
#define PBOC_ERR_READLOG_NO_9F4D            0x0372  // PBOC��ȡ������־��û��9F4D���޽�����־��������ֹ   
#define PBOC_ERR_READLOG_9F4D_SFI           0x0373  // PBOC��ȡ������־,��ȡ9F4D��SFI��Χ����11��30֮�䣬������ֹ
#define PBOC_ERR_READLOG_9F4F_FORMAT        0x0374  // PBOC��ȡ������־,get 9F4F��ʽ�������׸�ʽ��
#define PBOC_ERR_READLOG_NO_DF4D            0x0375  // PBOC��ȡȦ����־��û��9F4D���޽�����־��������ֹ
#define PBOC_ERR_READLOG_DF4D_SFI           0x0376  // PBOC��ȡȦ����־,��ȡ9F4D��SFI��Χ����11��30֮�䣬������ֹ
#define PBOC_ERR_READLOG_DF4F_FORMAT        0x0377  // PBOC��ȡȦ����־,get 9F4F��ʽ�������׸�ʽ��


/**************************************************************************/
/**<�ѻ���֤����*/
#define EMV_ERR_OFFAUTH					    0x0411  //�ѻ���֤ʧ�ܡ� Offline authentication failed
/**<SDA  */
#define EMV_ERR_OFFAUTH_SDA_FAIL            0x0421 //SDAʧ�ܡ�  SDA failed
#define EMV_ERR_OFFAUTH_SM_SDA_FAIL         0x0422 // SM SDA ʧ�ܡ�   SM SDA failed
/**<DDA  */
#define EMV_ERR_OFFAUTH_DDA_FAIL		    0x0431 // DDAʧ�ܡ� DDA failed
#define EMV_ERR_OFFAUTH_SM_DDA_FAIL         0x0432 // SM DDA ʧ�ܡ� SM DDA failed
/*< CDA*/
#define EMV_ERR_OFFAUTH_CDA_PREFORM_FAIL    0x0441 //CDA��Ԥ����ʧ�ܡ� CDA preprocessing failed
#define EMV_ERR_OFFAUTH_SM_CDA_PREFORM_FAIL 0x0442 // SM CDA��Ԥ����ʧ�ܡ� SM CDA preprocessing failed

#define EMV_ERR_OFFAUTH_CAPK				0x0451 //��ȡCA��Կʧ�ܡ�Failed to obtain the CA public key.
#define EMV_ERR_OFFAUTH_ISPK				0x0452 //�ָ������й�Կʧ�ܡ�Failed to recover the issuer's public key.
#define EMV_ERR_OFFAUTH_ICPK				0x0453 //�ָ�IC����Կʧ�ܡ�Failed to recover the IC card public key.
#define EMV_ERR_OFFAUTH_ISPK_CHECK			0x0454 //�ָ�����֤��̬ǩ�����ݡ�Recover and verify dynamic signature data.
#define EMV_ERR_OFFAUTH_SDATA				0x0455 //�ָ�����֤��̬��֤����ʧ�ܡ�Failed to recover and verify static authentication data.

#define EMV_ERR_OFFAUTH_NO_AID_INDEX		0x0461  //�ѻ���֤�лָ�CAPKʱ��Ƭ��û��AID����CAPK ������There is no AID or CAPK index in the card when restoring CAPK in offline authentication.

#define EMV_ERR_OFFAUTH_GETINFO_FAIL		0x0462  //��ȡ������������Ϣʧ�ܡ�Failed to get card issuer center information.
#define EMV_ERR_OFFAUTH_RECOVE_ISPK			0x0463  //�ָ������й�Կʧ�ܡ�Failed to recover the issuer's public key.  
#define EMV_ERR_OFFAUTH_CHECK				0x0464  //���ָ������еĸ����ȷ��Check that the items in the recovered data are incorrect.
#define EMV_ERR_OFFLINE_CONNECTPK			0x0465  //����Կ��һ����ʽ���ӳ���Error linking public key in a certain format.
#define EMV_ERR_OFFAUTH_SIGNDYNAPPDT		0x0466  //�ڲ���֤��������77����ǩ���Ķ�̬Ӧ�����ݡ� The internal authentication returns data tag77, unsigned dynamic application data
#define EMV_ERR_OFFAUTH_SDA_DATA93          0x0467  //�ָ�����֤��̬��֤����ʱȱ��93�� Tag93 is missing when restoring and verifying static authentication data.
#define EMV_ERR_OFFAUTH_DDA_INTERAUTH		0x0468  //�ڲ���֤�����ʧ�ܡ� The internal authentication command failed.

#define EMV_ERR_OFFAUTH_DDA_INTERAUTH_FORMAT		0x0471 //�ڲ���֤��������ģ���ʽ���ԡ� The format of the internal authentication return data template is incorrect
#define EMV_ERR_OFFAUTH_DDA_INTERAUTH_ANALY			0x0472 //�ڲ���֤�������ݲ��ܽ�����TLV��ʽ�� The internal authentication return data cannot be parsed in TLV format.
#define EMV_ERR_OFFAUTH_DDA_INTERAUTH_DATA80_LEN	0x0473 //�ڲ���֤��������80ģ�����ݳ���Ϊ0�� Internal authentication return data tag80 template data length is 0
#define EMV_ERR_OFFAUTH_DDOL_MIS					0x0474 //�ն˺Ϳ�Ƭͬʱȱ��DDOL��Both the terminal and the card are missing DDOL.
#define EMV_ERR_OFFAUTH_IC_DDOL9F37					0x0475 //��ƬDDOLȱ��9F37��Card DDOL is missing 9F37. 

#define QPBOC_ERR_FDDA_DDOL_MIS9F37         0x0481 //FDDAʱ׼��DDOL��ʱ��ȱ��9F37 
#define QPBOC_ERR_FDDA_DDOL_MIS9F02         0x0482 //FDDAʱ׼��DDOL��ʱ��ȱ��9F02 
#define QPBOC_ERR_FDDA_DDOL_MIS5F2A         0x0483 //FDDAʱ׼��DDOL��ʱ��ȱ��5F2A(���׻��Ҵ���) 
#define QPBOC_ERR_FDDA_DDOL_MIS9F69         0x0484 //FDDAʱ׼��DDOL��ʱ��ȱ��9F69(��Ƭ��֤�������) 
/**<fDDA  */
#define QPBOC_ERR_OFFAUTH_DDA_FAIL		    0x0485 // FDDAʧ�ܡ� DDA failed
#define QPBOC_ERR_OFFAUTH_SM_DDA_FAIL       0x0486 // SM FDDA ʧ�ܡ� SM DDA failed

#define EMV_ERR_GAC_CDA						0x0491  // cdaʧ�ܡ�cda failed. 
#define EMV_ERR_GAC_CDA_ICPK                0x0492  // CDA �ָ�IC����Կʧ�ܡ�Failed to recover IC card public key when CDA
#define EMV_ERR_GAC_CDA_ICPK_LEN            0x0493  // CDAʱIC����Կ���Ȳ���ȷ��IC card public key length is incorrect when CDA 
#define EMV_ERR_GAC_CDA_CERT                0x0494  // CDA֤���ʽ���ʧ�ܡ� Certificate format check failed when CDA 
#define EMV_ERR_GAC_SIGAPPDATA				0x0495  // 9F4B��̬ǩ�����ݻ�ȡʧ�ܡ�Failed to obtain dynamic signature data

#define EMV_ERR_EC_NOBINDLOAD               0x04a1	// �����ֽ��ָ���˻����ѻ���֤�󷵻� 
#define EMV_ERR_ONLY_EC_NOBINDLOAD          0x04a2	// �������ֽ��ָ���˻����ѻ���֤�󷵻� 

/***********************************************************************/
/**<�ֿ�����֤����*/
#define EMV_ERR_CHVERIFY					0x0611  //�ֿ�����֤����  Cardholder verification error.

#define EMV_ERR_CHVERIFY_CVMFOMAT		    0x0621  //CVM�б��ȴ��󣬽�����ֹ�� CVM list length error

/***********************************************************************/
/**<��Ϊ��������*/
#define EMV_ERR_ACT_ANALY_TAA			    0x0811  //��Ϊ�����У�������ֹ��During the ACT ANALY, the transaction was aborted.	 

#define EMV_ERR_ACT_ANALY_GAC               0x0821  //GAC ����ز�Ϊ9000��GAC command returns not 9000
#define EMV_ERR_ACT_GAC_DATA                0x0822  //GAC �������ݸ�ʽ����ȷ��GAC parsing data is malformed
#define EMV_ERR_TAA_CID		                0x0823  //����GAC����CID�ȼ������ն���������AAC��ARQC������TC,������ֹ ����AAC����Ƭ����ARQC��TC,������ֹ ����AAC����Ƭ����ARQC��TC,������ֹ����Parsing GAC data CID level is higher than terminal request
#define EMV_ERR_TAA_NOCID		            0x0824  //GAC����������û��CID��������ֹ��No CID in the returned data when GAC 
#define EMV_ERR_TAA_NOATC		            0x0825  //GAC����������û��ATC��������ֹ��No ATC in return data when GAC 
#define EMV_ERR_PARASE_NO_91                0x0826  //�����������Զ�������ʱû��91��No tag91 when parsing custom data of issuer 
#define EMV_ERR_PARASE_91_LEN               0x0827  //�������Զ�������91 �ĳ��Ȳ���ȷ��tag91 is not the correct length

#define EMV_ERR_GAC_ERR_AC					0x0831	//�������ݻ�ȡʧ�ܡ�The ciphertext data acquisition failed.

#define EMV_ERR_GAC_CID_AAR					0x0841	//CID��ɵ�AAR��ֹ��AAR suspension due to CID


/***********************************************************************/
/**< ��ɴ���*/
#define EMV_ERR_COMPLETE					0x0911 //��ɴ���ʧ�ܡ�Failed to complete processing 

#define EMV_ERR_COMPLETE_ADVICE				0x0921 //�ն�������������ǿ��֪ͨ��������ʧ�ܣ�������ֹ��Terminal requested to connect and forced notification, but failed to connect
#define EMV_ERR_COMPLETE_GAC				0x0922 //�ڶ���GAC���ز�Ϊ9000��The second GAC return is not 9000    
#define EMV_ERR_COMPLETE_EC_NO_SCRIPT       0x0923 //�����ֽ�Ȧ�棬��ѯ�İ���������û�нű��·���������ֹ�� 
#define EMV_ERR_COMPLETE_CID_INTERRUPT      0x0924 //��Ƭ���ķ��ؽ�����ֹ��������ֹ�� CID returned transaction aborted
#define EMV_ERR_COMPLETE_PARASE_GAC			0x0925 //GAC����ʧ�ܡ�GAC parsing failed 


/***********************************************************************/
/**<����*/
#define EMV_ERR_INITHASH	                   0x0a11 //��ϣ�б�δ�ܳ�ʼ����Hash list failed to initialize  
/**<CAPK����*/
#define EMV_ERR_CAPK	                       0x0a21 //CAPK����CAPK error
#define EMV_ERR_CAPK_NOFOUND		           0x0a22 //CAPKû���ҵ���CAPK not found 
#define EMV_ERR_CAPK_VERIFY		               0x0a23 //CAPK��֤����CAPK verification error 
#define EMV_ERR_CAPK_EXPIRE		               0x0a24 //CAPKʧЧ��CAPK is invalid
#define EMV_ERR_CAPK_RECOVER		           0x0a25 //CAPK�ڻ��չ�Կ��

/**<AID����*/
#define EMV_ERR_AID		                       0x0a31 //AID����AID error
#define EMV_ERR_AID_GETLIST		               0x0a32 //��ȡAID�ļ���AIDΪ�ա�Read AID file, AID is empty
#define EMV_ERR_AID_SPARAERR		           0x0a33 //��ȡAIDʱAID��������AID parameter error while getting AID
#define EMV_ERR_AID_GPARAERR		           0x0a34 //����AIDʱAID��������AID parameter error when adding AID
#define EMV_ERR_AID_MAXNUM		               0x0a35 //AID�����������AID exceeds the maximum number

/**<ICS����*/
#define EMV_ERR_ICS		                       0x0a41 //ICS����ICS error
#define EMV_ERR_ICS_READ			           0x0a42 //ICS��ȡ����������ֹ��ICS read error

/**<IC����������*/
#define ERR_SWITCH_INTERFACE		           0x0a51  //ת���档Go to other interface
#define EMV_ERR_ICCOP_L1_ERR				   0x0a52  //APDUδ�յ����ء�APDU not returned
#define EMV_ERR_ICCOP_POWERUP		           0x0a53  //IC���ϵ����IC card power on error
#define EMV_ERR_ICCOP_POWERDOWN	               0x0a54  //IC���µ����IC card power off error

/**< ������ʾ�����*/
#define EMV_ERR_PAN_QUIT                       0x0a61	// ��ʾPANȷ��ʱ���û�ѡ��ȡ����When prompted for PAN confirmation, the user chooses to cancel   
#define EMV_ERR_AMT_QUIT                       0x0a62	// ��ʾ���뽻�׽��ʱ���û�ѡ��ȡ���� When prompted to enter the transaction amount, the user chooses to cancel  

#define PAYPASS_ERR_CCC_CHECK				   0x0a71	// PAYPASS CCC ��������PAYPASS CCC parsing error
#define PAYPASS_ERR_RRP_CHECK				   0x0a72	// PAYPASS RRP ��������PAYPASS RRP parsing error

#define VISA_ERR_SWITCH				           0x0C //VISAת����
#define EMV_ERR_ICCOP						   VISA_ERR_SWITCH


/***********************************************************************/


#endif
