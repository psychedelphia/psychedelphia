//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Array                                     //
//-------------------------------------------------------------//

#define BUFFER_SIZE 20

// minimize useage of (/ → * → - → +) operator and floating-point
// New Struct Here! -------------------------------------------------------------
typedef struct array Array;
struct array{
    // struct variables Here!
    int dataset[BUFFER_SIZE];
    int cursor;
    
    // struct functions Here!
    void (* init)(Array * s);
    void (* push_front)(Array * s, int number);
    void (* push_back)(Array * s, int number);
    void (* insert)(Array * s, int pos, int number);
    void (* erase)(Array * s, int pos);
    void (* assign)(Array * s, int range, int number); 
    void (* swap)(Array * s, int pos1, int pos2);
    void (* front)(Array * s);
    void (* back)(Array * s);
    void (* at)(Array * s, int pos);
    void (* print)(Array * s);
    void (* capacity)(Array * s);
    void (* size)(Array * s);
    void (* rest)(Array * s);
    int (* empty)(Array * s);    
};

// Explanation of Functions ------------------------------------------------------------
void init_st(Array * s); // initializing memory (all data = 0)
void push_front_st(Array * s, int number); // insert data in the front
void push_back_st(Array * s, int number); // insert data in the back
void insert_st(Array * s, int pos, int number); // insert data (placed in position)
void erase_st(Array * s, int pos); // erase data (placed in position)
void assign_st(Array * s, int range, int number); // insert data (range, 1 to range number)
void swap_st(Array * s, int pos1, int pos2); // swap two data
void front_st(Array * s); // print first data
void back_st(Array * s); // print last data
void at_st(Array * s, int pos); //print specific data (placed in poistion)
void print_st(Array * s); // print all in memory including the rest(the rest = 0)
void capacity_st(Array * s); // print total memory
void size_st(Array * s); // print the number of data(in use)
void rest_st(Array * s); // print the number of data(the reamining part)
int empty_st(Array * s); // return 1:true(empty) or 0:false(not empty)
