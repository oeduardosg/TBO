#include "item.h"

void sort(Item  * a, int lo, int hi) {

    int turn = 1;

    for(int i = lo; i < hi; i++) {

        int swapped = 0;

        if(turn) {
            for(int j = lo; j < hi - i - 1; j++) {
                if(less(a[j + 1], a[j])) {
                    exch(a[j], a[j + 1]);
                    swapped = 1;
                }
            }
            turn = 0;
        }
        else {
            for(int j = hi; j > i + 1; j--) {
                if(less(a[j], a[j - 1])) {
                    exch(a[j - 1], a[j]);
                    swapped = 1;
                }
            }
            turn = 1;
        }

        if(!swapped) break;
    }
}