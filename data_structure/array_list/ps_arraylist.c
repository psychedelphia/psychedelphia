//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array List                                //
//-------------------------------------------------------------//
// ps_arraylist.c                                              //
//-------------------------------------------------------------//

#include <stdio.h>
#include "arraylist.h"

extern ArrayList * __ref = NULL; // using pointer "ref" from arraylist.h

// functions with struct arraylist(ArrayList) -----------------------------------
//-------------------------
// init_st() implementation
void init_st() { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);
    int rest = 0;
    
    if (dataset_size >= 8) { // array list >= 8 (it's more efficient than (one by one) loop)
        for (register int i = 0; (i + 7) < dataset_size; i += 8) {
            __ref->dataset[i]   = 0;
            __ref->dataset[i+1] = 0;  
            __ref->dataset[i+2] = 0;
            __ref->dataset[i+3] = 0;
            __ref->dataset[i+4] = 0;
            __ref->dataset[i+5] = 0;
            __ref->dataset[i+6] = 0;
            __ref->dataset[i+7] = 0;
            rest = i + 8;
        }
    }

    // the rest of (8 by one) loop
    for (register int i = rest; i < dataset_size; i++) { 
        __ref->dataset[i] = 0; 
    }
    
    __ref->cursor = 0;
}

//-------------------------------
// push_front_st() implementation
void push_front_st(int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);
    int quotient = __ref->cursor / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (__ref->cursor >= 0 && __ref->cursor < dataset_size) { // excution restrict
        if (__ref->cursor) { // some data in array list
            if ((__ref->cursor & 7) != 0) { // ref->cursor % 8 != 0
                for (register int i = __ref->cursor; i > multiple_eight; i--) {
                    __ref->dataset[i] = __ref->dataset[i-1]; 
                }
            }
            
            // ref->cursor % 8 == 0, (8 by one) loop
            for (register int i = multiple_eight; (i - 7) > 0; i -= 8) {
                __ref->dataset[i]   = __ref->dataset[i-1];
                __ref->dataset[i-1] = __ref->dataset[i-2];    
                __ref->dataset[i-2] = __ref->dataset[i-3];
                __ref->dataset[i-3] = __ref->dataset[i-4];
                __ref->dataset[i-4] = __ref->dataset[i-5];
                __ref->dataset[i-5] = __ref->dataset[i-6];
                __ref->dataset[i-6] = __ref->dataset[i-7];
                __ref->dataset[i-7] = __ref->dataset[i-8];
            }
        }

        __ref->dataset[0] = number;
        __ref->cursor++;
    } else {
        puts("out of bound!");
    }
}

//------------------------------
// push_back_st() implementation
void push_back_st(int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);
 
    // input data into dataset array
    if (__ref->cursor >= 0 && __ref->cursor < dataset_size) { // excution restrict
        __ref->dataset[__ref->cursor] = number;
        __ref->cursor++;
    } else {
        puts("out of bound!");
    }
}

//---------------------------
// insert_st() implementation 
void insert_st(int pos, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);
    int quotient = ((__ref->cursor + 1) - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (pos > 0 && pos < (__ref->cursor + 2) && __ref->cursor < dataset_size) { // excution restrict
        if ((((__ref->cursor + 1) - pos) & 7) != 0) { // ((ref->cursor + 1) - pos) % 8 != 0
            for (register int i = __ref->cursor; i > multiple_eight + pos - 1; i--) {
                __ref->dataset[i] = __ref->dataset[i-1]; 
            }
        }
        
        // ((ref->cursor + 1) - pos) % 8 == 0, (8 by one) loop
        for (register int i = multiple_eight + pos - 1; (i - 7) > (pos - 1); i -= 8) {
            __ref->dataset[i]   = __ref->dataset[i-1];
            __ref->dataset[i-1] = __ref->dataset[i-2];    
            __ref->dataset[i-2] = __ref->dataset[i-3];
            __ref->dataset[i-3] = __ref->dataset[i-4];
            __ref->dataset[i-4] = __ref->dataset[i-5];
            __ref->dataset[i-5] = __ref->dataset[i-6];
            __ref->dataset[i-6] = __ref->dataset[i-7];
            __ref->dataset[i-7] = __ref->dataset[i-8];
        }
        
        __ref->dataset[pos-1] = number;
        __ref->cursor++;
    } else {
        puts("out of bound!");
    }
}

