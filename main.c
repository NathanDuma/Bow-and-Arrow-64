#include <nusys.h>
#include <ultra64.h>
#include <nualstl_n.h>
#include "main.h"
#include "cont.h"
#include "segment.h"
#include "game_state.h"


/* Declaration of the external function  */
void _drawLogo(int pendingGfx);
void _drawGameOver(int pendingGfx);
void _drawGameMain(int pendingGfx);
void _drawGameTitle(int pendingGfx);

// 0.524288mb of heap space
u8 heap[1024 * 512 * 1];


// init the heap

int initHeap(void) {
    if (InitHeap(heap, sizeof (heap)) == -1) {
        return -1;
    }
    return 0;
}

/* Initialize audio. */
void initAudio(void) {
    musConfig c;

    c.control_flag = 0; /* Set to MUSCONTROL_RAM if wbk file also placed in RAM */
    c.channels = NU_AU_CHANNELS; /* Maximum total number of channels */
    c.sched = NULL; /* Ignore */
    c.thread_priority = NU_AU_MGR_THREAD_PRI; /* Usually not changed */
    c.heap = (unsigned char*) NU_AU_HEAP_ADDR; /* Usually not changed */
    c.heap_length = NU_AU_HEAP_SIZE;
    c.ptr = NULL; /* Can set the default ptr file */
    c.wbk = NULL; /* Can set the default wbk file */
    c.default_fxbank = NULL; /* Can set the default bfx file  */
    c.fifo_length = NU_AU_FIFO_LENGTH; /* Usually not changed */
    c.syn_updates = NU_AU_SYN_UPDATE_MAX;
    c.syn_output_rate = 44100;
    /* Usually set to NU_AU_OUTPUT_RATE=32kHz or less*/
    c.syn_rsp_cmds = NU_AU_CLIST_LEN;
    c.syn_retraceCount = 1; /* Usually not changed */
    c.syn_num_dma_bufs = NU_AU_DMA_BUFFER_NUM;
    c.syn_dma_buf_size = NU_AU_DMA_BUFFER_SIZE;

    /* Initialize the Audio Manager. */
    nuAuStlMgrInit(&c);

    /* Register the PRENMI function.*/
    nuAuPreNMIFuncSet(nuAuPreNMIProc);
}

void main(void) {
    currState = INIT;

    for (;;) {
        switch (currState) {
            case INIT:
                initHeap();

                initController();

                mapNumber = 0;

                debug = false;

                initAudio();

                /* The initialization of graphic  */
                nuGfxInit();
                /* The screen display is ON */
                nuGfxDisplayOn();

                if (debug) {
                    currState = GAME_MAIN;
                } else {
                    currState = LOGO;
                }

                break;
            case LOGO:
                initLogo();

                /* Register call-back  */
                nuGfxFuncSet((NUGfxFunc) _drawLogo);
                currState = IDLE;
                break;
            case GAME_TITLE:
                initGameTitle();

                nuGfxFuncSet((NUGfxFunc) _drawGameTitle);

                currState = IDLE;
                break;
            case GAME_OVER:
                initGameOver();

                nuGfxFuncSet((NUGfxFunc) _drawGameOver);

                currState = IDLE;
                break;
            case GAME_MAIN:
                initGameMain();

                /* Register call-back  */
                nuGfxFuncSet((NUGfxFunc) _drawGameMain);

                currState = IDLE;
                break;
            case IDLE:
                // draw graphics to the screen
                break;
            default:
                // should never reach here
                break;
        }
    }
}
