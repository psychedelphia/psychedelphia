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

extern Array * __array_ptr; // using pointer "__array_ptr" from array.h

// functions with struct arraylist(Array) -----------------------------------
//-------------------------
// init_st() implementation
void init_st() { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);
    int rest = 0;
    
    if (dataset_size >= 8) { // array >= 8 (in certain circumstances, it's more efficient than (one by one) loop)
        for (register int i = 0; (i + 7) < dataset_size; i += 8) {
            __array_ptr->dataset[i]   = 0;
            __array_ptr->dataset[i+1] = 0;  
            __array_ptr->dataset[i+2] = 0;
            __array_ptr->dataset[i+3] = 0;
            __array_ptr->dataset[i+4] = 0;
            __array_ptr->dataset[i+5] = 0;
            __array_ptr->dataset[i+6] = 0;
            __array_ptr->dataset[i+7] = 0;
            rest = i + 8;
        }
    }

    // the rest of (8 by one) loop
    for (register int i = rest; i < dataset_size; i++) { 
        __array_ptr->dataset[i] = 0; 
    }
    
    __array_ptr->cursor = 0;
}

//-------------------------------
// push_front_st() implementation
void push_front_st(int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);
    int quotient = __array_ptr->cursor / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (__array_ptr->cursor >= 0 && __array_ptr->cursor < dataset_size) { // excution restrict
        if (__array_ptr->cursor) { // some data in array list
            if ((__array_ptr->cursor & 7) != 0) { // ref->cursor % 8 != 0
                for (register int i = __array_ptr->cursor; i > multiple_eight; i--) {
                    __array_ptr->dataset[i] = __array_ptr->dataset[i-1]; 
                }
            }
            
            // ref->cursor % 8 == 0, (8 by one) loop
            for (register int i = multiple_eight; (i - 7) > 0; i -= 8) {
                __array_ptr->dataset[i]   = __array_ptr->dataset[i-1];
                __array_ptr->dataset[i-1] = __array_ptr->dataset[i-2];    
                __array_ptr->dataset[i-2] = __array_ptr->dataset[i-3];
                __array_ptr->dataset[i-3] = __array_ptr->dataset[i-4];
                __array_ptr->dataset[i-4] = __array_ptr->dataset[i-5];
                __array_ptr->dataset[i-5] = __array_ptr->dataset[i-6];
                __array_ptr->dataset[i-6] = __array_ptr->dataset[i-7];
                __array_ptr->dataset[i-7] = __array_ptr->dataset[i-8];
            }
        }

        __array_ptr->dataset[0] = number;
        __array_ptr->cursor++;
    } else {
        printf("out of bound!");
    }
}

//------------------------------
// push_back_st() implementation
void push_back_st(int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);
 
    // input data into dataset array
    if (__array_ptr->cursor >= 0 && __array_ptr->cursor < dataset_size) { // excution restrict
        __array_ptr->dataset[__array_ptr->cursor] = number;
        __array_ptr->cursor++;
    } else {
        printf("out of bound!");
    }
}

//---------------------------
// insert_st() implementation 
void insert_st(int pos, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);
    int quotient = ((__array_ptr->cursor + 1) - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (pos > 0 && pos < (__array_ptr->cursor + 2) && __array_ptr->cursor < dataset_size) { // excution restrict
        if ((((__array_ptr->cursor + 1) - pos) & 7) != 0) { // ((ref->cursor + 1) - pos) % 8 != 0
            for (register int i = __array_ptr->cursor; i > multiple_eight + pos - 1; i--) {
                __array_ptr->dataset[i] = __array_ptr->dataset[i-1]; 
            }
        }
        
        // ((ref->cursor + 1) - pos) % 8 == 0, (8 by one) loop
        for (register int i = multiple_eight + pos - 1; (i - 7) > (pos - 1); i -= 8) {
            __array_ptr->dataset[i]   = __array_ptr->dataset[i-1];
            __array_ptr->dataset[i-1] = __array_ptr->dataset[i-2];    
            __array_ptr->dataset[i-2] = __array_ptr->dataset[i-3];
            __array_ptr->dataset[i-3] = __array_ptr->dataset[i-4];
            __array_ptr->dataset[i-4] = __array_ptr->dataset[i-5];
            __array_ptr->dataset[i-5] = __array_ptr->dataset[i-6];
            __array_ptr->dataset[i-6] = __array_ptr->dataset[i-7];
            __array_ptr->dataset[i-7] = __array_ptr->dataset[i-8];
        }
        
        __array_ptr->dataset[pos-1] = number;
        __array_ptr->cursor++;
    } else {
        printf("out of bound!");
    }
}

