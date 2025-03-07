#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define MAX 1000000

int main() {

    bst * t = CreateBst();
    srand(time(NULL));

    for(int i = 0; i < MAX; i++) {
        t = InsertBst(t, rand(), 0);
    }

    printf("Tree's height is: %d\n", HeightBst(t));

    FreeBst(t);

return 0;
}