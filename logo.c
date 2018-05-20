#include <nusys.h>
#include <ultra64.h>
#include <nualstl_n.h>
#include <assert.h>
#include "segment.h"
#include "bool.h"
#include "graphic.h"
#include "logo.h"
#include "cont.h"
#include "game_state.h"
#include "vector.h"
#include "common_sprites.h"

// prototypes
void initLogo(void);
void drawLogo(void);
void _drawLogo(int pendingGfx);
void updateLogo(void);
void Rom2Ram(void *from_addr, void *to_addr, s32 seq_size);

// from animation.c
void drawSprite(Gfx **pglistp, Sprite *sp, vector2D *v, vector2D *scale);


float theta2;

u32 frames;

u16 perspNorm;
f32 far_plane;
f32 near_plane;



Dynamic dynamicLogo;

vector2D nintendoScale;
vector2D sixtyfourScale;

vector2D nintendoPosition;
vector2D sixtyfourPosition;


// for audio
int seq;
bool audioStarted = false;
int ptr_buf[NU_AU_SAMPLE_SIZE];
int tune_buf[NU_AU_SONG_SIZE];
int sfx_buf[NU_AU_SE_SIZE];


u8 *song_start_list[] = {
    MUSIC1_START,
};

u8 *song_end_list[] = {
    MUSIC1_END,
};

void initLogo(void) {
    // spinning logo
    theta2 = 1.0F;

    // for audio
    seq = 0;
    audioStarted = false;
/*
    Rom2Ram((void *) PBANK_START, (void *) ptr_buf, PBANK_END - PBANK_START);
    MusPtrBankInitialize(ptr_buf, WBANK_START);
*/


    // switch to GAME_TITLE after 4-5 seconds
    frames = 0;

    // for the spinning logo
    perspNorm = 0;
    near_plane = 10;
    far_plane = 2000;


    // initalize stuff for the sprites (NINTENDO + 64)
    initVector2D(&nintendoScale);
    initVector2D(&sixtyfourScale);

    nintendoScale.x = 1.5;
    nintendoScale.y = 1.5;

    sixtyfourScale.x = 1.5;
    sixtyfourScale.y = 1.5;

    initVector2D(&nintendoPosition);
    initVector2D(&sixtyfourPosition);

    nintendoPosition.x = 45.0;
    nintendoPosition.y = 35.0;

    sixtyfourPosition.x = nintendoPosition.x +
            nintendologoTRUEIMAGEW * nintendoScale.x;
    sixtyfourPosition.y = 35.0;
}


/*----------------------------------------------------------------------*/
/*	Rom2Ram - Reads data from ROM into RAM			*/
/*	IN:	from_addr	The source address of the data in ROM		*/
/*		to_addr		The destination address of the data in RAM */
/*		seq_size	      	Size of the data to read			*/
/*	RET:	Nothing							*/

/*----------------------------------------------------------------------*/
void Rom2Ram(void *from_addr, void *to_addr, s32 seq_size) {
    /* Cannot transfer if size is an odd number, so make it an even number. */
    if (seq_size & 0x00000001) seq_size++;

    nuPiReadRom((u32) from_addr, to_addr, seq_size);
}

void updateLogo(void) {
    static int seqHandle = 0;
    theta2++;

    // play the audio after 30 frames
    if (frames > 30 && (audioStarted == false)) {
        /* Read the sequences. */

//        Rom2Ram((void *) song_start_list[seq], (void *) tune_buf,
//                song_end_list[seq] - song_start_list[seq]);
        /* Play a sequence. */
//        seqHandle = MusStartSong(tune_buf);


        audioStarted = true;
    }

    // exit after 4-5 seconds or so and switch to GAME_TITLE
    if (frames > 5 * 60) {

        currState = GAME_TITLE;
/*
        MusStop(MUSFLAG_SONGS, 0);
*/

        nuGfxFuncRemove();
    }
}

