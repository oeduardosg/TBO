#include <stdio.h>
#include <time.h>
#include "bst.h"
#include <stdlib.h>

int main() {

    bst * node = CreateBst();

    srand(time(NULL));

    for(int i = 0; i < 10000000; i++) {
        int r = rand();
        InsertBst(node, r);
    }

    clock_t start, stop;
    start = clock();

    BreadthFirstSearch(node, PrintBst);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\nBFS time: %lf\n", time_taken);

return 0;
}