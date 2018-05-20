#ifndef sp_dove1_h
#define sp_dove1_h

#include <PR/sp.h>

#define dove1TRUEIMAGEH	36
#define dove1TRUEIMAGEW	32
#define dove1IMAGEH	64
#define dove1IMAGEW	32
#define dove1BLOCKSIZEW	32
#define dove1BLOCKSIZEH	32
#define dove1SCALEX	1.0
#define dove1SCALEY	1.0
#define dove1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap dove1_bitmaps[];
extern Gfx dove1_dl[];

#define NUM_dove1_BMS  (sizeof(dove1_bitmaps)/sizeof(Bitmap))

extern Sprite dove1_sprite;

#endif 

#if 0	/* Image preview */
+--------------------------------+
|                                |
|                                |
|                                |
|             @@                 |
|      @@@@   @@@                |
|       @@@@  @@@@               |
|       @@@@ @@@@@               |
|        @@@ @@@@@@              |
|        @@@ @@@@@@              |
|        @@@ @@@@@@@             |
|   @b@@@   @@@@@@@@    @@       |
|   @b@@@@@ @@@@@@@@ @ @@        |
|   @@@@@@@@@@@@@@@@@@@@@        |
|    @@@@@@@@@@@@@@@@@@@@@@      |
|        @@@@@@@@@@@@            |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
|                                |
+--------------------------------+
#endif

