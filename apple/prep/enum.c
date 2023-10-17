#include <stdio.h>
#include <stdint.h>

enum cases{case1, case2, case3, case4, case5, maxcase=4294967296};

int main_enum(){
    enum cases case_num;
    case_num = case3;
    printf("case is: %lu, size of one case: %u, sizeof enum: %lu\n", case_num, case1, sizeof(enum cases));
    return 0;
}

int main_maxtrix(){
    int buff_0[][2][8] = {
        {{1,2,3,4,5,6,7,8}},
        {{9,10,11,12,13,14,15,16}}
    };

    int buff_1[][2][8] = {
        {{1,2,3,4,5,6,7,8}},
        {{9,10,11,12,13,14,15,16}}
    };

    int buff_2[][2] = {
        {1,2}
    };
    return 0;
}

//Given two unsigned integer without multiplying, check if the product will overflow.

bool isOverFlow(uint32_t a, uint32_t b){
    
}