//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Converting integer(decimal) into binary form                //
//-------------------------------------------------------------//

#include <stdio.h>

// minimize useage of (/ → * → - → +) operator and floating-point
// New Function Here! -------------------------------------------
void ps_to_binary(int value); // convert decimal into binary form
// --------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    int x = 444444444;
     
    printf("x  = %10d: ",  x); /* << */ ps_to_binary(x);  /* << */ puts("");
    printf("~x = %10d: ", ~x); /* << */ ps_to_binary(~x); /* << */ puts("");

  return 0; 
}

//------------------------------
// ps_to_binary() implementation 
void ps_to_binary(int value) {
    const int INT_MIN = -2147483648;
    enum flag { OFF = 0, ON = 1 } sign_switch = OFF; // Off = negative, on = positive    
    int max_bit = 32;
    int mask = INT_MIN; // 10000000 00000000 00000000 00000000
  
    // efficiency for loop (0 <= value <= 2147483647)
    if (value >= 0) {
        mask = 1073741824; // 01000000 00000000 00000000 00000000
        sign_switch = ON;
        max_bit = 31;
        printf("0");
        
        if (value < 16777216) { 
            max_bit = 24;
            mask >>= 7;
            printf("0000000 ");
            
            if (value < 65536) {
                max_bit = 16;
                mask >>= 8;
                printf("00000000 ");
                
                if (value < 256) {
                    max_bit = 8;
                    mask >>= 8;
                    printf("00000000 ");
                }
            }
        }
    }
    
    // print 0 or 1
    for (register int i = max_bit - 1; i >= 0; i--) {
        printf("%d", (value & mask) ? 1 : 0);
        mask >>= 1;
              
        // prevent right shift with 1
        if (sign_switch == OFF) {
                             //    11000000 00000000 00000000 00000000
            mask ^= INT_MIN; // -> 01000000 00000000 00000000 00000000
            sign_switch = ON;
        }
              
        if ((i & 7) == 0) printf(" "); // separator for reading
    }
}
