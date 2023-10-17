#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

//1. What is the size of this structure?
/*
struct packet_t{
    uint32_t a;     // 4byte
    uint8_t b;      // 1byte + 1byte padding
    uint16_t c;     // 2 byte
    uint16_t d;     // 2 byte + 2byte padding
};
*/
//2. Declare a function pointer that return an int and takes in a boolean arguments
//int (*func) (bool);

//3. A 12-bit ADC get interrupt every second and packet the data in a continuous buffer
// The task is to return each of the sample via a pointer buffer the each of those sample

/*
* input: 01 23 45 67 89 ab cd ef
* output: 012 345 678 9ab cde 00f
*
*   input: 0123 4567 89ab cdef
*   output: 012 345 678 9ab cde
*/

//0x-fff
uint16_t *process_buffer(uint8_t *buff, uint32_t num_sample){
    uint16_t *output = (uint16_t *)malloc(sizeof(uint16_t)*num_sample);
    uint32_t i = 0;
    uint32_t j = 0;

    if (output != NULL){
        /*
        for(j = 0, i = 0; i < num_sample; i++, j++) {
            if (i % 3) {
                //take lower nibble case
                output[j] = buff[i] & 0x0fU;
                output[j] = (output[j] << 8U);
                output[j] |= buff[i+1];
                i++;
            } else {
                //take whole byte case
                output[j] = buff[i];
                output[j] = (output[j] << 4U);
                output[j] |= (buff[i+1] & 0xf0U)>>4;
            }
        }
        */
        for(j = 0, i = 0; i < num_sample; i+=3, j+=2) {
            
                //take lower nibble case
                output[j+1] = buff[i+1] & 0x0fU;
                output[j+1] = (output[j+1] << 8U);
                output[j+1] |= buff[i+2];

                //take whole byte case
                output[j] = buff[i];
                output[j] = (output[j] << 4U);
                output[j] |= (buff[i+1] & 0xf0U)>>4;
            
        }
    }
    return output;
}
// 0x0012 = 18
// 0x0345 = 837
// 0x0678 = 1656
// 0x09ab = 2475
// 0x0cde = 3294
// 0x000f = 15
int main(void) {
    uint8_t buff[] = {0x01, 0x23, 0x45, 0x67, 0x89, 0xab, 0xcd, 0xef};
    uint32_t buff_size = sizeof(buff)/sizeof(buff[0]);

    uint16_t *data = process_buffer(buff, buff_size);

    uint32_t i = 0;

    if(data != NULL) {
        for(i = 0; i < 6; i++) {
            printf("0x%04x\n", data[i]);
        }
    }
    return 0;
}