#include <stdio.h>
#include <time.h>
#include "bst.h"
#include <stdlib.h>

int main() {

    bst * node = CreateBst();

    srand(time(NULL));

    /** Sample
    InsertBst(node, 10);
    InsertBst(node, 5);
    InsertBst(node, 15);
    InsertBst(node, 4);
    InsertBst(node, 6);
    InsertBst(node, 14);
    InsertBst(node, 16);
     */

    srand(time(NULL));

    for(int i = 0; i < 10000000; i++) {
        int r = rand();
        InsertBst(node, r);
    }

    clock_t start, stop;
    start = clock();

    IterPreorder(node, PrintBst);

    stop = clock();
    double time_taken1 = ((double) stop - start) / CLOCKS_PER_SEC;

    start = clock();

    IterInorder(node, PrintBst);

    stop = clock();
    double time_taken2 = ((double) stop - start) / CLOCKS_PER_SEC;

    start = clock();

    IterPostorder(node, PrintBst);

    stop = clock();
    double time_taken3 = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("\nIter Pre-order time: %lf\n", time_taken1);
    printf("\nIter In-order time: %lf\n", time_taken2);
    printf("\nIter Post-order time: %lf\n", time_taken3);

return 0;
}