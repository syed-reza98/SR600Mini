#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include "base64_url.h"

#define JOSE_B64_DEC_BLK 3
#define JOSE_B64_ENC_BLK 4
#define JOSE_B64_MAP "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_"

static int b64_dlen(int elen)
{
    switch (elen % JOSE_B64_ENC_BLK)
    {
         case 0: return elen / JOSE_B64_ENC_BLK * JOSE_B64_DEC_BLK;

         case 2: return elen / JOSE_B64_ENC_BLK * JOSE_B64_DEC_BLK + 1;

         case 3: return elen / JOSE_B64_ENC_BLK * JOSE_B64_DEC_BLK + 2;

         default: return SIZE_MAX;
    }
}

static int b64_elen(int dlen)
{
    switch (dlen % JOSE_B64_DEC_BLK)
    {
         case 0: return dlen / JOSE_B64_DEC_BLK * JOSE_B64_ENC_BLK;

         case 1: return dlen / JOSE_B64_DEC_BLK * JOSE_B64_ENC_BLK + 2;

         case 2: return dlen / JOSE_B64_DEC_BLK * JOSE_B64_ENC_BLK + 3;

         default: return SIZE_MAX;
    }
}

static int jose_b64_dec_buf(const void* i, int il, void* o, int ol)
{
    const int len = strlen(JOSE_B64_MAP);
    const char* e = (const char*)i;
    unsigned char* d = (unsigned char*)o;
    unsigned char rem = 0;
    int oo = 0;

    if (il == SIZE_MAX)
    {
        return SIZE_MAX;
    }

    if (!o)
    {
        return b64_dlen(il);
    }

    if (ol < b64_dlen(il))
    {
        return SIZE_MAX;
    }

    for (int io = 0; io < il; io++)
    {
        unsigned char v = 0;

        for (const char c = e[io]; v < len && c != JOSE_B64_MAP[v]; v++)
        {
            continue;
        }

        if (v >= len)
        {
            return SIZE_MAX;
        }

        switch (io % JOSE_B64_ENC_BLK)
        {
             case 0:

               if (!e[io + 1] || rem > 0)
               {
                   return SIZE_MAX;
               }
               rem = v << 2;
               break;

             case 1:
               d[oo++] = rem | (v >> 4);
               rem = v << 4;
               break;

             case 2:
               d[oo++] = rem | (v >> 2);
               rem = v << 6;
               break;

             case 3:
               d[oo++] = rem | v;
               rem = 0;
               break;
        }
    }

    return rem > 0 ? SIZE_MAX : oo;
}
/**
 * @brief
 *
 * @param[in] Base64UrlType_E type
 * @param[in] int dstLength
 * @return length
 */
int Base64UrlDestLength(Base64UrlType_E type, int dstLength)
{
    return (B64_URL_ENC == type) ? b64_elen(dstLength) : b64_dlen(dstLength);
}

/**
 * @brief
 *
 * @param[in] const unsigned char *src
 * @param[in] int ilen
 * @param[out] unsigned char*dst
 * @param[in] int iDst
 * @return < 0 failed
 */
int Base64UrlDec(const unsigned char* src, int ilen, unsigned char* dst, int iDst)
{
    return jose_b64_dec_buf(src, ilen, dst, iDst);
}

static int jose_b64_enc_buf(const void* i, int il, void* o, int ol)
{
    const unsigned char* ib = (const unsigned char*)i;
    unsigned char rem = 0;
    int oo = 0;
    char* ob = (char*)o;

    if (!o)
    {
        return b64_elen(il);
    }

    if (ol < b64_elen(il))
    {
        return SIZE_MAX;
    }

    for (int io = 0; io < il; io++)
    {
        unsigned char c = ib[io];

        switch (io % 3)
        {
             case 0:
               ob[oo++] = JOSE_B64_MAP[c >> 2];
               ob[oo++] = JOSE_B64_MAP[rem = (c & 0b11) << 4];
               break;

             case 1:
               ob[oo - 1] = JOSE_B64_MAP[rem | (c >> 4)];
               ob[oo++] = JOSE_B64_MAP[rem = (c & 0b1111) << 2];
               break;

             case 2:
               ob[oo - 1] = JOSE_B64_MAP[rem | (c >> 6)];
               ob[oo++] = JOSE_B64_MAP[c & 0b111111];
               break;
        }
    }

    return oo;
}

/**
 * @brief
 *
 * @param[in] const unsigned char* src
 * @param[in] int ilen
 * @param[out] unsigned char* dst
 * @param[in] int iDst
 * @return < 0 failed
 */
int Base64UrlEnc(const unsigned char* src, int ilen, unsigned char* dst, int iDst)
{
    int elen = b64_elen(ilen);

    if (iDst < elen) { return -1; }

    if (jose_b64_enc_buf(src, ilen, dst, elen) == elen)
    {
        return elen;
    }
    return -1;
}

