#include <stdbool.h>
#include <stdlib.h>

#include "queue.h"

#define MAX_QUEUE 100000

typedef struct _queue_t {
    unsigned int start;
    unsigned int size;
    queue_elem elems[MAX_QUEUE];
} _queue_t;

queue_t create_queue() {
	queue_t q = (queue_t)malloc(sizeof(_queue_t));
	empty_queue(q);
	return (q);
}

void empty_queue(queue_t q) {
	q->size = 0;
}

/* pre: !is_full_queue(q) */
void enqueue(queue_t q, queue_elem e) {
	q->elems[(q->start + q->size) % MAX_QUEUE] = e;
	q->size = q->size + 1;

}

/* pre: !is_empty_queue(q) */
queue_elem first(queue_t q) {
	return(q->elems[q->start]);
}

/* pre: !is_empty_queue(q) */
void dequeue(queue_t q) {
	q->start = (q->start + 1) % MAX_QUEUE;
	q->size = q->size - 1;
}

bool is_empty_queue(queue_t q) {
	return (q->size == 0);
}

bool is_full_queue(queue_t q) {
	return(q->size == MAX_QUEUE);
}

void destroy_queue(queue_t q) {
	free(q);
}

