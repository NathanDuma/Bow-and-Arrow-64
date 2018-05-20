#ifndef sp_vulture1_h
#define sp_vulture1_h

#include <PR/sp.h>

#define vulture1TRUEIMAGEH	67
#define vulture1TRUEIMAGEW	55
#define vulture1IMAGEH	96
#define vulture1IMAGEW	64
#define vulture1BLOCKSIZEW	32
#define vulture1BLOCKSIZEH	32
#define vulture1SCALEX	1.0
#define vulture1SCALEY	1.0
#define vulture1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap vulture1_bitmaps[];
extern Gfx vulture1_dl[];

#define NUM_vulture1_BMS  (sizeof(vulture1_bitmaps)/sizeof(Bitmap))

extern Sprite vulture1_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                             i                  |
|                            i i                 |
|             i iii              i               |
|             i      i      i     i              |
|             i        i   i                     |
|             i         i  i        i            |
|                        i i        i            |
|                          i         i           |
|              i          i          i           |
|              i          i          i           |
|               i         i           i          |
|               i         i           i          |
|                i       i             i         |
|                i       i             i         |
|                i       i             i         |
|                i      i              i         |
|                 i     i              i         |
|                 i    i               i         |
|                 i   i                i         |
|        iiii      i  i               i          |
|        r@@@@i    i                  i          |
| yYYYYy@@@@@@i    i@i               i           |
| Yy  yy@@@@@@i    i@i                           |
|   yyy  iii@@@@@@@i@i                    iiiiiii|
|            i@@@@i@i                           i|
|                 i                             i|
|                 i                    iii      i|
|                   i               yyyyy  i   i |
|                      iiiiiiiiii    yyyyy       |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
|                                                |
+------------------------------------------------+
#endif

