/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <libdragon.h>

typedef struct{
    float x;
    float y;
} vector;

typedef struct{
    sprite_t *a;
    int size;
    char state;
} animation;

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* VECTOR_H */

