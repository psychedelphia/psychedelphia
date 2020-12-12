//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Calcuation: sum(1 + 2 + ... + n), (n is natural number)     //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ps_datatypes.h"

// Global variable Here! --------------------------------------------------------
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
void sum(int32 max); // 1 + 2 + … + n
//-------------------------------------------------------------------------------

// minimize usage of (/, *, -, +) operator and floating-point
//----------------------
// main() implementation 
int32 main(void) {
    int32 max;
     
    srand(time(NULL));
     
    max = rand() >> 24;
     
    // sum = 1 + 2 + ... + n
    printf("1 ~ %d: ", max); /* << */ sum(max); /* << */ puts("");
     
    return SUCCESS; 
}
 
//-----------------------
// sum() implementation
void sum(int32 max) {
    int32 sum;
    
    if (max >= 1) { // execution
        // (1 + max) * (max / 2): Gaussian formula
        sum = (1 + max) * (max >> 1);
        
        printf("case 1: sum = %d", sum);        
    } else { // exception
        printf("out of bound!");
    }
}
