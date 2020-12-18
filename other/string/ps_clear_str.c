//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// clear string                                                //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
char * clear_str_h(char * str);
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printf("string: %s, length: %ld, address: %p\n", str1, strlen(str1), str1);
    
    str1 = clear_str_h(str1);
    
    printf("size is changed: string: %s, length: %ld, address: %p\n", str1, strlen(str1), str1);

    str1 = term_str(str1);
    
    printf("afte free(): string: %s, address: %p\n", str1, str1);    

    return SUCCESS; 
}

char * clear_str(char * this) {
    if (this) {
        memset(this, '\0', strlen(this));        
    } 
    
    return this;   
}
