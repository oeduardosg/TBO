#include "stack.h"

typedef struct cell cell;

struct cell {
    void * item;
    cell * prior;
};

struct stack {
    cell * last;
};

cell * create_cell(cell * prior, void * item) {

    cell * c = (cell *) calloc(1, sizeof(cell));
    c -> prior = prior;
    c -> item = item;

return c;
}

void * get_item(cell * c) {
return c -> item;
}

cell * get_prior(cell * c) {
return c -> prior;
}

stack * create_stack() {

    stack * s = (stack *) calloc(1, sizeof(stack));

    s -> last = NULL;

return s;
}

void insert_stack(stack * s, void * item) {

    cell * nc = create_cell(s -> last, item);
    s -> last = nc;

}

void * remove_stack(stack * s) {

    void * item = get_item(s);
    cell * c = s -> last;
    s -> last = get_prior(c);

    free(c);

return item;
}

void free_stack(stack * s) {

    cell * c = s -> last;
    cell * to_free = NULL;

    while(c) {
        to_free = c;
        c = c -> prior;
        free(c);
    }

    free(s);

}