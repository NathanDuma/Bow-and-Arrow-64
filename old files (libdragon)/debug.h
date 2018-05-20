/* 
 * File:   debug.h
 * Author: Nathan Duma
 *
 */

#include <libdragon.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define SCREENWIDTH 640
#define SCREENHEIGHT 480

extern bool debug;
extern display_context_t *disp;
extern int startDebugX;
extern int startDebugY;

void printMessage(const char *message, int x, int y);
void printDebugMessage(const char *message);
void printFloat(const char *message, float n);
void printInt(const char *message, int n);

#ifndef DEBUG_H
#define DEBUG_H

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* DEBUG_H */

