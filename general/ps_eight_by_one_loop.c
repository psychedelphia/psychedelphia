//-------------------------------------------------------------//
// Forever a Student in C                                      //
// Psychedelphia: https://psychedelphia.wordpress.com/         //
//-------------------------------------------------------------//
// (eight by one loop) VS (one by one loop)                    //
//-------------------------------------------------------------//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// minimize usage of (/ → * → - → +) operator and floating-point
// New Function Here! -------------------------------------------
int eight_by_one(); // eight by one loop
int one_by_one(); // one by one loop
// --------------------------------------------------------------

//----------------------
// main() implementation 
int main(void) {
    clock_t start, stop;
    unsigned long int time1 = 0, time2 = 0;
    int result = 0;

    start = clock();
    result = eight_by_one();
    stop = clock();
    printf("result(eight by one): %d\n", result);

    time2 = stop - start;
    puts("In certain circumstances, it's pretty fast.");
    puts("------ eight by one loop ------");
    printf("start(clock ticks): %ld\n", start);
    printf("stop (clock ticks): %ld\n", stop);
    printf("stop - start: %ld\n", time2);
    printf("CPU TIME: %.9lfsec\n", (double)(time2) / CLOCKS_PER_SEC);

    start = clock();
    result = one_by_one();
    stop = clock();
    printf("result(one by one): %d\n", result);

    time1 = stop - start;
    puts("------ one by one loop ------");
    printf("start(clock ticks): %ld\n", start);
    printf("stop (clock ticks): %ld\n", stop);
    printf("stop - start: %ld\n", time1);
    printf("CPU TIME: %.9lfsec\n", (double)(time1) / CLOCKS_PER_SEC);
    puts("");

    return 0;
}

//----------------------------
// eight_by_one implementation
int eight_by_one() {
    int a = 1, b = 0;
    int temp = 0;

    for (register int i = 0; i < 1000000; i++) {
        if (a > b) { temp++; }
        if (a > b) { temp++; }
        if (a > b) { temp++; }
        if (a > b) { temp++; }
        if (a > b) { temp++; }
        if (a > b) { temp++; }
        if (a > b) { temp++; }
        if (a > b) { temp++; }
    }

    return temp;
}

//--------------------------
// one_by_one implementation
int one_by_one() {
    int a = 1, b = 0;
    int temp = 0;

    for (register int i = 0; i < 8000000; i++) {
        if (a > b) { temp++; }
    }

    return temp;
}
