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

// Global variable Here! --------------------------------------------------------
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
int32 cmp_str(const char * str1, const char * str2); // print string

char * init_str_h(const char * str); // create string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    char * str3 = init_str_h("What happened?");
    char * str4 = init_str_h("Whaa happened?");    
    int32 ret;
    
    ret = cmp_str(str1, str2);
    
    if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }

    ret = cmp_str(str2, str3);
    
    if (ret == 0) {
        printf("two string are same.\n");
    } else {
        printf("two string are not same.\n");
    }
    
    ret = cmp_str(str3, str4);
    
    if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }
    
    free(str1);
    str1 = NULL;
    free(str2);
    str2 = NULL;
    free(str3);
    str3 = NULL;
    free(str4);
    str4 = NULL;    
    
    return SUCCESS; 
}

int32 cmp_str(const char * str1, const char * str2) {
    uint64 len1, len2, less;
    int32 result;
    
    if (str1 != NULL && str2 != NULL) { // execution
        len1 = strlen(str1);
        len2 = strlen(str2);
        
        if (len1 == len2) { 
            result = memcmp(str1, str2, len1);
        }
        else { 
            result = len1 < len2 ? -1 : 1;
        }
    } else { // exception
        printf("NULL found!");    
    }
    
    return result;
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
