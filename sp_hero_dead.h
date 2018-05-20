#ifndef sp_hero_dead_h
#define sp_hero_dead_h

#include <PR/sp.h>

#define hero_deadTRUEIMAGEH	112
#define hero_deadTRUEIMAGEW	101
#define hero_deadIMAGEH	128
#define hero_deadIMAGEW	128
#define hero_deadBLOCKSIZEW	32
#define hero_deadBLOCKSIZEH	32
#define hero_deadSCALEX	1.0
#define hero_deadSCALEY	1.0
#define hero_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap hero_dead_bitmaps[];
extern Gfx hero_dead_dl[];

#define NUM_hero_dead_BMS  (sizeof(hero_dead_bitmaps)/sizeof(Bitmap))

extern Sprite hero_dead_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|                                              YY|
| Y                   YYYYYYYYYYYY           YYYY|
| YYY                Y          YYY        YYYYYY|
| YYYYY                                 YYYYYYYY |
|  YYYYYYYY             YYYYYYYYY    YYYYYYY YYYY|
| Y YYYYYYYYY          YYYYYYYYYYYY YYYYY YYYYYY |
|   YY YYYYYYYYY      YYYYYYYYYYYYYY YYYYYYYY YYY|
| YYY YYY YYYYYYYY    YY YYY@@YYYY  YY YYY YYYY  |
|   YYYYYYY YYYYYYY   YYYYYYYY@@@@@ YYYYYYYY YYY |
|   YYY YYYYY YYYYYY    YYYYYY@@@  @ YYYYYYYYY   |
|  YY YYYYYYYYYYYYYY     @@@@@Y  YYYYYYYYYY YYYY |
|   YYYY YYYYYYYYYYYY  @@@ YYY   YYYY YYYYYYY    |
|      YYYY YYYYYYYYY@@@@@@@@@@@@YYYY YYYY YYY   |
|    YYYY YYYYYY YY @@@@@@@@@@@@@@@ YYYYYYYY     |
|     YYY YYYYYYY  @@@@@  @@@@@y@@@@@ YYYYYY     |
|        YYYYYYYYY @@@@@@@@ @@@y@@@@@@@@YY y     |
|         Y YYYYYY @@@@@@@@@@@  @  @@@@@Yy       |
|          YYY YYYY @@@@@@@@@ YYYY@@@  Y@        |
|             YYYYYY @@@@@@@@Y@@@@@@ @ @Y        |
|                   YYY @@@@  @   @@@ @          |
|                        @ @  @  @@ @@           |
|                       @@Y    @@ @@ @@y         |
|                       @ Y  @  @@ @@            |
|                       @Y @ @@ y    y@@         |
|                        Y@@ @@@i@@@@@@@         |
|                      Y Y@@ @@ I @@@@i@         |
|                      @ @@Y  @ Ii@@@@i@         |
|                     @@ @@   @ @i @@@@@@        |
|                    @@@@@@@ @@@@II @@@@@        |
|                    @@@@@@@@@@@@    @@@@@       |
|                   @@@@@@@@@@@      @@@@@       |
|                   @@@@@@@@@           @@@      |
|                  @@@@@@@                       |
|                 @@@@                           |
+------------------------------------------------+
#endif

