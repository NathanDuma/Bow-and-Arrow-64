#ifndef sp_watcher2_h
#define sp_watcher2_h

#include <PR/sp.h>

#define watcher2TRUEIMAGEH	42
#define watcher2TRUEIMAGEW	28
#define watcher2IMAGEH	64
#define watcher2IMAGEW	32
#define watcher2BLOCKSIZEW	32
#define watcher2BLOCKSIZEH	32
#define watcher2SCALEX	1.0
#define watcher2SCALEY	1.0
#define watcher2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap watcher2_bitmaps[];
extern Gfx watcher2_dl[];

#define NUM_watcher2_BMS  (sizeof(watcher2_bitmaps)/sizeof(Bitmap))

extern Sprite watcher2_sprite;

#endif 

#if 0	/* Image preview */
+----------------------------+
|                            |
|            iiiiii          |
|          iiiiiiiiii        |
|         iiiiiiiiiii        |
|         iiiii   iiii       |
|         iiii  ii  ii       |
|           iiiiiii i        |
|        ii  iiiiiiii        |
|      iiiiiiiiiiiiiii       |
|      iiiiiiiiiiiiiii       |
|       iii iiiiiiiiiiiii    |
|        i  iiiiiiiiiiiii    |
|    iiiii iiiiiiiiiiiiii    |
|   iiiiii  iiiiiiiiiiiii    |
|  iiiiiiii  ii      iiiiii  |
|  iiiiiiiiii   iiiii iiiii  |
|  iiiiiiiii iiiiiiiii  iii  |
|  iiiiiiiiiiiiiiiiiiii iii  |
|   iiiiiii iiiiiiiiiii iii  |
|        ii iiiiiiiiiiiiiii  |
|   iiiiiiii iiiiiiiiiiiiiii |
|   iiiiiiii iiiii   iiiiiii |
|  iiiiiiiiiiiiiiiii iiiiiii |
| iiiiiiiiiiiiiiiiii iiiiiii |
|  iiiiiiiii iiiiii iiiiii   |
|  iiiiiiiii    i   iiiii    |
|     iiiiiiiiiiiii          |
|         iiiiiii            |
+----------------------------+
#endif

