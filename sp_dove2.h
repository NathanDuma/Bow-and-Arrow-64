#ifndef sp_dove2_h
#define sp_dove2_h

#include <PR/sp.h>

#define dove2TRUEIMAGEH	36
#define dove2TRUEIMAGEW	32
#define dove2IMAGEH	64
#define dove2IMAGEW	32
#define dove2BLOCKSIZEW	32
#define dove2BLOCKSIZEH	32
#define dove2SCALEX	1.0
#define dove2SCALEY	1.0
#define dove2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap dove2_bitmaps[];
extern Gfx dove2_dl[];

#define NUM_dove2_BMS  (sizeof(dove2_bitmaps)/sizeof(Bitmap))

extern Sprite dove2_sprite;

#endif 

#if 0	/* Image preview */
+--------------------------------+
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|   @b@@  @@@@@@@@      @        |
|   @b@@@@@@@@@@@@@@@@ @ @       |
|   @@@@@@@@@@@@@@@@@@@@ @@      |
|    @@@@ @@@@@@@@@@@@@@@@@      |
|        @@@@@@@@@@ @            |
|        @@@@@@@@@@              |
|       @@@@@@@@@@               |
|     @ @@@@@@@@                 |
|   @@ @@@@@@@                   |
|  @@ @@@@@@@@                   |
|    @@@@@                       |
|    @@@                         |
|                                |
|                                |
+--------------------------------+
#endif

