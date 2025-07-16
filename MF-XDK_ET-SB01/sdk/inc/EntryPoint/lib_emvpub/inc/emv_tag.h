#ifndef _EMV_TAG_
#define _EMV_TAG_

/*
* ��ƬICC����Ԫ��ǩ
*/
#define   EMV_TAG_9F26_IC_AC 				"\x9F\x26"		/**<  0 - Ӧ������(Application Cryptogram)*/
#define   EMV_TAG_9F42_IC_APPCURCODE 		"\x9F\x42"		/**<  1 - Ӧ�û��Ҵ���(Application Currency Code)*/
#define   EMV_TAG_9F44_IC_APPCUREXP		"\x9F\x44"		/**<  2 - Ӧ�û���ָ��(Application Currency Exponent)*/
#define   EMV_TAG_9F05_IC_APPDISCDATA		"\x9F\x05"		/**<  3 - Ӧ���Զ�������(Application Discretionary Data)*/
#define   EMV_TAG_5F25_IC_APPEFFECTDATE	"\x5F\x25"		/**<  4 - Ӧ����Ч����(Application Effective Date)YYMMDD*/
#define   EMV_TAG_5F24_IC_APPEXPIREDATE	"\x5F\x24"		/**<  5 - Ӧ��ʧЧ����(Application Expiration Date)YYMMDD*/
#define   EMV_TAG_94_IC_AFL					"\x94"			/**<  6 - Ӧ���ļ���λ��AFL(Application File Locator)	*/
#define   EMV_TAG_4F_IC_AID					"\x4F"			/**<  7 - Ӧ�ñ�ʶ��AID(Application Identifier) */
#define   EMV_TAG_82_IC_AIP					"\x82"			/**<  8 - Ӧ�ý�������AIP(Application Interchange Profile) */
#define   EMV_TAG_50_IC_APPLABEL			"\x50"			/**<  9 - Ӧ�ñ�ǩ(Application Label) */
#define   EMV_TAG_9F12_IC_APNAME 			"\x9F\x12"		/**< 10 - Ӧ����ѡ����(Application Preferred Name) */
#define   EMV_TAG_5A_IC_PAN				"\x5A"			/**< 11 - Ӧ�����ʺ�PAN(Application Primary Account Number) */
#define   EMV_TAG_5F34_IC_PANSN			"\x5F\x34"		/**< 12 - Ӧ�����ʺ����PAN_Sn(Application Primary Account Number Sequence Number) */
#define   EMV_TAG_87_IC_APID				"\x87"			/**< 13 - Ӧ�����ȱ�ʶ��(Application Priority Indicator)*/
#define   EMV_TAG_9F3B_IC_APCUR			"\x9F\x3B"		/**< 14 - Ӧ����ѡ����(Application Preference Currency)*/
#define   EMV_TAG_9F43_IC_APCUREXP		"\x9F\x43"		/**< 15 - Ӧ����ѡ����ָ��(Application Preferece Currency Exponent)*/
#define   EMV_TAG_61_IC_APPTEMP			"\x61"			/**< 16 - Ӧ��ģ��(Application Template)*/
#define   EMV_TAG_9F36_IC_ATC				"\x9F\x36"		/**< 17 - Ӧ�ý��׼�����ATC(Application Transaction Counter)*/
#define   EMV_TAG_9F07_IC_AUC				"\x9F\x07"		/**< 18 - Ӧ����;����AUC(Application Usage Control)*/
#define   EMV_TAG_9F08_IC_APPVERNO		"\x9F\x08"		/**< 19 - Ӧ�ð汾��(Application Version Number)*/
#define	  EMV_TAG_5F54_IC_BIC				"\x5F\x54"		/**<  - �����б�ʶ��(Bank Identifier Code (BIC))*/
#define   EMV_TAG_8C_IC_CDOL1				"\x8C"			/**< 20 - ��Ƭ���չ������ݶ����б�1CDOL1(Card Risk Management Data Object List 1)*/
#define   EMV_TAG_8D_IC_CDOL2				"\x8D"			/**< 21 - ��Ƭ���չ������ݶ����б�2CDOL2(Card Risk Management Data Object List 2)*/
#define   EMV_TAG_5F20_IC_HOLDERNAME 		"\x5F\x20"		/**< 22 - �ֿ�������(Cardholder Name)*/
#define   EMV_TAG_9F0B_IC_HOLDERNAMEEX 	"\x9F\x0B"		/**< 23 - �ֿ�����չ����(Cardholder Name Extended)*/
#define   EMV_TAG_8E_IC_CVMLIST			"\x8E"			/**< 24 - �ֿ�����֤�����б�(Cardholder Verification Method List)*/
#define   EMV_TAG_8F_IC_CAPKINDEX			"\x8F"			/**< 25 - ��֤���Ĺ�Կ����(Certification Authority Public Key Index)*/
#define   EMV_TAG_9F27_IC_CID				"\x9F\x27"		/**< 26 - ������Ϣ����CID(Cryptogram Infomation Data)*/
#define   EMV_TAG_9F45_IC_DTAUTHCODE 		"\x9F\x45"		/**< 27 - ������֤��(Data Authentication Code)*/
#define   EMV_TAG_84_IC_DFNAME 			"\x84"			/**< 28 - DF����(Dedicated File Name)*/
#define   EMV_TAG_9D_IC_DDFNAME			"\x9D"			/**< 29 - Ŀ¼�����ļ�DDF����(Directory Definition File)*/
#define   EMV_TAG_73_IC_DIRDISCTEMP		"\x73"			/**< 30 - Ŀ¼�Զ���ģ��(Directory Discretionary Template)*/
#define   EMV_TAG_9F49_IC_DDOL				"\x9F\x49"		/**< 31 - ��̬������֤���ݶ����б�DDOL(Dynamic Data Authentication Data Object List)*/
#define   EMV_TAG_BF0C_IC_FCIDISCDATA		"\xBF\x0C"		/**< 32 - FCI�������Զ�������(File Control Information Issuer Discretionary Data)*/
#define   EMV_TAG_A5_IC_FCIPROPTEMP		"\xA5"			/**< 33 - FCIר��ģ��(File Control Information Proprietary Template)*/
#define   EMV_TAG_6F_IC_FCITEMP			"\x6F"			/**< 34 - FCIģ��(File Control Information Template)*/
#define   EMV_TAG_9F4C_IC_ICCDYNNUM		"\x9F\x4C"		/**< 35 - IC����̬��(ICC Dynamic Number)*/
#define   EMV_TAG_9F2D_IC_PECERT 			"\x9F\x2D"		/**< 36 - IC��PIN���ܹ�Կ֤��(ICC PIN Encipherment Public Key Certificate)*/
#define   EMV_TAG_9F2E_IC_PEEXP			"\x9F\x2E"		/**< 37 - IC��PIN���ܹ�Կָ��(ICC PIN Encipherment Public Key Exponent)*/
#define   EMV_TAG_9F2F_IC_PERMD			"\x9F\x2F"		/**< 38 - IC��PIN���ܹ�Կ����(ICC PIN Encipherment Public Key Remainder)*/
#define   EMV_TAG_9F46_IC_ICCPKCERT		"\x9F\x46"		/**< 39 - IC����Կ֤��(ICC Public Key Certificate)*/
#define   EMV_TAG_9F47_IC_ICCPKEXP			"\x9F\x47"		/**< 40 - IC����Կָ��(ICC Public Key Exponent)*/
#define   EMV_TAG_9F48_IC_ICCPKRMD			"\x9F\x48"		/**< 41 - IC����Կ����(ICC Public Key Remainder)*/
#define   EMV_TAG_5F53_IC_IBAN				"\x5F\x53"		/**<  - ���������˻���(International Bank Account Number (IBAN) )*/
#define   EMV_TAG_9F0D_IC_IAC_DEFAULT		"\x9F\x0D"		/**< 42 - ��������Ϊ����-ȱʡ(Issuer Action Code-Default)*/
#define   EMV_TAG_9F0E_IC_IAC_DENIAL 		"\x9F\x0E"		/**< 43 - ��������Ϊ����-�ܾ�(Issuer Action Code-Denial)*/
#define   EMV_TAG_9F0F_IC_IAC_ONLINE 		"\x9F\x0F"		/**< 44 - ��������Ϊ����-����(Issuer Action Code-Online)*/
#define   EMV_TAG_9F10_IC_ISSAPPDATA 		"\x9F\x10"		/**< 45 - ������Ӧ������(Issuer Application Data)*/
#define   EMV_TAG_9F11_IC_ISSCTINDEX 		"\x9F\x11"		/**< 46 - �����д��������(Issuer Code Table Index)*/
#define   EMV_TAG_5F28_IC_ISSCOUNTRYCODE "\x5F\x28"		/**< 47 - �����й��Ҵ���(Issuer Country Code)*/
#define	EMV_TAG_5F55_IC_ALPHA2 			"\x5F\X55"		/**<  - �ն˹��Ҵ���(Issuer Country Code (alpha2 format) )*/
#define	EMV_TAG_5F56_IC_ALPHA3			"\x5F\X56"		/**<  - �ն˹��Ҵ���(Issuer Country Code (alpha3 format)  )*/
#define 	EMV_TAG_42_IC_IIN					"\x42"			/**<  - ��������֤����(Issuer Identification Number (IIN)  )*/
#define   EMV_TAG_90_IC_ISSPKCERT			"\x90"			/**< 48 - �����й�Կ֤��(Issuer Public Key Certificate)*/
#define   EMV_TAG_9F32_IC_ISSPKEXP			"\x9F\x32"		/**< 49 - �����й�Կָ��(Issuer Public Key Exponent)*/
#define   EMV_TAG_92_IC_ISSPKRMD			"\x92"			/**< 50 - �����й�Կ����(Issuer Public Key Remainder)*/
#define   EMV_TAG_5F50_IC_ISSURL 			"\x5F\x50"		/**< 51 - ������URL(Issuer URL)*/
#define   EMV_TAG_5F2D_IC_LANGPREF		"\x5F\x2D"		/**< 52 - ��ѡ����(Language Preference)*/
#define   EMV_TAG_9F13_IC_LASTATC			"\x9F\x13"		/**< 53 - �ϴ�����ATC�Ĵ���(Last Online Application Transaction Counter Register)*/
#define   EMV_TAG_9F14_IC_LCOL				"\x9F\x14"		/**< 54 - �����ѻ���������(Lower Consecutive Offline Limit)*/
#define   EMV_TAG_9F17_IC_PINTRYCNTR 		"\x9F\x17"		/**< 55 - PIN���Լ�����(Personal Identification Number Try Counter)*/
#define   EMV_TAG_9F38_IC_PDOL				"\x9F\x38"		/**< 56 - ����ѡ�����ݶ����б�PDOL(Processing Options Data Object List)*/
#define   EMV_TAG_80_IC_RMTF1				"\x80"			/**< 57 - ��Ӧ��Ϣģ���ʽ1(Response Message Template Format 1)*/
#define   EMV_TAG_77_IC_RMTF2				"\x77"			/**< 58 - ��Ӧ��Ϣģ���ʽ2(Response Message Template Format 2)*/
#define   EMV_TAG_5F30_IC_SERVICECODE		"\x5F\x30"		/**< 59 - ������(Service Code)*/
#define   EMV_TAG_88_IC_SFI					"\x88"			/**< 60 - ���ļ���ʶ��SFI(Short File Indicator)*/
#define   EMV_TAG_9F4B_IC_SIGNDYNAPPDT	"\x9F\x4B"		/**< 61 - ǩ���Ķ�̬Ӧ������(Signed Dynamic Application Data)*/
#define   EMV_TAG_93_IC_SIGNSTAAPPDT		"\x93"			/**< 62 - ǩ���ľ�̬Ӧ������(Signed Static Application Data)*/
#define   EMV_TAG_9F4A_IC_SDATAGLIST 		"\x9F\x4A"		/**< 63 - ��̬������֤��ǩ�б�(Static Data Authentication Tag List)*/
#define   EMV_TAG_9F1F_IC_TRACK1DATA 		"\x9F\x1F"		/**< 64 - 1�ŵ��Զ�������(Track 1 Discretionary Data)*/
#define   EMV_TAG_9F20_IC_TRACK2DATA 		"\x9F\x20"		/**< 65 - 2�ŵ��Զ�������(Track 2 Discretionary Data)*/
#define   EMV_TAG_57_IC_TRACK2EQUDATA	"\x57"			/**< 66 - 2�ŵ���Ч����(Track 2 Equivalent Data)*/
#define   EMV_TAG_97_IC_TDOL				"\x97"			/**< 67 - ����֤�����ݶ����б�TDOL(Transaction Certificate Data Object List)*/
#define   EMV_TAG_9F23_IC_UCOL				"\x9F\x23"		/**< 68 - �����ѻ���������(Upper Consecutive Offline Limit)	*/
#define	EMV_TAG_70_TEMP					"\x70"			/**< 69 - ��������ģ��70	*/
#define	EMV_TAG_9F61_IC_CERTNO			"\x9F\x61"		/**< 70 - ֤����*/
#define	EMV_TAG_9F62_IC_CERTTYPE			"\x9F\x62"		/**< 71 - ֤������*/	
#define 	EMV_TAG_9F4D_IC_PBOCLOG			"\x9F\x4D"		/**< 72 - PBOC LOG*/
#define	EMV_TAG_9F4F_IC_PBOCLOGFORMAT	"\x9F\x4F"		/**< 73 - PBOC LOG��ʽ*/
#define EMV_TAG_DF4D_IC_UPLOAD_FORMAT "\xDF\x4D"  /**<  Ȧ��Ľ�����־��ʽ*/

