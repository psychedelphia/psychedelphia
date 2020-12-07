//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array                                     //
//-------------------------------------------------------------//
// global pointer is critical. use your own part.              // 
// don't let people use this pointer.                          //
//-------------------------------------------------------------//

#define BUFFER_SIZE 20

// minimize useage of (/ → * → - → +) operator and floating-point
// New Struct Here! -------------------------------------------------------------
typedef struct array{
    // struct variables Here!
    int dataset[BUFFER_SIZE];
    int cursor;
    
    // struct functions Here!
    void (* init)();
    void (* push_front)(int number);
    void (* push_back)(int number);
    void (* insert)(int pos, int number);
    void (* erase)(int pos);
    void (* assign)(int range, int number); 
    void (* swap)(int pos1, int pos2);
    void (* front)();
    void (* back)();
    void (* at)(int pos);
    void (* print)();
    void (* capacity)();
    void (* size)();
    void (* rest)();
    int (* empty)();    
} Array;

Array * __array_ptr; // All functions related to Array can use this pointer.

// Explanation of Functions ------------------------------------------------------------
void init_st(); // initializing memory (all data = 0)
void push_front_st(int number); // insert data in the front
void push_back_st(int number); // insert data in the back
void insert_st(int pos, int number); // insert data (placed in position)
void erase_st(int pos); // erase data (placed in position)
void assign_st(int range, int number); // insert data (range, 1 to range number)
void swap_st(int pos1, int pos2); // swap two data
void front_st(); // print first data
void back_st(); // print last data
void at_st(int pos); //print specific data (placed in poistion)
void print_st(); // print all in memory including the rest(the rest = 0)
void capacity_st(); // print total memory
void size_st(); // print the number of data(in use)
void rest_st(); // print the number of data(the reamining part)
int empty_st(); // return 1:true(empty) or 0:false(not empty)
