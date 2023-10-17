#include <stdint.h>
#include <stdio.h>

typedef union bit_field
{
    struct {
        uint32_t bit_0: 1;
        uint32_t bit_1: 1;
        uint32_t bit_2: 1;
        uint32_t bit_3: 1;
        uint32_t bit_4: 1;
        uint32_t bit_5: 1;
        uint32_t bit_6_to_32: 26;
    };
    uint32_t bits;
}num;

int main(){
    num my_num;
    my_num.bits = 0xFFFFFFFF;
    printf("my_num is: %x\n", my_num.bits);    
    my_num.bit_0 = 0;
    printf("my_num is: %x\n", my_num.bits);
}