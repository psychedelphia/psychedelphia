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

char * clear_str_h(char * str) { // function name + "_h" (meaning: heap memory(free() needed))
    char * removed;

    if (str != NULL) { // execution
        removed = str;
        free(removed);
    } 
    
    removed = NULL;
    removed = (char * )malloc(sizeof(char));
    
    if (removed != NULL) { // execution
        *removed = '\0';        
    } else { // exception
        printf("memory is not allocated!");
        exit(EXIT_FAILURE);
    }
 
    return removed;   
}
