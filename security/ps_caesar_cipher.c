//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Implementation of Caesar Cipher (substitution cipher)       //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
                           // 0    1    2    3    4    5    6    7    8    9   10   11   12  
static char alphabet[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
                           //13   14   15   16   17   18   19   20   21   22   23   24   25     
                             'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
// minimize useage of (/ → * → - → +) operator and floating-point
// New Function Here! -----------------------------------------------------------
void show_text(int * text); // print contents
//-------------------------------------------------------------------------------
int caesar_cipher(int x, int key); // perform caesar cipher(substitution cipher)
int * encrypt(int * encrypted, int * plaintext, int key); // encryption
int * decrypt(int * decrypted, int * encrypted, int key); // decryption
//-------------------------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
                                 // ITISNOTALWAYSWHATYOUSEE
    int plaintext[BUFFER_SIZE] = { 8, 19, 8, 18, 13, 14, 19, 0, 11, 22, 0, 24, 18, 22, 7, 0, 19, 24, 14, 20, 18, 4, 4};
    int encrypted[BUFFER_SIZE] = { 0 };
    int decrypted[BUFFER_SIZE] = { 0 };    
    int en_key = 3;  // 1 <= key <= 25
    int de_key = en_key * (-1);
    
    printf("plaintext: "); /* << */ show_text(plaintext); /* << */ puts("");
    
    encrypt(encrypted, plaintext, en_key);
    
    printf("encrypted: "); /* << */ show_text(encrypted); /* << */ puts("");
    
    decrypt(decrypted, encrypted, de_key);
    
    printf("decrypted: "); /* << */ show_text(decrypted); /* << */ puts("");
    
    return 0; 
}

//---------------------------
// show_text() implementation 
void show_text(int * text) {
    for (register int i = 0; i < BUFFER_SIZE; i++) {
        printf("%c", alphabet[*(text + i)]);
        fflush(stdout);
        usleep(100000);
    }
}

//-------------------------
// encrypt() implementation 
int * encrypt(int * encrypted, int * plaintext, int key) {
    if (key > 25 || key == 0) { printf("invalid key!\n"); /* \n */ return encrypted; }

    for (register int i = 0; i < BUFFER_SIZE; i++)
        encrypted[i] = caesar_cipher(*(plaintext + i), key);
    
    return encrypted;
}

//-------------------------
// decrypt() implementation 
int * decrypt(int * decrypted, int * encrypted, int key) {
    if (key < -25 || key == 0) { printf("invalid key!\n"); /* \n */ return decrypted; }

    for (register int i = 0; i < BUFFER_SIZE; i++)
        decrypted[i] = caesar_cipher(*(encrypted + i), key);
    
    return decrypted;
}

//-------------------------------
// caesar_cipher() implementation 
int caesar_cipher(int x, int key) {
    int result = x + key;
    
    // result mod 26
    if (result > 25) result -= 26; 
    if (result < 0)  result += 26;
    
    return result;
}
