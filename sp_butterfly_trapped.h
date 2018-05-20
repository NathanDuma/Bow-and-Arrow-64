#ifndef sp_butterfly_trapped_h
#define sp_butterfly_trapped_h

#include <PR/sp.h>

#define butterfly_trappedTRUEIMAGEH	32
#define butterfly_trappedTRUEIMAGEW	30
#define butterfly_trappedIMAGEH	32
#define butterfly_trappedIMAGEW	32
#define butterfly_trappedBLOCKSIZEW	32
#define butterfly_trappedBLOCKSIZEH	32
#define butterfly_trappedSCALEX	1.0
#define butterfly_trappedSCALEY	1.0
#define butterfly_trappedMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap butterfly_trapped_bitmaps[];
extern Gfx butterfly_trapped_dl[];

#define NUM_butterfly_trapped_BMS  (sizeof(butterfly_trapped_bitmaps)/sizeof(Bitmap))

extern Sprite butterfly_trapped_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------+
|           @@@@@@@@           |
|        @@@CCCCCCCC@@@        |
|      @CCCCCCCCCCCCCCCC@      |
|     @CCCCCCCCCCCCCCCCCC@     |
|   @CCCCCCCCCCCCCCCCCCCCCC@   |
|  @CCCCCCCCCCCCCC@@@CCCCCCC@  |
| @CCCCCCCCCCCCCCCC@@@@@CCCCC@ |
| @CCCCCCCCCCCCC@@@@C@@@@CCCC@ |
|@CCCCCCCCCCCCCC  Y @@CCCCCCCC@|
|@CCCCCCC CCCCC rYrY CCCCCCCCC@|
|@C CCCCC CCC rY YrY CCCCCCCCC@|
|@CC CCCC CC rY   Y CCCCCCCCCC@|
|@CCCC CC C YrYrYrY CCCCCCCCCC@|
|@CCCCC C C rY     CCCCCCCCCCC@|
| @CCCCC   Y YrYrYrY CCCCCCCC@ |
| @CCCCCC   YrYr  Yr CCCCCCCC@ |
|  @CCCCC C   YrYrYr@@@CCCCC@  |
|   @CCCC C    YrYrY @@CCCC@   |
|     @CCCCC   CC@@@CCCCC@     |
|      @CCCCC  CCCCCCCCC@      |
|        @@@CCCCCCCC@@@        |
+------------------------------+
#endif

