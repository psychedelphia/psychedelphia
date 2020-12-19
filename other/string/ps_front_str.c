//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// changing a character(first character)                       //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
char * front_str(char * this, const char c); // change a character
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printn_str(str1);

    str1 = front_str(str1, '#');
    printn_str(str1);
    
    str1 = term_str(str1);

    return SUCCESS; 
}

char * front_str(char * this, const char c) {
    if (this) { *this = c;}
    else      { printf("(null)"); }
    
    return this;
}
