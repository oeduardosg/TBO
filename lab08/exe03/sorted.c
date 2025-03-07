#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "bst.h"

#define MAX 1000000

int main() {

    bst * t = CreateBst();

    for(int i = 0; i < MAX; i++) {
        t = InsertBstRandom(t, i, 0);
    }

    printf("Tree's height is: %d\n", HeightBst(t));

    FreeBst(t);

return 0;
}