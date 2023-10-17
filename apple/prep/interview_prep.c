// Two inputs:
//  - an array of integers
//  - length of the array
// Find the number in the array that appears the most

// unsigned int highest_frequency(unsigned int *array, int len){
//     unsigned int freq_array[len] = {0};
//     // traverse through the array
//     for(int i = 0; i < len; ++i){
//         //keep track of frequency of each number appearing in the array
//         freq_array[array[i]]++;
//     }
//     // traverse the frequency array to find the most count

// }
#include <stdio.h>
#include <stdlib.h>

int highest_frequency(int *array, int len){
    int max_count = 0;
    int curr_count = 0;
    int max_freq_int = 0;
    for(int i = 0; i < len; ++i){
        curr_count = 0;
        for(int j = 0; j < len; ++j){
            if(array[i] == array[j]){
                curr_count++;
            }
        }
        if(curr_count > max_count){
            max_count = curr_count;
            max_freq_int = array[i];
        }
    }
    return max_freq_int;
}

int compare(const void *x, const void *y){
    return (*(int *)x) - (*(int *)y); 
}

void print_array(int *array, int len){
    printf("Array: ");
    for(int i = 0; i < len; ++i){
        printf("%d, ", array[i]);
    }
}

int highest_frequency_w_sort(int *array, int len){
    int max_count = 0;
    int curr_count = 0;
    int curr_num = 0;
    int max_freq_int = 0;
    qsort(array, len, sizeof(int), compare);
    print_array(array, len);
    curr_num = array[0];
    for(int i = 0; i < len; i++){
        if(array[i] == curr_num){
            curr_count++;
        }
        else{
            if(curr_count > max_count){
                max_count = curr_count;
                max_freq_int = array[i-1];
            }
            curr_count = 1;
            curr_num = array[i];
        }
    }
    return max_freq_int;
}

void foo(void)
{
    unsigned int a = 6;
    int b = -20;
    printf("%u\n", (unsigned int)b);
    printf("%s\n", (a+b > 6) ? "> 6" : "<= 6");
}

int main(){
    int array[7] = {1,2,1,3,4,1,5};
    printf("highest_frequency: %d\n",highest_frequency_w_sort(array, 7));
    foo();
    return 0;
}
