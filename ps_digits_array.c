//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//

#include <stdio.h>
#include <math.h>

// minimize useage of (/ → * → - → +) operator and floating-point
// New Function Here! -------------------------------------------
int * digits_array(int * decimal, unsigned int value); // input digits into array
// --------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    int digits[10] = { 0 }; // initializing
    unsigned int number = 4294967; // unsigned MAX = 4,294,967,295

    digits_array(digits, number);
    for (register int i = 0; i < 10; i++) {
        printf("%d:", digits[i]);
    }
    puts("");
    puts("--------------------");    

    for (register unsigned int j = 3999999900; j < 4000000000; j++) {
        digits_array(digits, j);

        for (register int i = 0; i < 10; i++) {
            printf("%d:", digits[i]);
        }
        puts("");
    }
    
    return 0; 
}

//-----------------------------
// digits_array implementation
int * digits_array(int * digits, unsigned int value) {
    int * digits_local = digits;
    double before = 0.0, after = 0.0;
    
    before = (double)value / 1000000000;
    digits_local[0] = (int)floor(before);

    for (register int i = 1; i < 9; i += 4) {
        after = before - (double)digits_local[i-1];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i]   = (int)floor(before);
        after = before - (double)digits_local[i];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i+1] = (int)floor(before);
        after = before - (double)digits_local[i+1];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i+2] = (int)floor(before);
        after = before - (double)digits_local[i+2];
        before = fma(after, 10.0, 0.00000000001);
        digits_local[i+3] = (int)floor(before);
    }
    
    after  = before - (double)digits_local[8];
    before = fma(after, 10.0, 0.00000000001);
    digits_local[9] = (int)floor(before);
    
    return digits_local;
}
