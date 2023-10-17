//Implement atoi()
//Ex: atoi("4") -> 4
//Ex: atoi("-4") -> -4
//Assuming that input is valid, max output number is 2^32

#include <stdlib.h>
#include <stdio.h>

int my_atoi(char *input){
    if(input == NULL){
        return 0;
    }
    //Initialization based on positive input
    char sign = input[0], ch = input[0];
    int num = 0;
    int i = 0;

    if(sign == '-'){
        ch = input[1];
        i = 1;
    }

    while(ch){
        if((ch >= '0') && (ch <= '9')){
            //Accumulating number
            num = num * 10 + (ch - '0');
            // printf("num: %d\n", num);
        }
        ch = input[++i];
    }

    //Add sign at the end
    // printf("num: %d\n", num);
    num = (sign == '-') ? (num * -1) : num;
    return num;
}

int main(){
    char* num1 = "-4";
    char* num2 = "4";
    char* num3 = "0";
    char* num4 = "10";
    char* num5 = "1100001001";
    char* num6 = "4294967295";
    char* num7 = "-4294967295";


    // Test my function
    printf("Output: %d, Expected: %d \n", my_atoi(num1), atoi(num1));
    printf("Output: %d, Expected: %d \n", my_atoi(num2), atoi(num2));
    printf("Output: %d, Expected: %d \n", my_atoi(num3), atoi(num3));
    printf("Output: %d, Expected: %d \n", my_atoi(num4), atoi(num4));
    printf("Output: %d, Expected: %d \n", my_atoi(num5), atoi(num5));
    printf("Output: %d, Expected: %d \n", my_atoi(num6), atoi(num6));
    printf("Output: %d, Expected: %d \n", my_atoi(num7), atoi(num7));    
    return 0;
}