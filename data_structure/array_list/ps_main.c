//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array List                                //
//-------------------------------------------------------------//

#include <stdio.h>
#include "arraylist.h"

// minimize usage of (/ → * → - → +) operator and floating-point

//----------------------
// main() implementation 
int main(void) {
    ArrayList a = { { 0 }, 0, 
                    init_st,     push_front_st, push_back_st, 
                    insert_st,   erase_st,      assign_st, 
                    swap_st,     front_st,      back_st,     
                    at_st,       print_st,      capacity_st, 
                    size_st,     rest_st,       empty_st,
                  };  // initializing(constructor)
__arraylist_ptr = &a; // for ArrayList functions(must)
    
    // example
    printf("capacity: "); /* << */ a.capacity(); /* << */ puts("");  
    a.print(); /* << */ puts("");
    printf("insert data\n");
    a.push_front(1);
    a.print(); /* << */ puts("");
    printf("insert data\n");
    a.push_front(2);
    a.print(); /* << */ puts("");

    printf("insert data\n");    
    a.push_back(3);
    a.print(); /* << */ puts("");
    printf("insert data\n");
    a.push_back(4);
    a.print(); /* << */ puts("");    
    printf("first data: "); /* << */ a.front(); /* << */ puts("");
    printf("last data: "); /* << */ a.back(); /* << */ puts("");
    
    printf("value of data[2]: "); /* << */ a.at(2); /* << */ puts("");
    printf("value of data[3]: "); /* << */ a.at(3); /* << */ puts("");

    printf("swap data\n");
    a.swap(1, 4);    
    a.print(); /* << */ puts("");
    printf("swap data\n");    
    a.swap(2, 3);    
    a.print(); /* << */ puts("");

    printf("assign data\n");
    a.assign(5, 3);
    a.print(); /* << */ puts("");

    printf("insert data\n");
    a.insert(4, 4);
    a.print(); /* << */ puts("");
    printf("insert data\n");
    a.insert(5, 5);
    a.print(); /* << */ puts("");

    printf("erase data\n");
    a.erase(2);
    a.print(); /* << */ puts("");
    printf("erase data\n");
    a.erase(6);
    a.print(); /* << */ puts("");

    printf("rest of array list: "); /* << */ a.rest(); /* << */ puts("");
    printf("size: "); /* << */ a.size(); /* << */ puts("");
    
    if (a.empty()) { printf("array list is empty\n"); }
    else { printf("array list is not empty\n"); }
    
    printf("initializing\n");
    a.init();
    printf("size: "); /* << */ a.size(); /* << */ puts("");
    if (a.empty()) { printf("array list is empty\n"); }
    else { printf("array list is not empty\n"); }    
    
    return 0; 
}
