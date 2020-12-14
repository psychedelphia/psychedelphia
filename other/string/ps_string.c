#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// initialize and terminate string ----------------------------------------------
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
        printf("memory is not allocated!");
        exit(EXIT_FAILURE);
    }

    return copied;
}

char * term_str(char * this) {
    if (this != NULL) { // execution
        free(this);
    }
    
    this = NULL;

    return this;   
}
//-------------------------------------------------------------------------------

void print_str(const char * str) {
    printf("%s", str);
}
