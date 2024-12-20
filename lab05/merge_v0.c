#include "item.h"
#include <stdlib.h>

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

void merge_sort(Item * a, Item * aux, int lo, int hi) {

    if (hi <= lo) return;
    int mid = lo + (hi - lo) / 2;
    merge_sort(a, aux, lo, mid);
    merge_sort(a, aux, mid+1, hi);
    merge(a, aux, lo, mid, hi);

}

void sort(Item  * a, int lo, int hi) {

    int n = (hi - lo) + 1;
    Item * aux = malloc(n * sizeof(Item));
    merge_sort(a, aux, lo, hi);
    free(aux);

}