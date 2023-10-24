/*
Given a root node reference of a BST and a key, delete the node with the given key in the BST. 
Return the root node reference (possibly updated) of the BST.

Basically, the deletion can be divided into two stages:

Search for a node to remove.
If the node is found, delete the node.
 

Example 1:


Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
Explanation: Given key to delete is 3. So we find the node with value 3 and delete it.
One valid answer is [5,4,6,2,null,null,7], shown in the above BST.
Please notice that another valid answer is [5,2,6,null,4,null,7] and it's also accepted.

Example 2:

Input: root = [5,3,6,2,4,null,7], key = 0
Output: [5,3,6,2,4,null,7]
Explanation: The tree does not contain a node with value = 0.
Example 3:

Input: root = [], key = 0
Output: []
*/
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *new_node(){
    struct TreeNode *newNode = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    newNode->val = 0;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct TreeNode *insert_node(struct TreeNode *root, int key){
    if(root == NULL){
        root = new_node();
        root->val = key;
    }
    else{
        if(key < root->val){
            root->left = insert_node(root->left, key);
        }
        else{
            root->right = insert_node(root->right, key);
        }
    }
    return root;
}



struct TreeNode *delete_node(struct TreeNode *root, int key){
    struct TreeNode *temp = NULL;
    struct TreeNode *succ_parent = NULL;
    struct TreeNode *succ = NULL;
    // Traverse to find the right node
    if(key < root->val){
        root->left = delete_node(root->left, key);
        return root;
    }
    else if(key > root->val){
        root->right = delete_node(root->right, key);
        return root;
    }

    // Case 2: Delete a Node with Single Child in BST
    if(root->left != NULL){
        temp = root->left;
        free(root);
        return temp;
    }
    else if(root->right != NULL){
        temp = root->right;
        free(root);
        return temp;
    }
    else{ // Case 1: Delete a leaf node in BST
        free(root);
        return NULL;
    }

    // Case 3: Delete a Node with Both Children in BST
    // Traverse to the right note
    succ_parent = root;
    // Find the successor
    succ = root->right;
    while(succ->left != NULL){
        succ_parent = succ;
        succ = succ->left;
    }
    temp = succ_parent;
    
    succ_parent = succ;
    free(temp);
    
}

void print_tree(struct TreeNode *root){
    if(root == NULL){
        printf("NULL\n");
    }
    else{
        printf("%d\n", root->val);

        printf("left of %d is: ", root->val);
        print_tree(root->left);

        printf("right of %d is: ", root->val);
        print_tree(root->right);
    }
}
int main(void){
    struct TreeNode *root = NULL;
    root = insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 6);
    insert_node(root, 2);
    insert_node(root, 4);
    insert_node(root, 7);
    print_tree(root);

    printf("\nDelete 2\n");
    delete_node(root, 2);
    print_tree(root);

    printf("\nDelete 4\n");
    delete_node(root, 4);
    print_tree(root);

    printf("\nDelete 6\n");
    delete_node(root, 6);
    print_tree(root);
    return 0;
}