#define EMV_TAG_9F69_IC_CERTIFCATION_DATA        "\x9F\x69"  /**< ��Ƭ��֤�������*/
#define EMV_TAG_9F63_IC_IDENTIFY_INFOR           "\x9F\x63"  /**< ��Ƭ��ʶ��Ϣ ***/

#define   EMV_TAG_9F24_IC_PAR				"\x9F\x24"		/**< PAR �����˻��ο��ţ�	*/
#define   EMV_TAG_9F19_IC_TOKEN				"\x9F\x19"		/**< Token Data Object��	*/
#define   EMV_TAG_DF61_IC_ODA				"\xDF\x61"		/**< ��Ƭ��ֵ���� ����ָʾODA	*/
#define   EMV_TAG_9F7C_IC_PAR				"\x9F\x7c"		/**< �û�ר������	*/
#define   EMV_TAG_9F25_IC_PAR				"\x9F\x25"		/**< �û�ר������	*/

/*
* �ն�TERM����Ԫ��ǩ
*/
#define   EMV_TAG_9F01_TM_ACQID			"\x9F\x01"	  /**< 0 - �յ��б�ʶ��(Acquirer Identifier)*/
#define   EMV_TAG_9F40_TM_CAP_AD 		  	"\x9F\x40"	  /**< 1 - �����ն�����(Additional Terminal Capability)*/
#define   EMV_TAG_81_TM_AUTHAMNTB	   	"\x81"		  /**< 2 - ��Ȩ���|������(Amount,Authorised<Binary>)*/
#define   EMV_TAG_9F02_TM_AUTHAMNTN	   	"\x9F\x02"	  /**< 3 - ��Ȩ���|����(Amount,Authorised<Binary>)*/
#define   EMV_TAG_9F04_TM_OTHERAMNTB 	"\x9F\x04"	  /**< 4 - �������|������(Amount,Other<Binary>)*/
#define   EMV_TAG_9F03_TM_OTHERAMNTN 	"\x9F\x03"	  /**< 5 - �������|����(Amount,Other<Numeric>)*/
#define   EMV_TAG_9F3A_TM_REFCURAMNT 	"\x9F\x3A"	  /**< 6 - �ο����ҽ��(Amount,Reference Currency)*/
#define   EMV_TAG_9F06_TM_AID			  	"\x9F\x06"	  /**< 7 - �ն�AID(Terminal Application Identifier)*/
#define   EMV_TAG_9F09_TM_APPVERNO		"\x9F\x09"	  /**< 8 - �ն�Ӧ�ð汾��(Terminal Application Version Number)*/
#define	  EMV_TAG_5F57_TM_ACCOUNTTYPE	"\x5F\x57"	  /**< 9- �˻�����(Account Type)*/
#define   EMV_TAG_8A_TM_ARC			   	"\x8A"		  /**< 10 - ��Ȩ��Ӧ��ARC(Authorisation Response Code)*/
#define   EMV_TAG_9F34_TM_CVMRESULT	   	"\x9F\x34"	  /**< 11 - �ֿ�����֤�������(Cardholder Verification Method Results)*/
#define   EMV_TAG_9F22_TM_CAPKINDEX		"\x9F\x22"	  /**< 12 - �ն�CA��Կ����(Terminal Certification Authority Public Key Index)*/
#define   EMV_TAG_9F1E_TM_IFDSN			"\x9F\x1E"	  /**< 13 - IFD���к�(Interface Device Serial Number)*/
#define	  EMV_TAG_83_TM_COMTEM			"\x83"		   /**<14- ����ģ��(Command Template )*/
#define   EMV_TAG_86_TM_ISSSCRCMD		   	"\x86"		  /**< 15 - �����нű�����(Issuer Script Command)*/
#define   EMV_TAG_9F18_TM_ISSSCRID		   	"\x9F\x18"	  /**< 16 - �����нű���ʶ��(Issuer Script Identifier)*/
#define   EMV_TAG_9F15_TM_MCHCATCODE 	"\x9F\x15"	  /**< 17 - �̻�������(Merchant Category Code)*/
#define   EMV_TAG_9F16_TM_MCHID			"\x9F\x16"	  /**< 18 - �̻���ʶ��(Merchant Identifier)*/
#define   EMV_TAG_9F39_TM_POSENTMODE 	"\x9F\x39"	  /**< 19 - POS����ģʽ(Point-of-Service Entry Mode)*/ //�Ƽ����������ף�02�Ӵ�ʽ����ǣ�05qPBOC��07�ǽӴ�����ǣ�98
#define   EMV_TAG_9F33_TM_CAP			   	"\x9F\x33"	  /**< 20 - �ն�����(Terminal Capabilities)*/
#define   EMV_TAG_9F1A_TM_CNTRYCODE	   	"\x9F\x1A"	  /**< 21 - �ն˹��Ҵ���(Terminal Country Code)*/
#define   EMV_TAG_9F1B_TM_FLOORLMT		"\x9F\x1B"	  /**< 22 - �ն��޶�(Terminal Floor Limit)*/
#define   EMV_TAG_9F1C_TM_TERMID 		   	"\x9F\x1C"	  /**< 23 - �ն˱�ʶ��(Terminal Identification)*/
#define   EMV_TAG_9F1D_TM_RMDATA 		   	"\x9F\x1D"	  /**< 24 - �ն˷��չ�������(Terminal Risk Management Data)*/
#define   EMV_TAG_9F35_TM_TERMTYPE		"\x9F\x35"	  /**< 25 - �ն�����(Terminal Type)*/
#define   EMV_TAG_95_TM_TVR			   	"\x95"		  /**< 26 - �ն���֤���TVR(Terminal Verification Result)*/
#define   EMV_TAG_98_TM_TCHASH 		   	"\x98"		  /**< 27 - ����֤���ϣֵ(Transaction Certificate Hash Value)*/
#define   EMV_TAG_5F2A_TM_CURCODE		   	"\x5F\x2A"	  /**< 28 - ���׻��Ҵ���(Transaction Currency Code)*/
#define   EMV_TAG_5F36_TM_CUREXP 		   	"\x5F\x36"	  /**< 29 - ���׻���ָ��(Transaction Currency Exponent)*/
#define   EMV_TAG_9A_TM_TRANSDATE	   		"\x9A"		  /**< 30 - ��������(Transaction Date)*/
#define   EMV_TAG_99_TM_PINDATA		   	"\x99"		  /**< 31 - PIN����(Transaction Personal Identification Number Data)*/
#define   EMV_TAG_9F3C_TM_REFCURCODE 	   	"\x9F\x3C"	  /**< 32 - ���ײο����Ҵ���(Transaction Reference Currency Code)*/
#define   EMV_TAG_9F3D_TM_REFCUREXP		"\x9F\x3D"	  /**< 33 - ���ײο�����ָ��(Transaction Reference Currency Exponent)*/
#define   EMV_TAG_9F41_TM_TRSEQCNTR	   	"\x9F\x41"	  /**< 34 - �������м�����(Transcation Sequence Counter)*/
#define   EMV_TAG_9B_TM_TSI			   	"\x9B"		  /**< 35 - ����״̬��ϢTSI(Transaction Status Information)*/
#define   EMV_TAG_9F21_TM_TRANSTIME	   	"\x9F\x21"	  /**< 36 - ����ʱ��(Transaction Time)*/
#define   EMV_TAG_9C_TM_TRANSTYPE	   		"\x9C"		  /**< 37 - ��������(Transaction Type)*/
#define   EMV_TAG_9F37_TM_UNPNUM 		   	"\x9F\x37"	  /**< 38 -  ����Ԥ֪��(Unpredictable Number) */
#define		EMV_TAG_9F4E_TM_NAMELOC			"\x9F\x4E"	  /**< 39- �̻����Ƶ�ַ*/

