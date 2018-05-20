#ifndef sp_tree1_h
#define sp_tree1_h

#include <PR/sp.h>

#define tree1TRUEIMAGEH	72
#define tree1TRUEIMAGEW	72
#define tree1IMAGEH	96
#define tree1IMAGEW	96
#define tree1BLOCKSIZEW	32
#define tree1BLOCKSIZEH	32
#define tree1SCALEX	1.0
#define tree1SCALEY	1.0
#define tree1MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap tree1_bitmaps[];
extern Gfx tree1_dl[];

#define NUM_tree1_BMS  (sizeof(tree1_bitmaps)/sizeof(Bitmap))

extern Sprite tree1_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|                                                |
|                                                |
|                     y       y                  |
|                    yrr yr  yr                  |
|                    yrryyr yyr   r              |
|                    yrryyrryyr  yr              |
|                    yrryyrryyr  yr              |
|                    ryyrryyrryyrryy             |
|                      yrry   yyrryy             |
|                    ry  r yrryyrryy             |
|                     @yrry @ryyrryy             |
|                     @ yyr @ rryyrr             |
|                       yyr   rryyrr             |
|                       yyr   rryyrr             |
|                      ryyrr yrryyrr             |
|                    ryyrryyrryyrryy             |
|                  yrryy ryy ry rryy             |
|              yrryyrryyrr yrryy ryy             |
|              yrryyrryyrryyrryy ryy ry          |
|                    yrryyrry rryyrr yrryyr      |
|                yrryyrryyr yyrryyrr  rryyr yy   |
|              ryyrryyrry    yrryyrr   ry rry rry|
|           yyrryyrryy ry    yrryyrr     y ry    |
|       rryyr yyrr  rryyrryyrryyrryy     ry  ry  |
|      yr  yrry    yrryyrryyrryyrry rr    y      |
|        ry  ry    yrryyrryyrryyrryyrr           |
|        r   r    yyrryyrryyrryyr yyrry          |
|               yyrryyrryyrryyr yyrryyrry        |
|              ryyrryyrryyrryyrry rryyrryyr      |
|             rryyrryyrry   y rryyrryyrryyrr     |
|            yrryyrr         yrry    yrryyrryy   |
+------------------------------------------------+
#endif

