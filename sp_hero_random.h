#ifndef sp_hero_random_h
#define sp_hero_random_h

#include <PR/sp.h>

#define hero_randomTRUEIMAGEH	137
#define hero_randomTRUEIMAGEW	103
#define hero_randomIMAGEH	160
#define hero_randomIMAGEW	128
#define hero_randomBLOCKSIZEW	32
#define hero_randomBLOCKSIZEH	32
#define hero_randomSCALEX	1.0
#define hero_randomSCALEY	1.0
#define hero_randomMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap hero_random_bitmaps[];
extern Gfx hero_random_dl[];

#define NUM_hero_random_BMS  (sizeof(hero_random_bitmaps)/sizeof(Bitmap))

extern Sprite hero_random_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                     YYYYYYY                    |
|                 YYYYYYYYYYYYYYY                |
|              YYYYYYYYYYYYYYYYYYYYY             |
|             YYYYYYYYYYYYYYYYYYYYYYY            |
|          YYYYYYYYYYYYYYYYYYYYYYYYYYYYY         |
|         YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY        |
|        YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY       |
|   rrrr  YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY      |
|     rr  rrrr YYYgg YYYYYYYYYYYYYY YYYYYYYY     |
|     YYrrrrr  rrr gggYYYYYYYYYYYY YYYYYYYYYY    |
|    YYYYY rrrrrr rr ggggYYYYYYYYYY YYYYYYYYYY   |
|   YYYYYYYYYYY   rrrrggggg YYYYYYYY  YYYYYYYYY  |
|   YYYYYYYYYYYYYYYggggggggggggg YYYYY  YYYYYYY  |
|  YYYYYYYYYYYYYYYY                YYYYY YYYYYYY |
|  YYYYYYYYYYYYYYYY YYYYYY      Y YYYYYYY  YYYYY |
| YYYYYYYYYYYYYY YY Y YYY@@@@Y b YYYYYYYYY YYYYYY|
| YYYYYYYYYYYYYr rrrY  @@@@@@Y  YYYYYYYYYYY YYYYY|
| YYYYYYYYYYYYYr rrrrrYYYYY@Y@ @@ YYYYYYYYY YYYYY|
| YYYYYYYYYYYYYY   iir@@@@@@@YYY YYYYYYYYYY  YYYY|
|YYYYYYYYYYYYYY  @@@@@YY                        I|
|YYYYYYYYYYY YY@@@@@@ Y r@rrryyyy @@YYYYYYY @@YYY|
|YYYYYYYYYYY@@@YYYYYrryyyy@yyrrrrYYY@@@@@@@ Y YYY|
|YYYYYYYYYYYY Y@  y  yrrrrr@ryyyy@@@YY     rrYYYY|
|YYYYYYYYYYYYYYYYyyyy rrrrrrryYYYYYYYYYYYYY  YYYY|
| YYYYYYYYYYYYYYYrrrrr  y yyy@YYYYYYYYYYYYY YYYYY|
| YYYYYYYYYYYYYYYyyy y r rrrry@YYYYYYYYYYYYYYYYYY|
| YYYYYYYYYYYYYYY rr   yy     Y@YYYYYYYYY  YYYYYY|
| YYYYYYYYYYYYYYY rrrryyyyy  r YYYYYYYY  YYYYYYYY|
|  YYYYYYYYYYYYYYYY g   rrrrr Y YYYYYY YYYYYYYYY |
|  YYYYYYYYYYYYYYYYgrrgg     g  YYYY YYYYYYYYYYY |
|   YYYYYYYYYYYYYY yygggggggg YYYYYYYYYYYYYYYYY  |
|   YYYYYYYYYYYYY     g  ggggYYYYYYYYYYYYYYYYYY  |
|    YYYYYYYYYYYYY YY YY g@ gYYYYYYYYYYYYYYYYY   |
|     YYYYYYYYYYYY@@@@YYYYYY YYYYYYYYYYYYYYYY    |
|      YYYYYYYYY  YYY YYY@@@ YYYYYYYYYYYYYYY     |
|       YYYYYYYYggggg Y    ggYYYYYYYYYYYYYY      |
|        Y   ggggggggYY gggggYYYYYYYYYYYYY       |
|       ggggggggggg YYY gggggggggg YYYYYY        |
|          YYYYYYYYYYYYYY   gggggg  YYYY         |
|             YYYYYYYYYYYYYYYYYYYYYYY            |
|              YYYYYYYYYYYYYYYYYYYYY             |
|                 YYYYYYYYYYYYYYY                |
+------------------------------------------------+
#endif

