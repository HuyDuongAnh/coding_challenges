/*
Given the root of a binary tree, return its maximum depth.
A binary tree's maximum depth is the number of nodes along the longest path from the root 
node down to the farthest leaf node.

Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3

Example 2:
Input: root = [1,null,2]
Output: 2

Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/
*/

//Definition for a binary tree node.
#include <stdlib.h>
#include <stdio.h>

struct TreeNode {
     int val;
     struct TreeNode *left;
     struct TreeNode *right;
};

int maxDepth(struct TreeNode* root){
    int curr_depth = 0;
    int left_depth = 0, right_depth = 0;
    if(root != NULL){
        curr_depth += 1;
        left_depth = maxDepth(root->left);
        right_depth = maxDepth(root->right);
        curr_depth += ((left_depth > right_depth) ? left_depth : right_depth);
    }
    return curr_depth;
}

int main(){
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = 3;

    root->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->left->val = 9;
    root->left->left = root->left->right = NULL;

    root->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->val = 20;

    root->right->left = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->left->val = 15;
    root->right->left->left = root->right->left->right = NULL;

    root->right->right = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->right->right->val = 7;
    root->right->right->left = root->right->right->right = NULL;

    printf("maxDepth's ret: %d\n", maxDepth(root));

    free(root->right->right);
    free(root->right->left);
    free(root->right);
    free(root->left);
    free(root);
    return 0;
}