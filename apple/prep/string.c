/*
Given a string s which represents an expression with ‘+’ and ‘-‘ operation, evaluate this expression and return its value.
Please assume that the given expression is always valid.

Example 1:
Input: s = "3+2”
Output: 5

Example 2:
Input: s = “5+7-33+6-4”
Output: -19
*/
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int calculator(char *input){
    if(input == NULL){
        return 0;
    }

    int result = 0, num = 0;
    char* ch_ptr = input;
    char ch = *ch_ptr, prev_op = '\0';
    bool first_time = true;

    //Traverse through the string
    while(ch != '\0'){
        // printf("ch is %c\n", ch);
        //Get the number until hitting + or -
        if((ch != '+') && (ch != '-')){
            //If num already contains a number
            if(num != 0){
                num = num + (ch - '0') * 10;
            }
            else{
                num = ch - '0';
            }
            // printf("num is %d\n", num);
        }

        //Hitting + or -
        if((ch == '+') || (ch == '-')){
            if(first_time){
                result += num;
                first_time = false;
            }
            else{
                if(prev_op == '+'){
                    result += num;
                }
                else if(prev_op == '-'){
                    result -= num;
                }
            }
            prev_op = ch;
            num = 0;
        }

        ++ch_ptr;
        ch = *(ch_ptr);
    }

    //Compute the final result with the last number
    if(prev_op == '+'){
        result += num;
    }
    else if(prev_op == '-'){
        result -= num;
    }
    return result;
}

int calculator_improv(char *input){
    if(input == NULL){
        return 0;
    }

    int result = 0, num = 0;
    char ch = input[0], prev_op = '+';

    //Traverse through the string
    for(int i = 1; ch; ++i){
        //Get the number until hitting + or -
        if((ch >= '0') && (ch <= '9')){
            num = num * 10 + (ch - '0');
        }
        else { //Hitting + or -
            if(prev_op == '+'){
                result += num;
            }
            else if(prev_op == '-'){
                result -= num;
            }
            prev_op = ch;
            num = 0;
        }
        ch = input[i];
    }

    //Compute the final result with the last number
    result = (prev_op == '+') ? result + num : result - num;

    return result;
}


int computeIntStr(const char *buf) {
    int compute = 0;
    int integerDelim = 0;
    int i = 0;
    char signCnd = '+';   //false == postive; othwerise negative

    //3-2-1
    for(i = 0; buf[i]; i++){
        if (buf[i] >= '0' && buf[i] <= '9') {
            integerDelim = (integerDelim * 10) + (buf[i] - '0');
        } else {
            // printf("Compute = %d, integerDelim = %d\n",compute,integerDelim);
            //Check for sign
            if(signCnd == '-') {
                compute = compute - integerDelim;
            } else if (signCnd == '+') {
                compute = compute + integerDelim;
            }
            // printf("Compute = %d\n",compute);
            signCnd = buf[i];
            integerDelim = 0;
        }
    }

    // printf("Compute = %d, integerDelim = %d\n",compute,integerDelim);
    compute = signCnd == '-' ? (compute - integerDelim) : (compute + integerDelim);
    return compute;
}

int main(){

    //Test my code
    char str1[] = "3+2+1";
    char str2[] = "3+2-1";
    char str3[] = "3-2-1";
    char str4[] = "3-2-1-1";    
    char str5[] = "5+7-33";
    char str6[] = "5+7-33+6";
    char str7[] = "5+7-33+6-4";
    char str8[] = "5+7-333+6-4";
    char str9[] = "-5";
    char str10[] = "-5+1";

    // printf("result = %d, expected 6\n", calculator(str1));
    // printf("result = %d, expected 4\n", calculator(str2));
    // printf("result = %d, expected 0\n", calculator(str3));
    // printf("result = %d, expected -1\n", calculator(str4));
    // printf("result = %d, expected -21\n", calculator(str5));
    // printf("result = %d, expected -15\n", calculator(str6));
    // printf("result = %d, expected -19\n", calculator(str7));

    //Test Marady's code
    printf("result = %d, expected 6\n",     computeIntStr(str1));
    printf("result = %d, expected 4\n",     computeIntStr(str2));
    printf("result = %d, expected 0\n",     computeIntStr(str3));
    printf("result = %d, expected -1\n",    computeIntStr(str4));
    printf("result = %d, expected -21\n",   computeIntStr(str5));
    printf("result = %d, expected -15\n",   computeIntStr(str6));
    printf("result = %d, expected -19\n",   computeIntStr(str7));
    printf("result = %d, expected -319\n",   computeIntStr(str8));
    printf("result = %d, expected -5\n",   computeIntStr(str9));
    printf("result = %d, expected -4\n",   computeIntStr(str10));

    //Test my improv code
    // printf("result = %d, expected 6\n",     calculator_improv(str1));
    // printf("result = %d, expected 4\n",     calculator_improv(str2));
    // printf("result = %d, expected 0\n",     calculator_improv(str3));
    // printf("result = %d, expected -1\n",    calculator_improv(str4));
    // printf("result = %d, expected -21\n",   calculator_improv(str5));
    // printf("result = %d, expected -15\n",   calculator_improv(str6));
    // printf("result = %d, expected -19\n",   calculator_improv(str7));
    // printf("result = %d, expected -319\n",  calculator_improv(str8));    
    printf("result = %d, expected -5\n",  calculator_improv(str9));    
    printf("result = %d, expected -4\n",  calculator_improv(str10));    
    return 0;
}