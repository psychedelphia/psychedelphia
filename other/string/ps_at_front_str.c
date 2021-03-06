//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// first character                                             //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
void at_front_str(char * this); // print first character
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printn_str(str1);

    printf("last character = "); /* << */ at_front_str(str1); /* << */ puts("");

    str1 = term_str(str1);

    return SUCCESS; 
}

void at_front_str(char * this) {
    if (this) { printf("%c", *this); } 
    else      { printf("(null)"); }
}
