#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

status_t add_node(llist_t *head, int data){
    llist_t *new_node, *curr_node;
    // Create a new node
    new_node = (llist_t *)malloc(sizeof(llist_t));
    new_node->data = data;
    new_node->next = NULL;
    // Checking if head is NULL
    if(head == NULL){
        head = new_node;
    }
    else{
        curr_node = head;
        while(curr_node->next != NULL){
            curr_node = curr_node->next;
        }
        curr_node->next = new_node;
    }
    return 0;
}
status_t remove_node(llist_t *head, int data){

}
llist_t* find_node(int data){

}
int get_linkList_lenght(llist_t *head){

}

/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input.
You must solve the problem in O(1) extra space complexity and O(n) time complexity.

Example 1:
Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]

Example 2:
Input: head = [2,1,3,5,6,4,7]
2,1 // curr -> index 2 (even), even_start -> index 2, even_end -> index 2, odd_end -> index 1
2,1,3 // curr -> index 3 (odd)
2,3,1 // add index 3 to odd_end->next, odd_end -> index 2, even_start -> index 3, even_end -> index 3, curr -> index 4
2,3,1,5 // curr -> index 4 (even), even_end -> index 4, curr goes to the next node
2,3,1,5,6 // curr -> index 5 (odd)
2,3,6,1,5 // add index 5 to odd_end->next, odd_end -> index 3 and even_start -> index 4, curr -> index 6
2,3,6,1,5,4 // curr -> index 6 (even), even_end -> index 6, curr -> index 7
2,3,6,5,1,4,7 // curr -> index 7 (odd)
2,3,6,5,1,4,7 // add index 7 to odd_end, odd_end -> index 4 and even_start -> index 5, curr -> index 8 (NULL) 
Output: [2,3,6,7,1,5,4]

Example 3:
Input: head = [3,1,4,6]
3,1 // 1 is 2 (even) index, needs a pointer here
3,1,4 //4 is 3 (odd) index, needs another pointer here
3,4,1 //swap 4 with the previous index, increasing both pointers
3,4,1,6 // 6 is 4 (even) index, done swapping
OUtput: [3,4,1,6]
*/

llist_t *oddEvenList(llist_t *head){
    if(NULL != head && NULL != head->next){
        // Marady's solution
        llist_t *odd = head;
        llist_t *even = head->next;
        llist_t *hEven = head->next;

        while(even != NULL && even->next != NULL){
            odd->next = even->next; // Update the odd next pointer
            odd = odd->next; // Increment the odd node

            even->next = even->next->next; // Update the even next pointer
            even = even->next; // Increment the even node
        }
        odd->next = hEven; // Joint odd and even lists together
        return head;
    }
}
/*
Example 1: 1->2->3->4->5 -> 5->4->3->2->1]
Head -> 1 // The start
1->NULL // Create a new list with the last node
Head = head->next // next node
2->1->NULL // Link the next node to the last node
*/

llist_t reverseLinkedList(llist_t *head){
    // llist_t *rev_list = malloc(sizeof(*head));
    // rev_list->next = NULL;
    // while(head != NULL){
    //     rev_list->data = head->data;
    //     head = head->next;
    // }

    //Marady's solution
    llist_t *rhead = head;
    if (NULL != head && NULL != head->next){
        llist_t *tmp = NULL;

        head = head->next;
        rhead->next = NULL;

        while(NULL != head && NULL != head->next){
            tmp = head->next;
            head->next = rhead;
            rhead = head;
            head = tmp;
        }
        head->next = rhead;
        rhead = head;
    }
    //Another solution
    llist_t *prev = NULL;
    llist_t *curr = head;
    llist_t *temp;

    while(curr){
        temp = curr->next;
        curr->next = prev;
        prev = curr;
        curr = temp;
    }
    return prev;
}
void pretty_print_linkedlist(llist_t *head){
    llist_t *curr_node = head;
    for(int i = 0; curr_node->next != NULL; ++i){
        printf("current node: %d\n", i);
        printf("data: %d\n", curr_node->data);
        curr_node = curr_node->next;
    }
}
