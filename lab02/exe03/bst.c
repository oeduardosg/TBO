#include "bst.h"
#include <stdlib.h>

struct bst {
    int * key;
    bst * left;
    bst * right;
};

int GetIntBst(bst * node) {
    return *node -> key;
}

int IsEmptyBst(bst * node) {
    return node == NULL;
}

bst * CreateBst() {

    bst * node = (bst *) calloc(1, sizeof(bst));
    node -> key = NULL;
    node -> right = NULL;
    node -> left = NULL;

return node;
}

void InsertBst(bst * node, int key) {

    if(!(node -> key)) {
        int * ckey = (int *) calloc(1, sizeof(int));
        *ckey = key;
        node -> key = ckey;
    }
    else if(key == *node -> key) {
        return;
    }
    else if(key < *node -> key) {
        if(IsEmptyBst(node -> left)) node -> left = CreateBst();
        InsertBst(node -> left, key);
    }
    else {
        if(IsEmptyBst(node -> right)) node -> right = CreateBst();
        InsertBst(node -> right, key);
    }

}

void FreeBst(bst * node) {

    if(!IsEmptyBst(node -> left)) FreeBst(node -> left);
    if(!IsEmptyBst(node -> right)) FreeBst(node -> right);
    if(node -> key) free(node -> key);
    free(node);

}

int HeightBst(bst * node) {

    if(!node) return -1;
    int left_height = HeightBst(node -> left);
    int right_height = HeightBst(node -> right);

return 1 + (left_height >= right_height ? left_height : right_height);
}

void PrintBst(bst * node) {
    printf("%d ", *node -> key);
}

void RecPreorder(bst * t, void (*visit)(bst *)) {

    if(!t) return;

    visit(t);
    RecPreorder(t -> left, visit);
    RecPreorder(t -> right, visit);

}

void RecInOrder(bst * t, void (*visit)(bst *)) {

    if(!t) return;

    RecPreorder(t -> left, visit);
    visit(t);
    RecPreorder(t -> right, visit);

}

void RecPostOrder(bst * t, void (*visit)(bst *)) {

    if(!t) return;

    RecPreorder(t -> left, visit);
    RecPreorder(t -> right, visit);
    visit(t);
    
}