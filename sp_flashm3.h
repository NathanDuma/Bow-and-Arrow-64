#ifndef sp_flashm3_h
#define sp_flashm3_h

#include <PR/sp.h>

#define flashm3TRUEIMAGEH	46
#define flashm3TRUEIMAGEW	27
#define flashm3IMAGEH	64
#define flashm3IMAGEW	32
#define flashm3BLOCKSIZEW	32
#define flashm3BLOCKSIZEH	32
#define flashm3SCALEX	1.0
#define flashm3SCALEY	1.0
#define flashm3MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap flashm3_bitmaps[];
extern Gfx flashm3_dl[];

#define NUM_flashm3_BMS  (sizeof(flashm3_bitmaps)/sizeof(Bitmap))

extern Sprite flashm3_sprite;

#endif 

#if 0	/* Image preview */
+---------------------------+
|           YYYYYYY         |
|          YYYYYYYYY        |
|        YY         Y       |
|        Y          YY      |
|       YY           Y      |
|       YY           Y      |
|       YY          YY      |
|        YY         Y       |
|         Y         Y       |
|         Y         Y       |
|        YY         YY      |
|        YY  YYYY    Y      |
|        YY Y        YY     |
|        YYY         YY     |
|       YYY          YY     |
|   YY               Y YY   |
|  YY           YYY  Y  YY  |
|  YY       YYY      Y   YY |
|   YY  YYYY         YY  YY |
|    YYY    Y        Y      |
|    YY     YY       Y      |
|   Y        Y        YY    |
|   YY       YY        YY   |
|   YY    YYY  YY        YY |
|   Y     YY    YY        Y |
| YYY     Y       YYY      Y|
|YY       Y         YY     Y|
|Y      YYY          Y    YY|
|Y     YYY           Y   YY |
|  YYY               YYYYY  |
+---------------------------+
#endif

