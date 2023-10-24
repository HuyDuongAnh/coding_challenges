/*
    Given a complete binary tree with nodes of values of either 1 or 0, the following rules always hold:
    (1) a node's value is 1 if and only if all its subtree nodes' values are 1
    (2) a leaf node can have value either 1 or 0
    Implement the following 2 APIs:
    set_bit(offset, length), set the bits at range from offset to offset+length-1
    clear_bit(offset, length), clear the bits at range from offset to offset+length-1
    
    i.e. The tree is like:
                 0
              /     \
             0        1
           /  \      /  \
          1    0    1    1
         /\   / \   / 
        1  1 1   0 1
        Since it's complete binary tree, the nodes can be stored in an array:
        [0,0,1,1,0,1,1,1,1,1,0,1]     
Implement a buddy bitmap with APIs for setting and unsetting bits in the bitmap.
Bitmap buddy problem
Implement two functions (clear and set bit) for Buddy Bitmap data structure.
Set values in a level within a binary tree, and rebalance the tree optimally.
Buddybits, given an array of bits with each level above composed as the && of the two below, how to propigate the changes by setting a range to all 0's as well as in another operation set all to 1's.
*/

#include <stdio.h>
#include <stdlib.h>

// Define the binary tree node structure
typedef struct TreeNode {
    int val;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

// Function to create a new binary tree node
TreeNode* createNode(int val) {
    TreeNode* newNode = (TreeNode*)malloc(sizeof(TreeNode));
    newNode->val = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to set a range of bits to 1 in the binary tree
void set_bit(TreeNode* root, int offset, int length) {
    // // Base case: If the current node is NULL, return
    // if (root == NULL) {
    //     return;
    // }

    // // Check if the current node is a leaf node within the specified range
    // if (offset <= 0 && offset + length - 1 >= 0) {
    //     root->val = 1;
    //     return;
    // }

    // // Recursively update left and right subtrees
    // int mid = offset + length / 2;
    // set_bit(root->left, offset, mid - offset);
    // set_bit(root->right, mid + 1, offset + length - mid - 1);


    /******************************/
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Check if the current node is a leaf node within the specified range
    if (offset <= 0 && offset + length - 1 >= 0) {
        root->val = 1;
        return;
    }

    // Recursively update left and right subtrees
    int mid = offset + length / 2;
    set_bit(root->left, offset, mid - offset);
    set_bit(root->right, mid + 1, offset + length - mid - 1);

    // Check if both left and right subtrees have a value of 1
    if (root->left != NULL && root->right != NULL && root->left->val == 1 && root->right->val == 1) {
        root->val = 1;
    }
}

// Function to clear a range of bits to 0 in the binary tree
void clear_bit(TreeNode* root, int offset, int length) {
    // // Base case: If the current node is NULL, return
    // if (root == NULL) {
    //     return;
    // }

    // // Check if the current node is a leaf node within the specified range
    // if (offset <= 0 && offset + length - 1 >= 0) {
    //     root->val = 0;
    //     return;
    // }

    // // Recursively update left and right subtrees
    // int mid = offset + length / 2;
    // clear_bit(root->left, offset, mid - offset);
    // clear_bit(root->right, mid + 1, offset + length - mid - 1);
    
    /************************************************/
    // Base case: If the current node is NULL, return
    if (root == NULL) {
        return;
    }

    // Check if the current node is a leaf node within the specified range
    if (offset <= 0 && offset + length - 1 >= 0) {
        root->val = 0;
        return;
    }

    // Recursively update left and right subtrees
    int mid = offset + length / 2;
    clear_bit(root->left, offset, mid - offset);
    clear_bit(root->right, mid + 1, offset + length - mid - 1);

    // Check if both left and right subtrees have a value of 0
    if (root->left != NULL && root->right != NULL && root->left->val == 0 && root->right->val == 0) {
        root->val = 0;
    }
}

// Function to print the binary tree (for debugging purposes)
void printTree(TreeNode* root) {
    if (root == NULL) {
        return;
    }
    printf("%d ", root->val);
    printTree(root->left);
    printTree(root->right);
}

int main() {
    // Example usage
    TreeNode* root = createNode(0);
    root->left = createNode(0);
    root->right = createNode(0);
    root->left->left = createNode(1);
    root->left->right = createNode(1);
    root->right->left = createNode(0);
    root->right->right = createNode(1);

    printf("Original Tree: ");
    printTree(root);
    printf("\n");

    // Set bits 2 to 4 (0-based indexing) to 1
    set_bit(root, 2, 3);

    printf("Tree after setting bits 2 to 4: ");
    printTree(root);
    printf("\n");

    // Clear bits 1 to 3 (0-based indexing) to 0
    clear_bit(root, 1, 3);

    printf("Tree after clearing bits 1 to 3: ");
    printTree(root);
    printf("\n");

    return 0;
}
