#ifndef sp_hero3_h
#define sp_hero3_h

#include <PR/sp.h>

#define hero3TRUEIMAGEH	105
#define hero3TRUEIMAGEW	99
#define hero3IMAGEH	128
#define hero3IMAGEW	128
#define hero3BLOCKSIZEW	32
#define hero3BLOCKSIZEH	32
#define hero3SCALEX	1.0
#define hero3SCALEY	1.0
#define hero3MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap hero3_bitmaps[];
extern Gfx hero3_dl[];

#define NUM_hero3_BMS  (sizeof(hero3_bitmaps)/sizeof(Bitmap))

extern Sprite hero3_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|  r rrrr                                        |
|    rrr rrrr     g                              |
|      rrrrrr  rrr ggg                           |
|         rrrrrrrrrrggggg                        |
|                rrrr ggggg                      |
|                  ggggggggggggg@                |
|                              @                 |
|                  YYYYYYY    @                  |
|                  YY@YYY@@@@@@@@                |
|              r   YYYY  YYY@  YY                |
|              r   g  YYYYY@YYYYY                |
|                 ii  @@@@@@@@@@                 |
|                YYYYYYY                         |
|            YYYY@@@@@@@ @yyyyyyy           Y    |
|           @@@@@YYYrrrr  @rrrrrr @@@@@@@@@@ @   |
|           YYYYY   yyyy  y@yyyyy YYYYYYYYYYr    |
|                yyy  yyyyyy@y                   |
|                rrrrr r   rr@                   |
|                yyyyyy  yyyyy@                  |
|                rr gggrr r    @                 |
|                yyygg yyy  gg  @                |
|                  g yyyyyyy  y  @               |
|                  ggggg rrrr     @              |
|                 gyyggg ggggg     @             |
|                 ggggggggggg                    |
|                  @@gg  gggg                    |
|                 YYYY    YYg                    |
|                YYYY    YYY                     |
|               g@  g   g@@@                     |
|               gggg    ggggg                    |
|         gggggggggg    gggggg                   |
|        gggggggg       ggggggggggg              |
+------------------------------------------------+
#endif

