/* 
 * File:   game_state.h
 * Author: Nathan Duma
 *
 * Created on May 11, 2018, 1:02 AM
 */

#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <ultra64.h>
#include "bool.h"

#ifndef ERRORS
#define ERRORFLAG1 (1<<0)
#define ERRORFLAG2 (1<<1)
#define ERRORFLAG3 (1<<2)
#define ERRORFLAG4 (1<<3)
#define ERRORFLAG5 (1<<4)
#define ERRORFLAG6 (1<<5)
#define ERRORFLAG7 (1<<6)
#define ERRORFLAG8 (1<<7)
#define ERRORFLAG9 (1<<8)
#define ERRORFLAG10 (1<<9)
#define ERRORFLAG11 (1<<10)
#define ERRORFLAG12 (1<<11)
#define ERRORFLAG13 (1<<12)
#define ERRORFLAG14 (1<<13)
#endif


typedef enum state_e {
    INIT, LOGO, GAME_TITLE, GAME_MAIN,
    GAME_OVER, IDLE
} state_t;

// state of the game
state_t currState;

int errors;
bool debug;

bool doveHit;

// even maps are scroll, odd maps have enemies
int mapNumber;

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* GAME_STATE_H */

