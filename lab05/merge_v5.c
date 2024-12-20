#include "item.h"
#include <stdlib.h>
#include "insertion_sort.c"

#define SZ2 (sz+sz)
#define MIN(X,Y) ((X < Y) ? (X) : (Y))
#define CUTOFF 8

void merge(Item * a, Item * aux, int lo, int mid, int hi) {

    for(int i = lo; i <= hi; i++) {
        aux[i] = a[i];
    }

    int j = lo, k = mid + 1;

    for(int i = lo; i <= hi; i++) {

        if(j > mid) a[i] = aux[k++];
        else if(k > hi) a[i] = aux[j++];
        else if(less(aux[j], aux[k])) a[i] = aux[j++];
        else a[i] = aux[k++];

    }

}

void sort(Item *a, int lo, int hi) {

    int n = (hi - lo) + 1;
    int y = n - 1;
    Item * aux = malloc(n * sizeof(Item));

        for (int sz = 1; sz < n; sz = SZ2) {
            for (int lo = 0; lo < n - sz; lo += SZ2) {
                int x = lo + SZ2 - 1;
                if (hi <= lo + CUTOFF) {
                    insertion_sort(a, lo, hi);
                    continue;
                }
                merge(a, aux, lo, lo + sz-1, MIN(x,y));
            }
        }

    free(aux);

}