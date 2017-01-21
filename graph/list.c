#include <stdlib.h>
#include <assert.h>

#include "graph.h"

void list_destroy(ListNode *l) {

    ListNode *curptr = l;
    ListNode *nextptr = NULL;

    while (curptr != NULL) {
	nextptr = curptr->next;
	free(curptr);
	curptr = nextptr; 	
    }
}

ListNode * list_add(ListNode *l, void *obj, int weight) {

    ListNode *ptr = (ListNode*) malloc(sizeof(ListNode));
    assert(ptr);

    /* add obj, insert at front */
    ptr->obj = obj;
    ptr->weight = weight;
    ptr->next = l;

    return ptr;

}
