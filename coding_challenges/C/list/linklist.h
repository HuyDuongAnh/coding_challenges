#ifndef __LINKLIST_H_
#define __LINKLIST_H_
typedef struct llist_t{
    int data;
    llist_t *next;
}llist_t;

typedef enum {
    SUCCESS,
    ERROR,
} status_t;

status_t add_node(llist_t *head, int data);
status_t remove_node(llist_t *head, int data);
llist_t* find_node(int data);
int get_linkList_lenght(llist_t *head);
void pretty_print_linklist(llist_t *head);
#endif