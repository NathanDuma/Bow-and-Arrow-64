#ifndef sp_fire2_h
#define sp_fire2_h

#include <PR/sp.h>

#define fire2TRUEIMAGEH	20
#define fire2TRUEIMAGEW	49
#define fire2IMAGEH	32
#define fire2IMAGEW	64
#define fire2BLOCKSIZEW	32
#define fire2BLOCKSIZEH	32
#define fire2SCALEX	1.0
#define fire2SCALEY	1.0
#define fire2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap fire2_bitmaps[];
extern Gfx fire2_dl[];

#define NUM_fire2_BMS  (sizeof(fire2_bitmaps)/sizeof(Bitmap))

extern Sprite fire2_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|           rrrr                                 |
|      YYYYYYYYrrrrrrrrrr                        |
|   YYYYYYYYYrYYYrYYYYYYYYrrrrrYYrrrr      rrr   |
| YrrrrrYYYrrrrrYYYrrrrrrrrYYYYYYYYrrYYrrrrrYrr r|
| YryrrrYYYYYYYYYrrrYYYYYYYYrrrrrrYYYYrrrYYYYrrrr|
| yrrrrYrrrYYYYYYrrrrrrrYrYYrrrrrrrrYYrrrYYYYrrr |
| yryYYYYYYYYYYYYYrrrrrrrYYYYYrYYYYYrrYYrrrrrrr  |
| ryYYrYYYYYYYYrrrrrrrrYYYYrrrrrrrrYYYYrrrYYYYYY |
| rrrrrrrYYYYYrrrrrrYYrrrrrYYYYrYYrrrrrrrrr      |
|  rrYrrrrryryrYYYYrrrrrYYYYYrrYYYrrr   rr rr    |
|    rYYYYYYYYYYyrrrrrrrrrrrr rrYrrrrrrrrrrr     |
|      YYYYYYYYYYYY                              |
+------------------------------------------------+
#endif

