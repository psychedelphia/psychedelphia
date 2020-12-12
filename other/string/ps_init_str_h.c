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

// New Function Here! -----------------------------------------------------------
char * init_str_h(const char * str); // create string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string"); // dynamic memory
    char * str2 = init_str_h("What happened?"); // dynamic memory
    
    printf("string1 created: %s\n", str1);
    printf("string1 length: %ld\n", strlen(str1));
    printf("string2 created: %s\n", str2);
    printf("string2 length: %ld\n", strlen(str2));    
    
    free(str1);
    str1 = NULL;
    free(str2);
    str2 = NULL;
    
    return SUCCESS; 
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
