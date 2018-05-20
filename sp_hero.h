#ifndef sp_hero0_h
#define sp_hero0_h

#include <PR/sp.h>

#define hero0TRUEIMAGEH	106
#define hero0TRUEIMAGEW	94
#define hero0IMAGEH	128
#define hero0IMAGEW	96
#define hero0BLOCKSIZEW	32
#define hero0BLOCKSIZEH	32
#define hero0SCALEX	1.0
#define hero0SCALEY	1.0
#define hero0MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap hero0_bitmaps[];
extern Gfx hero0_dl[];

#define NUM_hero0_BMS  (sizeof(hero0_bitmaps)/sizeof(Bitmap))

extern Sprite hero0_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|  r                                             |
|   rr rrrr                                      |
|     rrrr  rrrr   gg                            |
|        rrrrrr rrrrggg                          |
|            rrrrr  r ggggg                      |
|                       gggggg                   |
|                   gggggggggggggg               |
|                                                |
|                   YYYYYYY       Y              |
|                   YYYYYY @@@@@ b               |
|               rr  YY@@  YYYYbYYY               |
|               rr  g YYYY@@@@@@  @              |
|                     g@  YYYY  YYY              |
|                i    YYYY@@                     |
|              @@@@@@@@@@      yyyyy             |
|            YYYYYYYY  YYY@rrrrrrrrrYYYYYYYYYY Y |
|            @@@@@@ rrrrrr yyyyyyyy @@@@@@@@@@r@ |
|                 yy  yyyy rrrrrrr            rr |
|                 yyy  yyy rrrr                  |
|                 rrrrr r   yyyy                 |
|                 yyyyyy  r rrrr                 |
|                 rr gggrr  yg g                 |
|                 yyygg yyr   g                  |
|                    rrrrry y  y                 |
|                   gggggy   rr                  |
|                   rrggg ggggg                  |
|                  gggggggggggg                  |
|                 g Y gg  ggggg                  |
|                  @@@@      g                   |
|                  YYY     @@@                   |
|                g@@@@     YYY                   |
|                g ggg   g @@ g                  |
|               ggggg    ggggg                   |
|       ggggggggggggg    ggggggggg               |
|                         gggggggggggg           |
+------------------------------------------------+
#endif