/**<����������*/
#define   EMV_TAG_89_TM_AUTHCODE		"\x89"		  /**< ��Ȩ��(Authorization Code)*/
#define   EMV_TAG_91_TM_ISSAUTHDT	   	"\x91"		  /**<  ��������֤����(Issuer Authentication Data)*/
#define   EMV_TAG_71_ISS_RMTF			"\x71"		   /**< �����нű�����71ģ��*/
#define   EMV_TAG_72_ISS_RMTF			"\x72"		   /**< �����нű�����72ģ��*/
#define   EMV_TAG_71_ISS_SCRIPT		0x3F		   /**< �����нű�����71ģ��*/
#define   EMV_TAG_72_ISS_SCRIPT		0x7F		   /**< �����нű�����72ģ��*/

/**<����Ϊ����AID��������*/
#define	EMV_TAG_DF01_TM_ASI				"\xDF\x01"	  /**< 1 - Ӧ��ѡ��ָʾ��,	ָ���ն��Ƿ�֧��AID����ƥ�䷽ʽ*/
#define	EMV_TAG_DF11_TM_DEFAULTTAC		"\xDF\x11"	  /**< 2 - �ն���Ϊ���룭Ĭ��*/
#define	EMV_TAG_DF12_TM_ONLINETAC		"\xDF\x12"	  /**< 3 - �ն���Ϊ���룭����*/
#define	EMV_TAG_DF13_TM_REFUSETAC		"\xDF\x13"	  /**< 4 - �ն���Ϊ���룭�ܾ�*/
#define	EMV_TAG_DF14_TM_DDOL			"\xDF\x14"	  /**< 5 - ȱʡ��̬������֤���ݶ����б�(�䳤)*/
#define	EMV_TAG_DF15_TM_RANHOLD			"\xDF\x15"	  /**< 6 - ƫ�����ѡ�����ֵ*/
#define	EMV_TAG_DF16_TM_RANMAXPER		"\xDF\x16"	  /**< 7 - ƫ�����ѡ������Ŀ��ٷ���*/
#define	EMV_TAG_DF17_TM_RANTARPER		"\xDF\x17"	  /**< 8 - ���ѡ���Ŀ��ٷ���*/
#define	EMV_TAG_DF18_TM_ONLINEPINCAP	"\xDF\x18"       /**< 9 - �ն�����PIN����*/
#define	EMV_TAG_DF02_TM_CAPKMOD		"\xDF\x02"	  /**< 9 - (CAPK)��֤����ģ*/
#define	EMV_TAG_DF03_TM_CAPKCHECKSUM	"\xDF\x03"	  /**< 10 - ��֤���Ĺ�ԿУ���*/	
#define	EMV_TAG_DF04_TM_CAPKEXPONENT	"\xDF\x04"	  /**< 11 - ��֤���Ĺ�Կָ��*/
#define	EMV_TAG_DF05_TM_CAPKEXPIRE		"\xDF\x05"	  /**< 12 - ��֤���Ĺ�Կ��Ч��*/
#define	EMV_TAG_DF06_TM_CAPKHASHFLAG	"\xDF\x06"	  /**< 13 - ��֤���Ĺ�Կ��ϣ�㷨��ʶ*/
#define	EMV_TAG_DF07_TM_CAPKALGORITHM	"\xDF\x07"	  /**< 14 - ��֤���Ĺ�Կ�㷨��ʶ*/
#define	EMV_TAG_DF08_TM_CAINDEX			"\xDF\x08"	  /**< 14 - ��֤���Ĺ�Կ���к� ��֤��*/
#define EMV_TAG_DF31_IC_IISSCRIRES		"\xDF\x31"	  /**< 15 - �������ű����(Issuer Script Results)EMV��PBOC��*/
#define EMV_TAG_9F5B_IC_IISSCRIRES		"\x9F\x5B"	  /**< 15 - �������ű����(Issuer Script Results)	*/
#define EMV_TAG_DF69_TM_SM				"\xDF\x69"		/**< 16 - SM�㷨֧��ָʾ��*/
#define EMV_TAG_9F63_TM_BIN				"\x9F\x63"		/**< */
#endif


