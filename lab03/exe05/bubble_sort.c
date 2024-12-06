#include "item.h"

void sort(Item  * a, int lo, int hi) {

    for(int i = lo; i < hi; i++) {

        int swapped = 0;

        for(int j = lo; j < hi - i; j++) {
            if(less(a[j + 1], a[j])) {
                exch(a[j], a[j + 1]);
                swapped = 1;
            }
        }

        if(!swapped) break;
    }

}