#include <stdlib.h>
#include "linkedlist.h"

int main() {
    llist_t *head = NULL;
    add_node(head, 1);
    pretty_print_linkedlist(head);
    return 0;
}