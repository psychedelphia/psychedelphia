#include <stdio.h>

// minimize useage of (/ → * → - → +) operator and floating-point
// New Function Here! -------------------------------------------
void precision(int value, double number); // double precision
// --------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    double x = 1.123456789012345;
    double y = 12345.1234567890152;
     
    printf("x  = "); /* << */ precision(-1, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 0, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 1, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 2, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 3, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 4, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 5, x); /* << */ puts("");
    printf("x  = %lf\n",  x);
    printf("x  = "); /* << */ precision( 7, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 8, x); /* << */ puts("");
    printf("x  = "); /* << */ precision( 9, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(10, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(11, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(12, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(13, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(14, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(15, x); /* << */ puts("");
    printf("x  = "); /* << */ precision(16, x); /* << */ puts("");

    printf("-----\n");

    for (register int i = -1; i < 16; i++) {
        printf("y  = "); /* << */ precision(i, y); /* << */ puts("");
    }

    return 0; 
}

//-------------------------
// precision implementation
void precision(int value, double number) {
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
