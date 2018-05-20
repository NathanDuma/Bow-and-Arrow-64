/* 
 * File:   llist.h
 * Author: Nathan Duma
 *
 */

#ifndef LLIST_H
#define LLIST_H

#include "debug.h"
#include <malloc.h>
#include <stdlib.h>


typedef struct llist{
    void *node;
    struct llist *next;
    struct llist *prev;
} llist;


bool testtraversalllist(llist **head);
llist *addllist(llist *head, void *item);
void destructllist(llist *head);
void deleteitemllist(llist **node);

#ifdef __cplusplus
extern "C" {
#endif




#ifdef __cplusplus
}
#endif

#endif /* LLIST_H */

