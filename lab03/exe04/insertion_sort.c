#include "item.h"

void sort(Item  * a, int lo, int hi) {

    for(int i = lo + 1; i < hi; i++) {

        int j = i - 1, k = i;
        while(less(a[k], a[j])) {
            exch(a[j], a[k]);
            j--;
            k--;
        }
        
    }

}