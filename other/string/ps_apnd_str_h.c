//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// append string                                               //
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
    char * str1 = NULL;
    char * str2 = init_str_h("This is a string");
    char * str3 = init_str_h("after");
    
    printn_str(str1);
    
    str1 = apnd_str_h(str1, str2);
    printn_str(str1);

    str1 = apnd_char_str_h(str1, '+', 3);
    printn_str(str1);

    str1 = apnd_fsub_str_h(str1, str3, 2);
    printn_str(str1);

    str1 = apnd_isub_str_h(str1, str1, 2, 4);
    printn_str(str1);    
    
    str1 = term_str(str1);
    str2 = term_str(str2);
    str3 = term_str(str3);    
    
    return SUCCESS; 
}

char * apnd_str_h(char * this, const char * str) { // function name + "_h" (meaning: heap memory(free() needed))
    char * temp = NULL;
    uint64 thislength, strlength;

    if (str) { // str != NULL
        strlength = strlen(str);
    
        if (this) { // this != NULL
            thislength = strlen(this);

            temp = this;
            this = (char * )realloc(this, sizeof(char) * (thislength + strlength + 1));

            if (this) { // execution
                if (this != temp) {
                    temp = term_str(temp);
                } else {
                    temp = NULL;
                }
            
                memcpy(this + thislength, str, strlength);
                *(this + thislength + strlength) = '\0';
            } else { // exception
                temp = term_str(temp);
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }
        } else { // this == NULL
            this = (char * )malloc(sizeof(char) * (strlength + 1));
            
            if (this) { // execution
                memcpy(this, str, strlength);
                *(this + strlength) = '\0';
            } else { // exception
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }            
        }
    }
    
    return this;   
}

char * apnd_char_str_h(char * this, const char c, int num) { // function name + "_h" (meaning: heap memory(free() needed))
    char * temp = NULL;
    uint64 thislength;

    if (num >= 0) { // execution
        if (this) { // this != NULL
            thislength = strlen(this); 

            temp = this;
            this = (char * )realloc(this, sizeof(char) * (thislength + num + 1));
        
            if (this) { // execution
                if (this != temp) {
                    temp = term_str(temp);
                } else {
                    temp = NULL;
                }

                memset(this + thislength, c, num);
                *(this + thislength + num) = '\0';
            } else { // exception
                temp = term_str(temp);
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }
        } else { // this == NULL
            this = (char * )malloc(sizeof(char) * (num + 1));
        
            if (this) { // execution
                memset(this, c, num);
                *(this + num) = '\0';
            } else { // exception
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }
        }
    } else { // exception
        printf("char: out of bounds!");
        exit(EXIT_FAILURE);
    }

    return this;   
}

char * apnd_fsub_str_h(char * this, const char * str, int32 len) { // function name + "_h" (meaning: heap memory(free() needed))
    char * temp = NULL;
    uint64 thislength, strlength;

    if (str) { // execution
        strlength = strlen(str);
    
        if (len > 0 && strlength >= len) { // execution
            if (this) {
                thislength = strlen(this); 

                temp = this;
                this = (char * )realloc(this, sizeof(char) * (thislength + len + 1));
        
                if (this) { // execution         
                    if (this != temp) {
                        temp = term_str(temp);
                    } else {
                        temp = NULL;
                    }

                    memcpy(this + thislength, str, len);
                    *(this + thislength + len) = '\0';
                } else { // exception
                    temp = term_str(temp);
                    printf("memory is not allocated!");
                    exit(EXIT_FAILURE);
                }
            } else {
                this = (char * )malloc(sizeof(char) * (len + 1));
                
                if (this) { // execution
                    memcpy(this, str, len);
                    *(this + len) = '\0';
                } else { // exception
                    printf("memory is not allocated!");
                    exit(EXIT_FAILURE);
                }
            }
        } else { // exception
            printf("str: out of bounds!");
            exit(EXIT_FAILURE);
        }
    }

    return this;   
}

char * apnd_isub_str_h(char * this, const char * str, int32 index, int32 len) { // function name + "_h" (meaning: heap memory(free() needed))
    char * temp = NULL;
    uint64 thislength, strlength;

    if (str) { // execution
        strlength = strlen(str);
    
        if (index >= 0 && len > 0 && strlength >= (index + len)) { // execution
            if (this) { // this != NULL
                thislength = strlen(this); 

                temp = this;
                this = (char * )realloc(this, sizeof(char) * (thislength + len + 1));
        
                if (this) { // execution       
                    if (this != temp) {
                        temp = term_str(temp);
                    } else {
                        temp = NULL;
                    }

                    memcpy(this + thislength, str + index, len);  
                    *(this + thislength + len) = '\0';
                } else { // exception
                    temp = term_str(temp);
                    printf("memory is not allocated!");
                    exit(EXIT_FAILURE);
                }
            } else { // this == NULL
                this = (char * )malloc(sizeof(char) * (len + 1));
                
                if (this) { //execution
                    memcpy(this, str + index, len);
                    *(this + len) = '\0';
                } else { // exception
                    printf("memory is not allocated!");
                    exit(EXIT_FAILURE);
                }
            }
        } else { // exception
            printf("str: out of bounds!");
            exit(EXIT_FAILURE);
        }
    }
    
    return this;   
}
