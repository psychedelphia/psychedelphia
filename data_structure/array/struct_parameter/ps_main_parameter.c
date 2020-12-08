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
    Array a = { { 0 }, 0, 
                init_st,     push_front_st, push_back_st, 
                insert_st,   erase_st,      assign_st, 
                swap_st,     front_st,      back_st,     
                at_st,       print_st,      capacity_st, 
                size_st,     rest_st,       empty_st,
              };  // initializing(constructor)
              
    // example
    printf("capacity: "); /* << */ a.capacity(&a); /* << */ puts("");  
    a.print(&a); /* << */ puts("");
    printf("insert data\n");
    a.push_front(&a, 1);
    a.print(&a); /* << */ puts("");
    printf("insert data\n");
    a.push_front(&a, 2);
    a.print(&a); /* << */ puts("");

    printf("insert data\n");    
    a.push_back(&a, 3);
    a.print(&a); /* << */ puts("");
    printf("insert data\n");
    a.push_back(&a, 4);
    a.print(&a); /* << */ puts("");    
    printf("first data: "); /* << */ a.front(&a); /* << */ puts("");
    printf("last data: "); /* << */ a.back(&a); /* << */ puts("");
    
    printf("value of data[2]: "); /* << */ a.at(&a, 2); /* << */ puts("");
    printf("value of data[3]: "); /* << */ a.at(&a, 3); /* << */ puts("");

    printf("swap data\n");
    a.swap(&a, 1, 4);    
    a.print(&a); /* << */ puts("");
    printf("swap data\n");    
    a.swap(&a, 2, 3);    
    a.print(&a); /* << */ puts("");

    printf("assign data\n");
    a.assign(&a, 5, 3);
    a.print(&a); /* << */ puts("");

    printf("insert data\n");
    a.insert(&a, 4, 4);
    a.print(&a); /* << */ puts("");
    printf("insert data\n");
    a.insert(&a, 5, 5);
    a.print(&a); /* << */ puts("");

    printf("erase data\n");
    a.erase(&a, 2);
    a.print(&a); /* << */ puts("");
    printf("erase data\n");
    a.erase(&a, 6);
    a.print(&a); /* << */ puts("");

    printf("rest of array: "); /* << */ a.rest(&a); /* << */ puts("");
    printf("size: "); /* << */ a.size(&a); /* << */ puts("");
    
    if (a.empty(&a)) { printf("array is empty\n"); }
    else { printf("array is not empty\n"); }
    
    printf("initializing\n");
    a.init(&a);
    printf("size: "); /* << */ a.size(&a); /* << */ puts("");
    if (a.empty(&a)) { printf("array is empty\n"); }
    else { printf("array is not empty\n"); }    
    
    return 0; 
}
