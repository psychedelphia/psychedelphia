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
char * term_str(char * str); // terminate string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printf("string: %s, address: %p\n", str1, str1);

    str1 = term_str(str1);

    printf("after terminated - string: %s, address: %p\n", str1, str1);
    
    return SUCCESS; 
}

char * term_str(char * str) {
    char * removed;

    if (str != NULL) { // execution
        removed = str;
        free(removed);
    } 
    
    removed = NULL;
 
    return removed;   
}
