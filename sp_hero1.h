#ifndef sp_hero1_h
#define sp_hero1_h

#include <PR/sp.h>

#define hero1TRUEIMAGEH	106
#define hero1TRUEIMAGEW	128
#define hero1IMAGEH	128
#define hero1IMAGEW	128
#define hero1BLOCKSIZEW	32
#define hero1BLOCKSIZEH	32
#define hero1SCALEX	1.0
#define hero1SCALEY	1.0
#define hero1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap hero1_bitmaps[];
extern Gfx hero1_dl[];

#define NUM_hero1_BMS  (sizeof(hero1_bitmaps)/sizeof(Bitmap))

extern Sprite hero1_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|   rrr                                          |
|    rr  rrr  gg              @                  |
|      rrrrr rr ggg           @                  |
|             rrrgggg         @                  |
|              gggggggggg     @                  |
|              YYYYYYYYYYY    @                  |
|              Y YY @Y@@      @                  |
|           rrrY @ @@Yb@Y     @                  |
|           rrrgr@Y@@Y@@Y@    @                  |
|            iii  Y@@Y@@      @rrr               |
|             yry@Y@@Y      @@ rrr               |
|            yyry Y@@Y@@Y@@Y  @@@Y @             |
|                ry  yrry     @   rr             |
|            rryr yrryrr      @                  |
|            rryrr r yrr      @                  |
|             r ggyr  gg      @                  |
|             ryrryr  rr      @                  |
|              gggg  yr g     @                  |
|              yggggggg       @                  |
|             g  gggggg       @                  |
|              @              @                  |
|             Y@Y   Y@                           |
|               g   Y@g                          |
|           gggg   ggg                           |
|     ggggggggg    gggggggg                      |
+------------------------------------------------+
#endif

