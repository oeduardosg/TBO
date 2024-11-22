#include <stdio.h>
#include <stdlib.h>

typedef struct stack stack;

stack * create_stack();

void push(stack * s, void * item);

void * pop(stack * s);

void free_stack(stack * s);

int empty(stack * s);

void * peek(stack * s);