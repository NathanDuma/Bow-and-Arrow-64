/*
   gfxinit.c
   
   The display list for the initialization of graphic 

   Copyright (C) 1997-1999, NINTENDO Co,Ltd.	
*/

#include <nusys.h>
#include "graphic.h"

/*
  The viewport structure 
  The conversion from (-1,-1,-1)-(1,1,1).  The decimal part of 2-bit. 
 */
static Vp vp = {
    SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0,	/* The scale factor  */
    SCREEN_WD*2, SCREEN_HT*2, G_MAXZ/2, 0,	/* Move  */
};

/*
  The initialization of RDP 
*/
Gfx setup_rdpstate[] = {
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPPipelineMode(G_PM_1PRIMITIVE),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WD, SCREEN_HT),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureFilter(G_TF_BILERP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetBlendMask(0xff),
    gsDPPipeSync(),
    gsSPEndDisplayList(),
};

/*
  The initialization of RSP 
*/
Gfx setup_rspstate[] = {
    gsSPViewport(&vp),
    gsSPClearGeometryMode(G_SHADE | G_SHADING_SMOOTH | G_CULL_BOTH |
    G_FOG | G_LIGHTING | G_TEXTURE_GEN |
    G_TEXTURE_GEN_LINEAR | G_LOD),
    gsSPTexture(0, 0, 0, 0, G_OFF),
    gsSPSetGeometryMode(G_SHADE | G_SHADING_SMOOTH),
    gsSPEndDisplayList(),
};

