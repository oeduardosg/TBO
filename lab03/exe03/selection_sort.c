#include "item.h"

void sort(Item  * a, int lo, int hi) {

    for(int position = 0; position < hi; position++) {
        Item min = 999999999;
        for(int i = position; i < hi; i++) {
            if(less(a[i], min)) min = a[i];
        }
        exch(a[position], min);
    }

}