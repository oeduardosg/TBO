#include "item.h"

void sort(Item  * a, int lo, int hi) {

    for(int i = lo; i < hi; i++) {
        for(int j = lo; j < hi - i; j++) {
            if(less(a[j], a[j + 1])) exch(a[j], a[j + 1]);
        }
    }

}