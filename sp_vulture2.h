#ifndef sp_vulture2_h
#define sp_vulture2_h

#include <PR/sp.h>

#define vulture2TRUEIMAGEH	67
#define vulture2TRUEIMAGEW	55
#define vulture2IMAGEH	96
#define vulture2IMAGEW	64
#define vulture2BLOCKSIZEW	32
#define vulture2BLOCKSIZEH	32
#define vulture2SCALEX	1.0
#define vulture2SCALEY	1.0
#define vulture2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap vulture2_bitmaps[];
extern Gfx vulture2_dl[];

#define NUM_vulture2_BMS  (sizeof(vulture2_bitmaps)/sizeof(Bitmap))

extern Sprite vulture2_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|        iiii                                    |
|        r@@@@i       iiiiiiiiii                 |
| yYYYYy@@@@@@i    i@               iii          |
| Yy  yy@@@@@@i    i@i                           |
|   yyy iiii@@@@@@@i@i                    iiiiiii|
|            i@@@@i@i                           i|
|                 i i                           i|
|                 i i                  gii      i|
|                 i i                iyyy  i   i |
|               i   i               iyyyyy       |
|                   i              i             |
|             i    i              i              |
|           i     i             i                |
|         i      i            i                  |
|       i       i                                |
|       i      i            i                    |
|           iii         i                        |
|            i       ii                          |
|           i    i                               |
+------------------------------------------------+
#endif