/**<�Զ����ǩ*/
#define	EMV_TAG_B0_TM_PDOL				"\xB0"		   /**<PDOL*/
#define	EMV_TAG_B1_TM_DDOL1				"\xB1"		   /**<DDOL1*/
#define	EMV_TAG_B2_TM_DDOL2				"\xB2"		   /**<DDOL2*/
#define	EMV_TAG_B3_TM_DTDOL				"\xB3"		   /**<�ն�ȱʡTDOL*/
#define	EMV_TAG_B4_TM_ISSPK				"\xB4"		   /**<�����й�Կ*/
#define	EMV_TAG_B8_TM_DYNAMICSIG		"\xB8"		   /**<��̬ǩ����֤����*/
#define	EMV_TAG_B9_TM_AUTHDATA			"\xB9"		   /**<��̬��֤����*/
#define	EMV_TAG_BD_TM_ONLINEPIN			"\xBD"		   /**<������������*/
#define	EMV_TAG_99_TM_ONLINEPIN			"\x99"		   /**<������������ ���ڼ�������Զ������Թ��߶���*/
#define	EMV_TAG_BE_MSD_TRACK2			"\xBE"		   /**< MSD���ŵ�����*/
#define	EMV_TAG_BF_IC_TRACK2_EXPIRY		"\xBA"		   /**< ���ŵ���Ч��*/
#define	EMV_TAG_BC_MSD_TEC				"\xBC"		   /**<Terminal Entry Capability*/
#define	EMV_TAG_BB_IC_PK					"\xBB"		   /**<IC����Կ*/
#define 	EMV_TAG_C5_IC_CTTA				"\xC5"		   /*�ۼƽ����ܽ��*/
#define 	EMV_TAG_C6_IC_CTTAL				"\xC6"		   /*�ۼƽ����ܽ������*/
#define 	EMV_TAG_C1_MSD_TRACK1				"\xC1"		   /*MSDһ�ŵ�����*/
/**< �����ֽ� EC ֧��˫���ֿ�Ƭ����*/
#define	EMV_TAG_DF79_IC_DOUBLE_CUR_EC_BALANCE				"\xDF\x79"	/**< �����ֽ���EC Balance��*/
#define	EMV_TAG_DF77_IC_DOUBLE_CUR_EC_BALANCELIMIT			"\xDF\x77"	/**< �����ֽ�������ޣ�EC Balance Limit��*/
#define	EMV_TAG_DF78_IC_DOUBLE_CUR_EC_STL					"\xDF\x78"	/**< �����ֽ𵥱ʽ����޶EC Single Transaction Limit��*/
#define	EMV_TAG_DF76_IC_DOUBLE_CUR_EC_RESETTHRESHOLD		"\xDF\x76"	/**< �����ֽ�������ֵ��EC Reset Threshold��*/
#define EMV_TAG_DF71_IC_DOUBLE_CUR_EC_CURCODE               "\xDF\x71"	/**< �����ֽ���Ҵ��루EC Cur Code��*/
/**< �����ֽ� EC��Ƭ����*/
#define	EMV_TAG_9F79_IC_EC_BALANCE				"\x9F\x79"	/**< �����ֽ���EC Balance��*/
#define	EMV_TAG_9F77_IC_EC_BALANCELIMIT			"\x9F\x77"	/**< �����ֽ�������ޣ�EC Balance Limit��*/
#define	EMV_TAG_9F74_IC_EC_IAC					"\x9F\x74"	/**< �����ֽ𷢿�����Ȩ�루EC Issuer Authorization Code��*/
#define	EMV_TAG_9F78_IC_EC_STL					"\x9F\x78"	/**< �����ֽ𵥱ʽ����޶EC Single Transaction Limit��*/
#define	EMV_TAG_9F6D_IC_EC_RESETTHRESHOLD		"\x9F\x6D"	/**< �����ֽ�������ֵ��EC Reset Threshold��*/
#define EMV_TAG_9F51_IC_EC_CURCODE               "\x9F\x51"  /**< �����ֽ���Ҵ���**/
/**< �����ֽ� EC�ն�����*/
#define	EMV_TAG_9F7A_TM_EC_TSI					"\x9F\x7A"	/**< �����ֽ��ն�֧��ָʾ����EC Terminal Support Indicator��*/
#define	EMV_TAG_9F7B_TM_EC_TTL					"\x9F\x7B"	/**< �����ֽ��ն˽����޶EC Terminal Transaction Limit��*/

#define EMV_TAG_DF4F_UPLOAD_FORMAT              "\xDF\x4F" /**< Ȧ�潻�׵����ڸ�ʽ*/
#define  EMV_TAG_DF79_UPLOAG_BALANCE             "\xDF\x79" /**< Ȧ�潻����־�Ľ��**/
/**< �ǽӴ��ն�����*/
#define EMV_TAG_9F66_TM_RF_TRANSPROP			"\x9F\x66"	/**< �ն˽�������*/
#define EMV_TAG_DF20_TM_RF_LIMIT					"\xDF\x20"	/**< �ǽӴ��ն˽����޶�*/
#define EMV_TAG_DF19_TM_RF_OFFLINELIMIT				"\xDF\x19"	/**< �ǽӴ��ն��ѻ������޶�*/
#define EMV_TAG_9F5D_IC_RF_BALANCE				"\x9F\x5D"	/**< �ѻ��������*/
#define EMV_TAG_9F6C_IC_RF_TRANSPROP				"\x9F\x6C"	/**< ��Ƭ��������*/
#define EMV_TAG_DF21_TM_CVMLIMIT					"\xDF\x21"	/**< �ն�ִ��CVM�޶�*/

#define BCTC_TAG_DF8107_TRACK2					"\xDF\x81\x07"//�Զ������Թ��� ���ŵ�����
#define BCTC_TAG_DF8105_CERTRS					"\xDF\x81\x05"//�Զ������Թ��� ֤�����к�
#define BCTC_TAG_DF8104_CAPTURE					"\xDF\x81\x04"//�Զ������Թ��� 00 ��ʾbatch data capture �� 01 ��ʾonline data capture��
#define BCTC_TAG_DF8101_TRCC					"\xDF\x81\x01"//�Զ������Թ��� Transaction Reference Currency Conversion(n8)
#define BCTC_TAG_DF8102_TDOL					"\xDF\x81\x02"//�Զ������Թ��� default TDOL
#define BCTC_TAG_DF8106_TIMEOUT					"\xDF\x81\x06"//�Զ������Թ��� 0 ��ʾ���н��ף�FF ��ʾ�˳�����������ʾ�ȴ���Ӧʱ�䣨��λ���룩������ٴη��ͽ�����������
#define BCTC_TAG_DF8103_LOADTYPE				"\xDF\x81\x03"//�Զ������Թ��� ���ز���ָʾλ����ѡ���֣�B8-B6��RFU B5��ɾ�����н�����־ B4�����չ�Կ B3�������� B2��AID B1��CAPK
#define BCTC_TAG_DFC10B_EFFECT	 				"\xDF\xC1\x0B"//�Զ������Թ��� ���ڱ�ʾִ��ODA ���

//EMV_Entry_Point
#define EMV_TAG_9F2A_IC_KERN_ID				"\x9F\x2A"		// Kernel Identifier 
#define	EMV_TAG_9F0A_IC_ASRPD				"\x9F\x0A"		//Application Selection Registered Proprietary Data
#define	EMV_TAG_9F29_IC_EXSEL				"\x9F\x29"		//Extended Selection
//MASTER��ǩ----IC������Ԫ
#define   M_TAG_56_IC_TRACK1			"\x56"				// TRACK1
#define	  M_TAG_9F24_IC_PAR					"\x9F\x24"		//Payment Account Reference 
#define   M_TAG_9F50_IC_ACCUBAL				"\x9F\x50"		// Offline Accumulator Balance �ѻ��ۻ����ѽ��
#define   M_TAG_9F51_IC_DRDOL				"\x9F\x51"		// DRDOL �C ����RECOVER AC����
#define   M_TAG_9F54_IC_DS_ODS_Card			"\x9F\x54"		// DS ODS Card
#define   M_TAG_9F5B_IC_DSDOL				"\x9F\x5B"		// DSDOL �C ����GAC����
#define   M_TAG_9F5D_IC_APP_CAPA_INFO		"\x9F\x5D"		// Application Capabilities Information Ӧ��������Ϣ
#define	  M_TAG_9F5E_IC_DS_ID				"\x9F\x5E"		// DS ID
#define	  M_TAG_9F5F_IC_DS_SLOT_AVAILABILITY	"\x9F\x5F"		// DS Slot Availability 
#define   M_TAG_9F60_IC_CVC3_TRACK1			"\x9F\x60"      // CVC3-TRACK1
#define   M_TAG_9F61_IC_CVC3_TRACK2			"\x9F\x61"      // CVC3-TRACK2
#define   M_TAG_9F62_IC_PCVC3_TRACK1			"\x9F\x62"      // PCVC3-TRACK1
#define   M_TAG_9F63_IC_PUNATC_TRACK1		"\x9F\x63"      // PUNATC-TRACK1
#define   M_TAG_9F64_IC_NATC_TRACK1			"\x9F\x64"      // NATC-TRACK1
#define   M_TAG_9F65_IC_PCVC3_TRACK2			"\x9F\x65"      // PCVC3-TRACK2
#define   M_TAG_9F66_IC_PUNATC_TRACK2		"\x9F\x66"      // PUNATC-TRACK2
#define   M_TAG_9F67_IC_NATC_TRACK2			"\x9F\x67"      // NATC-TRACK2
#define   M_TAG_9F69_IC_UDOL					"\x9F\x69"      // UDOL
#define   M_TAG_9F6B_IC_TRACK2				"\x9F\x6B"      // Track 2 Data
#define   M_TAG_9F6D_IC_APPVERNO_MAG			"\x9F\x6D"      // Mag-stripe Application Version Number (Reader)
#define   M_TAG_IC_THIRDPARTY				"\x9F\x6E"      // PayPass Third Party Data   
#define   M_TAG_9F6F_IC_DS_SLOT_MANAGE_CONTROL	"\x9F\x6F"	// DS Slot Management Control
#define	  M_TAG_9F70_IC_PROTECTED_DATA_1		"\x9F\x70"		// Protected Data Envelope 1 
#define	  M_TAG_9F71_IC_PROTECTED_DATA_2		"\x9F\x71"		// Protected Data Envelope 2 
#define	  M_TAG_9F72_IC_PROTECTED_DATA_3		"\x9F\x72"		// Protected Data Envelope 3 
#define	  M_TAG_9F73_IC_PROTECTED_DATA_4		"\x9F\x73"		// Protected Data Envelope 4 
#define	  M_TAG_9F74_IC_PROTECTED_DATA_5		"\x9F\x74"		// Protected Data Envelope 5 
#define	  M_TAG_9F75_IC_UNPROTECTED_DATA_1	"\x9F\x75"		// Unprotected Data Envelope 1 
#define	  M_TAG_9F76_IC_UNPROTECTED_DATA_2	"\x9F\x76"		// Unprotected Data Envelope 2 
#define	  M_TAG_9F77_IC_UNPROTECTED_DATA_3	"\x9F\x77"		// Unprotected Data Envelope 3 
#define	  M_TAG_9F78_IC_UNPROTECTED_DATA_4	"\x9F\x78"		// Unprotected Data Envelope 4 
#define	  M_TAG_9F79_IC_UNPROTECTED_DATA_5	"\x9F\x79"		// Unprotected Data Envelope 5 
#define	  M_TAG_9F7D_IC_DS_SUMMARY_1			"\x9F\x7D"		// DS Summary 1
#define	  M_TAG_9F7F_IC_DS_UNPREDICTABLE_NUMBER	"\x9F\x7F"		// DS Unpredictable Number 
#define	  M_TAG_DF4B_IC_PCII					"\xDF\x4B"		//POS Cardholder Interaction Information 
#define   M_TAG_DF8101_IC_DS_SUMMARY_2			"\xDF\x81\x01"	// DS Summary 2
#define   M_TAG_DF8102_IC_DS_SUMMARY_3			"\xDF\x81\x02"	// DS Summary 3
#define   M_TAG_DF8302_IC_RRP_ENTROPY			"\xDF\x83\x02"	// RRP Device Relay Resistance Entropy 		
#define	  M_TAG_DF8303_IC_RRP_MIN_TIME			"\xDF\x83\x03"	// Min Time For Processing Relay Resistance APDU
#define	  M_TAG_DF8304_IC_RRP_MAX_TIME			"\xDF\x83\x04"	// Max Time For Processing Relay Resistance APDU
#define   M_TAG_DF8305_IC_RRP_TRANSPORT_TIME	"\xDF\x83\x05"	// RRP Device Estimated Transmission Time For Relay Resistance R-APDU


