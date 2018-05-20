#ifndef sp_wind_dead_h
#define sp_wind_dead_h

#include <PR/sp.h>

#define wind_deadTRUEIMAGEH	32
#define wind_deadTRUEIMAGEW	37
#define wind_deadIMAGEH	32
#define wind_deadIMAGEW	64
#define wind_deadBLOCKSIZEW	32
#define wind_deadBLOCKSIZEH	32
#define wind_deadSCALEX	1.0
#define wind_deadSCALEY	1.0
#define wind_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap wind_dead_bitmaps[];
extern Gfx wind_dead_dl[];

#define NUM_wind_dead_BMS  (sizeof(wind_dead_bitmaps)/sizeof(Bitmap))

extern Sprite wind_dead_sprite;

#endif 

#if 0	/* Image preview */
+-------------------------------------+
|             MMMMM                   |
|           MMM@@@@MMM                |
|          MM@@@@@@@@@@@M             |
|          M@@@@@@@@@@@@@M            |
|         M@@@@@@@@MMM                |
|         M@@@@@@@MM                  |
|         MM@@@MMM                    |
|          MM@@M            MMM       |
|            MM         MM@@@@@@@M    |
|                       MM@@@@@@@@M   |
| M                       MM@@@@@@@MM |
| M                        MM@@@@@@@M |
|M@M                         M@@@@@@@M|
|M@MM                        M@@@@@@@M|
|M@@MM         MM            M@@@@@@M |
|M@@@MMM     MMMM            M@@@@@@M |
|M@@@@@@@@@@@@@M             M@@@@M   |
|M@@@@@@@@@@@@@M            M@@@@M    |
| M@@@@@@@@@@@@M           M@@MM      |
| M@@@@@@@@@@@M           MMMM        |
|  MMM@@@@@@MMM                       |
+-------------------------------------+
#endif

