#include "bst.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct bst {
    int key;
    int value;
    bst * left;
    bst * right;
};

int GetKeyBst(bst * node) {
    return node -> key;
}

int IsEmptyBst(bst * node) {
    return node == NULL;
}

bst * CreateBst() {

    bst * node = (bst *) calloc(1, sizeof(bst));
    node -> key = NULL;
    node -> value = NULL;
    node -> right = NULL;
    node -> left = NULL;

return node;
}

void InsertBst(bst * node, int key, int value) {

    if(node -> key == NULL) {
        node -> key = key;
        node -> value = value;
    }
    else if(key == node -> key) {
        return;
    }
    else if(key < node -> key) {
        if(IsEmptyBst(node -> left)) node -> left = CreateBst();
        InsertBst(node -> left, key, value);
    }
    else {
        if(IsEmptyBst(node -> right)) node -> right = CreateBst();
        InsertBst(node -> right, key, value);
    }

}

void FreeBst(bst * node) {

    if(!IsEmptyBst(node -> left)) FreeBst(node -> left);
    if(!IsEmptyBst(node -> right)) FreeBst(node -> right);
    free(node);

}

int HeightBst(bst * node) {

    if(!node) return -1;
    int left_height = HeightBst(node -> left);
    int right_height = HeightBst(node -> right);

return 1 + (left_height >= right_height ? left_height : right_height);
}

void PrintBst(bst * node) {
    printf("%d ", node -> value);
}