#include <stdlib.h>
#include <errno.h>
#include "list.h"

/* Return the length of the list */
int  ListLength(List* list) {
	return list->num_members;
}

/* Return true if list is empty */
int  ListEmpty(List* list) {
	return (ListLength(list) == 0);
}

/* Create a new element and insert at back of list */
int  ListAppend(List* list, void* ptr) {
	return ListInsertAfter(list,ptr,ListLast(list));
}

int  ListPrepend(List* list, void* ptr) {
	return ListInsertBefore(list,ptr,ListFirst(list));
}

void ListUnlink(List* list, ListElem* elem) {
	elem->prev = elem->next;
	list->num_members--;
	free(elem);	
}

void ListUnlinkAll(List* list) {
	ListElem *elem=NULL;
  	for (elem=ListFirst(list);elem != NULL;elem=ListNext(list, elem)) {
      	    ListUnlink(list,elem); 
        } 
}

int  ListInsertAfter(List* list, void* ptr, ListElem* elem) {

	/* Create new element */
	ListElem *newElem = (ListElem*) malloc(sizeof(ListElem));
	if (newElem == NULL) return FALSE;

	/* Add obj pointer to element */
	elem->obj = ptr;
	
	/* Insert new element */
	newElem->prev = elem;
	newElem->next = elem->next;
	elem->next = newElem;
	newElem->next->prev = newElem;

	/* Update the count */
	list->num_members++;

	return TRUE;
}

int  ListInsertBefore(List* list, void* ptr, ListElem* elem) {
	/* Create new element */
	ListElem *newElem = (ListElem*) malloc(sizeof(ListElem));
	if (newElem == NULL) return FALSE;

	/* Add obj pointer to element */
	elem->obj = ptr;
	
	/* Insert new element */
	newElem->next = elem;
	newElem->prev = elem->prev;
	elem->prev = newElem;
	newElem->prev->next = newElem;	

	/* Update the count */
	list->num_members++;

	return TRUE;
}

/* Return the first element in the list */
ListElem *ListFirst(List* list) {
	return list->anchor.next;
}

/* Return the last element in the list */
ListElem *ListLast(List* list) {
	return list->anchor.prev;
}

/* Return the next element in the list given the current element */
ListElem *ListNext(List* list, ListElem* elem) {
	if ( elem->next == &(list->anchor) )
	    return NULL;
	else
	    return elem->next;
}

/* Return the previous element in the list given the current element */
ListElem *ListPrev(List* list, ListElem* elem) {
	if ( elem->prev == &(list->anchor) )
	    return NULL;
	else
	    return elem->prev;
}


/* Iterate the list to find element whos obj matches ptr */
ListElem *ListFind(List* list, void* ptr) {
	ListElem *elem=NULL;
  	for (elem=ListFirst(list);elem != NULL;elem=ListNext(list, elem)) {
      	    if (ptr == elem->obj) break; 
        } 
	return elem;
}

/* Initialize the list to 0 and NULL for anchor */
int ListInit(List* list) {
	list->num_members = 0;
	list->anchor.prev = &(list->anchor);
	list->anchor.next = &(list->anchor);
	return TRUE;
}

