
#include <ultra64.h>
#include <nusys.h>
#include <assert.h>
#include "map.h"
#include "graphic.h"
#include "cont.h"
#include "game_state.h"

void initGameOver(void);
void drawGameOver(void);
void _drawGameOver(int pendingGfx);
void updateGameOver(void);


map mapGameOver;
float theta;

void initGameOver(void) {
    initMap(&mapGameOver);
    theta = 0.0;
}

void updateGameOver() {
    nuContDataGetEx(contdata, 0);

    mapGameOver.updateMap(&mapGameOver);

    if (contdata[0].trigger & A_BUTTON ||
            contdata[0].trigger & B_BUTTON ||
            contdata[0].trigger & START_BUTTON) {
        mapNumber = 0;

        mapGameOver.destructMap(&mapGameOver);
        currState = GAME_TITLE;
        nuGfxFuncRemove();
    }

    theta++;
}

void drawGameOver(void) {
    Dynamic* dynamicp;
    char conbuf[20];

    /* Specify the display list buffer */
    dynamicp = &gfx_dynamic[gfx_gtask_no];
    glistp = &gfx_glist[gfx_gtask_no][0];

    /* Initialize RCP */
    gfxRCPInit();

    /* Clear the frame and Z-buffer */
    gfxClearCfb();

    /* projection,modeling matrix set */
    guOrtho(&dynamicp->projection,
            -(float) SCREEN_WD / 2.0F, (float) SCREEN_WD / 2.0F,
            -(float) SCREEN_HT / 2.0F, (float) SCREEN_HT / 2.0F,
            1.0F, 10.0F, 1.0F);
    guRotate(&dynamicp->modeling, theta, 0.0F, 0.0F, 1.0F);
    guTranslate(&dynamicp->translate, 0, 0, 0.0F);


    mapGameOver.drawMap(&mapGameOver, &glistp);


    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);

    assert((glistp - gfx_glist[gfx_gtask_no]) < GFX_GLIST_LEN);

    /* Activate the task and 
       switch display buffers */
    nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
            (s32) (glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
            NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);


    if (debug) {
        nuDebConTextPos(0, 12, 24);
        sprintf(conbuf, "mapNumber=%d", mapNumber);
        nuDebConCPuts(0, conbuf);
        if (errors) {
            nuDebConTextPos(0, 12, 25);
            sprintf(conbuf, "error=%d", errors);
            nuDebConCPuts(0, conbuf);
            errors = 0;
        }
    } else {
        nuDebConClear(NU_DEB_CON_WINDOW0);
    }



    /* Display characters on the frame buffer */
    nuDebConDisp(NU_SC_SWAPBUFFER);

    /* Switch display list buffers */
    gfx_gtask_no ^= 1;
}

void _drawGameOver(int pendingGfx) {
    if (pendingGfx < 2) {
        drawGameOver();
    }
    updateGameOver();
}

