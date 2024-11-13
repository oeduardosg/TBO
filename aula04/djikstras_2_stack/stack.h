#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;

stack * create_stack();

void insert_stack(void * item);

void * remove_stack(stack * s);

void free_stack(stack * s);