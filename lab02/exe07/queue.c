#include "queue.h"
#include <stdlib.h>

typedef struct cell cell;

struct cell {
    cell * next;
    void * item;
};

struct queue {
    cell * first;
    cell * last;
};

cell * create_cell(void * item) {

    cell * c = (cell *) calloc(1, sizeof(cell));
    c -> next = NULL;
    c -> item = item;

return c;
}

void set_next(cell * c, cell * n) {
    c -> next = n;
}

void * get_item(cell * c) {
    return c -> item;
}

cell * get_next(cell * c) {
    return c -> next;
}

void free_cell(cell * c) {
    free(c);
}

queue * create_queue() {

    queue * q = (queue *) calloc(1, sizeof(queue));
    q -> first = NULL;
    q -> last = NULL;

return q;
}

void enqueue(queue * q, void * item) {

    cell * c = create_cell(item);

    if(!(q -> first)) {
        q -> first = c;
        q -> last = c;
    }
    else {
        set_next(q -> last, c);
        q -> last = c;
    }

}

void * dequeue(queue * q) {

    if(!(q -> first)) return NULL;
    
    void * t = get_item(q -> first);
    cell * to_free = q -> first;

    if(q -> first == q -> last) {
        q -> first = NULL;
        q -> last = NULL;
    }
    else {
        q -> first = get_next(q -> first);
    }

    free_cell(to_free);

return t;
}

int empty(queue * q) {
    return !(q -> first);
}

void free_queue(queue * q) {
    
    while(!empty(q)) {
        void * trash = dequeue(q);
    }

    free(q);
    
}