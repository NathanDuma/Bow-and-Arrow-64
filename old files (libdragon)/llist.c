/* 
 * File:   llist.c
 * Author: Nathan Duma
 *
 */

#include "llist.h"
#include "animation.h"



// test traversal through llist and return true if successful

bool testtraversalllist(llist **head) {
    if (!head || !*head) return true;
    for (llist *it = *head; it; it = (*head)->next) {
        if (it->next == NULL) {
            for (llist *it2 = *head; it2; it2 = (*head)->prev) {
                int j = 1;
                j = j + 1;
            }
            return true;
        }
    }
    return false;
}



// add an item to the front of the linked list
// it should be the same type as the other items
// side effect: modifies head

llist *addllist(llist *head, void *item) {

    if (!item) printDebugMessage("Item is NULL");

    llist *newItem = malloc(sizeof (llist));

    if (!newItem) printDebugMessage("Failed to allocate newItem");

    newItem->node = item;
    newItem->next = head;
    newItem->prev = NULL;

    if (head) head->prev = newItem;

    return newItem;
}


// delete item from llist
// simply deletes the node requested

void deleteitemllist(llist **node) {

    llist *temp = NULL;

    if ((*node)->prev == NULL) { // deleting beginning element
        printDebugMessage("node->prev == NULL");
        if ((*node)->next == NULL) { // we only have a 1 element llist
            temp = *node;
            *node = (*node)->next;
            free(temp);
            printDebugMessage("Freed single elem");
        } else { // there is more than 1 element
            temp = *node;
            *node = (*node)->next;
            (*node)->prev = NULL;
            free(temp);
        }

    } else if ((*node)->next == NULL) { // deleting the end element
        temp = *node;
        *node = (*node)->prev;
        (*node)->next = NULL;
        free(temp);
        printDebugMessage("Freed end node");

    } else { // middle element
        temp = *node;
        (*node)->prev->next = (*node)->next;
        (*node)->next->prev = (*node)->prev;
        free(temp);
        printDebugMessage("Freed middle node");

    }

}



// destruct llist
// caller frees head
// we only need to get rid of the llist itself, not its objects
// caller frees void *data

void destructllist(llist *head) {
    llist *temp;

    while (head) {
        temp = head;
        head = head->next;
        free(temp);
    }

    temp = NULL;
}



