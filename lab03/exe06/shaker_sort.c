#include "item.h"

void sort(Item  * a, int lo, int hi) {

    int turn = 1;

    for(int i = lo; i < hi; i++) {
        if(turn) {
            for(int j = lo; j < hi - i - 1; j++) {
                if(less(a[j + 1], a[j])) exch(a[j], a[j + 1]);
            }
            turn = 0;
        }
        else {
            for(int j = hi - i; j > i + 1; j--) {
                if(less(a[j - 1], a[j])) exch(a[j - 1], a[j]);
            }
            turn = 1;
        }
    }
}