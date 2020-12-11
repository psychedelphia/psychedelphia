//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Calcuation: sum(1 + 2 + ... + n), (n is natural number)     //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include "ps_datatypes.h"

// Global variable Here! --------------------------------------------------------
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
void sum01(int32 one, int32 max); // 1 + 2 + … + n
void sum02(int32 one, int32 max); // 1 + 2 + … + n
//-------------------------------------------------------------------------------

// minimize usage of (/, *, -, +) operator and floating-point
//----------------------
// main() implementation 
int32 main(void) {
    int32 one, max;
     
    srand(time(NULL));
     
    one = 1;
    max = rand() >> 24;
     
    // sum = 1 + 2 + ... + n
    printf("1 ~ %d: ", max); /* << */ sum01(one, max); /* << */ puts("");
    printf("1 ~ %d: ", max); /* << */ sum02(one, max); /* << */ puts("");   
     
    return SUCCESS; 
}
 
//-----------------------
// sum01() implementation
void sum01(int32 one, int32 max) {
    int32 sum;
     
    // (1 + (max - 1)) * ((max - 1) / 2) + max, (max is odd) 
    // (1 + max) * (max / 2), (max is even)
    if (max & 1) {
        sum = (one + (max ^ 1)) * ((max ^ 1) >> 1) + max;  
    } else { 
        sum = (one + max) * (max >> 1);
    }
     
    printf("case 1: sum = %d", sum);
}
 
//-----------------------
// sum02() implementation
void sum02(int32 one, int32 max) {
    int32 sum;
     
    // (1 + max) * ((max - 1) / 2) + ((max + 1) / 2) , (max is odd)    
    // (1 + max) * (max / 2), (max is even)
    if (max & 1) {
        sum = (one + max) * ((max ^ 1) >> 1) + ((max + 1) >> 1);  
    } else { 
        sum = (one + max) * (max >> 1);
    }
     
    printf("case 2: sum = %d", sum);
}