void drawLogo(void) {
    Dynamic* dynamicp;
    char conbuf[20];

    /* Specify the display list buffer */
    dynamicp = &gfx_dynamic[gfx_gtask_no];
    glistp = &gfx_glist[gfx_gtask_no][0];

    /* Initialize RCP */
    gfxRCPInit();

    /* Clear the frame and Z-buffer */
    gfxClearCfb();

    // make the background grey
    gDPSetFillColor(glistp++, GPACK_RGBA5551(96, 96, 96, 69) << 16 |
            GPACK_RGBA5551(96, 96, 96, 69));
    gDPFillRectangle(glistp++, 0, 0, SCREEN_WD - 1, SCREEN_HT - 1);
    gDPPipeSync(glistp++);

    /* projection,modeling matrix set */
    guPerspective(&dynamicp->projection, &perspNorm,
            30,
            (f32) SCREEN_WD / (f32) SCREEN_HT,
            near_plane, far_plane, 1.0);
    guTranslate(&dynamicp->translate, 0, 5.0F, -250.0F);
    guRotateRPY(&dynamicp->modeling, 0.0F, theta2, 0.0F);
    guLookAt(&dynamicp->camera, 0.0F, 150.0F, -550.0F, 0.0F, 0.0F, 0.0F, 0.0F, 1.0F, 0.0F);

    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&(dynamicp->projection)),
            G_MTX_PROJECTION | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&(dynamicp->camera)),
            G_MTX_PROJECTION | G_MTX_MUL | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&(dynamicp->translate)),
            G_MTX_MODELVIEW | G_MTX_LOAD | G_MTX_NOPUSH);
    gSPMatrix(glistp++, OS_K0_TO_PHYSICAL(&(dynamicp->modeling)),
            G_MTX_MODELVIEW | G_MTX_MUL | G_MTX_NOPUSH);
    gDPPipeSync(glistp++);
    gDPSetCycleType(glistp++, G_CYC_1CYCLE);
    gDPSetRenderMode(glistp++, G_RM_AA_ZB_OPA_SURF, G_RM_AA_ZB_OPA_SURF2);
    //gSPSetLights(glistp++, lightSource);
    gSPClearGeometryMode(glistp++, 0xFFFFFFFF);
    gSPSetGeometryMode(glistp++, G_SHADE | G_ZBUFFER | G_CULL_BACK | G_SHADE);
    gDPPipeSync(glistp++);

    // draw the n64 logo on screen
    gSPDisplayList(glistp++, logoDisplayList);


    // draw the sprite logo on top (NINTENDO)
    spInit(&glistp);

    drawSprite(&glistp, &nintendologo_sprite,
            &nintendoPosition, &nintendoScale);

    spFinish(&glistp);

    // remove the enddisplaylist so we can draw other things
    glistp--;

    // draw 64
    if (frames >= 0) {
        spInit(&glistp);

        drawSprite(&glistp, &sixtyfour_sprite,
                &sixtyfourPosition, &sixtyfourScale);

        spFinish(&glistp);

        // remove the enddisplaylist so we can draw other things
        glistp--;
    }

    gDPFullSync(glistp++);
    gSPEndDisplayList(glistp++);

    assert((glistp - gfx_glist[gfx_gtask_no]) < GFX_GLIST_LEN);

    /* Activate the task and 
       switch display buffers */
    nuGfxTaskStart(&gfx_glist[gfx_gtask_no][0],
            (s32) (glistp - gfx_glist[gfx_gtask_no]) * sizeof (Gfx),
            NU_GFX_UCODE_F3DEX, NU_SC_NOSWAPBUFFER);


    if (debug) {
        /* Change character representation positions */
        nuDebConTextPos(0, 12, 23);
        sprintf(conbuf, "Theta2=%5.1f", theta2);
        nuDebConCPuts(0, conbuf);
    }


    /* Display characters on the frame buffer */
    nuDebConDisp(NU_SC_SWAPBUFFER);

    frames++;

    /* Switch display list buffers */
    gfx_gtask_no ^= 1;
}

void _drawLogo(int pendingGfx) {
    if (pendingGfx < 3) {
        drawLogo();
    }

    updateLogo();
}


