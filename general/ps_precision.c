//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// Precision for double data typesdouble                       //
//-------------------------------------------------------------//

#include <stdio.h>

// minimize usage of (/ → * → - → +) operator and floating-point
// New Function Here! -------------------------------------------
void precision(double number, int value); // double precision
// --------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    double x = 1.123456789012345;
    double y = 12345.1234567890152;
     
    printf("x  = "); /* << */ precision(x, -1); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  0); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  1); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  2); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  3); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  4); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  5); /* << */ puts("");
    printf("x  = %lf\n",  x);
    printf("x  = "); /* << */ precision(x,  7); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  8); /* << */ puts("");
    printf("x  = "); /* << */ precision(x,  9); /* << */ puts("");
    printf("x  = "); /* << */ precision(x, 10); /* << */ puts("");
    printf("x  = "); /* << */ precision(x, 11); /* << */ puts("");
    printf("x  = "); /* << */ precision(x, 12); /* << */ puts("");
    printf("x  = "); /* << */ precision(x, 13); /* << */ puts("");
    printf("x  = "); /* << */ precision(x, 14); /* << */ puts("");
    printf("x  = "); /* << */ precision(x, 15); /* << */ puts("");

    printf("-----\n");

    for (register int i = -1; i < 16; i++) {
        printf("y  = "); /* << */ precision(y, i); /* << */ puts("");
    }

    return 0; 
}

//-------------------------
// precision implementation
void precision(double number, int value) {
    switch (value) {
        case  1 : printf("%.1lf",  number); /* \n */ break;
        case  2 : printf("%.2lf",  number); /* \n */ break;
        case  3 : printf("%.3lf",  number); /* \n */ break;
        case  4 : printf("%.4lf",  number); /* \n */ break;
        case  5 : printf("%.5lf",  number); /* \n */ break;
        case  7 : printf("%.7lf",  number); /* \n */ break;
        case  8 : printf("%.8lf",  number); /* \n */ break;
        case  9 : printf("%.9lf",  number); /* \n */ break;
        case 10 : printf("%.10lf", number); /* \n */ break;
        case 11 : printf("%.11lf", number); /* \n */ break;
        case 12 : printf("%.12lf", number); /* \n */ break;
        case 13 : printf("%.13lf", number); /* \n */ break;
        case 14 : printf("%.14lf", number); /* \n */ break;
        case 15 : printf("%.15lf", number); /* \n */ break;                  
        default : printf("%.6lf",  number); /* \n */ break;
    }
}
