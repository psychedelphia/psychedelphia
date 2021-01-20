//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Number of Decimal Places(long double: 0.0...0    )          //
//                                         [max 18]            //
//-------------------------------------------------------------//

#include <stdio.h>
#include "ps_datatypes.h"

// New Function Here! -----------------------------------------------------------
int32 decimal_places(float128 x);
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    puts("----------------------------------------");
    printf("[00] = %d\n", decimal_places(0.0L));
    puts("----------------------------------------");    
    printf("[01] = %d\n", decimal_places(0.1L));
    printf("[02] = %d\n", decimal_places(0.01L));
    printf("[02] = %d\n", decimal_places(0.12L));
    printf("[03] = %d\n", decimal_places(0.123L));
    printf("[04] = %d\n", decimal_places(0.1234L));
    printf("[05] = %d\n", decimal_places(0.12345L));
    printf("[06] = %d\n", decimal_places(0.123456L));
    printf("[07] = %d\n", decimal_places(0.1234567L));
    printf("[08] = %d\n", decimal_places(0.12345678L));
    printf("[09] = %d\n", decimal_places(0.123456789L));
    printf("[09] = %d\n", decimal_places(0.1234567890L));
    printf("[10] = %d\n", decimal_places(0.1234567891L));
    printf("[11] = %d\n", decimal_places(0.12345678912L));
    printf("[12] = %d\n", decimal_places(0.123456789123L));
    printf("[13] = %d\n", decimal_places(0.1234567891234L));
    printf("[14] = %d\n", decimal_places(0.12345678912345L));
    printf("[15] = %d\n", decimal_places(0.123456789123456L));
    printf("[16] = %d\n", decimal_places(0.1234567891234567L));
    printf("[17] = %d\n", decimal_places(0.12345678912345678L));
    printf("[18] = %d\n", decimal_places(0.123456789123456789L));
    puts("----------------------------------------");
    printf("[00] = %d\n", decimal_places(1.0L));    
    puts("----------------------------------------");
    
    return SUCCESS; 
}

//--------------------------------
// decimal_places() implementation
int32 decimal_places(float128 x) {
    int32 result = 0;
    uint64 x_zero, x_origin;
    uint64 intx_zero = 100000000000000000;
    uint64 intx_origin = 1000000000000000000;
    float128 f_x = x + 0.0000000000000000001L;
    
    if (x > 0.0L && x < 1.0L) {
        for (register int32 i = 18; i > 0; i--) {
            x_zero = (uint64)(f_x * (float128)intx_zero) * 10;
            x_origin = (uint64)(f_x * (float128)intx_origin);
        
            if (x_origin == x_zero) {
                intx_zero /= 10;
                intx_origin /= 10;
            } else {
                result = i;
                i = 0;
            }
        }
    } else {
        puts("out of bounds! - [0.0 < x < 1.0]");
    }

    return result;
}
