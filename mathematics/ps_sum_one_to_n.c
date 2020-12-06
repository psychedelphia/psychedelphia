//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Calcuation: sum(1 + 2 + ... + n), (n is natural number)     //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// minimize usage of (/, *, -, +) operator and floating-point
// New Function Here! -----------------------------------------------------------
void sum01(int one, int max); // 1 + 2 + … + n
void sum02(int one, int max); // 1 + 2 + … + n
//-------------------------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    int one, max;
     
    srand(time(NULL));
     
    one = 1;
    max = rand() >> 24;
     
    // sum = 1 + 2 + ... + n
    printf("1 ~ %d: ", max); /* << */ sum01(one, max);
    printf("1 ~ %d: ", max); /* << */ sum02(one, max);    
     
    return 0; 
}
 
//------------------------
// sum01() implementation
void sum01(int one, int max) {
    int sum;
     
    // (1 + (max - 1)) * ((max - 1) / 2) + max, (max is odd) 
    // (1 + max) * (max / 2), (max is even)
    if (max & 1) {
        sum = (one + (max ^ 1)) * ((max ^ 1) >> 1) + max;  
    } else { 
        sum = (one + max) * (max >> 1);
    }
     
    printf("case 1: sum = %d\n", sum);
}
 
//------------------------
// sum02() implementation
void sum02(int one, int max) {
    int sum;
     
    // (1 + max) * ((max - 1) / 2) + ((max + 1) / 2) , (max is odd)    
    // (1 + max) * (max / 2), (max is even)
    if (max & 1) {
        sum = (one + max) * ((max ^ 1) >> 1) + ((max + 1) >> 1);  
    } else { 
        sum = (one + max) * (max >> 1);
    }
     
    printf("case 2: sum = %d\n", sum);
}
