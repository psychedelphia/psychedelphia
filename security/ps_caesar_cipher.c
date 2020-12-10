//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Caesar Cipher (substitution cipher)       //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 23

// Data Types(often used) -------------------------------------------------------
typedef unsigned char           uchar;
typedef int                     int32;
typedef unsigned int           uint32;
typedef long int                int64;
typedef unsigned long int      uint64;
//-------------------------------------------------------------------------------

// Global variable Here! --------------------------------------------------------
                           // 0    1    2    3    4    5    6    7    8    9   10   11   12  
static char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                           //13   14   15   16   17   18   19   20   21   22   23   24   25     
                             'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
//-------------------------------------------------------------------------------

// New Function Here! -----------------------------------------------------------
void show_text(int32 * text); // print contents

int32 caesar_cipher(int32 x, int32 key); // perform caesar cipher(substitution cipher)
int32 * encrypt(int32 * encrypted, int32 * plaintext, int32 key); // encryption
int32 * decrypt(int32 * decrypted, int32 * encrypted, int32 key); // decryption
//-------------------------------------------------------------------------------

// minimize usage of (/ → * → - → +) operator and floating-point
//----------------------
// main() implementation 
int32_t main(void) {
                                    // ITISNOTALWAYSWHATYOUSEE
    int32 plaintext[BUFFER_SIZE] = { 8, 19, 8, 18, 13, 14, 19, 0, 11, 22, 0, 24, 18, 22, 7, 0, 19, 24, 14, 20, 18, 4, 4};
    int32 encrypted[BUFFER_SIZE] = { 0 };
    int32 decrypted[BUFFER_SIZE] = { 0 };    
    int32 en_key = 3;  // 1 <= key <= 25
    int32 de_key = en_key * (-1);
    
    printf("plaintext: "); /* << */ show_text(plaintext); /* << */ puts("");
    
    encrypt(encrypted, plaintext, en_key);
    
    printf("encrypted: "); /* << */ show_text(encrypted); /* << */ puts("");
    
    decrypt(decrypted, encrypted, de_key);
    
    printf("decrypted: "); /* << */ show_text(decrypted); /* << */ puts("");
    
    return 0; 
}

//---------------------------
// show_text() implementation 
void show_text(int32 * text) {
    for (register int32 i = 0; i < BUFFER_SIZE; i++) {
        printf("%c", alphabet[*(text + i)]);
        fflush(stdout);
        usleep(100000);
    }
}

//-------------------------
// encrypt() implementation 
int32 * encrypt(int32 * encrypted, int32 * plaintext, int32 key) {
    if (key < 26 && key > 0) { // execution
        for (register int32 i = 0; i < BUFFER_SIZE; i++)
            encrypted[i] = caesar_cipher(*(plaintext + i), key);
    } else { // exception
        printf("invalid key!");
    }
    
    return encrypted;
}

//-------------------------
// decrypt() implementation 
int32 * decrypt(int32 * decrypted, int32 * encrypted, int32 key) {
    if (key > -26 && key < 0) { // execution
        for (register int32 i = 0; i < BUFFER_SIZE; i++)
            decrypted[i] = caesar_cipher(*(encrypted + i), key);
    } else { // exception
        printf("invalid key!");
    }

    return decrypted;
}

//-------------------------------
// caesar_cipher() implementation 
int32 caesar_cipher(int32 x, int32 key) {
    int32 result = 0;

    if (key > -26 && key < 26 && key != 0) { // execution
        result = x + key;
        
        // result mod 26
        if (result > 25) result -= 26; 
        if (result < 0)  result += 26;
    } else { // exception
        printf("invalid key!");
    }
    
    return result;
}
