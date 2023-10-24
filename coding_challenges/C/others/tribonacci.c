#include <stdio.h>

/*
int tribonacci(int n){
    int total = 0;
    if(n == 0){
        total = 0;
    }
    else if(n == 1){
        total = 1;
    }
    else if(n == 2){
        total = 1;
    }
    else if(n > 2){
        total += tribonacci(n--); 
    }
    return total;
}
*/

// Marc's solution
int tribonacci(int n){
    int nMin3 = 0; // result for n = 0
    int nMin2 = 1; // result for n = 1
    int nMin1 = 1; // result for n = 2
    int total = 1;

    if(n > 2){
        for(int i = 3; i <= n; i++){
            total = nMin1 + nMin2 +nMin3;

            nMin3 = nMin2;
            nMin2 = nMin1;
            nMin1 = total;
        }
    }
    else if (0 == n){
        return total = 0;
    }
    return total;
}

int main(){
    printf("tribonacci(0) is: %d, expected: \n", tribonacci(0));
    printf("tribonacci(1) is: %d, expected: \n", tribonacci(1));
    printf("tribonacci(2) is: %d, expected: \n", tribonacci(2));
    printf("tribonacci(3) is: %d, expected: \n", tribonacci(3));
    printf("tribonacci(25) is: %d, expected: 1389537 \n", tribonacci(25));
    return 0;
}