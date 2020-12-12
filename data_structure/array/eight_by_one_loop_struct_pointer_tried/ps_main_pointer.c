//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array                                     //
//-------------------------------------------------------------//
// global pointer is critical. use your own part.              // 
// don't let people use this pointer.                          //
//-------------------------------------------------------------//

#include <stdio.h>
#include "array.h"

//----------------------
// main() implementation 
int main(void) {
    Array a = { { 0 }, 0 };  // initializing(constructor)
__array_ptr = &a; // for Array functions(must)
    // example
    printf("capacity: "); /* << */ capacity_st(); /* << */ puts("");  
    print_st(); /* << */ puts("");
    printf("insert data\n");
    push_front_st(1);
    print_st(); /* << */ puts("");
    printf("insert data\n");
    push_front_st(2);
    print_st(); /* << */ puts("");

    printf("insert data\n");    
    push_back_st(3);
    print_st(); /* << */ puts("");
    printf("insert data\n");
    push_back_st(4);
    print_st(); /* << */ puts("");    
    printf("first data: "); /* << */ front_st(); /* << */ puts("");
    printf("last data: "); /* << */ back_st(); /* << */ puts("");
    
    printf("value of data[2]: "); /* << */ at_st(2); /* << */ puts("");
    printf("value of data[3]: "); /* << */ at_st(3); /* << */ puts("");

    printf("swap data\n");
    swap_st(1, 4);    
    print_st(); /* << */ puts("");
    printf("swap data\n");    
    swap_st(2, 3);    
    print_st(); /* << */ puts("");

    printf("assign data\n");
    assign_st(5, 3);
    print_st(); /* << */ puts("");

    printf("insert data\n");
    insert_st(4, 4);
    print_st(); /* << */ puts("");
    printf("insert data\n");
    insert_st(5, 5);
    print_st(); /* << */ puts("");

    printf("erase data\n");
    erase_st(2);
    print_st(); /* << */ puts("");
    printf("erase data\n");
    erase_st(6);
    print_st(); /* << */ puts("");

    printf("rest of array: "); /* << */ rest_st(); /* << */ puts("");
    printf("size: "); /* << */ size_st(); /* << */ puts("");
    
    if (empty_st()) { printf("array is empty\n"); }
    else { printf("array is not empty\n"); }
    
    printf("initializing\n");
    init_st();
    printf("size: "); /* << */ size_st(); /* << */ puts("");
    if (empty_st()) { printf("array is empty\n"); }
    else { printf("array is not empty\n"); }    
    
    return 0; 
}
