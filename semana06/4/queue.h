#ifndef _QUEUE_H
#define _QUEUE_H

#include <stdbool.h>

/* queue as pointers to structs to guarantee encapsulation
*/

typedef unsigned int queue_elem;

typedef struct _queue_t * queue_t;

queue_t create_queue();
/*
    Creates a new queue.
*/

void empty_queue(queue_t q);
/*
    Sets q to be the empty queue.
*/

/* pre: !is_full_queue(q) */
void enqueue(queue_t q, queue_elem e);
/*
    Adds e to the queue.
*/

/* pre: !is_empty_queue(q) */
queue_elem first(queue_t q);
/*
    Returns the top of the queue.
*/

/* pre: !is_empty_queue(q) */
void dequeue(queue_t q);
/*
    Removes the top of the queue.
*/

bool is_empty_queue(queue_t q);
/*
    Returns whether the queue q is empty or not.
*/

bool is_full_queue(queue_t q);
/*
    Returns whether the queue q is full or not.
*/

void destroy_queue(queue_t q);
/*
    Frees the dynamic memory used by the queue.
*/

#endif
