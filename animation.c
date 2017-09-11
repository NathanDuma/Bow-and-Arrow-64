/* 
 * File:   animation.c
 * Author: Nathan Duma
 *
 */

#include "animation.h"


// add the sprites to the animation
static void addAnimations(animation *self, const char *sprites[], int size){
    self->size = size;
    
    self->a = malloc(sizeof(sprite_t*) * self->size);
    
    if (!self->a) printDebugMessage("Failed to allocate self->a");
    
    // load all of the sprites into a
    for (int i = 0; i < self->size; i++){
        int fp = dfs_open(sprites[i]);
        self->a[i] = malloc(dfs_size(fp));
        
        if (!self->a[i]) printInt("Failed to allocate self->a[%i]", i);
        
        dfs_read(self->a[i], 1, dfs_size(fp), fp);
        dfs_close(fp);
    }
}


// destruct the animation
// caller frees
static void destructAnimation(animation *self){
    for (int i = 0; i < self->size; i++){
        free(self->a[i]);
    }
    printDebugMessage("Freed self->a[i]");
    
    free(self->a);
    printDebugMessage("Freed self->a");
    
    printDebugMessage("END destructAnimation");
}

animation *initAnimation(){
    animation *self = malloc(sizeof(animation));
    
    if (!self) printDebugMessage("Failed to allocate animation *self");
    
    self->state = 0;
    self->size = 0;
    self->a = NULL;

    self->addAnimations = addAnimations;
    self->destructAnimation = destructAnimation;
    
    return self;
}
    
