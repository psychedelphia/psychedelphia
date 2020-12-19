//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// position in the string                                      //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
void at_str(char * this, int32 pos); // print character at position
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    uint64 length = strlen(str1);

    printn_str(str1);

    for (register int32 i = 0; i < length; i++) {
        printf("[%2d] = ", i); /* << */ at_str(str1, i); /* << */ puts("");
    }

    str1 = term_str(str1);

    return SUCCESS; 
}

void at_str(char * this, int32 pos) {
    if (this) { printf("%c", *(this + pos)); } 
    else      { printf("(null)"); }
}
