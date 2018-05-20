#ifndef sp_butterfly_burst_h
#define sp_butterfly_burst_h

#include <PR/sp.h>

#define butterfly_burstTRUEIMAGEH	33
#define butterfly_burstTRUEIMAGEW	30
#define butterfly_burstIMAGEH	64
#define butterfly_burstIMAGEW	32
#define butterfly_burstBLOCKSIZEW	32
#define butterfly_burstBLOCKSIZEH	32
#define butterfly_burstSCALEX	1.0
#define butterfly_burstSCALEY	1.0
#define butterfly_burstMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap butterfly_burst_bitmaps[];
extern Gfx butterfly_burst_dl[];

#define NUM_butterfly_burst_BMS  (sizeof(butterfly_burst_bitmaps)/sizeof(Bitmap))

extern Sprite butterfly_burst_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------+
|                              |
|                              |
|       @ CCC    CC CC @       |
|       C  C       CC C @      |
|    @CCCC             C       |
|    C C C    C       CC  C    |
|        C       CC @ @        |
| @    C    C    C       CC    |
| @C C     CCC           C  C  |
|                C         C C@|
| CCC CC                 C    @|
| C     C                C   C@|
|@ C   C CC     C  C         C@|
|@ C     C C   C        C C   @|
|    C C        CC       CCC @ |
|   C  C     C CC   C C   C  @ |
|  @C C        C C   @C  C C@  |
|  @ CCC       C      @ CC C@  |
|    @C  C   CC     @@    @    |
|       CC C CC C   CC C @     |
|       @CCC  CC    CC         |
|        @@    CC  C  @        |
+------------------------------+
#endif

