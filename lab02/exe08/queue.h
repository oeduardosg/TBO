#ifndef _queue_h_
#define _queue_h_

typedef struct queue queue;

queue * create_queue();

void enqueue(queue * q, void * data);

void * dequeue(queue * q);

int empty(queue * q);

void free_queue(queue * q);

#endif