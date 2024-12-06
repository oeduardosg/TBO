#include "item.h"

void sort(Item  * a, int lo, int hi) {

    for(int position = 0; position < hi; position++) {
        Item min = position;
        for(int i = position + 1; i < hi; i++) {
            if(less(a[i], a[min])) min = i;
        }
        exch(a[position], a[min]);
    }

}