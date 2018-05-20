/* 
 * File:   vector.h
 * Author: Nathan Duma
 *
 */

#include "vector.h"


// init the vector at [0.0 0.0]
void initVector2D(vector2D *self) {
    self->x = 0.0F;
    self->y = 0.0F;
    self->d = up;
}
