//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// length of string                                            //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
void length_str(const char * str); // length of string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    
    printf("string1 created: %s\n", str1);
    printf("string1 length: "); /* << */ length_str(str1); /* << /*/ puts("");
    printf("string2 created: %s\n", str2);
    printf("string2 length: "); /* << */ length_str(str2); /* << /*/ puts("");    
    
    str1 = term_str(str1);
    str2 = term_str(str2);
    
    return SUCCESS; 
}

void length_str(const char * str) {
    if (this) { printf("%ld", strlen(this)); } // this != NULL
    else      { printf("(null)"); } // this == NULL
}
