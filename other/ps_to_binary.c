//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// converting integer(decimal) into binary form                //
//-------------------------------------------------------------//

#include <stdio.h>
#include "ps_datatypes.h"

// New Function Here! -------------------------------------------
void ps_to_binary(int32 value); // convert decimal into binary form
// --------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation 
int32 main(void) {
    int32 x = 444444444;
     
    printf("x  = %10d: ",  x); /* << */ ps_to_binary(x);  /* << */ puts("");
    printf("~x = %10d: ", ~x); /* << */ ps_to_binary(~x); /* << */ puts("");

  return SUCCESS; 
}

//------------------------------
// ps_to_binary() implementation 
void ps_to_binary(int32 value) {
    int32 max_bit = 31;
    int32 mask = 1073741824; // 01000000 00000000 00000000 0000000

    // efficiency for loop 
    if (value >= 0) { // (0 <= value <= 2147483647)
        printf("0");
        
        if (value < 256) { 
            max_bit = 8;
            mask >>= 23;
            printf("0000000 00000000 00000000 ");
        } else if (value < 65536) {
            max_bit = 16;
            mask >>= 15;
            printf("0000000 00000000 ");
        } else if (value < 16777216) {
            max_bit = 24;
            mask >>= 7;
            printf("0000000 ");
        }
    } else { // (-2147483648 <= value < 0)
        printf("1");
        
        if (value > -257) { 
            max_bit = 8;
            mask >>= 23;
            printf("1111111 11111111 11111111 ");
        } else if (value > -65537) {
            max_bit = 16;
            mask >>= 15;
            printf("1111111 11111111 ");
        } else if (value > -16777217) {
            max_bit = 24;
            mask >>= 7;
            printf("1111111 ");
        }
    }
    
    // print 0 or 1
    for (register int32 i = max_bit - 1; i >= 0; i--) {
        printf("%d", (value & mask) ? 1 : 0);
        mask >>= 1;
              
        if ((i & 7) == 0) printf(" "); // separator for reading
    }
}
