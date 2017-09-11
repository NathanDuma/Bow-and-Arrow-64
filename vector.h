/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include "debug.h"
#include <libdragon.h>
#include <assert.h>
#include <malloc.h>


enum direction{
    up, down
};

typedef struct{
    float x; // x coordinate of vector
    float y; // y coordinate of the vector
    enum direction d; // direction of object
    float speed; // only used for weapons, since weapon struct can't hold any more variables?? (don't know why)
} vector;

vector *initVector();


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VECTOR_H */

