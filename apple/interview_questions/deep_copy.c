#include <stdio.h>
#include <stdlib.h>
//Interviewer - Sumeet Tiwana
//Deep copy a linked list where each node has below format. The random pointer may point to any other node in the linked list.

typedef struct _node
{
    struct _node *next;
    struct _node *random;
    int val;
} Node;

/* Huy's incomplete solution */
Node *deep_copy(Node *list){
  if(list == NULL){
    return NULL;
  }
  Node *curr = list;
  Node *new_list = malloc(sizeof(Node)); 
  Node *new_list_curr = new_list;
  //traverse through the list
  while(curr != NULL){
    //copy the node to a new list
    new_list_curr->val = curr->val;
    new_list_curr->next = malloc(sizeof(Node));
    // update new list curr and curr pointers
    new_list_curr = new_list_curr->next;
    curr = curr->next;
  }
  return new_list;
}
/* Ling's solution */

// Definition for a Node.
typedef struct Node {
  int val;
  struct Node* next;
  struct Node* random;
} Node;

// Helper function to create a new Node.
Node* newNode(int _val) {
  Node* node = (Node*)malloc(sizeof(Node));
  if(!node) {
    // Handle memory allocation failure.        
    exit(1);
  }
  node->val = _val;
  node->next = NULL;
  node->random = NULL;
  return node;
}

Node* copyRandomList(Node* head) {
  if (head == NULL) {
    return head;
  }
  Node* temp = head;
  Node* deep;
  Node* step;
  while (temp != NULL) {
    deep = newNode(temp->val);
    step = temp->next;
    temp->next = deep;
    deep->next = step;
    temp = temp->next->next;
  }
  temp = head;
  Node* ans = head->next;
  step = ans;
  while (temp != NULL) {
    if (temp->random == NULL) {
      temp->next->random = temp->random;
    } else {
      temp->next->random = temp->random->next;
    }
    temp = temp->next->next;
  }
  temp = head;
  while (temp != NULL) {
    temp->next = temp->next->next;
    temp = temp->next;
    if (temp != NULL) {
      ans->next = temp->next;
    }
    ans = ans->next;
  }
  return step;
}

/*Marady's solution*/
Node* Marady_copyRandomList(Node* head) {
  
  // [S0]->[D0] --> [S1]->[D1] --> [S2]->[D2] --> ....
  // Second loop 0(N) - Update the random pointer
  current = head;
  while(current) {
    newChain = current->next;

    if (current->random){
      newChain->random = (current->random)->next;
    }

    // Current will get the source on the next link.
    current = newChain->next;
  }

  // Third loop O(N) - unzip or uninterleave the source and destination link list
  current = head;
  struct Node *temp = current->next;

  while(current){
    // 1. Update newChain
    newChain = current->next;
    // 2. Update the current source to the next source node
    if(newChain->next){
      newChain->next = newChain->next->next;
    }

  }
}

/* Helper functions */
void print_list(Node *head){
  Node *temp = head;
  if(head == NULL){
    return NULL;
  }
  do
  {
    printf("Val: %d\n", temp->val);
    printf("Next ptr: %d\n", temp->next);
    printf("Randome ptr: %d\n", temp->random);
    temp = head->next;
  } while(temp != NULL);
}

int main() {
  Node node_0;
  Node node_1;
  Node node_2;
  Node *copy_list;

  node_0.next = &node_1;
  node_0.val = 0;
  node_0.random = &node_0;

  node_1.next = &node_2;
  node_1.val = 1;
  node_1.random = &node_1;

  node_2.next = NULL;
  node_2.val = 2;
  node_1.random = &node_1;


  // copy_list = deep_copy(&node_0);
  // printf("copy_list_0 val: %d\n", copy_list->val);
  // printf("copy_list_1 val: %d\n", copy_list->next->val);
  // printf("copy_list_2 val: %d\n", copy_list->next->next->val);
  // node_0.random = &node_2;
  // node_1.random = &node_0;

  copy_list = copyRandomList(&node_0);

  return 0;
}