
#include "libapi_xpos/inc/mfsdk_fs.h"
#include "libapi_xpos/inc/mfsdk_mem.h"
#include "font_manage.h"
#include "../tracedef.h"


static int g_font_exist = -1;
static uint8_t *g_font_buf = NULL;
static const s8 *g_fontpath = "exdata\\multfont.bin";
static const s8 *g_fontinipath = "exdata\\multfont.ini";


static const char* disp_msg_def[] = 
{
	"Welcome",
	"Amount",
	"Qrcode",
	"Maxstring"
};

#define MSGMAXCOUNT (sizeof(disp_msg_def) / sizeof(disp_msg_def[0]))

char* GetDispMessageMap(const char *str)
{
	static char message[128] = {0};

	if(NULL == str) return NULL;

	memset(message, 0, sizeof(message));
    MfSdkFsReadProfileString((const s8 *)"string", (const s8 *)str, (s8 *)message, sizeof(message), (const s8 *)"", (const s8 *)g_fontinipath);
	APP_TRACE("key = %s, message = %s\r\n", str, message);
	
	if(strlen(message) <= 0 || strlen(message) > sizeof(message))
		return str;
	
	return message;
}

char* GetDispMessageFromCfg(MessageStingID index)
{
	static char string[128] = {0};
	s8* key[16] = {0};

	if(index < 0 || index >= MSG_STRING_MAX)
		return NULL;

	memset(string, 0, sizeof(string));
	snprintf(key, sizeof(key), "%s", disp_msg_def[index]);
    MfSdkFsReadProfileString((const s8 *)"string", (const s8 *)key, (s8 *)string, sizeof(string), (const s8 *)"", (const s8 *)g_fontinipath);
	APP_TRACE("key = %s, text = %s\r\n", key, string);
	
	if(strlen(string) <= 0 && index <= MSGMAXCOUNT)
	{
		return disp_msg_def[index];
	}
	
	return string;
}

static int FontReadBinFile(const s8* name ,char *buffer, s32 size)
{
	int length = MFSDK_RET_FAILED;
	int fd = MfSdkFsOpen(name, MFSDK_FS_FLAG_READ,MFSDK_FS_MODE_READ);
	
	APP_TRACE("File = %s, ret :%d\r\n",name, fd);
	if(fd >= 0)
	{
		MfSdkFsLseek(fd ,0, 0);
		length = MfSdkFsRead(fd, buffer, size);
		MfSdkFsClose(fd);
	}
	
	APP_TRACE("FontReadBinFile length :%d\r\n",length);
	return length;
}

static int CheckFontExist(const char *fontpath)
{
	int ret = -1;
	
    if(MFSDK_FS_RET_OK != MfSdkFsCheckPath((const s8 *) fontpath))
    {
        APP_TRACE("\n files %s not Exist\r\n", fontpath);
		ret = 0;
    }
	else
	{
		ret = 1;
	}

	return ret;
}

int MultiFontInit()
{
	int ret = 0;
	int length = -1;
	const char *fontpath = g_fontpath;

	if(-1 != g_font_exist) return g_font_exist;

	ret = CheckFontExist(fontpath);
	APP_TRACE("g_font_exist :%d\r\n", ret);
	if(1 == ret)
	{
		length = MfSdkFsGetFileLength(fontpath);
		APP_TRACE("[%s] length :%d\r\n", fontpath, length);
		if(length > 0)
		{
			g_font_buf = MfSdkMemMalloc(length+1);
			//APP_TRACE("g_font_buf :%p\r\n",g_font_buf);
			if(g_font_buf != NULL)
			{
				memset(g_font_buf, 0 , length+1);				
				if(FontReadBinFile((const s8*)fontpath,(char*)g_font_buf ,length) != length)
				{
					MfSdkMemFree(g_font_buf);
					g_font_buf = NULL;
					ret = 0;
				}
				else
				{
					ret = 1;
				}
			}
		}
	}
	g_font_exist = ret;

	return g_font_exist;
}

lv_font_t* GetMultiFont()
{
	LV_FONT_DECLARE(multfont);
	return &multfont;
}

uint8_t * AppFontAddr()
{
	if(1 != g_font_exist || NULL == g_font_buf) return NULL;
		
	APP_TRACE("fontdata :%p\r\n", g_font_buf);
	return g_font_buf;
}

