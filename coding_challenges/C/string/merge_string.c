/*
You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. 
If a string is longer than the other, append the additional letters onto the end of the merged string.
Return the merged string.

Example 1:

Input: word1 = "abc", word2 = "pqr"
Output: "apbqcr"
Explanation: The merged string will be merged as so:
word1:  a   b   c
word2:    p   q   r
merged: a p b q c r
Example 2:

Input: word1 = "ab", word2 = "pqrs"
Output: "apbqrs"
Explanation: Notice that as word2 is longer, "rs" is appended to the end.
word1:  a   b 
word2:    p   q   r   s
merged: a p b q   r   s
Example 3:

Input: word1 = "abcd", word2 = "pq"
Output: "apbqcd"
Explanation: Notice that as word1 is longer, "cd" is appended to the end.
word1:  a   b   c   d
word2:    p   q 
merged: a p b q c   d

*/
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

char * mergeAlternately(char * word1, char * word2){
    // Checking for NULL case
    if((word1 == NULL) || (word2 == NULL)){
        return NULL;
    }

    int32_t i1 = 0, i2 = 0, i = 0;

    // Figure out the length needed for the return array
    int32_t len_1 = strlen(word1);
    int32_t len_2 = strlen(word2);
    int32_t length = len_1 + len_2 + 1;

    // Malloc the return character array
    char *ret = malloc(sizeof(char) * length);

    // One index traversing through the first word
    // Another index traversing through the second word
    // Merging both characters at the indexes into the final string
    while(i < length - 1){
        if(word1[i1] != '\0' && i1 <= len_1){
            ret[i++] = word1[i1++];
        }
        if(word2[i2] != '\0' && i2 <= len_2){
            ret[i++] = word2[i2++];
        }
    }
    
    // Added null terminated character
    ret[i] = '\0';

    return ret;
}

int main(){
    printf("abc + pqr = %s\n", mergeAlternately("abc", "pqr"));
    printf("ab + pqrs = %s\n", mergeAlternately("ab", "pqrs"));
    printf("abcd + pq = %s\n", mergeAlternately("abcd", "pq"));
    return 0;
}