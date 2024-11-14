#include <stdio.h>
#include "election.h"
#include <time.h>

int main() {

    int nPeople, mElimination;

    scanf("%d %d", &nPeople, &mElimination);

    clock_t start, stop;
    start = clock();

    array_election(nPeople, mElimination, 0);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;
    printf("\ntime: %lf\n", time_taken);

return 0;
}