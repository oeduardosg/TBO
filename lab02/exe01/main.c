#include <stdio.h>
#include "bst.h"

int main() {

    bst * node = CreateBst();

    int key = 0;
    printf("Insert how many keys you want and then enter -1 to stop\n");
    do {
        scanf("%d", &key);
        InsertBst(node, key);
    } while(key != -1);
    FreeBst(node);
    printf("Program finished\n");

return 0;
}