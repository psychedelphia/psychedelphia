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

extern ArrayList * ref; // using pointer "ref" from arraylist.h

// functions with struct arraylist(ArrayList) -----------------------------------
//-------------------------
// init_st() implementation
void init_st() { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);
    int rest = 0;
    
    if (dataset_size >= 8) { // array list >= 8 (it's more efficient than (one by one) loop)
        for (register int i = 0; (i + 7) < dataset_size; i += 8) {
            ref->dataset[i]   = 0;
            ref->dataset[i+1] = 0;  
            ref->dataset[i+2] = 0;
            ref->dataset[i+3] = 0;
            ref->dataset[i+4] = 0;
            ref->dataset[i+5] = 0;
            ref->dataset[i+6] = 0;
            ref->dataset[i+7] = 0;
            rest = i + 8;
        }
    }

    // the rest of (8 by one) loop
    for (register int i = rest; i < dataset_size; i++) { 
        ref->dataset[i] = 0; 
    }
    
    ref->cursor = 0;
}

//-------------------------------
// push_front_st() implementation
void push_front_st(int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);
    int quotient = ref->cursor / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (ref->cursor >= 0 && ref->cursor < dataset_size) { // excution restrict
        if (ref->cursor) { // some data in array list
            if ((ref->cursor & 7) != 0) { // ref->cursor % 8 != 0
                for (register int i = ref->cursor; i > multiple_eight; i--) {
                    ref->dataset[i] = ref->dataset[i-1]; 
                }
            }
            
            // ref->cursor % 8 == 0, (8 by one) loop
            for (register int i = multiple_eight; (i - 7) > 0; i -= 8) {
                ref->dataset[i]   = ref->dataset[i-1];
                ref->dataset[i-1] = ref->dataset[i-2];    
                ref->dataset[i-2] = ref->dataset[i-3];
                ref->dataset[i-3] = ref->dataset[i-4];
                ref->dataset[i-4] = ref->dataset[i-5];
                ref->dataset[i-5] = ref->dataset[i-6];
                ref->dataset[i-6] = ref->dataset[i-7];
                ref->dataset[i-7] = ref->dataset[i-8];
            }
        }

        ref->dataset[0] = number;
        ref->cursor++;
    } else {
        puts("out of bound!");
    }
}

//------------------------------
// push_back_st() implementation
void push_back_st(int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);
 
    // input data into dataset array
    if (ref->cursor >= 0 && ref->cursor < dataset_size) { // excution restrict
        ref->dataset[ref->cursor] = number;
        ref->cursor++;
    } else {
        puts("out of bound!");
    }
}

//---------------------------
// insert_st() implementation 
void insert_st(int pos, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);
    int quotient = ((ref->cursor + 1) - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (pos > 0 && pos < (ref->cursor + 2) && ref->cursor < dataset_size) { // excution restrict
        if ((((ref->cursor + 1) - pos) & 7) != 0) { // ((ref->cursor + 1) - pos) % 8 != 0
            for (register int i = ref->cursor; i > multiple_eight + pos - 1; i--) {
                ref->dataset[i] = ref->dataset[i-1]; 
            }
        }
        
        // ((ref->cursor + 1) - pos) % 8 == 0, (8 by one) loop
        for (register int i = multiple_eight + pos - 1; (i - 7) > (pos - 1); i -= 8) {
            ref->dataset[i]   = ref->dataset[i-1];
            ref->dataset[i-1] = ref->dataset[i-2];    
            ref->dataset[i-2] = ref->dataset[i-3];
            ref->dataset[i-3] = ref->dataset[i-4];
            ref->dataset[i-4] = ref->dataset[i-5];
            ref->dataset[i-5] = ref->dataset[i-6];
            ref->dataset[i-6] = ref->dataset[i-7];
            ref->dataset[i-7] = ref->dataset[i-8];
        }
        
        ref->dataset[pos-1] = number;
        ref->cursor++;
    } else {
        puts("out of bound!");
    }
}

