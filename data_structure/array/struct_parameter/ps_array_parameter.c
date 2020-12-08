//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array                                     //
//-------------------------------------------------------------//

#include <stdio.h>
#include "array.h"

// functions with struct arraylist(Array) -----------------------------------
//-------------------------
// init_st() implementation
void init_st(Array * s) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);
    int rest = 0;
    
    if (dataset_size >= 8) { // array >= 8 (in certain circumstances, it's more efficient than (one by one) loop)
        for (register int i = 0; (i + 7) < dataset_size; i += 8) {
            s->dataset[i]   = 0;
            s->dataset[i+1] = 0;  
            s->dataset[i+2] = 0;
            s->dataset[i+3] = 0;
            s->dataset[i+4] = 0;
            s->dataset[i+5] = 0;
            s->dataset[i+6] = 0;
            s->dataset[i+7] = 0;
            rest = i + 8;
        }
    }

    // the rest of (8 by one) loop
    for (register int i = rest; i < dataset_size; i++) { 
        s->dataset[i] = 0; 
    }
    
    s->cursor = 0;
}

//-------------------------------
// push_front_st() implementation
void push_front_st(Array * s, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);
    int quotient = s->cursor / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (s->cursor >= 0 && s->cursor < dataset_size) { // excution restrict
        if (s->cursor) { // some data in array list
            if ((s->cursor & 7) != 0) { // ref->cursor % 8 != 0
                for (register int i = s->cursor; i > multiple_eight; i--) {
                    s->dataset[i] = s->dataset[i-1]; 
                }
            }
            
            // ref->cursor % 8 == 0, (8 by one) loop
            for (register int i = multiple_eight; (i - 7) > 0; i -= 8) {
                s->dataset[i]   = s->dataset[i-1];
                s->dataset[i-1] = s->dataset[i-2];    
                s->dataset[i-2] = s->dataset[i-3];
                s->dataset[i-3] = s->dataset[i-4];
                s->dataset[i-4] = s->dataset[i-5];
                s->dataset[i-5] = s->dataset[i-6];
                s->dataset[i-6] = s->dataset[i-7];
                s->dataset[i-7] = s->dataset[i-8];
            }
        }

        s->dataset[0] = number;
        s->cursor++;
    } else {
        printf("out of bound!");
    }
}

//------------------------------
// push_back_st() implementation
void push_back_st(Array * s, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);
 
    // input data into dataset array
    if (s->cursor >= 0 && s->cursor < dataset_size) { // excution restrict
        s->dataset[s->cursor] = number;
        s->cursor++;
    } else {
        printf("out of bound!");
    }
}

//---------------------------
// insert_st() implementation 
void insert_st(Array * s, int pos, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);
    int quotient = ((s->cursor + 1) - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8
    
    if (pos > 0 && pos < (s->cursor + 2) && s->cursor < dataset_size) { // excution restrict
        if ((((s->cursor + 1) - pos) & 7) != 0) { // ((ref->cursor + 1) - pos) % 8 != 0
            for (register int i = s->cursor; i > multiple_eight + pos - 1; i--) {
                s->dataset[i] = s->dataset[i-1]; 
            }
        }
        
        // ((ref->cursor + 1) - pos) % 8 == 0, (8 by one) loop
        for (register int i = multiple_eight + pos - 1; (i - 7) > (pos - 1); i -= 8) {
            s->dataset[i]   = s->dataset[i-1];
            s->dataset[i-1] = s->dataset[i-2];    
            s->dataset[i-2] = s->dataset[i-3];
            s->dataset[i-3] = s->dataset[i-4];
            s->dataset[i-4] = s->dataset[i-5];
            s->dataset[i-5] = s->dataset[i-6];
            s->dataset[i-6] = s->dataset[i-7];
            s->dataset[i-7] = s->dataset[i-8];
        }
        
        s->dataset[pos-1] = number;
        s->cursor++;
    } else {
        printf("out of bound!");
    }
}

