#ifndef _bst_h_
#define _bst_h_

typedef struct bst bst;

/**
 * Creates an empty binary search tree data struct;
 * @return empty bst;
 */
bst * CreateBst();

/**
 * Inserts a key (int) value in a bst type;
 * @param node candidate node to receive a value
 * @param key key of the node to be inserted
 * @param value value to be stored
 */
bst * InsertBst(bst * node, int key, int value);

bst * InsertBstRandom(bst * node, int key, int value);

bst * BalanceBst(bst * node);

/**
 * Frees a node;
 * @param node to be freed;
 */
void FreeBst(bst * node);

int HeightBst(bst * node);

void PrintBst(bst * node);

#endif