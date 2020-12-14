//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// size of data types                                          //
//-------------------------------------------------------------//

#include <stdio.h>
#include "ps_datatypes.h"

// minimize usage of (/ → * → - → +) operator and floating-point
// New Function Here! -----------------------------------------------------------
void show_sizeof();
//-------------------------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    show_sizeof();

    return SUCCESS; 
}

void show_sizeof() {
    printf("char     size: %ld\n", sizeof(char));
    printf("uchar    size: %ld\n", sizeof(uchar));
    printf("char16   size: %ld\n", sizeof(char16));
    printf("int16    size: %ld\n", sizeof(int16));
    printf("uint16   size: %ld\n", sizeof(uint16));
    printf("wchar    size: %ld\n", sizeof(wchar));
    printf("char32   size: %ld\n", sizeof(char32));    
    printf("int32    size: %ld\n", sizeof(int32));
    printf("uint32   size: %ld\n", sizeof(uint32));
    printf("float32  size: %ld\n", sizeof(float32));
    printf("int64    size: %ld\n", sizeof(int64));
    printf("uint64   size: %ld\n", sizeof(uint64));
    printf("float64  size: %ld\n", sizeof(float64));
    printf("float128 size: %ld\n", sizeof(float128));    
}