//--------------------------
// erase_st() implementation
void erase_st(Array * s, int pos) { // function name + "_st" (mean: for struct)
    int quotient = (s->cursor - pos) / 8;
    int multiple_eight = quotient * 8; // multiple of 8

    if (pos > 0 && pos <= s->cursor) { // excution restrict
        if ((s->cursor - pos) >= 8) { // moving data >= 8, (8 by one) loop
            for (register int i = pos - 1; (i + 7) < s->cursor; i += 8) {
                s->dataset[i]   = s->dataset[i+1];
                s->dataset[i+1] = s->dataset[i+2];  
                s->dataset[i+2] = s->dataset[i+3];
                s->dataset[i+3] = s->dataset[i+4];
                s->dataset[i+4] = s->dataset[i+5];
                s->dataset[i+5] = s->dataset[i+6];
                s->dataset[i+6] = s->dataset[i+7];
                s->dataset[i+7] = s->dataset[i+8];
            }
        }
        
        // the rest of (8 by one) loop
        for (register int i = (pos - 1) + multiple_eight; i < s->cursor - 1; i++) {
            s->dataset[i] = s->dataset[i+1];
        }
        
        s->dataset[s->cursor - 1] = 0;
        s->cursor--;
    } else {
        printf("out of bound!");
    }
}

//---------------------------
// assign_st() implementation
void assign_st(Array * s, int range, int number) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);
    int rest = 0;

    if (range > 0 && range <= dataset_size) { // excution restrict
        if (range >= 8) { // range >=8, (8 by one) loop
            for (register int i = 0; (i + 7) < range; i += 8) {
                s->dataset[i]   = number;
                s->dataset[i+1] = number;  
                s->dataset[i+2] = number;
                s->dataset[i+3] = number;
                s->dataset[i+4] = number;
                s->dataset[i+5] = number;
                s->dataset[i+6] = number;
                s->dataset[i+7] = number;
                rest = i + 8;
            }
        }   

        // the rest of (8 by one) loop
        for (register int i = rest; i < range; i++) {
            s->dataset[i] = number;
        }
    } else {
        printf("out of bound!");
    }
    
    if (s->cursor < range) { s->cursor = range; }
}

//-------------------------
// swap_st() implementation
void swap_st(Array * s, int pos1, int pos2) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);
    int temp;

    if (pos1 <= 0 || s->cursor < pos1 || pos2 <= 0 || s->cursor < pos2) {
        printf("out of bound!");
    } else if (pos1 == pos2) {
    } else {
        temp = s->dataset[pos1-1];
        s->dataset[pos1-1] = s->dataset[pos2-1]; 
        s->dataset[pos2-1] = temp;     
    }
}
    
//--------------------------
// front_st() implementation
void front_st(Array * s) { // function name + "_st" (mean: for struct)
    if (s->cursor == 0) { printf("empty"); }
    else { printf("%d", s->dataset[0]); }
}

//-------------------------
// back_st() implementation
void back_st(Array * s) { // function name + "_st" (mean: for struct)
    if (s->cursor == 0) { printf("empty"); }
    else { printf("%d", s->dataset[s->cursor - 1]); }    
}

//-----------------------
// at_st() implementation
void at_st(Array * s, int pos) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);

    if (pos > 0 && pos <= s->cursor) { printf("%d", s->dataset[pos-1]); }
    else { printf("out of bound!"); }
}

//--------------------------
// print_st() implementation
void print_st(Array * s) { // function name + "_st" (mean: for struct)
    long int dataset_size = sizeof(s->dataset) / sizeof(s->dataset[0]);

    for (register int i = 0; i < dataset_size; i++) {
        printf(": %d ", s->dataset[i]); 
    }
    
    printf(":");
}

//-----------------------------
// capacity_st() implementation
void capacity_st(Array * s) { // function name + "_st" (mean: for struct)
    printf("%ld", sizeof(s->dataset) / sizeof(s->dataset[0]));
}

//-------------------------
// size_st() implementation
void size_st(Array * s) { // function name + "_st" (mean: for struct)
    printf("%d", s->cursor);
}

//-------------------------
// rest_st() implementation
void rest_st(Array * s) { // function name + "_st" (mean: for struct)
    printf("%ld", (sizeof(s->dataset) / sizeof(s->dataset[0])) - s->cursor);
}

//--------------------------
// empty_st() implementation    
int empty_st(Array * s) { // function name + "_st" (mean: for struct)
    return s->cursor ? 0 : 1;    
}
//-------------------------------------------------------------------------------
