/*
For two strings s and t, we say "t divides s" if and only if s = t + ... + t 
(i.e., t is concatenated with itself one or more times).

Given two strings str1 and str2, return the largest string x such that x divides both str1 and str2.

Example 1:

Input: str1 = "ABCABC", str2 = "ABC"
Output: "ABC"
Example 2:

Input: str1 = "ABABAB", str2 = "ABAB"
Output: "AB"
Example 3:

Input: str1 = "LEET", str2 = "CODE"
Output: ""

Huy's cases:
Input: str1 = "ABACBAB", str2 = "BABC"
Output: "BAB"
*/
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>

#define GCD_SIZE 256

char * gcdOfStrings(char * str1, char * str2){
    char *gcd_array = alloc(sizeof(char) * GCD_SIZE);
    uint32_t str1_len = strlen(str1);
    uint32_t str2_len = strlen(str2);
    uint32_t i = 0, i1 = 0, i2 = 0; 
    bool found_matching_index = false, done_copy = false; 

    if(gcd_array == NULL){
        return NULL;
    }

    // Obtain one character from the first string, then find that character in the second string
    for(i1 = 0; i1 < str1_len; ++i1){
        for(i2 = 0; i2 < str2_len; ++i2){
            // If the character is found, then continue updating the gcd string until the characters no longer match
            if(str1[i1] == str2[i2]){
                gcd_array[i] = str1[i1];                
            }
        }
    }
    // If no matching character is found, then output an empty string
    if(!found_matching_index){
        return gcd_array;
    }

    // Else move on the next character in the first string
}