//MASTER��ǩ----�ն�����Ԫ
#define  M_TAG_DF8301_TM_RRP_TERMINAL_ENTROPY	"\xDF\x83\x01"			//Terminal Relay Resistance Entropy
#define  M_TAG_DF8306_TM_RRP_MEASURE_TIME		"\xDF\x83\x06"			//Measured Relay Resistance Processing Time
#define  M_TAG_DF8307_TM_RRP_COUNTER			"\xDF\x83\x07"			//RRP Counter 

#define  M_TAG_DF61_TM_DS_DIGEST_H 			"\xDF\x61"			//DS Digest H 
#define  M_TAG_DF62_TM_DS_ODS_INFO			"\xDF\x62"			//DS ODS Info 
#define  M_TAG_DF63_TM_DS_ODS_TERM			"\xDF\x63"			//DS ODS Term 
#define  M_TAG_DF60_TM_DS_INPUT_CARD			"\xDF\x60"			//DS Input (Card) 
#define  M_TAG_9F6A_TM_UN_NUMBER				"\x9F\x6A"			//Unpredictable Number (Numeric) 
#define  M_TAG_9F6D_TM_MAG_APP_VER_NUM		"\x9F\x6D"			//Mag-stripe Application Version Number
#define  M_TAG_9F53_TM_TRANSCATECODE			"\x9F\x53"			//Transaction Category Code
#define  M_TAG_9F5C_TM_DS_REQ_OPER_ID		"\x9F\x5C"			//DS Requested Operator ID
#define  M_TAG_9F7C_TM_MERCHANT_CUSTOM_DATA	"\x9F\x7C"			//Merchant Custom Data
#define  M_TAG_9F7E_TM_MOBILE_SUPP			"\x9F\x7E"			//Mobile Support Indicator �ֻ�֧�ֱ�־
#define  M_TAG_DF8104_TM_BAL_BFGENAC			"\xDF\x81\x04"		//Balance Read before Gene
#define  M_TAG_DF8105_TM_BAL_AFGENAC			"\xDF\x81\x05"		//Balance Read after Gene
#define  M_TAG_DF8106_TM_DATA_NEEDED 			"\xDF\x81\x06"		//Data Needed 
#define  M_TAG_DF8107_TM_CDOL1_DT				"\xDF\x81\x07"		//CDOL1 Related Data
#define  M_TAG_DF8108_TM_DS_AC_TYPE			"\xDF\x81\x08"		//DS AC Type
#define  M_TAG_DF8109_TM_DS_INPUT_TERM			"\xDF\x81\x09"		//DS Input (Term) 
#define  M_TAG_DF810A_TM_DS_ODS_INFO_READER	"\xDF\x81\x0A"		//DS ODS Info For Reader 
#define  M_TAG_DF810B_TM_DS_Summary_Status	"\xDF\x81\x0B"		//DS Summary Status
#define  M_TAG_DF810C_TM_KERNID				"\xDF\x81\x0C"		//Kernel ID
#define  M_TAG_DF810D_TM_DSVN_TERM				"\xDF\x81\x0D"		//DSVN Term
#define  M_TAG_DF810E_TM_POST_GAC_PUTDATA_STATUS	"\xDF\x81\x0E"		//Post-Gen AC Put Data Status
#define  M_TAG_DF810F_TM_PRE_GAC_PUTDATA_STATUS	"\xDF\x81\x0F"		//Pre-Gen AC Put Data Status
#define  M_TAG_DF8110_TM_FIRST_WRITE_FLAG		"\xDF\x81\x10"		// Proceed To First Write Flag 
#define  M_TAG_DF8111_TM_PDOL_DT				"\xDF\x81\x11"		//PDOL Related Data
#define  M_TAG_DF8112_TM_TAGS_TO_READ			"\xDF\x81\x12"		//Tags To Read 
#define  M_TAG_DF8113_TM_DRDOL_DT				"\xDF\x81\x13"		//DRDOL Related Data
#define  M_TAG_DF8114_TM_REFE_CTRL_PARA		"\xDF\x81\x14"      // Reference Control Parameter
#define  M_TAG_DF8115_TM_ERR_INDI				"\xDF\x81\x15"		//Error Indication
#define  M_TAG_DF8116_TM_UI_REQ    			"\xDF\x81\x16"      // User Interface Request Data
#define  M_TAG_DF8117_TM_CARD_INPUT_CAPA		"\xDF\x81\x17"		//Card Data Input Capability
#define  M_TAG_DF8118_TM_MC_CVMCAPA_REQ		"\xDF\x81\x18"		//CVM Capability �C CVM Required 
#define  M_TAG_DF8119_TM_MC_CVMCAPA_NOREQ		"\xDF\x81\x19"		//CVM Capability �C NO CVM Required
#define  M_TAG_DF811A_TM_DEF_UDOL				"\xDF\x81\x1A"		//Default UDOL
#define  M_TAG_DF811B_TM_KERNCONF				"\xDF\x81\x1B"		//Kernel Configuration
#define  M_TAG_DF811C_TM_MAX_TORN_TIME			"\xDF\x81\x1C"		//Max Lifetime of Torn Transaction Log Record
#define  M_TAG_DF811D_TM_MAX_TORN_NUM			"\xDF\x81\x1D"		//Max Number of Torn Transaction Log Records
#define  M_TAG_DF811E_TM_MS_CVMCAPA_REQ		"\xDF\x81\x1E"		//Mag-stripe CVM Capability �C CVM Required
#define  M_TAG_DF811F_TM_SEC_CAPA    			"\xDF\x81\x1F"      // Security Capability

