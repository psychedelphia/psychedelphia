//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// size of data types                                          //
//-------------------------------------------------------------//

#include <stdio.h>
#include <wchar.h>

typedef short int               int16;
typedef unsigned short int     uint16;
// Data Types(often used)--------------------------------------------------------
typedef unsigned char           uchar;
typedef wchar_t                 wchar;
typedef int                     int32;
typedef unsigned int           uint32;
typedef long int                int64;
typedef unsigned long int      uint64;
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
// New Function Here! -----------------------------------------------------------
void show_sizeof();
//-------------------------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    show_sizeof();

    return 0; 
}

void show_sizeof() {
    printf("char   size: %ld\n", sizeof(char));
    printf("uchar  size: %ld\n", sizeof(uchar));
    printf("int16  size: %ld\n", sizeof(int16));
    printf("uint16 size: %ld\n", sizeof(uint16));
    printf("wchar  size: %ld\n", sizeof(wchar));
    printf("int32  size: %ld\n", sizeof(int32));
    printf("uint32 size: %ld\n", sizeof(uint32));
    printf("float  size: %ld\n", sizeof(float));
    printf("int64  size: %ld\n", sizeof(int64));
    printf("uint64 size: %ld\n", sizeof(uint64));
    printf("double size: %ld\n", sizeof(double));        
}
