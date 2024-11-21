#include <stdio.h>
#include "bst.h"
#include <time.h>
#include <stdlib.h>

int main() {

    bst * node = CreateBst();

    srand(time(NULL));

    for(int i = 0; i < 1000000; i++) {
        int r = rand();
        InsertBst(node, r);
    }

    printf("%d\n", HeightBst(node));
    FreeBst(node);

return 0;
}