//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// append new string                                           //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
char * apnd_str_h(char * this, const char * str); // append new string
char * apnd_char_str_h(char * this, const char c, int32 num); // append new character
char * apnd_fsub_str_h(char * this, const char * str, int32 len); // append new string(front)
char * apnd_isub_str_h(char * this, const char * str, int32 index, int32 len); // append new sub-string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("after");

    str1 = apnd_str_h(str1, str2);
    print_str(str1); /* << */ puts("");    

    str2 = apnd_char_str_h(str2, '$', 5);
    print_str(str2); /* << */ puts("");    

    str1 = apnd_fsub_str_h(str1, str2, 3);
    print_str(str1); /* << */ puts("");

    str2 = apnd_isub_str_h(str2, str1, 5, 4);
    print_str(str2); /* << */ puts("");
    
    str1 = term_str(str1);
    str2 = term_str(str2);
    
    return SUCCESS; 
}

char * apnd_str_h(char * this, const char * str) { // function name + "_h" (meaning: heap memory(free() needed))
    char * append = NULL;
    uint64 thislength, strlength;

    if (str != NULL) { // execution
        strlength = strlen(str);
        
        if (this != NULL) { thislength = strlen(this); } 
        else              { thislength = 0; }
    
        append = (char * )malloc(sizeof(char) * (thislength + strlength + 1));
    
        if (append != NULL) { // execution
            if (this != NULL) { memcpy(append, this, thislength); }

            memcpy(append + thislength, str, strlength);
            *(append + thislength + strlength) = '\0';
            
            this = term_str(this); // destructed original pointer
        } else { // exception
            printf("memory is not allocated!");
            exit(EXIT_FAILURE);
        }
    } else { // exception
        append = this;
    } 

    return append;   
}

char * apnd_char_str_h(char * this, const char c, int num) { // function name + "_h" (meaning: heap memory(free() needed))
    char * append = NULL;
    uint64 thislength;

    if (this != NULL) { thislength = strlen(this); } 
    else              { thislength = 0; }
    
    append = (char * )malloc(sizeof(char) * (thislength + num + 1));
    
    if (append != NULL) { // execution
        if (this != NULL) { memcpy(append, this, thislength); }

        memset(append + thislength, c, num);
        *(append + thislength + num) = '\0';
            
        this = term_str(this); // destructed original pointer
    } else { // exception
        printf("memory is not allocated!");
        exit(EXIT_FAILURE);
    }

    return append;   
}

char * apnd_fsub_str_h(char * this, const char * str, int32 len) { // function name + "_h" (meaning: heap memory(free() needed))
    char * append = NULL;
    uint64 thislength, strlength;

    if (str != NULL) { // execution
        strlength = strlen(str);
    
        if (strlength >= len) { // execution
            if (this != NULL) { thislength = strlen(this); } 
            else              { thislength = 0; }
        
            append = (char * )malloc(sizeof(char) * (thislength + len + 1));
        
            if (append != NULL) { // execution
                if (this != NULL) { memcpy(append, this, thislength); }             

                memcpy(append + thislength, str, len);
                *(append + thislength + len) = '\0';
                
                this = term_str(this); // destructed original pointer
            } else { // exception
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }
        } else { // exception
            printf("st2: out of bounds!");
            exit(EXIT_FAILURE);
        }
    } else { // exception
        append = this;
    } 

    return append;   
}

char * apnd_isub_str_h(char * this, const char * str, int32 index, int32 len) { // function name + "_h" (meaning: heap memory(free() needed))
    char * append = NULL;
    uint64 thislength, strlength;

    if (str != NULL) { // execution
        strlength = strlen(str);
    
        if (strlength >= (index + len)) { // execution
            if (this != NULL) { thislength = strlen(this); } 
            else              { thislength = 0; }
        
            append = (char * )malloc(sizeof(char) * (thislength + len + 1));
        
            if (append != NULL) { // execution
                if (this != NULL) { memcpy(append, this, thislength); }             

                memcpy(append + thislength, str + index, len);
                *(append + thislength + len) = '\0';
                
                this = term_str(this); // destructed original pointer
            } else { // exception
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }
        } else { // exception
            printf("st2: out of bounds!");
            exit(EXIT_FAILURE);
        }
    } else { // exception
        append = this;
    } 

    return append;   
}
