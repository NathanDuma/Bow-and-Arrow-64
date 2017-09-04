/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <libdragon.h>
#include <assert.h>
#define SCREENWIDTH 640
#define SCREENHEIGHT 480


enum direction{
    up, down
};

typedef struct{
    float x; // x coordinate of vector
    float y; // y coordinate of the vector
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

