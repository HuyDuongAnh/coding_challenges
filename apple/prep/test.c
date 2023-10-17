#include <stdio.h>

int main(){
    int a = 0, b = 1;
    int c = (a+++++b);
    printf("a = %d, b = %d, c= %d\n", a, b, c);
    return 0;
}