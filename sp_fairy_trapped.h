#ifndef sp_fairy_trapped_h
#define sp_fairy_trapped_h

#include <PR/sp.h>

#define fairy_trappedTRUEIMAGEH	40
#define fairy_trappedTRUEIMAGEW	30
#define fairy_trappedIMAGEH	64
#define fairy_trappedIMAGEW	32
#define fairy_trappedBLOCKSIZEW	32
#define fairy_trappedBLOCKSIZEH	32
#define fairy_trappedSCALEX	1.0
#define fairy_trappedSCALEY	1.0
#define fairy_trappedMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap fairy_trapped_bitmaps[];
extern Gfx fairy_trapped_dl[];

#define NUM_fairy_trapped_BMS  (sizeof(fairy_trapped_bitmaps)/sizeof(Bitmap))

extern Sprite fairy_trapped_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------+
|                              |
|                              |
|                              |
|           @@@@@@@@           |
|       @CCCCCCCCCC   C@       |
|      @CCC@CCCCCC @Y@ C@      |
|    @CCC@@CCCCC @Y@@@@CCC@    |
|   @CCCC@@CCCCC Y@@@Y@CCCC@   |
|  @C  CYYYYYYC @Y@Y@@@CCCCC@  |
| @CC @ C@@YYYC Y@Y CC@@CCCCC@ |
| @CCC @@ @@YYC Y CC  Y@Y@Y@ @ |
|@CCCCC @@ YYY Y @@ @Y@Y@Y@Y C@|
|@C      @@ MYY @Y@@@Y@@@@@CCC@|
|@C      MMMMMYYCCCC@CC@C@@CCC@|
|@CCCCCC  MMMM YCCCC@CCCC@CCCC@|
|@CCCCCCCC@ MMMMM CCCCCCCCCCCC@|
| @CCCCCCC@ MMMMMM CCCCCCCCCC@ |
| @CCCCCCCCC MMMM CCCCC@@CCCC@ |
|  @CCCCCCCC MM@@ CCCC@@@CCC@  |
|   @CCCCCCCCC   @@  @@@@CC@   |
|    @CCCCCCCCC @ @@@@@CCC@    |
|      @CCCCCCC @ CC @ C@      |
|       @CCCCCC @ CC  C@       |
|           @@@@@@@@           |
|                              |
|                              |
+------------------------------+
#endif

