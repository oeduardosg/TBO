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
 * @param key value to be inserted
 */
void InsertBst(bst * node, int key);

/**
 * Frees a node;
 * @param node to be freed;
 */
void FreeBst(bst * node);

/**
 * Calculates the total tree size;
 * @param node tree node to calculate the size of;
 */
int HeightBst(bst * node);

void RecPreorder(bst * t, void (*visit)(bst *));

void RecInorder(bst * t, void (*visit)(bst *));

void RecPostorder(bst * t, void (*visit)(bst *));

void IterPreorder(bst * t, void (*visit)(bst *));

void IterInorder(bst * t, void (*visit)(bst *));

void IterPostorder(bst * t, void (*visit)(bst *));

void PrintBst(bst * node);

#endif