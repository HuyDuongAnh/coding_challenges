/*
First: Implement atoi function 
Second: memcpy from src to dest with a fix size n
Second to last: Determine whether the system's data storage is little or big indian. Brain tease question.  
Last portion: Writing an enqueue and dequeue functions and count number of bits in an 32-bit integer
*/

//Brain teasing question: Change one character in the code so that it would print '*' 20 times (3 ways possible)
int main(){
    int i = 0, n = 20;
    for(i = 0; i < n; i--)
        printf("*");
    return 0;
}
Answers: 
1) change "i--" in the for loop to "n--"
2) change "i<n" in for loop to be "-i<n"
3) change "i<n" in the for loop to be "i+n"

// Determine whether the system's data storage is little or big indian
int x = 1; // 0x00000001 
uint8_t * y = &x;
if ((*y == 1)) printf("Little Endian\n");
else   printf("Big Endian\n");

/* 
Example: "123" -> 123  
*/
// Assuming that 
int my_atoi(char *input){
    for()
}

int main(){
    printf("my_atoi(%s) = %d\n", "123", my_atoi("123"));
    return 0;
}

