#ifndef sp_wind2_h
#define sp_wind2_h

#include <PR/sp.h>

#define wind2TRUEIMAGEH	32
#define wind2TRUEIMAGEW	30
#define wind2IMAGEH	32
#define wind2IMAGEW	32
#define wind2BLOCKSIZEW	32
#define wind2BLOCKSIZEH	32
#define wind2SCALEX	1.0
#define wind2SCALEY	1.0
#define wind2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap wind2_bitmaps[];
extern Gfx wind2_dl[];

#define NUM_wind2_BMS  (sizeof(wind2_bitmaps)/sizeof(Bitmap))

extern Sprite wind2_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------+
|              MMMMM           |
|            MMM@@@@MMM        |
|           MM@@@@@@@@@@@M     |
|           M@@@@@@@@@@@@@M    |
|          M@@@@@@@@MMM        |
|          M@@@@@@@MM          |
| M        M@@@@@MM            |
| M        M@@@@@M             |
|M@M        M@@@M    MMM       |
|M@MM       MM@@M MMM@@@MM     |
|M@@MM         MMMM@@@@@@@@M   |
|M@@@MMM     MMMM MM@@@@@@@MM  |
|M@@@@@@@@@@@@@@M   MM@@@@@@@M |
|M@@@@@@@@@@@@@@M    M@@@@@@@M |
| M@@@@@@@@@@@@M      M@@@@@@@M|
| M@@@@@@@@@@@MM      M@@@@@@@M|
|  MMM@@@@@@MMM       M@@@@@@M |
|    MMMMMMMM         M@@@@@M  |
|                    M@@@@M    |
|                    M@@@M     |
|                  MMMM        |
+------------------------------+
#endif

