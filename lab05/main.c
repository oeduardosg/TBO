#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "item.h"

#define LO 0

extern void sort(Item  * a, int lo, int hi);

int main() {

    int n = 0;
    char path[400], prepath[100], pow = 0;
    scanf("%d%c %s", &n, &pow, prepath);

    Item * array;
    if(pow == 'K') {
        n *= 1000;
        array = (Item *) calloc(n, sizeof(int));
    }
    else {
        n *= 1000000;
        array = (Item *) calloc(n, sizeof(int));
    }

    sprintf(path, "./input/%s/%d.txt", prepath, n);
    FILE * items = fopen(path, "r");

    if(!items) {
        printf("Couldn't open file %s\n", path);
        exit(1);
    }

    for(int i = 0; i < n; i++) {
        fscanf(items, "%d", &array[i]);
    }
    fclose(items);

    clock_t start, stop;
    start = clock();

    sort(array, LO, n - 1);

    stop = clock();
    double time_taken = ((double) stop - start) / CLOCKS_PER_SEC;

    printf("Ordenados:\n");
    for(int i = 0; i < n; i++) {
        printf("%d\n", array[i]);
    }

    printf("\n%.6lf\n", time_taken);

    free(array);

    printf("%d\n", n);

return 0;
}