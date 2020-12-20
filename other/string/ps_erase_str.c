//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// erase character(or the sequence of characters)              //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
char * erase_str(char * this, int32 pos); // erase character
char * erase_seq_str(char * this, int32 index, int32 len); // erase the sequence of characters
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printn_str(str1);
    str1 = erase_str(str1, 15);
    printn_str(str1);
    str1 = erase_str(str1, 14);
    printn_str(str1);
    str1 = erase_str(str1, 1);
    printn_str(str1);    
    str1 = erase_str(str1, 0);
    printn_str(str1);        

    str1 = erase_seq_str(str1, 3, 3);
    printn_str(str1);
    str1 = erase_seq_str(str1, 3, 3);
    printn_str(str1); 
    str1 = erase_seq_str(str1, 3, 3);
    printn_str(str1); 
    str1 = erase_seq_str(str1, 2, 1);
    printn_str(str1);

    str1 = term_str(str1);

    return SUCCESS; 
}

char * erase_str(char * this, int32 pos) {
    char * sub;
    uint64 thislength;
    
    if (this) {
        thislength = strlen(this);
        
        if (pos >= 0 && pos < thislength) {
            memmove(this + pos, this + pos + 1, thislength - pos);
            *(this + thislength - 1) = '\0';
        } else { // pos < 0 || pos > thislength
            printf("out of bounds!");
            exit(EXIT_FAILURE);
        }
    }
    
    return this;
}

char * erase_seq_str(char * this, int32 index, int32 len) {
    uint64 thislength;
    
    if (this) {
        thislength = strlen(this);
        
        if (index >= 0 && len > 0 && (index + len) <= thislength) {
            memmove(this + index, this + index + len, thislength - (index + len));
            *(this + thislength - len) = '\0';
        } else { // index < 0 || len <= 0 || (index + len) > thislength
            printf("out of bounds!");
            exit(EXIT_FAILURE);
        }
    }
    
    return this;
}