#define  M_TAG_DF8120_TM_TAC_DEFAULT    				"\xDF\x81\x20"      // Terminal Action Code �C Default
#define  M_TAG_DF8121_TM_TAC_DENIAL     				"\xDF\x81\x21"      // Terminal Action Code �C Denial
#define  M_TAG_DF8122_TM_TAC_ONLINE    				"\xDF\x81\x22"      // Terminal Action Code �C Online
#define  M_TAG_DF8123_TM_PPFLOOR_LMT					"\xDF\x81\x23"      // Reader Contactless Floor Limit
#define  M_TAG_DF8124_TM_PPTRAN_LMT_NODC				"\xDF\x81\x24"      // Reader Contactless Transaction Limit (No On-device CVM) 
#define  M_TAG_DF8125_TM_PPTRAN_LMT_ODC				"\xDF\x81\x25"      // Reader Contactless Transaction Limit (On-device CVM) 
#define  M_TAG_DF8126_TM_PPCVM_LMT       				"\xDF\x81\x26"      // Reader CVM Required Limit
#define  M_TAG_DF8127_TM_TIME_OUT_VALUE      			"\xDF\x81\x27"      // Time Out Value 
#define  M_TAG_DF8128_TM_IDS_STATUS       				"\xDF\x81\x28"      // IDS Status 
#define  M_TAG_DF8129_TM_OUTCOME_PAR					"\xDF\x81\x29"		//Outcome Parameter Set
#define  M_TAG_DF812A_TM_DDCARD_TRACK1					"\xDF\x81\x2A"		//DD Card (Track1)
#define  M_TAG_DF812B_TM_DDCARD_TRACK2					"\xDF\x81\x2B"		//DD Card (Track2)
#define  M_TAG_DF812C_TM_MS_CVMCAPA_NOREQ				"\xDF\x81\x2C"		//Mag-stripe CVM Capability �C No CVM Required
#define  M_TAG_DF812D_TM_MESG_HOLD_TIME				"\xDF\x81\x2D"		//Message Hold Time

#define  M_TAG_DF8130_TM_HOLD_TIME						"\xDF\x81\x30"		//Hold Time Value
#define  M_TAG_DF8131_TM_PHONE_MESG					"\xDF\x81\x31"		//Phone Message Table
#define  M_TAG_DF8132_TM_RRP_MIN_GRACE_PERIOD			"\xDF\x81\x32"		// Minimum Relay Resistance Grace Period
#define  M_TAG_DF8133_TM_RRP_MAX_GRACE_PERIOD			"\xDF\x81\x33"		// Maximum Relay Resistance Grace Period 
#define  M_TAG_DF8134_TM_RRP_TERM_EXP_TIME_CAPDU		"\xDF\x81\x34"		// Terminal Expected Transmission Time For Relay Resistance C-APDU 
#define  M_TAG_DF8135_TM_RRP_TERM_EXP_TIME_RAPDU		"\xDF\x81\x35"		// Terminal Expected Transmission Time For Relay Resistance R-APDU 
#define  M_TAG_DF8136_TM_RRP_ACCURACY_THRESHOLD		"\xDF\x81\x36"	// Relay Resistance Accuracy Threshold
#define  M_TAG_DF8137_TM_RRP_TRANMSIT_TIME_MISMATCH	"\xDF\x81\x37"	// Relay Resistance Transmission Time Mismatch 


#define  M_TAG_FF8101_TM_TORN_REC    					"\xFF\x81\x01"      // Torn Record
#define  M_TAG_FF8102_TAGS_TO_WRITE_PRE_GAC			"\xFF\x81\x02"      // Tags To Write Before Gen AC
#define  M_TAG_FF8103_TAGS_TO_WRITE_POST_GAC			"\xFF\x81\x03"      // Tags To Write After Gen AC 
#define  M_TAG_FF8104_TAGS_DATA_TO_SEND				"\xFF\x81\x04"      // Data To Send
#define  M_TAG_FF8105_TM_DATA_REC						"\xFF\x81\x05"		//Data Record
#define  M_TAG_FF8106_TM_DISC_DATA						"\xFF\x81\x06"		//Discretionary Data

//PayPass�Զ����ǩ
#define  M_TAG_DF8201_TM_DET_INFO				"\xDF\x82\x01"		//DET_INFO
#define  M_TAG_DF8202_TM_ACTIVE_SFI			"\xDF\x82\x02"		//ACTIVE SFI
#define  M_TAG_DF8203_TM_RECR_CERT_RID			"\xDF\x82\x03"		//����֤��RID------���ģ���̨�������
#define  M_TAG_DF8204_TM_RECR_CERT_SN			"\xDF\x82\x04"		//����֤�����к�---���ģ���̨�������
#define  M_TAG_DF8205_TM_RECR_CERT_INDEX		"\xDF\x82\x05"		//����֤������-----���ģ���̨�������			||||||| .r20203
#define  M_TAG_DF8206_TM_DEK_INFO_WAIT			"\xDF\x82\x06"		//DET_INFO_WAIT
#define	 M_TAG_DF8207_TM_DEK_INFO				"\xDF\x82\x07"		//DET_INFO_WAIT
#define  M_TAG_DF8208_TM_COFIG_NUM				"\xDF\x82\x08"		//ģ���̨���ù��ܺ�
#define  M_TAG_DF8209_TM_DISC_TORN_DATA		"\xDF\x82\x09"		//���ʹ�TornRecord���Զ�����(PayPass)
#define  M_TAG_DF820A_TM_APDU_SEND				"\xDF\x82\x0A"		//DE APDU����
#define  M_TAG_DF820B_TM_APDU_RECV				"\xDF\x82\x0B"		//DE APDU��������
#define  M_TAG_DF820C_TM_DYNAMIC_DATA		"\xDF\x82\x0C"		//ICC Dynamic Data
#define  M_TAG_DF820E_TM_STOP_SIGNAL		"\xDF\x82\x0D"		//Ӧ�ö�����STOP�ź�
#define  M_TAG_DF820F_TM_RA_UPDATE			"\xDF\x82\x0F"		//����RA��������

//VISA��ǩ
#define	EMV_TAG_9F7C_IC_CED					"\x9F\x7C"	/**< Customer Exclusive Data (CED)*/
#define	EMV_TAG_9F6E_IC_FFI					"\x9F\x6E"	/**< Form Factor Indicator (FFI)*/
#define EMV_TAG_9F5A_APPID					"\x9F\x5A" /*VISA APPID */
#define EMV_TAG_C2_TEST_ID					"\xC2"		//
#define EMV_TAG_C3_OUTCOME					"\xC3"

//RUPAY
//IC����ǩ	
#define RP_TAG_DF03_IC_SR_AI	"\xDF\x03"			// Service Availability Info
#define RP_TAG_DF07_IC_SR_DIR	"\xDF\x07"			//Service Directory 
#define RP_TAG_DF2E_IC_LOCAL_SR_CBL	"\xDF\x2E"			//Card Balance Limit �C Local(Service)
#define RP_TAG_DF33_IC_SRD		"\xDF\x33"			//Service Related Data
#define RP_TAG_DF3B_IC_SRD		"\xDF\x3B"			//Application Usage Control Extension
#define RP_TAG_DF61_IC_DSR_ID	"\xDF\x61"			//ICC Dynamic Signature Record Identifier
#define RP_TAG_DF16_IC_S_ID		"\xDF\x16"			//Service ID
#define RP_TAG_DF15_IC_SMI		"\xDF\x15"			//Service Management Info
#define RP_TAG_DF20_IC_SATC		"\xDF\x20"			//Service ATC
#define RP_TAG_DF47_IC_PRMISS	"\xDF\x47"			//PRMiss
#define RP_TAG_DF49_IC_PRMICC	"\xDF\x49"			//ICC Service Partial Key (PRMicc) 
#define RP_TAG_DF48_IC_PRMACQ	"\xDF\x48"			//PRMacq 
#define RP_TAG_DF4B_IC_PRE_PRMACQ	"\xDF\x4B"			//Pre PRMacq 
#define RP_TAG_DF54_IC_PRMACQ_KCV	"\xDF\x54"		//PRMacq KCV 

//�ն˱�ǩ
#define RP_TAG_DF22_TM_S_SUMMARY				"\xDF\x22"			// Service Summary
#define RP_TAG_DF23_TM_S_SIGNATURE				"\xDF\x23"			// Service Signature
#define RP_TAG_DF3A_TM_S_CAP_AD_EX				"\xDF\x3A"			// Additional Terminal Capabilities Extension (tag DF3A)
#define RP_TAG_DF4D_TM_CVM_LIMIT				"\xDF\x4D"			//Terminal CVM Limit
#define RP_TAG_DF45_TM_S_TERMINAL_DATA			"\xDF\x45"			//Service Terminal Data
#define RP_TAG_DF4C_TM_TRANC_LIMIT				"\xDF\x4C"			//Contactless Transaction Limit 


