#ifndef sp_flashm2_h
#define sp_flashm2_h

#include <PR/sp.h>

#define flashm2TRUEIMAGEH	46
#define flashm2TRUEIMAGEW	24
#define flashm2IMAGEH	64
#define flashm2IMAGEW	32
#define flashm2BLOCKSIZEW	32
#define flashm2BLOCKSIZEH	32
#define flashm2SCALEX	1.0
#define flashm2SCALEY	1.0
#define flashm2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap flashm2_bitmaps[];
extern Gfx flashm2_dl[];

#define NUM_flashm2_BMS  (sizeof(flashm2_bitmaps)/sizeof(Bitmap))

extern Sprite flashm2_sprite;

#endif 

#if 0	/* Image preview */
+------------------------+
|         YYYYYYY        |
|        YYYYYYYYY       |
|      YYrrrrrrrrrY      |
|      YrrrrrrrrrrYY     |
|     YYrrrrrrrrrrrY     |
|     YYrrrrrrrrrrrY     |
|     YYrrrrrrrrrrYY     |
|      YYrrrrrrrrrY      |
|       YrrrrrrrrrY      |
|       YrrrrrrrrrY      |
|      YYrrrrrrrrrYY     |
|      YYrrYYYYrrrrY     |
|      YYrYrrrrrrrrYY    |
|      YYYrrrrrrrrrYY    |
|     YYYrrrrrrrrrrYY    |
| YYrrrrrrrrrrrrrrrYrYY  |
|YYrrrrrrrrrrrYYYrrYrrYY |
|YYrrrrrrrYYYrrrrrrYrrrYY|
| YYrrYYYYrrrrrrrrrYYrrYY|
|     YrrrYrrrrrrrrY     |
|     YrrrYrrrrrrrrY     |
|     YrrrYrrrrrrrrY     |
|     YrrrYrrrrrrrrY     |
|     YrrrYYrrrrrrrY     |
|    YYrrrrYrrrrrrrY     |
|    YrrrrrYYrrrrrrY     |
|    YrrrrrYYrrrrrrY     |
|    YrrrrYYYYYrrrrY     |
|    YrrrrYY YYrrrrY     |
|   YrrrrYY  YrrrrYY     |
+------------------------+
#endif

