#include <stdint.h>
#include <stdio.h>
#include <stdbool.h>

/* Resource: https://learn.microsoft.com/en-us/cpp/cpp/left-shift-and-right-shift-operators-input-and-output?view=msvc-170
*/

int32_t maxInt( int32_t A, int32_t B) {
    int32_t sub_res = A - B;
    bool sign_sub_res = sub_res & 0x80000000;   //Note: if sub_res is negative, then sign_sub_res is negative 
                                            //after shifted by 31 => Not consistent with the definition of right shift

    //If sign_sub_res is 0, A is greater than B, return A
    // return A * !sign_sub_res;
    //If sign_sub_res is 1, B is greater than A, return B
    // return B * sign_sub_res;
    return (A * !sign_sub_res) | (B * sign_sub_res); // 
}

/* Return min integer between two input integer. [Try solve one for min]
```C
    /* Write a function that returns the smallest of two signed 32-bit integers, with the following constraints:
    - Cannot use comparisons (>, <, ==, ...)
    - Cannot use branching (if/else, for, while, ?/:, switch/case, ...)
    */
    
int32_t minInt( int32_t A, int32_t B) {
    int32_t delta = A - B;
    bool sign_delta = delta & 0x80000000;

    //if sign_delta is 0, A is larger than B, return B and vice versa
    return (sign_delta * A) | (!sign_delta * B);
}

/* Counting number of bit set in a number
*/
const uint8_t bit_set[] = {0,1,1,2,1,2}; // Pre-calculated number of bit set from 0-256 

uint8_t bitNum(uint8_t val){
    uint8_t mask_bit = 0x1;
    uint8_t num_bit_on = 0;

    for(num_bit_on = 0; val ; val >>= 1){
        num_bit_on += val & mask_bit; // num_bit_on += 1;
        // 0b0000 0000
    }

/*   for(int i = 0; i < 8; ++i){    // This way is more wasteful because I check every single bit with mask value
        if(mask_bit & val){
            num_bit_on++;
        }
        mask_bit <<= 1;
    }*/
    return num_bit_on;
}

int main(){
    // Max cases
    printf("MaxInt of (3, 2) is: %d\n", maxInt(3,2));
    printf("MaxInt of (1, 0) is: %d\n", maxInt(1,0));
    printf("MaxInt of (2, 3) is: %d\n", maxInt(2,3));
    printf("MaxInt of (0, 1) is: %d\n", maxInt(0,1));
    printf("MaxInt of (2, 4) is: %d\n\n", maxInt(2,4));

    // Min cases
    printf("MinInt of (3, 2) is: %d\n", minInt(3,2));
    printf("MinInt of (1, 0) is: %d\n", minInt(1,0));
    printf("MinInt of (2, 3) is: %d\n", minInt(2,3));
    printf("MinInt of (0, 1) is: %d\n", minInt(0,1));
    printf("MinInt of (2, 4) is: %d\n", minInt(2,4));

    // Bit num
    printf("bitNum(0):%u, %u\n",__builtin_popcount(0), bit_set[0]);
    printf("bitNum(1):%u, %u\n",__builtin_popcount(1), bit_set[1]);
    printf("bitNum(3):%u, %u\n",__builtin_popcount(3), bit_set[3]);    

    return 0;
}