//--------------------------
// erase_st() implementation
void erase_st(int pos) { // function name + "_st" (mean: for struct)
    int quotient = (ref->cursor - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8

    if (pos > 0 && pos <= ref->cursor) { // excution restrict
        if ((ref->cursor - pos) >= 8) { // moving data >= 8, (8 by one) loop
            for (register int i = pos - 1; (i + 7) < ref->cursor; i += 8) {
                ref->dataset[i]   = ref->dataset[i+1];
                ref->dataset[i+1] = ref->dataset[i+2];  
                ref->dataset[i+2] = ref->dataset[i+3];
                ref->dataset[i+3] = ref->dataset[i+4];
                ref->dataset[i+4] = ref->dataset[i+5];
                ref->dataset[i+5] = ref->dataset[i+6];
                ref->dataset[i+6] = ref->dataset[i+7];
                ref->dataset[i+7] = ref->dataset[i+8];
            }
        }
        
        // the rest of (8 by one) loop
        for (register int i = (pos - 1) + multiple_eight; i < ref->cursor - 1; i++) {
            ref->dataset[i] = ref->dataset[i+1];
        }
        
        ref->dataset[ref->cursor - 1] = 0;
        ref->cursor--;
    } else {
        puts("out of bound!");
    }
}

//---------------------------
// assign_st() implementation
void assign_st(int range, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);
    int rest = 0;

    if (range > 0 && range <= dataset_size) { // excution restrict
        if (range >= 8) { // range >=8, (8 by one) loop
            for (register int i = 0; (i + 7) < range; i += 8) {
                ref->dataset[i]   = number;
                ref->dataset[i+1] = number;  
                ref->dataset[i+2] = number;
                ref->dataset[i+3] = number;
                ref->dataset[i+4] = number;
                ref->dataset[i+5] = number;
                ref->dataset[i+6] = number;
                ref->dataset[i+7] = number;
                rest = i + 8;
            }
        }   

        // the rest of (8 by one) loop
        for (register int i = rest; i < range; i++) {
            ref->dataset[i] = number;
        }
    } else {
        puts("out of bound!");
    }
    
    if (ref->cursor < range) { ref->cursor = range; }
}

//-------------------------
// swap_st() implementation
void swap_st(int pos1, int pos2) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);

    if (pos1 <= 0 || ref->cursor < pos1 || pos2 <= 0 || ref->cursor < pos2) {
        printf("out of bound!");
    } else if (pos1 == pos2) {
    } else {
        ref->dataset[pos1-1] = ref->dataset[pos1-1] ^ ref->dataset[pos2-1]; 
        ref->dataset[pos2-1] = ref->dataset[pos2-1] ^ ref->dataset[pos1-1]; 
        ref->dataset[pos1-1] = ref->dataset[pos1-1] ^ ref->dataset[pos2-1];     
    }
}
    
//--------------------------
// front_st() implementation
void front_st() { // function name + "_st" (mean: for struct)
    if (ref->cursor == 0) { printf("empty"); }
    else { printf("%d", ref->dataset[0]); }
}

//-------------------------
// back_st() implementation
void back_st() { // function name + "_st" (mean: for struct)
    if (ref->cursor == 0) { printf("empty"); }
    else { printf("%d", ref->dataset[ref->cursor - 1]); }    
}

//-----------------------
// at_st() implementation
void at_st(int pos) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);

    if (pos > 0 && pos <= ref->cursor) { printf("%d", ref->dataset[pos-1]); }
    else { printf("out of bound!"); }
}

//--------------------------
// print_st() implementation
void print_st() { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(ref->dataset) / sizeof(ref->dataset[0]);

    for (register int i = 0; i < dataset_size; i++) {
        printf(": %d ", ref->dataset[i]); 
    }
    
    printf(":");
}

//-----------------------------
// capacity_st() implementation
void capacity_st() { // function name + "_st" (mean: for struct)
    printf("%ld", sizeof(ref->dataset) / sizeof(ref->dataset[0]));
}

//-------------------------
// size_st() implementation
void size_st() { // function name + "_st" (mean: for struct)
    printf("%d", ref->cursor);
}

//-------------------------
// rest_st() implementation
void rest_st() { // function name + "_st" (mean: for struct)
    printf("%ld", (sizeof(ref->dataset) / sizeof(ref->dataset[0])) - ref->cursor);
}

//--------------------------
// empty_st() implementation    
int empty_st() { // function name + "_st" (mean: for struct)
    return ref->cursor ? 0 : 1;    
}
//-------------------------------------------------------------------------------
