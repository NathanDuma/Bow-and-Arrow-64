#ifndef sp_watcher1_h
#define sp_watcher1_h

#include <PR/sp.h>

#define watcher1TRUEIMAGEH	42
#define watcher1TRUEIMAGEW	28
#define watcher1IMAGEH	64
#define watcher1IMAGEW	32
#define watcher1BLOCKSIZEW	32
#define watcher1BLOCKSIZEH	32
#define watcher1SCALEX	1.0
#define watcher1SCALEY	1.0
#define watcher1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap watcher1_bitmaps[];
extern Gfx watcher1_dl[];

#define NUM_watcher1_BMS  (sizeof(watcher1_bitmaps)/sizeof(Bitmap))

extern Sprite watcher1_sprite;

#endif 

#if 0	/* Image preview */
+----------------------------+
|                            |
|            @@@@@@          |
|          @@@@@@@@@@        |
|         @@@@@@@@@@@        |
|         @@@@@   @@@@       |
|         @@@@  @@  @@       |
|           @@@@@@@ @        |
|        @@  @@@@@@@@        |
|      @@@@@@@@@@@@@@@       |
|      @@@@@@@@@@@@@@@       |
|       @@@ @@@@@@@@@@@@@    |
|        @  @@@@@@@@@@@@@    |
|    @@@@@ @@@@@@@@@@@@@@    |
|   @@@@@@  @@@@@@@@@@@@@    |
|  @@@@@@@@  @@      @@@@@@  |
|  @@@@@@@@@@   @@@@@ @@@@@  |
|  @@@@@@@@@ @@@@@@@@@  @@@  |
|  @@@@@@@@@@@@@@@@@@@@ @@@  |
|   @@@@@@@ @@@@@@@@@@@ @@@  |
|        @@ @@@@@@@@@@@@@@@  |
|   @@@@@@@@ @@@@@@@@@@@@@@@ |
|   @@@@@@@@ @@@@@   @@@@@@@ |
|  @@@@@@@@@@@@@@@@@ @@@@@@@ |
| @@@@@@@@@@@@@@@@@@ @@@@@@@ |
|  @@@@@@@@@ @@@@@@ @@@@@@   |
|  @@@@@@@@@    @   @@@@@    |
|     @@@@@@@@@@@@@          |
|         @@@@@@@            |
+----------------------------+
#endif

