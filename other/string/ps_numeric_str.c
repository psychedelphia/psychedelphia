//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// numeric string                                              //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
bool numeric_str(const char * str); // numeric string or not
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    bool state;
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    char * str3 = init_str_h("1234567890");
    
    printf("string1 created: %s\n", str1);
    state = numeric_str(str1);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }    
    
    printf("string2 created: %s\n", str2);
    state = numeric_str(str2);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }
    
    printf("string3 created: %s\n", str3);    
    state = numeric_str(str3);
    if (state) { printf("a string is numeric.\n"); }
    else { printf("a string is not numeric.\n"); }    

    str1 = term_str(str1);
    str2 = term_str(str2);
    str3 = term_str(str3);
    
    return SUCCESS; 
}

bool numeric_str(const char * str) {
    bool state;
    int64 length;
    
    if (str) { // execution
        length = strlen(str);
        
        for (register int32 i = 0; i < length; i++) {
            if (*(str + i) >= 48 && *(str + i) <= 57) 
                 { state = TRUE; }
            else { state = FALSE; /* \n */ i = length; }
        } 
    } else { // exception
        state = FALSE;
    }
    
    return state;
}
