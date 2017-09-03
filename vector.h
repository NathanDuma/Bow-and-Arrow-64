/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <libdragon.h>
#include <assert.h>
#include <stdbool.h>
#define SCREENWIDTH 640
#define SCREENHEIGHT 480

bool paused;

enum direction{
    up, down
};

typedef struct{
    float x;
    float y;
    enum direction d; // direction of object
    float speed; // only used for weapons, since weapon struct can't hold any more variables?? (don't know why)
} vector;


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VECTOR_H */

