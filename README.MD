# A Singly-Linked List.
A simple implementaion of a singly-linked list.
You are meant to modify the source to get the most out of this.

# Usage
#define LL_IMPLEMENTATION
#define "linkedlist.h"

```C
int main() {
    LinkedList list = {1, NULL} // Set the data to what you want, and set the pointer to NULL.
    linked_list_add(&list, 1);
    linked_list_remove(&list, 1);
    linked_list_add(&list, 2);
    linked_list_add(&list, 3);
    linked_list_print(list, 0);
    linked_list_print(list, 1);
    linked_list_print(list, 2);

    return 0;
}
```