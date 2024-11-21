#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "sieve.h"


int main() {

    int qtt;
    scanf("%d", &qtt);

    clock_t start, stop;
    start = clock();

    char_sieve(qtt, 0);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("\ntime: %lf\n", time_taken);

return 0;
}