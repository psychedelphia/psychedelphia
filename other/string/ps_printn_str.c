//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// print string(+ newline)                                                //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
void printn_str(const char * str); // print string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    
    printf("string1 created: "); /* << */ printn_str(str1);
    printf("string2 created: "); /* << */ printn_str(str2);

    str1 = term_str(str1);
    str2 = term_str(str2);
    
    return SUCCESS; 
}

void printn_str(const char * str) {
    printf("%s\n", str);
}
