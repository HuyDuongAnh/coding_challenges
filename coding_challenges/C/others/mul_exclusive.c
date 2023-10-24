/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product 
of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

Example 1:

Input: nums = [1,2,3,4]
Output: [24,12,8,6]
Example 2:

Input: nums = [-1,1,0,-3,3]
Output: [0,0,9,0,0]
 
Constraints:

2 <= nums.length <= 105
-30 <= nums[i] <= 30
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
 

Follow up: Can you solve the problem in O(1) extra space complexity? (The output array does not 
count as extra space for space complexity analysis.)
*/

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#include <stdlib.h>

int* productExceptSelf(int* nums, int numsSize, int* returnSize){
    int mul_result = 1;
    int* out_array = (int *)malloc(numsSize * sizeof(int));
    if(out_array != NULL){
        // for(int j = 0; j < N; ++j){   // for out array
        //     for(int i = 0; i < N; ++i){ // for in array
        //     if(i != j){
        //         mul_result *= in[i];
        //     }
        //     }
        //     out[j] = mul_result;
        //     mul_result = 1;           //reset mul_result
        // }
    }
    return out_array;
}