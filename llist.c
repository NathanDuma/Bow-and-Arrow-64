/* 
 * File:   llist.c
 * Author: Nathan Duma
 *
 */

#include "llist.h"


// add an item to the front of the linked list
// it should be the same type as the other items
// side effect: modifies head
llist *addllist(llist *head, void *item){
    
    if (!item) printDebugMessage("Item is NULL");
    
    llist *newItem = (llist*)malloc(sizeof(llist));
    
    if (!newItem) printDebugMessage("Failed to allocate newItem");
    
    newItem->node = item;
    newItem->next = head;
    
    return newItem;
}


// destruct llist
// caller frees head
// we only need to get rid of the llist itself, not its objects
// caller frees void *data
void destructllist(llist *head){
    llist *temp;
    
    while(head){
        temp = head;
        head = head->next;
        free(temp);
    }
    
    temp = NULL;
}
