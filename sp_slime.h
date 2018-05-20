#ifndef sp_slime_h
#define sp_slime_h

#include <PR/sp.h>

#define slimeTRUEIMAGEH	49
#define slimeTRUEIMAGEW	39
#define slimeIMAGEH	64
#define slimeIMAGEW	64
#define slimeBLOCKSIZEW	32
#define slimeBLOCKSIZEH	32
#define slimeSCALEX	1.0
#define slimeSCALEY	1.0
#define slimeMODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap slime_bitmaps[];
extern Gfx slime_dl[];

#define NUM_slime_BMS  (sizeof(slime_bitmaps)/sizeof(Bitmap))

extern Sprite slime_sprite;

#endif 

#if 0	/* Image preview */
+---------------------------------------+
|                                       |
|         ggggggg                       |
|     gggggggggggggg                    |
|    gggggggggggggggg                   |
|   gggggggggggggggggg                  |
|   ggggggggggggggggggg                 |
|  gggg ggggg gggggggggg                |
|  ggg   ggg   ggggggggg                |
|  ggg   ggg   ggggggggg                |
|  ggg   ggg   gggggggggg               |
| gggg   ggg   gggggggggg               |
| gggg   ggg   gggggggggg               |
| ggggg ggggg gggggggggggg              |
| gggggggggggggggggggggggg              |
| gggggggggggggggggggggggg              |
| ggggggggggggggggggggggggg             |
| gggg            gggggg gggggg         |
|  gg              gggg gggggggg        |
|  gg              ggg gggggggggg       |
|  ggggg        ggggggg gggggggggg      |
|  gggggggggggggggggggggggggg           |
|  g  ggggggggggggggggggggggggggggggg   |
|   gggggggggggg  gggggggggggggggggggg  |
| ggggggggggggggggggggggggggggggggggggg |
| gggg  ggggggggggggggggggggggggggggggg |
| g ggggggg  ggggggggggg gggggggggggggg |
|  gggggggggggggggggggggg  gggggggggggg |
| ggggggggggggggggggggggggggggggggggg   |
| gggggggggggggggggggggggggggggggggggg  |
| ggggggggggggggggggggggg ggggggggggggg |
| ggggggggggg gggggggggg g gggggggggggg |
|   ggggg   gg gggggggg ggggg  ggggggg  |
+---------------------------------------+
#endif

