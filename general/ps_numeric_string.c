//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// checking out whether a string is numeric or not             //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include "ps_datatypes.h"

// Global variable Here! --------------------------------------------------------
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
int32 numeric_string(const char * string); // check out whether a string is numeric or not
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    bool state;
    char * example01 = "1234567890";
    char * example02 = "a123456789";
    char * example03 = "12345a6789";
    char * example04 = "123456789a";

    printf("example01: %s\n", example01);
    state = numeric_string(example01);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }

    printf("example02: %s\n", example02);
    state = numeric_string(example02);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }
    
    printf("example03: %s\n", example03);    
    state = numeric_string(example03);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }

    printf("example04: %s\n", example04);
    state = numeric_string(example04);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }

    return SUCCESS; 
}

int32 numeric_string(const char * string) {
    bool state;
    int64 length = strlen(string);
    
    for (register int32 i = 0; i < length; i++) {
        if (*(string + i) >= 48 && *(string + i) <= 57) { state = TRUE; }
        else { i = length; /* \n */ state = FALSE; }
    }
    
    return state;
}
