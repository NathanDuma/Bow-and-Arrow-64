#ifndef sp_flashm1_h
#define sp_flashm1_h

#include <PR/sp.h>

#define flashm1TRUEIMAGEH	46
#define flashm1TRUEIMAGEW	32
#define flashm1IMAGEH	64
#define flashm1IMAGEW	32
#define flashm1BLOCKSIZEW	32
#define flashm1BLOCKSIZEH	32
#define flashm1SCALEX	1.0
#define flashm1SCALEY	1.0
#define flashm1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap flashm1_bitmaps[];
extern Gfx flashm1_dl[];

#define NUM_flashm1_BMS  (sizeof(flashm1_bitmaps)/sizeof(Bitmap))

extern Sprite flashm1_sprite;

#endif 

#if 0	/* Image preview */
+--------------------------------+
|              YYYYYYY           |
|             YYYYYYYYY          |
|           YYrrrrrrrrrY         |
|           YrrrrrrrrrrYY        |
|          YYrrrrrrrrrrrY        |
|          YYrrrrrrrrrrrY        |
|          YYrrrrrrrrrrYY        |
|           YYrrrrrrrrrY         |
|            YrrrrrrrrrY         |
|            YrrrrrrrrrYY        |
|           YYrrrrrrrrrrrrYYY    |
|         YYYrrrrrrrrrrrrrrYY    |
|      YYYrrrrrrrrrrrrrrrrrrYY   |
|    YYYrrrrrrrrrrrrrrrrrrrrrY   |
| YYrrrrrrrrrrrrrrrrrYYrrrrrrYY  |
|YrrrrrrrrrYYrrrrrrrrrrYrrrrrrY  |
|YYrrrrrYYYYYYrrrrrrrrrrYrrrrrYY |
|          YYrrrrrrrrrrrY YrrrrrY|
|          YrrrrrrrrrrrrY YYrrrrY|
|       YYYrrrrrrrrrYYrrY  YYYYY |
|       YYrrrrrrrrrYYrrrY        |
|      YrrrrrrrrrYYrrrrrrYY      |
|      YYrrrrrrrYYrrrrrrrrYY     |
|      YYrrrrYYY  YYrrrrrrrrYY   |
|      YrrrrrYY    YYrrrrrrrrY   |
|    YYYrrrrrY       YYYrrrrrrY  |
|   YYrrrrrrrY         YYrrrrrY  |
|   YrrrrrrYYY          YrrrrYY  |
|   YrrrrrYYY           YrrrYY   |
|     YYY               YYYYY    |
+--------------------------------+
#endif

