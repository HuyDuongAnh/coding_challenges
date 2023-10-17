#include <stdio.h>
#include <stdint.h>

#define base_reg_timer 0x0000abcd
#define TIME_LOW    0x00
#define TIME_HIGH   0x04

uint32_t read_reg(base, base_offset);

uint64_t get_timer(void){
    // Assume you have a 64-bit timer
    // but you could only have a function that could only read 32-bit at a time
    // then when a sure call get_timer you need to pass in the correct 64-bit timer 
    // you got 15 mins 
    // fill in your code
    
}