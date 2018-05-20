#ifndef sp_bulls_eye_h
#define sp_bulls_eye_h

#include <PR/sp.h>

#define bulls_eyeTRUEIMAGEH	40
#define bulls_eyeTRUEIMAGEW	17
#define bulls_eyeIMAGEH	64
#define bulls_eyeIMAGEW	32
#define bulls_eyeBLOCKSIZEW	32
#define bulls_eyeBLOCKSIZEH	32
#define bulls_eyeSCALEX	1.0
#define bulls_eyeSCALEY	1.0
#define bulls_eyeMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap bulls_eye_bitmaps[];
extern Gfx bulls_eye_dl[];

#define NUM_bulls_eye_BMS  (sizeof(bulls_eye_bitmaps)/sizeof(Bitmap))

extern Sprite bulls_eye_sprite;

#endif 

#if 0	/* Image preview */
+-----------------+
|                 |
|        IIII     |
|         IIII    |
|          IIII   |
|          IIII   |
|     rr    IIII  |
|    rrrr   IIII  |
|    rrrr   IIII  |
|   rrbbrr   IIII |
|   rbbbbr   IIII |
|  rrbbbbrr  IIII |
|  rbbbbbbr  IIII |
|  rbbYYbbr  IIII |
|  rbbYYbbr  IIII |
|  rbbbbbbr  IIII |
|  rrbbbbrr  IIII |
|  rrbbbbrr  IIII |
|   rrbbrr   IIII |
|   rrrrrr   IIII |
|    rrrr   IIII  |
|    rrrr   IIII  |
|     rr    IIII  |
|          IIII   |
|          IIII   |
|         IIII    |
|        IIII     |
+-----------------+
#endif

