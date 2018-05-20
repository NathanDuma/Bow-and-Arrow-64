#ifndef sp_tree2_h
#define sp_tree2_h

#include <PR/sp.h>

#define tree2TRUEIMAGEH	72
#define tree2TRUEIMAGEW	72
#define tree2IMAGEH	96
#define tree2IMAGEW	96
#define tree2BLOCKSIZEW	32
#define tree2BLOCKSIZEH	32
#define tree2SCALEX	1.0
#define tree2SCALEY	1.0
#define tree2MODE	SP_Z | SP_OVERLAP | SP_TRANSPARENT

// extern varaibles 
extern Bitmap tree2_bitmaps[];
extern Gfx tree2_dl[];

#define NUM_tree2_BMS  (sizeof(tree2_bitmaps)/sizeof(Bitmap))

extern Sprite tree2_sprite;

#endif 

#if 0	/* Image preview */
+------------------------------------------------+
|                                                |
|                                                |
|                    r                           |
|                    ry      r                   |
|                    yr  yr  yr                  |
|                    yrryyrr yr   r              |
|                    yrryyrryyr  yr     rrr rrr  |
|                    yrryyrryyr  yr    rrrrrrrrr |
|                    ryyrryyrryyrryy   rrrr r r r|
|                    ryy  yyrry  ryy   rrrr r ryr|
|                    ryyrr yrr yrryy   rrrr r ry |
|                    ryyr y rry rryy    r   r  y |
|                    yrr @@ryy @@yrr       ryyr  |
|                    yrr  @ryy  @yrr       ryyr  |
|                    yrr  @ryy  @yrr       ryyr  |
|                    yrr  @ryyr  yrr      rryy   |
|                    ryyrryyrryyrryy  yyrryyrryy |
|                      yrryyrryyrr  rryyrryyr    |
|                r  rryyrryyr yyr yyrryyrr       |
|              yrr  rryyrryyr yyr yyrry          |
|         rryyrryyrryyrryyrryyrryyr              |
|      ryyrryyrry  ryyrryyr    ryyrr             |
|    yrry rry        yrr         yrr             |
| rry rryyr          yr           rr             |
|    ry  r          rryyrryyrryyrryyr            |
|       r          yrryyrryyrryyrryyrr           |
|       r          yrryyrryyrryyrryyrr           |
|                 yyrryyrryyrryyrryyrry          |
|               yyrryyrryyrryyrryyrryyrry        |
|              ryyrryyrryyrryyrryyrryyrryyr      |
|             rryyrryyrry   yyrryyrryyrryyrr     |
|            yrryyrr         yrry    yrryyrryy   |
+------------------------------------------------+
#endif

