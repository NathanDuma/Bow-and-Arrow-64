#ifndef sp_hero2_h
#define sp_hero2_h

#include <PR/sp.h>

#define hero2TRUEIMAGEH	107
#define hero2TRUEIMAGEW	107
#define hero2IMAGEH	128
#define hero2IMAGEW	128
#define hero2BLOCKSIZEW	32
#define hero2BLOCKSIZEH	32
#define hero2SCALEX	1.0
#define hero2SCALEY	1.0
#define hero2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap hero2_bitmaps[];
extern Gfx hero2_dl[];

#define NUM_hero2_BMS  (sizeof(hero2_bitmaps)/sizeof(Bitmap))

extern Sprite hero2_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|  r rrrr                                        |
|    rr  rrr     g                @              |
|       rrrrrr rrrggg            @               |
|          rrrrr  rgggg         @                |
|                    ggggg                       |
|                 ggggggggggggg@                 |
|                 YYYYYYYYYYYY@                  |
|                 Y YYY @@@@YY                   |
|             rr  Y Y Y@@@ bYY                   |
|             rr    @@@YYYYY@@@                  |
|             rr  gr YY@@@@@                     |
|              i   rr   @  rrrr                  |
|              rrrry y YYYYrrrry                 |
|              yyyyrYYY@@ yyrrrr@@@@YYYYY@@      |
|               yy YYYY yyyy@rr @@@@YYYYY        |
|               rrr @ y rrrryyy                  |
|               yyyr rr yyyy                     |
|               yyyrrr yyyyy                     |
|               rr gg y r      @                 |
|               yyyggrry  gg                     |
|                 grrrryyy                       |
|                 gggggrrrr      @               |
|                gyggggggggg      @              |
|               gg  gg gggg        @             |
|                YY    g  g                      |
|                @@Y    @@                       |
|              g@@@    @@@                       |
|              g gg    YY g                      |
|              gggg   ggggg                      |
|      ggggggggggg     ggggggggg                 |
|                         gggggg                 |
+------------------------------------------------+
#endif

