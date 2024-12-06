#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "item.h"

#define LO 0

extern void sort(Item  * a, int lo, int hi);

int main() {

    int n = 0;
    char path[400], prepath[100];
    scanf("%dK%s", &n, prepath);

    Item * array = (Item *) calloc(n*1000, sizeof(int));

    sprintf(path, "../in/%s/%dK%s.txt", prepath, n, prepath);
    FILE * items = fopen(path, "r");
    for(int i = 0; i < n * 1000; i++) {
        fscanf(items, "%d", &array[i]);
    }
    fclose(items);

    clock_t start, stop;
    start = clock();

    sort(array, LO, n * 1000);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("Ordenados:\n");
    for(int i = 0; i < n * 1000; i++) {
        printf("%d\n", array[i]);
    }

    printf("\n%.6lf\n", time_taken);

    free(array);

return 0;
}