//--------------------------
// erase_st() implementation
void erase_st(int pos) { // function name + "_st" (mean: for struct)
    int quotient = (__ref->cursor - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8

    if (pos > 0 && pos <= __ref->cursor) { // excution restrict
        if ((__ref->cursor - pos) >= 8) { // moving data >= 8, (8 by one) loop
            for (register int i = pos - 1; (i + 7) < __ref->cursor; i += 8) {
                __ref->dataset[i]   = __ref->dataset[i+1];
                __ref->dataset[i+1] = __ref->dataset[i+2];  
                __ref->dataset[i+2] = __ref->dataset[i+3];
                __ref->dataset[i+3] = __ref->dataset[i+4];
                __ref->dataset[i+4] = __ref->dataset[i+5];
                __ref->dataset[i+5] = __ref->dataset[i+6];
                __ref->dataset[i+6] = __ref->dataset[i+7];
                __ref->dataset[i+7] = __ref->dataset[i+8];
            }
        }
        
        // the rest of (8 by one) loop
        for (register int i = (pos - 1) + multiple_eight; i < __ref->cursor - 1; i++) {
            __ref->dataset[i] = __ref->dataset[i+1];
        }
        
        __ref->dataset[__ref->cursor - 1] = 0;
        __ref->cursor--;
    } else {
        puts("out of bound!");
    }
}

//---------------------------
// assign_st() implementation
void assign_st(int range, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);
    int rest = 0;

    if (range > 0 && range <= dataset_size) { // excution restrict
        if (range >= 8) { // range >=8, (8 by one) loop
            for (register int i = 0; (i + 7) < range; i += 8) {
                __ref->dataset[i]   = number;
                __ref->dataset[i+1] = number;  
                __ref->dataset[i+2] = number;
                __ref->dataset[i+3] = number;
                __ref->dataset[i+4] = number;
                __ref->dataset[i+5] = number;
                __ref->dataset[i+6] = number;
                __ref->dataset[i+7] = number;
                rest = i + 8;
            }
        }   

        // the rest of (8 by one) loop
        for (register int i = rest; i < range; i++) {
            __ref->dataset[i] = number;
        }
    } else {
        puts("out of bound!");
    }
    
    if (__ref->cursor < range) { __ref->cursor = range; }
}

//-------------------------
// swap_st() implementation
void swap_st(int pos1, int pos2) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);
    int temp;

    if (pos1 <= 0 || __ref->cursor < pos1 || pos2 <= 0 || __ref->cursor < pos2) {
        printf("out of bound!");
    } else if (pos1 == pos2) {
    } else {
        temp = __ref->dataset[pos1-1];
        __ref->dataset[pos1-1] = __ref->dataset[pos2-1]; 
        __ref->dataset[pos2-1] = temp;     
    }
}
    
//--------------------------
// front_st() implementation
void front_st() { // function name + "_st" (mean: for struct)
    if (__ref->cursor == 0) { printf("empty"); }
    else { printf("%d", __ref->dataset[0]); }
}

//-------------------------
// back_st() implementation
void back_st() { // function name + "_st" (mean: for struct)
    if (__ref->cursor == 0) { printf("empty"); }
    else { printf("%d", __ref->dataset[__ref->cursor - 1]); }    
}

//-----------------------
// at_st() implementation
void at_st(int pos) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);

    if (pos > 0 && pos <= __ref->cursor) { printf("%d", __ref->dataset[pos-1]); }
    else { printf("out of bound!"); }
}

//--------------------------
// print_st() implementation
void print_st() { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(__ref->dataset) / sizeof(__ref->dataset[0]);

    for (register int i = 0; i < dataset_size; i++) {
        printf(": %d ", __ref->dataset[i]); 
    }
    
    printf(":");
}

//-----------------------------
// capacity_st() implementation
void capacity_st() { // function name + "_st" (mean: for struct)
    printf("%ld", sizeof(__ref->dataset) / sizeof(__ref->dataset[0]));
}

//-------------------------
// size_st() implementation
void size_st() { // function name + "_st" (mean: for struct)
    printf("%d", __ref->cursor);
}

//-------------------------
// rest_st() implementation
void rest_st() { // function name + "_st" (mean: for struct)
    printf("%ld", (sizeof(__ref->dataset) / sizeof(__ref->dataset[0])) - __ref->cursor);
}

//--------------------------
// empty_st() implementation    
int empty_st() { // function name + "_st" (mean: for struct)
    return __ref->cursor ? 0 : 1;    
}
//-------------------------------------------------------------------------------
