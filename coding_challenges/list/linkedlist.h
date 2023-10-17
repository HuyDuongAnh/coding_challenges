#ifndef __LINKLIST_H_
#define __LINKLIST_H_

/* Delete the Middle Node of a Linked List

You are given the head of a linked list. Delete the middle node, and return the head of the modified linked list.

The middle node of a linked list of size n is the ⌊n / 2⌋th node from the start using 0-based indexing, where ⌊x⌋ denotes the largest integer less than or equal to x.

Example 1:
Input: head = [1,3,4,7,1,2,6]
Output: [1,3,4,1,2,6]

Example 2:
Input: head = [1,2,3,4]
Output: [1,2,4]
*/

/* Solution approach:
- Adding node into the list
- Remove node from the list
*/
struct node{
    int data;
    struct node *next;
};

typedef struct node llist_t;

typedef enum {
    SUCCESS,
    ERROR,
} status_t;


status_t add_node(llist_t *head, int data);
status_t remove_node(llist_t *head, int data);
llist_t* find_node(int data);
int get_linkedlist_length(llist_t *head);
void pretty_print_linkedlist(llist_t *head);
#endif