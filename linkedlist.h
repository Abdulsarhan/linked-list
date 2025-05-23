#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct LinkedList{
    int data;
    struct LinkedList* next;
}LinkedList;

#ifdef LL_STATIC
#define LLAPI static
#else
#define LLAPI extern // Extern is default.
#endif

#ifdef __cplusplus
extern "C" {
#endif

LLAPI void linked_list_add(LinkedList* linkedlist, int data);
LLAPI void linked_list_remove(LinkedList* currentlist, int listidx);
LLAPI void linked_list_print(LinkedList linkedlist, int listidx);

#ifdef __cplusplus
}
#endif

#ifdef LL_IMPLEMENTATION

LLAPI void linked_list_add(LinkedList* linkedlist, int data) {
    while(linkedlist->next != NULL) {
        linkedlist = linkedlist->next;
    }

    linkedlist->next = (LinkedList*)malloc(sizeof(LinkedList));
    assert(linkedlist->next != NULL);
    linkedlist = linkedlist->next;
    linkedlist->data = data;
    linkedlist->next = NULL;
}

LLAPI void linked_list_remove(LinkedList* currentlist, int listidx) {
    LinkedList* prevlist = NULL;

    for (int i = 0; i < listidx; i++) {
        if (currentlist == NULL) {
            printf("Index %d out of bounds.\n", listidx);
            return;
        }
        prevlist = currentlist;
        currentlist = currentlist->next;
    }

    if (prevlist == NULL || currentlist == NULL) {
        printf("Invalid index %d.\n", listidx);
        return;
    }

    prevlist->next = currentlist->next;
    free(currentlist);
}

LLAPI void linked_list_print(LinkedList linkedlist, int listidx) {

    for (int i = 0; i < listidx; i++) {
        if (linkedlist.next != NULL)
            linkedlist = *linkedlist.next;
	else
	    printf("ERROR: linked_list_print: param 2 (listidx) is invalid!\n");
    }

    printf("ListNumber: %d, ListData: %d\n", listidx ,linkedlist.data);
}
#endif
