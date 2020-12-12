//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of struct with function (memory problem)     //                     
//-------------------------------------------------------------//

#include <stdio.h>
#include "ps_datatypes.h"

// New Struct Here! -------------------------------------------------------------
typedef struct example Example;
struct example{
    // struct variables Here!
    int32 number;
    
    // struct functions Here!
    void (* push_number)(Example * str, int32 number);
};

// Explanation of Functions ------------------------------------------------------------
// functions with struct example(Example) -----------------------------------
//--------------------------------
// push_number_st() implementation: insert value into local variable 
void push_number_st(Example * str, int32 number) { // function name + "_st" (mean: for struct)
    str->number = number;
}

// minimize usage of (/ → * → - → +) operator and floating-point
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
    
    a.push_number(&a, 1); // a.number = 1
    printf("a.number = %d\n", a.number);    
    a.push_number(&a, 2); // a.number = 2
    printf("a.number = %d\n", a.number);

    b.push_number(&b, 3); // b.number = 3 
    printf("b.number = %d\n", b.number);
    b.push_number(&b, 4); // b.number = 4
    printf("b.number = %d\n", b.number);    
    
    c.push_number(&c, 5); // c.number = 5
    printf("c.number = %d\n", c.number);    
    c.push_number(&c, 6); // c.number = 6 
    printf("c.number = %d\n", c.number);
    
    a.push_number(&a, 5); // a.number = 1
    printf("a.number = %d\n", a.number);    
    a.push_number(&a, 6); // a.number = 2
    printf("a.number = %d\n", a.number);    
    
    if (a.number == c.number) { printf("equal!\n"); }
    else { printf("not equal!\n"); }
    
    if (b.number == c.number) { printf("equal!\n"); }
    else { printf("not equal!\n"); }
    
    return SUCCESS; 
}
