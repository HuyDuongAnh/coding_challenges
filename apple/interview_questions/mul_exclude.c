#include <stdio.h>

/* Thermal team interview (Nico) - 08/07/23*/
/*
Given an array of integers, write a function that returns an array whose k-th element is the multiplication of all the elements of the input 
array except the one in position k. Example:

Input: int x[5] = {3, 1, 5, 4, 2}; Output: int y[5] = {40, 120, 24, 30, 60};
*/

void multiply_exclude(int *in, int *out, unsigned int N) {
  int mul_result = 1;
  for(int j = 0; j < N; ++j){   // for out array
    for(int i = 0; i < N; ++i){ // for in array
      if(i != j){
        mul_result *= in[i];
      }
    }
    out[j] = mul_result;
    mul_result = 1;           //reset mul_result
  }
}

int main(){
  int arr_in[5] = {3, 1, 5, 4, 2};
  int arr_out[5] = {1, 1, 1, 1, 1};
  multiply_exclude(arr_in, arr_out, 5);
  printf("Output array: [");
  for(int i = 0; i < 5; ++i){
    printf("%d,", arr_out[i]);
  }
  return 0;
}