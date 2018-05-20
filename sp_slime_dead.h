#ifndef sp_slime_dead_h
#define sp_slime_dead_h

#include <PR/sp.h>

#define slime_deadTRUEIMAGEH	49
#define slime_deadTRUEIMAGEW	40
#define slime_deadIMAGEH	64
#define slime_deadIMAGEW	64
#define slime_deadBLOCKSIZEW	32
#define slime_deadBLOCKSIZEH	32
#define slime_deadSCALEX	1.0
#define slime_deadSCALEY	1.0
#define slime_deadMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap slime_dead_bitmaps[];
extern Gfx slime_dead_dl[];

#define NUM_slime_dead_BMS  (sizeof(slime_dead_bitmaps)/sizeof(Bitmap))

extern Sprite slime_dead_sprite;

#endif 

#if 0	/* Image preview */
+----------------------------------------+
|         @@@@@@@                        |
|      @@@YYYYYYY@@                      |
|    @YYYYYYYYYYYYYY@                    |
|   @YYYYYYYYYYYYYYYY@                   |
|  @YYYYYYYYYYYYYYYYYY@                  |
|  @YYYYYYYYYYYYYYYYYYY@                 |
| @YYYY@YYYYY@YYYYYYYYYY@                |
| @YYY@@@YYY@@@YYYYYYYYY@                |
| @YYY@@@YYY@@@YYYYYYYYY@                |
| @YYY@@@YYY@@@YYYYYYYYYY@               |
|@YYYY@@@YYY@@@YYYYYYYYYY@               |
|@YYYY@@@YYY@@@YYYYYYYYYY@               |
|@YYYYY@YYYYY@YYYYYYYYYYYY@              |
|@YYYYYYYYYYYYYYYYYYYYYYYY@              |
|@YYYYYYYYYYYYYYYYYYYYYYYY@              |
|@YYYYYYYYYYYYYYYYYYYYYYYYY@             |
|@YYYY@@@@@@@@@@@@YYYYYY@YYYYYY@         |
| @YY@@@@@@@@@@@@@@YYYY@YYYYYYYY@        |
| @YY@@@@@@@@@@@@@@YYY@YYYYYYYYYY@       |
| @YYYYY@@@@@@@@YYYYYYY@YYYYYYYYYY@      |
| @YYYYYYYYYYYYYYYYYYYYYYYYYY@@@@@@      |
| @Y@@YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY@@  |
|  @YYYYYYYYYYYY@@YYYYYYYYYYYYYYYYYYYYY@ |
|@YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY@|
|@YYYY@@YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY@|
|@Y@YYYYYYY@@YYYYYYYYYYY@YYYYYYYYYYYYYYY@|
| @YYYYYYYYYYYYYYYYYYYYYY@@YYYYYYYYYYYYY@|
|@YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY@@  |
|@YYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYYY@ |
|@YYYYYYYYYYYYYYYYYYYYYYY@YYYYYYYYYYYYYY@|
|@YYYYYYYYYYY@YYYYYYYYYY@Y@YYYYYYYYYYYYY@|
|  @YYYYY@@@YY@YYYYYYYY@YYYYY@@YYYYYYYY@ |
+----------------------------------------+
#endif

