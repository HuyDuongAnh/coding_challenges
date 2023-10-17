# Interview Screening Preperation

## Huy Duong

### Apple Thermal Management - San Diego

+ Thermal Firmware Team - 09/15/22

1. Return max integer between two input integer. [Try solve one for min]
```C
    /* Write a function that returns the largest of two signed 32-bit integers, with the following constraints:
    - Cannot use comparisons (>, <, ==, ...)
    - Cannot use branching (if/else, for, while, ?/:, switch/case, ...)
    */
    
    int32_t maxInt( int32_t A, int32_t B) {
        int32_t sub_res = A - B;
        int32_t sign_sub_res = sub_res >> 31;   //Note: if sub_res is negative, then sign_sub_res is negative 
                                                //after shifted by 31 => Not consistent with the definition of right shift

        //If sign_sub_res is 0, A is greater than B, return A
        // return A * !sign_sub_res;
        //If sign_sub_res is 1, B is greater than A, return B
        // return B * sign_sub_res;
        return (A * !sign_sub_res) + (B * sign_sub_res); 
    }
```

2. General Embedded Questions
```C
    #define IO_PORT 0x40022004
    #define LED_BIT 2

    // Complete the function below and make sure the system can remember the state of the LED even after the function exit

    void toggle_led(void)
    {

    }

    // Explain Little Endian and Big Endian

    // complete this function
    bool isLittleEndian(void){

    }

    // Explain what it does and how to fix it
    #define isValid(x) (((x) >= ‘0’) && ((x) <= ‘9’))
    int convert ( char* s )
    {
        int r = 0;
        while (s && *s && isValid(*s++))
        {
            r = r * 10 + *s - ‘0’;
        }
        return r;
    }
```

3. Implement atoi
4. Implement integer to ascii
5. Implement memcpy
6. Reverse string without declaring extra variable.
7. Implement malloc_align and free_align
8. Bit manipulations: Check dailyMeetingCode.c
9. Implement strtok, strlen, etc.
10. Review this reading material: https://rmbconsulting.us/publications/a-c-test-the-0x10-best-questions-for-would-be-embedded-programmers/