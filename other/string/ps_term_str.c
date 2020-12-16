//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// terminate string                                            //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
char * term_str(char * this); // terminate string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printf("string: %s, address: %p\n", str1, str1);

  //term_str(str1); it is possible.
    str1 = term_str(str1); // recommended

    printf("after terminated - string: %s, address: %p\n", str1, str1);
    
    return SUCCESS; 
}

char * term_str(char * this) {
    if (this) { // execution
        free(this);
        this = NULL;
    } 

    return this;   
}
