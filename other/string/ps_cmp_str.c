//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// compare string                                              //
//-------------------------------------------------------------//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "ps_datatypes.h"
#include "ps_string.h"

// New Function Here! -----------------------------------------------------------
int32 cmp_str(const char * str1, const char * str2); // compare string
int32 cmp_rsub_str(const char * str1, const char * str2, uint64 index, uint64 len); // compare string
int32 cmp_lrsub_str(const char * str1, uint64 index1, uint64 len1, 
                    const char * str2, uint64 index2, uint64 len2); // compare string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    char * str3 = init_str_h("string");
    char * str4 = init_str_h("It is a string");
    int32 ret;
    
    ret = cmp_str(str1, str2);
    
    if (ret == 0) {
        printf("two strings are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }

    ret = cmp_str(str1, str2);
    
    if (ret == 0) {
        printf("two strings are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }
    
    ret = cmp_rsub_str(str3, str1, 10, 6);

    if (ret == 0) {
        printf("two strings are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }
    
    ret = cmp_lrsub_str(str1, 10, 6, str4, 8, 6);

    if (ret == 0) {
        printf("two strings are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }

    str1 = term_str(str1);
    str2 = term_str(str2);
    str3 = term_str(str3);
    str4 = term_str(str4);

    return SUCCESS; 
}

int32 cmp_lrsub_str(const char * str1, uint64 index1, uint64 len1, const char * str2, uint64 index2, uint64 len2) {
    char * sub1, * sub2;
    int32 result;
    uint64 str1len, str2len;
    
    if (str1 != NULL && str2 != NULL) { // execution
        str1len = strlen(str1);
        str2len = strlen(str2);

        if ((index1 >= 0) && (len1 > 0) && ((index1 + len1) <= str1len)) { // execution
            if ((index2 >= 0) && (len2 > 0) && ((index2 + len2) <= str2len)) { // execution
                sub1 = (char * )malloc(sizeof(char) * (len1 + 1));

                if (sub1 != NULL) { // execution
                    *(sub1 + len1) = '\0';
                    memcpy(sub1, str1 + index1, len1);
                } else { // exception
                    printf("str1: memory is not allocated!");
                    exit(EXIT_SUCCESS); 
                }

                sub2 = (char * )malloc(sizeof(char) * (len2 + 1));

                if (sub1 != NULL) { // execution
                    *(sub2 + len2) = '\0';
                    memcpy(sub2, str2 + index2, len2);
                } else { // exception
                    printf("str2: memory is not allocated!");
                    exit(EXIT_SUCCESS); 
                }

                result = cmp_str(sub1, sub2);
            
                free(sub1);
                sub1 = NULL;
                free(sub2);
                sub2 = NULL;    
            } else { // exception
                printf("str2: out of bound!");
                exit(EXIT_SUCCESS);
            }
        } else { // exception
            printf("str1: out of bound!");
            exit(EXIT_SUCCESS);
        }
    } else { // exception
        printf("NULL found!");
        exit(EXIT_SUCCESS);
    }
    
    return result;
}

int32 cmp_rsub_str(const char * str1, const char * str2, uint64 index, uint64 len) {
    char * sub;
    int32 result;
    uint64 str2len;
    
    if (str1 != NULL && str2 != NULL) { // execution
        str2len = strlen(str2);
        
        if ((index >= 0) && (len > 0) && ((index + len) <= str2len)) { // execution
            sub = (char * )malloc(sizeof(char) * (len + 1));
            
            if (sub != NULL) { // execution
                *(sub + len) = '\0';
                memcpy(sub, str2 + index, len);
            } else { // exception
                printf("memory is not allocated!");
                exit(EXIT_SUCCESS); 
            }
            
            result = cmp_str(str1, sub);
            
            free(sub);
            sub = NULL;
        } else { // exception
           printf("str2: out of bound!");
           exit(EXIT_SUCCESS);
        }
    } else { // exception
        printf("NULL found!");
        exit(EXIT_SUCCESS);
    }
    
    return result;
}

int32 cmp_str(const char * str1, const char * str2) {
    uint64 len1, len2, less;
    int32 result;
    
    if (str1 != NULL && str2 != NULL) { // execution
        len1 = strlen(str1);
        len2 = strlen(str2);
        
        if (len1 == len2) { result = memcmp(str1, str2, len1); }
        else              { result = len1 < len2 ? -1 : 1; }
    } else { // exception
        if      (str1 == NULL && str2 == NULL) { result = 0; } 
        else if (str1 != NULL && str2 == NULL) { result = 1; }
        else                                   { result = -1; }
    }
    
    return result;
}
