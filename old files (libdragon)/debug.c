/* 
 * File:   debug.h
 * Author: Nathan Duma
 *
 */

#include "debug.h"
#include <malloc.h>

// store the text (max 300 characters)
char tStr[300];
// have the display here always
display_context_t *disp;
// starting positions for debug text
int startDebugX;
int startDebugY;
// set debug true in main if you want debug messages!
bool debug;
    

// updates screen to show error message
static void updateScreen(){
    graphics_set_color(0xFFFFFFFF, 0x00000000); // reset colours
    display_show(*disp);
}

// updates the screen coordinates to print the next debug message
// might be buggy and some things might overlap
static void updateDebugPosition(){
    if (startDebugY > (SCREENHEIGHT - 30)){
        startDebugY = 0;
        startDebugX += 90;
    } else{
        startDebugY += 10;
    }
}


// check if string starts with prefix "END"
// and make the whole text be RED
// or starts with "Failed", makes text BLUE
static bool prefix(const char *str){
    const char *end = "END";
    const char *failed = "Failed";
    
    if (strncmp(end, str, strlen(end)) == 0){
        graphics_set_color(0xFF000000, 0x00000000); // make text colour RED
    } else if (strncmp(failed, str, strlen(failed)) == 0){
        graphics_set_color(0x0000FF00, 0x00000000); // make colour 
    }
    return true;
}


// prints a message on screen at x,y 
void printMessage(const char *message, int x, int y){
    sprintf(tStr, message);
    graphics_draw_text(*disp, x, y, tStr);
}


// prints a message on screen at startDebugX, startDebugY
void printDebugMessage(const char *message){
    if (!debug) return;
    
    // change to RED if starts with "END"
    prefix(message);
    
    sprintf(tStr, message);
    graphics_draw_text(*disp, startDebugX, startDebugY, tStr);
    updateDebugPosition();
    updateScreen();
}

// prints a float on screen at x,y 
void printFloat(const char *message, float n){
    if (!debug) return;
    
    // change to RED if starts with "END"
    prefix(message);
    
    sprintf(tStr, message, n);
    graphics_draw_text(*disp, startDebugX, startDebugY, tStr);
    updateDebugPosition();
    updateScreen();
}


// prints a int on screen at x,y 
void printInt(const char *message, int n){
    if (!debug) return;
    
    // change to RED if starts with "END"
    prefix(message);
    
    sprintf(tStr, message, n);
    graphics_draw_text(*disp, startDebugX, startDebugY, tStr);
    updateDebugPosition();
    updateScreen();
}
