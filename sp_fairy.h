#ifndef sp_fairy_h
#define sp_fairy_h

#include <PR/sp.h>

#define fairyTRUEIMAGEH	30
#define fairyTRUEIMAGEW	19
#define fairyIMAGEH	32
#define fairyIMAGEW	32
#define fairyBLOCKSIZEW	32
#define fairyBLOCKSIZEH	32
#define fairySCALEX	1.0
#define fairySCALEY	1.0
#define fairyMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap fairy_bitmaps[];
extern Gfx fairy_dl[];

#define NUM_fairy_BMS  (sizeof(fairy_bitmaps)/sizeof(Bitmap))

extern Sprite fairy_sprite;

#endif 

#if 0	/* Image preview */
+-------------------+
|                   |
|         Y@        |
|        @Y@Y       |
|        Y@Y@       |
| YYYYYY Y@Y@       |
|  @@YYY @Y@        |
| @@@@YY @Y         |
|  @@YYY Y@         |
|   @ MYY           |
|   @ MMYY @Y       |
|   @ MMYY  Y@Y@Y   |
|   @ MMM   @Y@Y@Y  |
|  @  MMMMM   @Y@Y@ |
|  @  MMMMMM   @Y@Y |
|      MMM@MM       |
|      MMM@@M       |
|       M @ @@@     |
|         @@  @@    |
|            @      |
|             @     |
+-------------------+
#endif

