/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#include "vector.h"


// init the vector at [0.0 0.0]
vector *initVector(){
    vector *self = malloc(sizeof(vector));
    
    if (!self) printDebugMessage("Failed to allocate vector *self");
    
    self->x = 0.0;
    self->y = 0.0;
    self->d = up;
    self->speed = 0.0;
    
    return self;
}
