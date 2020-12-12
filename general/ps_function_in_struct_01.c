//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of struct with function                      //
//-------------------------------------------------------------//
// global pointer is critical. use your own part.              // 
// don't let people use this pointer. (and memory problem)     //
//-------------------------------------------------------------//

#include <stdio.h>
#include "ps_datatypes.h"

// minimize usage of (/ → * → - → +) operator and floating-point
// New Struct Here! -------------------------------------------------------------
typedef struct example{
    // struct variables Here!
    int32 number;
    
    // struct functions Here!
    void (* push_number)(int32 number);
} Example;

Example * __example_ptr; // All functions related to Example can use this pointer.

// Explanation of Functions ------------------------------------------------------------
// functions with struct example(Example) -----------------------------------
//--------------------------------
// push_number_st() implementation: input value into local variable 
void push_number_st(int32 number) { // function name + "_st" (mean: for struct)
    __example_ptr->number = number;
}

//----------------------
// main() implementation 
int32 main(void) {
    Example a = { 0,             // variables
                  push_number_st // functions 
                }; // initializing(constructor)
    Example b = { 0,             // variables
                  push_number_st // functions
                }; // initializing(constructor)
    Example c = { 0,             // variables
                  push_number_st // functions
                }; // initializing(constructor)    
    
__example_ptr = &a; // for Example functions(must): usage of Example a
    a.push_number(1); // a.number = 1
    printf("a.number = %d\n", a.number);    
    a.push_number(2); // a.number = 2
    printf("a.number = %d\n", a.number);

__example_ptr = &b; // for Example functions(must): usage of Example b
    b.push_number(3); // b.number = 3 
    printf("b.number = %d\n", b.number);
    b.push_number(4); // b.number = 4
    printf("b.number = %d\n", b.number);    
    
__example_ptr = &c; // for Example functions(must): usage of Example c    
    c.push_number(5); // c.number = 5
    printf("c.number = %d\n", c.number);    
    c.push_number(6); // c.number = 6 
    printf("c.number = %d\n", c.number);
    
__example_ptr = &a; // for Example functions(must): usage of Example a
    a.push_number(5); // a.number = 1
    printf("a.number = %d\n", a.number);    
    a.push_number(6); // a.number = 2
    printf("a.number = %d\n", a.number);    
    
    if (a.number == c.number) { printf("equal!\n"); }
    else { printf("not equal!\n"); }
    
    if (b.number == c.number) { printf("equal!\n"); }
    else { printf("not equal!\n"); }
    
    return SUCCESS; 
}