//rupay�Զ����ǩ
#define DEF_RP_TAG_DF8501_TM_LEGACY_PARAM				"\xDF\x85\x01"		//rupay legacy param
#define DEF_RP_TAG_DF8502_TM_NON_LEGACY_PARAM			"\xDF\x85\x02"		//rupay non legacy param
#define DEF_RP_TAG_DF8503_TM_FUN_SWITCH					"\xDF\x85\x03"		//rupay SWITCH���� 16�ֽ�  (CDC/EXCEPT/ADVICE/TORN��Ӧ��ǩ�������ֽ�1,2,3,4,5-16�ֽ�RFU)
#define DEF_RP_TAG_DF8504_TM_CVM_CAP					"\xDF\x85\x04"		//rupay CVM����	16�ֽ� (Online PIN/Signature/NoCvm/qDDA��Ӧ��ǩ�������ֽ�Ϊ1,2,3,4),5-16 RFU
#define DEF_RP_TAG_DF8505_TM_RANHOLD					"\xDF\x85\x05"		//rupay ƫ�����ѡ�����ֵ
#define DEF_RP_TAG_DF8506_TM_RANMAXPER					"\xDF\x85\x06"		//rupay ƫ�����ѡ�����ٷֱ�
#define DEF_RP_TAG_DF8507_TM_RANTARPER					"\xDF\x85\x07"		//rupay ƫ�����ѡ��Ŀ��ٷֱ�
#define DEF_RP_TAG_DF8508_TM_DEFAULTTAC					"\xDF\x85\x08"		//rupay �ն���Ϊ���룭Ĭ��
#define DEF_RP_TAG_DF8509_TM_ONLINETAC					"\xDF\x85\x09"		//rupay �ն���Ϊ���룭����
#define DEF_RP_TAG_DF850A_TM_REFUSETAC					"\xDF\x85\x0A"		//rupay �ն���Ϊ���룭�ܾ�
#define DEF_RP_TAG_DF850A_TM_REFUSETAC					"\xDF\x85\x0A"		//rupay �ն���Ϊ���룭�ܾ�
#define DEF_RP_TAG_DF850B_TM_TORN_TERM_ACTYPE			"\xDF\x85\x0B"		//rupay torn actype
//AEMX 
//IC����ǩ
#define AMEX_TAG_9F70_CARD_INTERFACE_AND_PAYMENT_CAP   	     "\x9F\x70"  //Card_Interface_and_Payment_Capabilities
#define AMEX_TAG_9F71_MOBILE_CVM_RESULTS				     "\x9F\x71"  //Mobile_CVM_Results
#define AMEX_TAG_9F1F_TRACK1_DIS_Data						 "\x9F\x1F"  //Track1_Discretionary_Data
#define AMEX_TAG_9F20_TRACK2_DIS_Data						 "\x9F\x20"  //Track2_Discretionary_Data
#define AMEX_TAG_9F5A_MEMBERSHIP_PRODUCT_ID					 "\x9F\x5A"  //Membership Product Identifier
#define AMEX_TAG_9F5B_PRODUCT_MEMBERSHIP_NUMBER				"\x9F\x5B"  //Product Membership Number

//�ն˱�ǩ
#define AMEX_TAG_9F6D_CONTACT_READ_CAP             	 "\x9F\x6D"  //Contactless_Reader_Capabilities
#define AMEX_TAG_9F6E_ENHANCED_CONTACT_READ_CAP		 "\x9F\x6E"  //Enhanced_Contactless_Reader_Capabilities
//AMEX�Զ����׼
#define AMEX_TAG_DF8601_TM_FUN_SWITCH 					 "\xDF\x86\x01"  //drl/delay auth �л�
#define AMEX_TAG_DF8602_DRL_READER_CON_FOOL_LIMIT		 "\xDF\x86\x02"  //default Dynamic Reader Limits-- Reader Contactless Floor Limit
#define AMEX_TAG_DF8603_DRL_READER_CON_TRANS_LIMIT	     "\xDF\x86\x03"  //default Dynamic Reader Limits-- Reader Contactless Transaction Limit
#define AMEX_TAG_DF8604_DRL_READER_CVM_LIMIT			 "\xDF\x86\x04"  //default Dynamic Reader Limits-- Reader CVM Required Limit
#define AMEX_TAG_DF8605_DRL_DATA                         "\xDF\x86\x05"
             //���ڴ洢DRL_for_XXXXb     ��ʽ �����ֽڳ���DRLѡ��+DRL_READER_CON_TRANS_LIMIT(6b)+DRL_READER_CON_FOOL_LIMIT(6b)+AMEX_TAG_DF8604_DRL_READER_CVM_LIMIT(6b)
			 //���ڸĳ��ļ������Ƿ����
#define AMEX_TAG_DF8606_TM_CHECK_INDICATE                "\xDF\x86\x06"    //B1b8   Reader Contactless Floor Limit check
																			//B1b7   Reader Contactless Transaction Limit check
																			//B1b6   Reader CVM Required Limit check
																			//B1b5   Reader zero Amount check
																			//B1b4   Reader zero option Amount check  0/1
																			//B1b3   Reader static check
																			//B1b2   Reader TM Floor Limit check
																			//B1b1   Reader static support   0/1
#define AMEX_TAG_DF8607_TRACK2_DATA                  "\xDF\x86\x07"  		
#define AMEX_TAG_DF8608_RF_AIDLIST					 "\xDF\x86\x08"		//amex aid�б�ָʾ��
#define AMEX_TAG_DF8607_TRACK2_DATA                  "\xDF\x86\x07"  																			//B1B2   Reader TM Floor Limit check
#define AMEX_TAG_DF8608_NORESPOND						"\xDF\x86\x08"
#define AMEX_TAG_DF8109_CONFIG_NUM					"\xDF\x81\x09"
#define AMEX_TAG_DF23_RESULT			"\xDF\x23"			// Service Signature


#define DPAS_TAG_DF8701_TRACK1_DATA                  "\xDF\x87\x01"  
#define DPAS_TAG_DF8702_TRACK2_DATA                  "\xDF\x87\x02" 
#define DPAS_TAG_DF8703                 				"\xDF\x87\x03" 		//black card

#define DPAS_TAG_DF8704                 				"\xDF\x87\x04" 		//black card sn
#define DPAS_TAG_9F80_DCVV2							 "\x9F\x80"  
#define DPAS_TAG_9F7E_DCVV1							 "\x9F\x7E"  
#define DPAS_TAG_9F7D_PAVN							 "\x9F\x7D"  
#define DPAS_TAG_DF8606_TM_CHECK_INDICATE            "\xDF\x86\x06"
#define DPAS_TAG_9F53_CRV								"\x9F\x53"

#define TAG_DF8109_CONFIG_NUM					"\xDF\x81\x09"
#define DPAS_FF8109_CVM_RET					"\xDF\x81\x09"		//ʹ���Լ��Ĺ�����DF8109
#define TAG_DF23_RESULT						"\xDF\x23"
//#define DPAS_FF8109_CVM_RET					"\xFF\x81\x09"
#define DPAS_DF8703_AUC_SKI					"\xDF\x87\x03"
#define DPAS_DF30_DS_RESULT					"\xDF\x30"
#define DPAS_DF3A_IC_CARD_VER_NUM			"\xDF\x3A"
#define DPAS_DF3B_IC_CARD_DESC				"\xDF\x3B"
#define DPAS_DF3E_IC_CARD_ID					"\xDF\x3E"
#define DPAS_DF3C_EXTERN_LOGGING				"\xDF\x3C"
#define DPAS_DF3D_DSD							"\xDF\x3D"
#define DPAS_DF3F_DS							"\xDF\x3F"
#define DPAS_TAG_BF10_TEMP					"\xBF\x10"
#define DPAS_TAG_BF11_TEMP					"\xBF\x11"
#define DPAS_DF1C_READ_CAP					"\xDF\x1C"
#define DPAS_FF8108_DATA_CONTAIN				"\xFF\x81\x08"
#define DPAS_TAG_DF70							"\xDF\x70"
#define DPAS_TAG_DF71							"\xDF\x71"
#define DPAS_TAG_DF72							"\xDF\x72"
#define DPAS_TAG_DF73_DSD_HASH               "\xDF\x73" 

/*****************JCB****************************/
#define JCB_TAG_9F50_IC_CVS					"\x9F\x50"		//Cardholder Verification Status
#define JCB_TAG_9F52_K_TCI					"\x9F\x52"		//Terminal Compatibility Indicator
#define JCB_TAG_9F53_K_TIP					"\x9F\x53"		//Terminal  InterchangeProfile (dynamic) 
#define JCB_TAG_9F5C_IC_MDOL				"\x9F\x5C"		//Magstripe Data Object List (MDOL) 
#define JCB_TAG_9F5F_IC_OB					"\x9F\x5F"		//Offline Balance 
#define JCB_TAG_9F60_IC_IUP					"\x9F\x60"		//Issuer Update Paramete

#define JCB_TAG_DF8801_COMBINATION_OPTIONS	"\xDF\x88\x01"
#define JCB_TAG_DF8802_ONLINE_TYPE			"\xDF\x88\x02"
#define JCB_TAG_DF8803_STATIC_TIP			"\xDF\x88\x03"

