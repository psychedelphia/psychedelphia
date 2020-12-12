//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Input digits(unsigned int) into array                       //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <math.h>
#include "ps_datatypes.h"

// New Function Here! -------------------------------------------
int32 * digits_array01(int * digits, unsigned int value); // input digits into array
int32 * digits_array02(int * digits, unsigned int value); // input digits into array
// --------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation 
int32 main(void) {
    int32 digits[10] = { 0 }; // initializing
    uint32 number = 4294967; // unsigned MAX = 4,294,967,295

    digits_array01(digits, number); // digits_array01()
    for (register int32 i = 0; i < 10; i++) {
        printf(":%d", digits[i]);
    }
    printf(":\n");
    puts("--------------------");    

    // initializing
    digits[0] = 0;
    digits[1] = 0;
    digits[2] = 0;
    digits[3] = 0;
    digits[4] = 0;
    digits[5] = 0;
    digits[6] = 0;
    digits[7] = 0;
    digits[8] = 0;
    digits[9] = 0;
    for (register int32 i = 0; i < 10; i++) {
        printf(":%d", digits[i]);
    }
    printf(":\n");
    puts("--------------------");

    digits_array02(digits, number); // digits_array02()
    for (register int32 i = 0; i < 10; i++) {
        printf(":%d", digits[i]);
    }
    printf(":\n");
    puts("--------------------");

    memset(digits, 0, sizeof(digits)); // initializing
    for (register int32 i = 0; i < 10; i++) {
        printf(":%d", digits[i]);
    }
    printf(":\n");
    puts("--------------------");

    // digits_array01() is faster
    for (register uint32 j = 3999999900; j < 4000000000; j++) {
        digits_array01(digits, j);

        for (register int32 i = 0; i < 10; i++) {
            printf(":%d", digits[i]);
        }
        printf(":\n");
    }
    
    return SUCCESS; 
}

//----------------------------
// digits_array implementation
int32 * digits_array01(int32 * digits, uint32 value) {
    int32 * digits_local = digits;
    
    for (register int32 i = 9; i > 0; i -= 5) {
        digits_local[i]   = value % 10;   
        value = value / 10;
        digits_local[i-1] = value % 10;
        value = value / 10;
        digits_local[i-2] = value % 10;
        value = value / 10;
        digits_local[i-3] = value % 10;
        value = value / 10;    
        digits_local[i-4] = value % 10;
        value = value / 10;
    }
    
    return digits_local;
}

//----------------------------
// digits_array implementation
int32 * digits_array02(int32 * digits, uint32 value) {
    int32 * digits_local = digits;
    float64 before = 0.0, after = 0.0;
    
    before = (float64)value / 1000000000;
    digits_local[0] = (int32)floor(before);

    for (register int32 i = 1; i < 9; i += 4) {
        after = before - (float64)digits_local[i-1];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i]   = (int32)floor(before);
        after = before - (float64)digits_local[i];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i+1] = (int32)floor(before);
        after = before - (float64)digits_local[i+1];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i+2] = (int32)floor(before);
        after = before - (float64)digits_local[i+2];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i+3] = (int32)floor(before);
    }
    
    after  = before - (float64)digits_local[8];
    before = fma(after, 10.0, 0.00000000001);
    digits_local[9] = (int32)floor(before);
    
    return digits_local;
}
