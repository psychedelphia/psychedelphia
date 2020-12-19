//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// assign string                                               //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
char * asgn_str_h(char * this, const char * str); // assign new string
char * asgn_char_str_h(char * this, const char c, int num); // assign new character
char * asgn_fsub_str_h(char * this, const char * str, int32 len); // assign new string(front)
char * asgn_isub_str_h(char * this, const char * str, int32 index, int32 len); // assign new sub-string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");

    printn_str(str1);

    str1 = asgn_str_h(str1, "abcdef");
    printn_str(str1);

    str1 = asgn_char_str_h(str1, '+', 10);
    printn_str(str1);
    
    str1 = asgn_fsub_str_h(str1, "It is a string", 10);
    printn_str(str1);
    
    str1 = asgn_isub_str_h(str1, "This is a string", 10, 6);
    printn_str(str1);

    str1 = term_str(str1);

    return SUCCESS; 
}

char * asgn_str_h(char * this, const char * str) {
    char * temp;
    uint64 thislength, strlength;

    if (str) {
        strlength = strlen(str);
        
        if (this) {
            thislength = strlen(this);
            
            if (strlength > thislength) {
                temp = this;
                this = (char * )realloc(this, (sizeof(char) * (strlength + 1)));
                
                if (this) {
                    memcpy(this, str, strlength);
                    *(this + strlength) = '\0';
                } else { // realloc this == NULL
                    temp = term_str(temp);
                    printf("memory is not allocated!");
                    exit(EXIT_FAILURE);
                }
            } else { // strlength <= thislength
                memcpy(this, str, strlength);
                *(this + strlength) = '\0';
            }
        } else { // this == NULL
            this = (char * )malloc(sizeof(char) * (strlength + 1));
            memcpy(this, str, strlength);
            *(this + strlength) = '\0';
        }
    } else {
        this = term_str(this);
    }
     
    return this;
}

char * asgn_char_str_h(char * this, const char c, int num) {
    char * temp;
    uint64 thislength;

    if (num >= 0) {
        if (this) {
            thislength = strlen(this);
            
            if (num > thislength) {
                temp = this;
                this = (char * )realloc(this, sizeof(char) * (num + 1));
                
                if (this) {
                    memset(this, c, num);
                    *(this + num) = '\0';
                } else { // realloc this == NULL
                    temp = term_str(temp);
                    printf("memory is not allocated!");
                    exit(EXIT_FAILURE);
                }
            } else { // num <= thislength
                memset(this, c, num);
                *(this + num) = '\0';
            }
        } else { // this == NULL
            this = (char * )malloc(sizeof(char) * (num + 1));
            
            if (this) {
                memset(this, c, num);
                *(this + num) = '\0';
            } else { // malloc this == NULL
                printf("memory is not allocated!");
                exit(EXIT_FAILURE);
            }
        }
    } else { // num < 0
        printf("char: out of bounds!");
        exit(EXIT_FAILURE);
    }
    
    return this;
}

char * asgn_fsub_str_h(char * this, const char * str, int32 len) {
    char * temp;
    uint64 thislength, strlength;
    
    if (str) {
        strlength = strlen(str);
        
        if (len > 0 && strlength >= len) {
            if (this) {
                thislength = strlen(this);
            
                if (len > thislength) {
                    temp = this;
                    this = (char * )realloc(this, (sizeof(char) * (len + 1)));
                
                    if (this) {
                        memcpy(this, str, len);
                        *(this + len) = '\0';
                    } else { // realloc this == NULL
                        temp = term_str(temp);
                        printf("memory is not allocated!");
                        exit(EXIT_FAILURE);
                    }
                } else { // strlength <= thislength
                    memcpy(this, str, len);
                    *(this + len) = '\0';
                }
            } else { // this == NULL
                this = (char * )malloc(sizeof(char) * (len + 1));
                memcpy(this, str, len);
                *(this + len) = '\0';
            }
        } else { // len <=0 || strlength < len
            printf("str: out of bounds!");
            exit(EXIT_FAILURE);
        }
    } else {
        this = term_str(this);
    }
    
    return this;
}

char * asgn_isub_str_h(char * this, const char * str, int32 index, int32 len) {
    char * temp;
    uint64 thislength, strlength;
    
    if (str) {
        strlength = strlen(str);
        
        if (index >= 0 && len > 0 && strlength >= (index + len)) {
            if (this) {
                thislength = strlen(this);
            
                if (len > thislength) {
                    temp = this;
                    this = (char * )realloc(this, (sizeof(char) * (len + 1)));
                
                    if (this) {
                        memcpy(this, str + index, len);
                        *(this + len) = '\0';
                    } else { // realloc this == NULL
                        temp = term_str(temp);
                        printf("memory is not allocated!");
                        exit(EXIT_FAILURE);
                    }
                } else { // strlength <= thislength
                    memcpy(this, str + index, len);
                    *(this + len) = '\0';
                }
            } else { // this == NULL
                this = (char * )malloc(sizeof(char) * (len + 1));
                memcpy(this, str + index, len);
                *(this + len) = '\0';
            }
        } else { // index < 0 || len <=0 || strlength < len
            printf("str: out of bounds!");
            exit(EXIT_FAILURE);
        }
    } else {
        this = term_str(this);
    }
    
    return this;
}
