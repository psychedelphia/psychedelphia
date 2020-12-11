//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// ascii encoding, decoding                                    //
//-------------------------------------------------------------//

#include <stdio.h>

#define BUFFER_SIZE 20

// Data Types(often used) -------------------------------------------------------
typedef unsigned char           uchar;
typedef int                     int32;
typedef unsigned int           uint32;
typedef long int                int64;
typedef unsigned long int      uint64;
//-------------------------------------------------------------------------------

// Global variable Here! --------------------------------------------------------
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
void show_binary(int32 value); // ascii to binary
void show_char(char text[]); // print buffer(char)
void show_int32(int32 encoded[]); // print buffer(integer)
void encoding_ascii(int32 encoded[], char text[]); // encoding string to ascii code
void decoding_ascii(char decoded[], int32 encoded[]); // decoding ascii code to string
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation
int32 main(void) {
    char text[BUFFER_SIZE] = { 'a', '0', 'b', 'c', 'd', 'e', '\t' };
    int32 encoded[BUFFER_SIZE] = { 0 };
    char decoded[BUFFER_SIZE] = { 0 };
 
    printf("text: "); /* << */ show_char(text); /* << */ puts("");
    puts("");
    
    encoding_ascii(encoded, text); /* << */ puts("");    
    
    printf("ascii: "); /* << */ show_int32(encoded); /* << */ puts("");
    puts("");    

    decoding_ascii(decoded, encoded); /* << */ puts("");

    printf("decoded: "); /* << */ show_char(decoded); /* << */ puts("");

    return 0; 
}

//---------------------------
// show_char() implementation
void show_char(char text[]) {
    for (register int32 i = 0; i < BUFFER_SIZE; i++) {
        printf(":%c", text[i]);
    }
    printf(":");
}

//----------------------------
// show_int32() implementation
void show_int32(int32 encoded[]) {
    for (register int32 i = 0; i < BUFFER_SIZE; i++) {
        printf(":%d", encoded[i]);
    }
    printf(":");
}

//--------------------------------
// encoding_ascii() implementation 
void encoding_ascii(int32 encoded[], char text[]) {
    int32 null_text = BUFFER_SIZE;
    
    for (register int32 i = 0; i < null_text; i++) {
        encoded[i] = (int32)text[i];
        printf("enconding: %c: %3d: ", text[i], encoded[i]); /* << */ show_binary(text[i]); /* << */ puts("");

        if (text[i] == '\0') { null_text = i; }
    }
}

//--------------------------------
// decoding_ascii() implementation
void decoding_ascii(char decoded[], int32 encoded[]) {
    int32 null_text = BUFFER_SIZE;
    
    for (register int32 i = 0; i < null_text; i++) {
        decoded[i] = (char)encoded[i];
        printf("deconding: %3d: %c", encoded[i], decoded[i]); /* << */ puts("");

        if (encoded[i] == 0) { null_text = i; }
    }
}

//-----------------------------
// show_binary() implementation 
void show_binary(int32 value) {
    const int32 MAX_BIT = 8;
    int32 mask = 128; // 00000000 00000000 00000000 10000000
    
    if (value >= 0 & value <= 128) { // execution
        for (register int32 i = MAX_BIT; i > 0; i--) {
            printf("%d", (value & mask) ? 1 : 0);
            mask = mask >> 1;
        }
    } else { // exception
        printf("It is not Ascii Code!");
    }
}