/*****************SIBS********************************/
#define SIBS_TAG_DF8901_CVMCAPA_REQ			"\xDF\x89\x01"	//CVM Capabilities (above or equal CVMLimit) 
#define SIBS_TAG_DF8902_CVMCAPA_NOREQ		"\xDF\x89\x02"	//CVM Capabilities (below CVM Limit) 
#define SIBS_TAG_DF8903_TM_PPFLOOR_LMT		"\xDF\x89\x03"  // Reader Contactless Floor Limit
#define SIBS_TAG_DF8904_TM_PPTRAN_LMT		"\xDF\x89\x04"  // Reader Contactless Transaction Limit
#define SIBS_TAG_DF8905_TM_PPCVM_LMT       	"\xDF\x89\x05"  // Reader CVM Required Limit
#define SIBS_TAG_DF8906_SECCAPA_REQ			"\xDF\x89\x06"	//Security Capability 

/********************PURE*******************/
#define PURE_TAG_9F70_GDDOL_IO								"\x9F\x70" 
#define PURE_TAG_9F71_GDDOL_RESULT_BUFFER_IO1				"\x9F\x71" 
#define PURE_TAG_9F72_MEMOREY_SLOT_IDENTIFIER_I01			"\x9F\x72" 
#define PURE_TAG_9F73_ISSUER_SCRIPT_RESULT					"\x9F\x73" 
#define PURE_TAG_9F74_DATA_ELEMENTS_UPDATA_RESULT			"\x9F\x74" 
#define PURE_TAG_9F75_ECHO_CARD_IDENTIFIER					"\x9F\x75" 
#define PURE_TAG_9F76_TERMINAL_TRANS_DATA					"\x9F\x76" 
#define PURE_TAG_A2_MEMORY_SLOT_UPDATA_ENTRY_TYPE1_I02		"\xA2" 
#define PURE_TAG_A3_MEMORY_SLOT_UPDATA_ENTRY_TYPE2_I02		"\xA3"
#define PURE_TAG_A4_MEMORY_SLOT_UPDATA_ENTRY_TYPE3_I02		"\xA4"
#define PURE_TAG_85_MEMORY_SLOT_UPDATA_ENTRY_SETTING		"\x85" 
#define PURE_TAG_9F74_MEMORY_SLOT_UPDATA_TEMPLATE_I02		"\x9F\x74" 
#define PURE_TAG_9F71_MEMORY_SLOT_READ_TEMPLATE_I01			"\x9F\x71" 
#define PURE_TAG_BF70_MEMORY_SLOT_READ_TEMPLATE_I01			"\xBF\x70" 
#define PURE_TAG_BF71_MEMORY_SLOT_READ_TEMPLATE		        "\xBF\x71" 
#define PURE_TAG_BF70_MEMORY_SLOT_READ_TEMPLATE		        "\xBF\x70" 
#define PURE_TAG_9F50_OFFLINE_BALANCE						"\x9F\x50"  


#define PURE_TAG_C5_CCID									"\xC5" 
#define PURE_TAG_C7_TTPI									"\xC7" 
#define PURE_TAG_CD_CRM_CURRENCY_CODE						"\xCD" 
#define PURE_TAG_DF7F_IO5									"\xDF\x7F" 


//����PAPASS���ֵ�TAG

#define PURE_TAG_DF8130_POS_TIMEOUT_LONG_TAP					"\xDF\x81\x30"		

#define PURE_TAG_DF812D_TM_MESG_HOLD_TIME					   "\xDF\x81\x2D"		
//�Զ���TAG	

#define PURE_TAG_DF8801_CONTACTLESS_APPLICATION_AND_KERNEL_CAP      	"\xDF\x88\x01" 
#define PURE_TAG_DF8802_CONTACTLESS_POS_IMPLEMENT_OPTION		     	"\xDF\x88\x02" 
#define PURE_TAG_DF8803_ECHO_COMMAND_SUPPORT_INDICATOR			     	"\xDF\x88\x03" 
#define PURE_TAG_DF8804_ECHO_COMMAND_TRANS_INDICATOR			    	"\xDF\x88\x04" 
#define PURE_TAG_DF8805_CAM_SELECT_INDICATOR			 		    	"\xDF\x88\x05" 
#define PURE_TAG_DF8806_MTOL							 		    	"\xDF\x88\x06" 
#define PURE_TAG_DF8807_ATDTOL											"\xDF\x88\x07" 
#define PURE_TAG_DF8808_TRANS_TYPE_FOR_AAT_IO4							"\xDF\x88\x08" 
#define PURE_TAG_DF8809_GAC1_DATA							            "\xDF\x88\x09" 
#define PURE_TAG_DF8810_ECHO_CMD_DATA							        "\xDF\x88\x10" 
#define PURE_TAG_DF8811_UIRD_RESTART							        "\xDF\x88\x11" 
#define PURE_TAG_DF8814_UIRD_SEP										"\xDF\x88\x14"
#define PURE_TAG_ABSENT										"\xDF\x88\x12"			//B8:5F2A absent .B7:9A absent . B6:9f37 absent
#define PURE_TAG_DF8813_ATOL									"\xDF\x88\x13"


#define PURE_TAG_DF8606_TM_CHECK_INDICATE                "\xDF\x86\x06"    //B1b8   Reader Contactless Floor Limit check
																			//B1b7   Reader Contactless Transaction Limit check
																			//B1b6   Reader CVM Required Limit check
																			//B1b5   Reader zero Amount check
																			//B1b4   Reader zero option Amount check  0/1
																			//B1b3   Reader static check
																			//B1b2   Reader TM Floor Limit check
																			//B1b1   Reader static support   0/1
/*****************MIR tag****************************/
//ICC TAG
#define MIR_TAG_IC_DF6F_ODOL		"\xDF\x6F"			//ODOL
#define MIR_TAG_IC_DF70_AI			"\xDF\x70"			//Application Info
#define MIR_TAG_IC_9F71_CPR			"\x9F\x71"			//CPR

//Terminal TAG
#define MIR_TAG_TERMINAL_DF71_TPM	"\xDF\x71"		//Transaction Processing Mode
#define MIR_TAG_TERMINAL_DF41_TRC	"\xDF\x41"		//Transaction Recovery Counter(TRC)
#define MIR_TAG_TERMINAL_DF74_TPM	"\xDF\x74"		//Kernel Verification Results(KVR)
#define MIR_TAG_TERMINAL_9F70_CDAR	"\x9F\x70"		//CDA Result(CDAR)
#define MIR_TAG_TERMINAL_DF54_TRANS_CDCVM_LIMIT		"\xDF\x54"		//Terminal Contactless Limit (CD-CVM) 
#define MIR_TAG_TERMINAL_DF53_TRANS_LIMIT			"\xDF\x53"		//Terminal Contactless Limit (Non CD-CVM) 
#define MIR_TAG_TERMINAL_DF52_CVM_LIMIT				"\xDF\x52"		//CVM_LIMIT	
#define MIR_TAG_TERMINAL_DF51_FLOOR_LIMIT			"\xDF\x51"		//FLOOR_LIMIT
#define MIR_TAG_TERMINAL_DF74_KVR					"\xDF\x74"		//KVR    
#define MIR_TAG_TERMINAL_DF55_TPM_CAP				"\xDF\x55"		//TPM CAP


//�Զ���TAG
#define MIR_TAG_TERMINAL_DF8A01_AEC		 "\xDF\x8A\x01"				//Allow Expired Card
#define MIR_TAG_TERMINAL_DF8A02_TAED	 "\xDF\x8A\x02"				//Threshold Application Expiration Date
#define MIR_TAG_TERMINAL_DF8A03_ODOL_DT	 "\xDF\x8A\x03"				//ODOL Related Data
#define MIR_TAG_TEMRINAL_DF8A04_DATA_EXCHANGE_TAG	"\xDF\x8A\x04"	//Data Exchange Tag List

//EMV �����Զ���TAG
#define DEF_TAG_ISS_RECOVER_SIGN	"\xDF\x84\x01"		//����֤���ʶ		0--������ 1-����
#define DEF_TAG_TORN_RECORD_DATA	"\xDF\x84\x02"		//��������
#define DEF_TAG_TRAN_RESULT_STATUS	"\xDF\x84\x03"		//���׽��״̬		0--TC  1--ARQC 2--AAC  3--AAR
#define DEF_TAG_PAN_BLACK_LIST		"\xDF\x84\x04"		//���ź�������ʶ	0--������ 1--����
#define DEF_TAG_ONLINE_REQ_TYPE		"\xDF\x84\x05"		//������������		0--��Ȩ���� 1--��������  2--����ȷ��  3--������
#define DEF_TAG_EXEC_CTL_2TAP_SIGN	"\xDF\x84\x06"		//�ǽ�2TAP��־      0--δִ��  1--��ִ��
#define DEF_TAG_DF8406_PIN_BYPASS	"\xDF\x84\x07"		//PIN bypass ��ʶ	0-Ĭ��ֵ  1-���ν���֧��bypass




//#define DEF_TAG_DF820D_FORCE_KERNEL_ID			"\xDF\x82\x0D"   //��֤��--��ͬ����淶��PPSE��ADF�����߼����ܲ�����,�����ݵĲ��ֿ���ͨ�����ö�Ӧ���ں�ID���촦��