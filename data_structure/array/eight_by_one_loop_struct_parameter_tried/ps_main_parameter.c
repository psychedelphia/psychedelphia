//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array                                     //
//-------------------------------------------------------------//

#include <stdio.h>
#include "array.h"

//----------------------
// main() implementation 
int main(void) {
    Array a = { { 0 }, 0 };  // initializing(constructor)
              
    // example
    printf("capacity: "); /* << */ capacity_st(&a); /* << */ puts("");  
    print_st(&a); /* << */ puts("");
    printf("insert data\n");
    push_front_st(&a, 1);
    print_st(&a); /* << */ puts("");
    printf("insert data\n");
    push_front_st(&a, 2);
    print_st(&a); /* << */ puts("");

    printf("insert data\n");    
    push_back_st(&a, 3);
    print_st(&a); /* << */ puts("");
    printf("insert data\n");
    push_back_st(&a, 4);
    print_st(&a); /* << */ puts("");    
    printf("first data: "); /* << */ front_st(&a); /* << */ puts("");
    printf("last data: "); /* << */ back_st(&a); /* << */ puts("");
    
    printf("value of data[2]: "); /* << */ at_st(&a, 2); /* << */ puts("");
    printf("value of data[3]: "); /* << */ at_st(&a, 3); /* << */ puts("");

    printf("swap data\n");
    swap_st(&a, 1, 4);    
    print_st(&a); /* << */ puts("");
    printf("swap data\n");    
    swap_st(&a, 2, 3);    
    print_st(&a); /* << */ puts("");

    printf("assign data\n");
    assign_st(&a, 5, 3);
    print_st(&a); /* << */ puts("");

    printf("insert data\n");
    insert_st(&a, 4, 4);
    print_st(&a); /* << */ puts("");
    printf("insert data\n");
    insert_st(&a, 5, 5);
    print_st(&a); /* << */ puts("");

    printf("erase data\n");
    erase_st(&a, 2);
    print_st(&a); /* << */ puts("");
    printf("erase data\n");
    erase_st(&a, 6);
    print_st(&a); /* << */ puts("");

    printf("rest of array: "); /* << */ rest_st(&a); /* << */ puts("");
    printf("size: "); /* << */ size_st(&a); /* << */ puts("");
    
    if (empty_st(&a)) { printf("array is empty\n"); }
    else { printf("array is not empty\n"); }
    
    printf("initializing\n");
    init_st(&a);
    printf("size: "); /* << */ size_st(&a); /* << */ puts("");
    if (empty_st(&a)) { printf("array is empty\n"); }
    else { printf("array is not empty\n"); }    
    
    return 0; 
}
