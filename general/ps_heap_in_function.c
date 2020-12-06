//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// using heap memory in function                               //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// minimize useage of (/ → * → - → +) operator and floating-point
// New Function Here! -------------------------------------------
char * heap_h(char * src); // duplicate string(new heap memory)
// --------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
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
    
    return 0; 
}

//----------------------
// heap_h implementation
char * heap_h(char * src) { // function name + "_h" (mean: heap memory(free() is needed))
    char * copied = NULL;
    unsigned long int length = strlen(src);
    
    copied = malloc(length + 1);

    if (length) {
        memcpy(copied, src, length);
        *(copied + length) = '\0';
    }

    return copied;
}
