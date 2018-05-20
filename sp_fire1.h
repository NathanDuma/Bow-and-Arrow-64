#ifndef sp_fire1_h
#define sp_fire1_h

#include <PR/sp.h>

#define fire1TRUEIMAGEH	20
#define fire1TRUEIMAGEW	49
#define fire1IMAGEH	32
#define fire1IMAGEW	64
#define fire1BLOCKSIZEW	32
#define fire1BLOCKSIZEH	32
#define fire1SCALEX	1.0
#define fire1SCALEY	1.0
#define fire1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap fire1_bitmaps[];
extern Gfx fire1_dl[];

#define NUM_fire1_BMS  (sizeof(fire1_bitmaps)/sizeof(Bitmap))

extern Sprite fire1_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|           rrrr                                 |
|   r  YYYYYYYrrYYYYYYYYr                        |
| rrYYYYrrrrrrrYYY rYYYYrYYYYrrrrrrrr            |
| rrrYYYrYYYYYYYYYYYYYYYYYYYYYrrrrYrYrrrrrrrrYr r|
| rryYYYyryrrryYrYrYrrYYYYYYYYYrYrYYYYYrrrYrrrrrY|
| yrYYrrrrrYYrYYYYYYYYYYYrYYYYYrrrrrrrrYYrrrrrYr |
| yryryrrrrrYYYYYYYYYYYYYYYrYYYYYYrrYYrrrrYrrrr  |
| ryrYYYYyYyryrrrYYYYYYYYrYYrYYYYYYrrrrrrrrrrrr  |
| rYrrrrrrrrYYYYYYYYrYrrrYYrrrrrrrrrrrrrrrr      |
| rrryYYrYYyryrrryrrrYYYrYYYYYYYYYrYr            |
|    ryYYrYYYYYryrrrrrrrrrrrr                    |
|    rrryryrrrrrrrr                              |
+------------------------------------------------+
#endif

