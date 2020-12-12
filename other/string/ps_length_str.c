//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// create string                                               //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"

// Global variable Here! --------------------------------------------------------
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
void length_str(const char * str); // length of string

char * init_str_h(const char * str); // create string
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
    
    free(str1);
    str1 = NULL;
    free(str2);
    str2 = NULL;
    
    return SUCCESS; 
}

void length_str(const char * str) {
    printf("%ld", strlen(str));
}

char * init_str_h(const char * str) { // function name + "_h" (mean: heap memory(free() needed))
    char * copied;
    uint64 length;

    if (str != NULL) { // execution
        length = strlen(str);        
    } else { // exception
        length = 0;
    }
    
    copied = (char * )malloc(sizeof(char) * (length + 1));

    if (copied != NULL) { // execution
        if (length) { memcpy(copied, str, length); }
    
        *(copied + length) = '\0';
    } else { // exception
        printf("memory is not enough!");
    }

    return copied;
}
