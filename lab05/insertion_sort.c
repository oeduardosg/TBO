#include "item.h"


void insertion_sort(Item *a, int lo, int hi){
    for(int i = lo; i <= hi; i++){
        for(int j = i; j > lo && less(a[j], a[j - 1]); j--) 
            exch(a[j - 1], a[j]);
    }
}