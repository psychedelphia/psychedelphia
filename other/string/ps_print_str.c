//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// print string                                                //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"

// New Function Here! -----------------------------------------------------------
void print_str(const char * str); // print string

char * init_str_h(const char * str); // create string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    
    printf("string1 created: "); /* << */ print_str(str1); /* << */ puts("");
    printf("string2 created: "); /* << */ print_str(str2); /* << */ puts("");

    free(str1);
    str1 = NULL;
    free(str2);
    str2 = NULL;
    
    return SUCCESS; 
}

void print_str(const char * str) {
    printf("%s", str);
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
