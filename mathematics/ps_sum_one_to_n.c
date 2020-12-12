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
void sum(int32 one, int32 max); // 1 + 2 + … + n
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
    printf("1 ~ %d: ", max); /* << */ sum(one, max); /* << */ puts("");
     
    return SUCCESS; 
}
 
//-----------------------
// sum() implementation
void sum(int32 one, int32 max) {
    int32 sum;

    sum = (one + max) * (max >> 1);
  
    printf("case 1: sum = %d", sum);
}
