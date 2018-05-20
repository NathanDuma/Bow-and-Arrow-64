#ifndef sp_wind1_h
#define sp_wind1_h

#include <PR/sp.h>

#define wind1TRUEIMAGEH	32
#define wind1TRUEIMAGEW	30
#define wind1IMAGEH	32
#define wind1IMAGEW	32
#define wind1BLOCKSIZEW	32
#define wind1BLOCKSIZEH	32
#define wind1SCALEX	1.0
#define wind1SCALEY	1.0
#define wind1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap wind1_bitmaps[];
extern Gfx wind1_dl[];

#define NUM_wind1_BMS  (sizeof(wind1_bitmaps)/sizeof(Bitmap))

extern Sprite wind1_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------+
|           MMMMM              |
|        MMM@@MM               |
|     M@@@@MM                  |
|    M@@@@@M                   |
|  M@@@@@@M        MMM@@@MMM   |
| MM@@@@@@M       MM@@@@@@@@M  |
|MM@@@@@@@M     MM@@@@@@@@@@@M |
|MM@@@@@@@M     M@@@@@@@@@@@@M |
| M@@@@@@@@M   M@@@@MMM@@@@@@@M|
| MM@@@@@@@MM  M@MMM   MM@@@@@M|
|  MM@@@@@@@@@MMMM        M@@@M|
|   MMM@@@@@MMMM@MM       MM@@M|
|              M@@@MM       M@M|
|              M@@@@M       M@M|
|             M@@@@@@M      MM |
|            MM@@@@@@M      MM |
| MMM      MMM@@@@@@@M         |
|  MMMMMMMMM@@@@@@@@@M         |
|    M@@@@@@@@@@@@@@M          |
|     M@@@@@@@@@@@@@M          |
|        MMM@@@@@@MM           |
+------------------------------+
#endif

