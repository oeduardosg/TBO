#include <stdio.h>
#include <time.h>
#include "item.h"

#define LO 0

extern void sort(Item  * a, int lo, int hi);

int main() {

    int n = 0;
    scanf("%d%*c", &n);

    Item * array = (Item *) calloc(n, sizeof(int));

    clock_t start, stop;
    start = clock();

    sort(array, LO, n);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    free(array);

return 0;
}