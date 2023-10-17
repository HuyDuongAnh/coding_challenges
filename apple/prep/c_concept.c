#include <stdio.h>
#include <stdint.h>

/*
Using the #define statement, how would you declare a manifest constant that returns the number 
of seconds in a year? Disregard leap years in your answer.*/

#define SEC_IN_ONE_YEAR (60UL * 60UL * 24UL * 365UL)

/*
Write the ‘standard’ MIN macro. That is, a macro that takes two arguments and returns the smaller 
of the two arguments.*/

#define MIN(X,Y) (((X) < (Y)) ? (X) : (Y))

int main_min(){
    int p[3] = {1,2,3};
    int b = 4;
    int least = 0;
    for(int i = 0; i < 3; ++i){
        least = MIN((*p)++, b); // *p++ => (*p)++ => *p = (*p) + 1
                                // ++ should take precedent over * without ()
    }
    return 0;
}

/*
Using the variable a, write down definitions for the following:
(a) An integer - int a;
(b) A pointer to an integer - int *a;
(c) A pointer to a pointer to an integer - int **a;
(d) An array of ten integers - int a[10];
(e) An array of ten pointers to integers - int *a[10]
(f) A pointer to an array of ten integers - 
    int (*arr)[10]; // reading inside the parentheses first
(g?) A pointer to a function that takes an integer as an argument and returns an integer
    int (*a)(int)
(h) An array of ten pointers to functions that take an integer argument and return an integer.
    int (*a[10])(int)
*/

int func(int arg){
    return 0;
}

int main_func(){
    void * a;
    void * b[10];
    a = (void *)&func;
    for(int i = 0; i < 10; ++i){
        b[i] = &func;
    }
    return 0;
}

/*
Given an integer variable a, write two code fragments. The first should set bit 3 of a. The second 
should clear bit 3 of a. In both cases, the remaining bits should be unmodified.*/

//Set bit 3 of a
void set_bit_3_func(int *a){
    int num = *a;
    num |= 0x08;
    *a = num;
}

//Clear bit 3 of a
void clear_bit_3_func(int *a){
    int num = *a;
    num &= ~(0xF7);
    *a = num; 
}

//Better solution
#define BIT3 0x00000001 << 3
static uint32_t a;

void set_bit_3(void){
    a |= BIT3;
}

void clear_bit_3(void){
    a &= ~BIT3;
}

/*Set an integer variable at the absolute address 0x67a9 to the value 0xaa55*/

void set_val_at_abs_addr(void){
    int *ptr = 0x67a9;
    *ptr = 0xaa55; 
}

void foo(void){
    unsigned int a = 6;
    int b = -20;
    (a+b > 6) ? printf("%s\n", "> 6") : printf("%s\n", "<= 6");
}

int main_foo(void){
    foo();
    return 0;
}

#define dPS struct s *

typedef struct s * tPS;

int main(){
    // dPS p1, p2;
    tPS p1, p2;
    short int a = 5, b = 7, c;
    c = a+++b;
    printf("a = %d, b = %d, c = %d\n", a, b, c);
    return 0;
}