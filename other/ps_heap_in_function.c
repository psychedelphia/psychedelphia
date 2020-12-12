//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// using heap memory in function                               //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"

// New Function Here! -------------------------------------------
char * heap_h(const char * src); // duplicate string(new heap memory)
// --------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation 
int32 main(void) {
    char * src = "abcd";
    char * copied = NULL;

    printf("text: %s,        address of copied(NULL): %p\n", copied, copied);

    copied = src;
    printf("text: %s,           address of copied(src): %p\n", copied, copied);
    
    copied = heap_h(src);
    printf("text: %s,        address of copied(heap_h): %p\n", copied, copied); 

    free(copied); // after heap_h(), free() is needed
    printf("text: %s,      address of copied(after free()): %p\n", copied, copied);    

    copied = NULL;
    printf("text: %s,        address of copied(NULL): %p\n", copied, copied);    
    
    return SUCCESS; 
}

//------------------------
// heap_h() implementation
char * heap_h(const char * src) { // function name + "_h" (mean: heap memory(free() needed))
    char * copied = NULL;
    uint64 length;

    if (src != NULL) { // execution
        length = strlen(src);        
        copied = malloc(length + 1);

        if (length) { memcpy(copied, src, length); }
    } else { // exception
        length = 0;
        copied = malloc(1);
    }
    
    *(copied + length) = '\0';

    return copied;
}