//--------------------------
// erase_st() implementation
void erase_st(int pos) { // function name + "_st" (mean: for struct)
    int quotient = (__array_ptr->cursor - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8

    if (pos > 0 && pos <= __array_ptr->cursor) { // excution restrict
        if ((__array_ptr->cursor - pos) >= 8) { // moving data >= 8, (8 by one) loop
            for (register int i = pos - 1; (i + 7) < __array_ptr->cursor; i += 8) {
                __array_ptr->dataset[i]   = __array_ptr->dataset[i+1];
                __array_ptr->dataset[i+1] = __array_ptr->dataset[i+2];  
                __array_ptr->dataset[i+2] = __array_ptr->dataset[i+3];
                __array_ptr->dataset[i+3] = __array_ptr->dataset[i+4];
                __array_ptr->dataset[i+4] = __array_ptr->dataset[i+5];
                __array_ptr->dataset[i+5] = __array_ptr->dataset[i+6];
                __array_ptr->dataset[i+6] = __array_ptr->dataset[i+7];
                __array_ptr->dataset[i+7] = __array_ptr->dataset[i+8];
            }
        }
        
        // the rest of (8 by one) loop
        for (register int i = (pos - 1) + multiple_eight; i < __array_ptr->cursor - 1; i++) {
            __array_ptr->dataset[i] = __array_ptr->dataset[i+1];
        }
        
        __array_ptr->dataset[__array_ptr->cursor - 1] = 0;
        __array_ptr->cursor--;
    } else {
        printf("out of bound!");
    }
}

//---------------------------
// assign_st() implementation
void assign_st(int range, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);
    int rest = 0;

    if (range > 0 && range <= dataset_size) { // excution restrict
        if (range >= 8) { // range >=8, (8 by one) loop
            for (register int i = 0; (i + 7) < range; i += 8) {
                __array_ptr->dataset[i]   = number;
                __array_ptr->dataset[i+1] = number;  
                __array_ptr->dataset[i+2] = number;
                __array_ptr->dataset[i+3] = number;
                __array_ptr->dataset[i+4] = number;
                __array_ptr->dataset[i+5] = number;
                __array_ptr->dataset[i+6] = number;
                __array_ptr->dataset[i+7] = number;
                rest = i + 8;
            }
        }   

        // the rest of (8 by one) loop
        for (register int i = rest; i < range; i++) {
            __array_ptr->dataset[i] = number;
        }
    } else {
        printf("out of bound!");
    }
    
    if (__array_ptr->cursor < range) { __array_ptr->cursor = range; }
}

//-------------------------
// swap_st() implementation
void swap_st(int pos1, int pos2) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);
    int temp;

    if (pos1 <= 0 || __array_ptr->cursor < pos1 || pos2 <= 0 || __array_ptr->cursor < pos2) {
        printf("out of bound!");
    } else if (pos1 == pos2) {
    } else {
        temp = __array_ptr->dataset[pos1-1];
        __array_ptr->dataset[pos1-1] = __array_ptr->dataset[pos2-1]; 
        __array_ptr->dataset[pos2-1] = temp;     
    }
}
    
//--------------------------
// front_st() implementation
void front_st() { // function name + "_st" (mean: for struct)
    if (__array_ptr->cursor == 0) { printf("empty"); }
    else { printf("%d", __array_ptr->dataset[0]); }
}

//-------------------------
// back_st() implementation
void back_st() { // function name + "_st" (mean: for struct)
    if (__array_ptr->cursor == 0) { printf("empty"); }
    else { printf("%d", __array_ptr->dataset[__array_ptr->cursor - 1]); }    
}

//-----------------------
// at_st() implementation
void at_st(int pos) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);

    if (pos > 0 && pos <= __array_ptr->cursor) { printf("%d", __array_ptr->dataset[pos-1]); }
    else { printf("out of bound!"); }
}

//--------------------------
// print_st() implementation
void print_st() { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]);

    for (register int i = 0; i < dataset_size; i++) {
        printf(": %d ", __array_ptr->dataset[i]); 
    }
    
    printf(":");
}

//-----------------------------
// capacity_st() implementation
void capacity_st() { // function name + "_st" (mean: for struct)
    printf("%ld", sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0]));
}

//-------------------------
// size_st() implementation
void size_st() { // function name + "_st" (mean: for struct)
    printf("%d", __array_ptr->cursor);
}

//-------------------------
// rest_st() implementation
void rest_st() { // function name + "_st" (mean: for struct)
    printf("%ld", (sizeof(__array_ptr->dataset) / sizeof(__array_ptr->dataset[0])) - __array_ptr->cursor);
}

//--------------------------
// empty_st() implementation    
int empty_st() { // function name + "_st" (mean: for struct)
    return __array_ptr->cursor ? 0 : 1;    
}
//-------------------------------------------------------------------------------
