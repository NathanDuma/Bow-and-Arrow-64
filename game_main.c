
#include <ultra64.h>
#include <assert.h>
#include "bool.h"
#include "map.h"
#include "cont.h"
#include "graphic.h"
#include "bool.h"

void initGameMain(void);
void drawGameMain(void);
void _drawGameMain(int pendingGfx);
void updateGameMain(void);

map mapGameMain;
bool switching;
bool forward;
int frameCount;
float theta;

void initGameMain(void) {
    errors = 0;
    mapNumber = 0;
    initMap(&mapGameMain);

    switching = false;
    forward = true;
    frameCount = 0;

    doveHit = false;

    theta = 1.0F;
}

static void switchMap(void) {
    switching = true;

    if (frameCount < 5) {
        return;
    }

    if (forward) {
        mapNumber++;
    } else {
        mapNumber--;
    }

    mapGameMain.destructMap(&mapGameMain);


    frameCount = 0;
    switching = false;

    // we are done now
    if (mapNumber > 24) {
        currState = LOGO;

        // end graphics thread, goto game logo
        nuGfxFuncRemove();

        return;
    }

    initMap(&mapGameMain);

}

void updateGameMain(void) {

    nuContDataGetEx(contdata, 0);

    if (!switching) {
        mapGameMain.updateMap(&mapGameMain);

        // switch to gameover sequence
        if (mapGameMain.h.hit == true) {
            mapNumber = -mapGameMain.mapNumber;

            mapGameMain.destructMap(&mapGameMain);
            currState = GAME_OVER;

            // switch graphics thread
            nuGfxFuncRemove();
        }
    }

    if (switching == true) {
        // we have a 5 frame buffer for switching maps
        // reason is because it crashes if we don't
        frameCount++;
        switchMap();
    } else {
        if ((mapNumber % 2) == 0) {

            if (contdata[0].trigger & A_BUTTON || 
                    (debug && contdata[0].trigger & R_TRIG)) {
                forward = true;

                switchMap();
            } else if (debug) {
                if (contdata[0].trigger & L_TRIG) {
                    forward = false;

                    switchMap();
                }
            }

        } else {
            // the level has been completed
            if (mapGameMain.mapNumber != mapNumber) {
                forward = true;

                switchMap();

                return;
            }

            // pause the game
            if (contdata[0].trigger & START_BUTTON) {
                mapGameMain.paused = !mapGameMain.paused;
                return;
            }

            // don't process movement if we are pasued
            if (mapGameMain.paused == true) {
                return;
            }

            // update hero position
            mapGameMain.h.move(&mapGameMain.h, down);

            // switch levels fast (debug)
            if (debug) {
                if (contdata[0].trigger & R_TRIG) {
                    forward = true;

                    switchMap();
                } else if (contdata[0].trigger & L_TRIG) {
                    forward = false;

                    switchMap();
                }
            }
        }
    }



    theta++;
}

void drawGameMain(void) {
    Dynamic* dynamicp;
    char conbuf[20];
    static int counter = 0;

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


    if (switching == false) {
        if (mapGameMain.paused == true) {
            nuDebConTextPos(0, 18, 15);
            sprintf(conbuf, "PAUSED");
            nuDebConCPuts(0, conbuf);
        } else {
            mapGameMain.drawMap(&mapGameMain, &glistp);
            nuDebConClear(NU_DEB_CON_WINDOW0);
        }
    }


    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);

    assert((glistp - gfx_glist[gfx_gtask_no]) < GFX_GLIST_LEN);

    /* Activate the task and 
       switch display buffers */
    nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
            (s32) (glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
            NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);

    
    // display arrow count
    if ((mapGameMain.mapNumber % 2) != 0){
        nuDebConTextPos(0, 23, 2);
        sprintf(conbuf, "Arrows left: %d", mapGameMain.h.quiverCount);
        nuDebConCPuts(0, conbuf);
    }
    
    if (debug) {
        /* Change character representation positions */
        nuDebConTextPos(0, 12, 23);
        sprintf(conbuf, "switching=%d", switching);
        nuDebConCPuts(0, conbuf);
        nuDebConTextPos(0, 12, 24);
        sprintf(conbuf, "counter=%d", counter);
        nuDebConCPuts(0, conbuf);
        counter++;

        if (errors) {
            nuDebConTextPos(0, 12, 25);
            sprintf(conbuf, "error=%d", errors);
            nuDebConCPuts(0, conbuf);
            errors = 0;
        }
    }



    /* Display characters on the frame buffer */
    nuDebConDisp(NU_SC_SWAPBUFFER);

    /* Switch display list buffers */
    gfx_gtask_no ^= 1;
}

void _drawGameMain(int pendingGfx) {
    if (pendingGfx < 3) {
        drawGameMain();
    }

    updateGameMain();
}
