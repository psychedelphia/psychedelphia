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
int32 cmp_str(const char * str1, const char * str2); // print string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char * str1 = init_str_h("This is a string");
    char * str2 = init_str_h("What happened?");
    char * str3 = init_str_h("What happened?");
    char * str4 = init_str_h("Whaa happened?");
    char * str5 = NULL;
    char * str6 = NULL;
    int32 ret;
    
    ret = cmp_str(str1, str2);
    
    if (ret == 0) {
        printf("two string are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }

    ret = cmp_str(str2, str3);
    
    if (ret == 0) {
        printf("two string are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }
    
    ret = cmp_str(str3, str4);
    
    if (ret == 0) {
        printf("two string are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }
    
    ret = cmp_str(str4, str5);
    
    if (ret == 0) {
        printf("two string are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }

    ret = cmp_str(str5, str6);
    
    if (ret == 0) {
        printf("two string are same.\n");
    } else if (ret > 0) {
        printf("left string > right string\n");
    } else {
        printf("left string < right string\n");
    }
    
    str1 = term_str(str1);
    str2 = term_str(str2);
    str3 = term_str(str3);
    str4 = term_str(str4);
    str5 = term_str(str5);
    str6 = term_str(str6);    
    
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
        if (str1 == NULL && str2 == NULL) {
            result = 0;
        } else if (str1 != NULL && str2 == NULL) {
            result = 1;
        } else {
            result = -1;
        }
    }
    
    return result;
}
