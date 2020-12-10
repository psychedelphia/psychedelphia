//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Caesar Cipher (substitution cipher)       //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 26
                             // 0    1    2    3    4    5    6    7    8    9   10   11   12  
static int8_t alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                             //13   14   15   16   17   18   19   20   21   22   23   24   25     
                               'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
// minimize usage of (/ → * → - → +) operator and floating-point
// New Function Here! -----------------------------------------------------------
void show_text(int32_t * text); // print contents
//-------------------------------------------------------------------------------
int32_t caesar_cipher(int32_t x, int32_t key); // perform caesar cipher(substitution cipher)
int32_t * encrypt(int32_t * encrypted, int32_t * plaintext, int32_t key); // encryption
int32_t * decrypt(int32_t * decrypted, int32_t * encrypted, int32_t key); // decryption
//-------------------------------------------------------------------------------

//----------------------
// main() implementation 
int32_t main(void) {
                                    // ITISNOTALWAYSWHATYOUSEE
    int32_t plaintext[BUFFER_SIZE] = { 8, 19, 8, 18, 13, 14, 19, 0, 11, 22, 0, 24, 18, 22, 7, 0, 19, 24, 14, 20, 18, 4, 4};
    int32_t encrypted[BUFFER_SIZE] = { 0 };
    int32_t decrypted[BUFFER_SIZE] = { 0 };    
    int32_t en_key = 3;  // 1 <= key <= 25
    int32_t de_key = en_key * (-1);
    
    printf("plaintext: "); /* << */ show_text(plaintext); /* << */ puts("");
    
    encrypt(encrypted, plaintext, en_key);
    
    printf("encrypted: "); /* << */ show_text(encrypted); /* << */ puts("");
    
    decrypt(decrypted, encrypted, de_key);
    
    printf("decrypted: "); /* << */ show_text(decrypted); /* << */ puts("");
    
    return 0; 
}

//---------------------------
// show_text() implementation 
void show_text(int32_t * text) {
    for (register int32_t i = 0; i < BUFFER_SIZE; i++) {
        printf("%c", alphabet[*(text + i)]);
        fflush(stdout);
        usleep(100000);
    }
}

//-------------------------
// encrypt() implementation 
int32_t * encrypt(int32_t * encrypted, int32_t * plaintext, int32_t key) {
    if (key > 25 || key == 0) { printf("invalid key!\n"); /* \n */ return encrypted; }

    for (register int32_t i = 0; i < BUFFER_SIZE; i++)
        encrypted[i] = caesar_cipher(*(plaintext + i), key);
    
    return encrypted;
}

//-------------------------
// decrypt() implementation 
int32_t * decrypt(int32_t * decrypted, int32_t * encrypted, int32_t key) {
    if (key < -25 || key == 0) { printf("invalid key!\n"); /* \n */ return decrypted; }

    for (register int32_t i = 0; i < BUFFER_SIZE; i++)
        decrypted[i] = caesar_cipher(*(encrypted + i), key);
    
    return decrypted;
}

//-------------------------------
// caesar_cipher() implementation 
int32_t caesar_cipher(int32_t x, int32_t key) {
    int32_t result = x + key;
    
    // result mod 26
    if (result > 25) result -= 26; 
    if (result < 0)  result += 26;
    
    return result;
}
