/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <ultra64.h>

typedef enum {
    up, down
} direction;

typedef struct {
    float x; // x coordinate of vector
    float y; // y coordinate of the vector
    direction d; // direction of object
} vector2D;

void initVector2D(vector2D *self);


#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VECTOR2D_H */

