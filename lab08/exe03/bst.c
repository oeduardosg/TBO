#include "bst.h"
#include <stdlib.h>
#include <math.h>
#include <stdio.h>

struct bst {
    int key;
    int value;
    int size;
    bst * left;
    bst * right;
};

int GetSize(bst * node) {
    if(node == NULL) return 0;
    return node -> size;
}

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
    node -> size = 0;
    node -> right = NULL;
    node -> left = NULL;

return node;
}

bst * RotateRight(bst * n) {

    bst * t = n -> left;
    n -> left = t -> right;
    t -> right = n;

    t -> size = GetSize(n);
    n -> size = GetSize(n -> right) + GetSize(n -> left) + 1;

return t;
}

bst * RotateLeft(bst * n) {

    bst * t = n -> right;
    n -> right = t -> left;
    t -> left = n;

    t -> size = GetSize(n);
    n -> size = GetSize(n -> right) + GetSize(n -> left) + 1;

return t;
}
    

bst * InsertBst(bst * node, int key, int value) {

    if(node == NULL) {
        bst * node = CreateBst();
        node -> key = key;
        node -> value = value;
        node -> size = 0;
        return node;
    }

    node -> size++;

    if(key <= node -> key) {
        node -> left = InsertBst(node -> left, key, value);
        node = RotateRight(node);
    }
    else {
        node -> right = InsertBst(node -> right, key, value);
        node = RotateLeft(node);
    }

return node;
}

bst * InsertBstRandom(bst * node, int key, int value) {

    if(node == NULL) {
        bst * node = CreateBst();
        node -> key = key;
        node -> value = value;
        node -> size = 0;
        return node;
    }

    node -> size++;

    if(rand() < RAND_MAX / (GetSize(node) + 1)) return InsertBst(node, key, value);
    
    if(key > GetKeyBst(node)) node -> right = InsertBstRandom(node -> right, key, value);
    else if(key < GetKeyBst(node)) node -> left = InsertBstRandom(node -> left, key, value);

    return node;

}

bst * PartitionBst(bst * node, int key) {

    int s = GetSize(node -> left);

    if(s > key) {
        if(node -> left) node -> left = PartitionBst(node -> left, key);
        node = RotateRight(node);
    }
    else if(s < key) {
        if(node -> right) node -> right = PartitionBst(node -> right, key - s - 1);
        node = RotateLeft(node);
    }

return node;
}

bst * BalanceBst(bst * node){
    if(GetSize(node) < 2) return node;

    node = PartitionBst(node, GetSize(node)/2);
    node -> left = BalanceBst(node -> left);
    node -> right = BalanceBst(node -> right);

    return node;
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