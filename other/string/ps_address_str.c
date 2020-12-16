//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// address of string                                           //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
void address_str(const char * str); // print string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    
    address_str(str1); /* << */ puts("");
    address_str(str2); /* << */ puts("");

    str1 = term_str(str1);
    str2 = term_str(str2);
    
    return SUCCESS; 
}

void address_str(const char * str) {
    printf("address: [%p], string: [%s]", str, str);
}
