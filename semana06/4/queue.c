#include <stdbool.h>
#include <stdlib.h>

#include "queue.h"

/* node_t the type of pointers to nodes
*/
typedef struct _node_t * node_t;

/* _node_t the type of nodes
*/
struct _node_t {
    queue_elem elem;
    node_t next;
} _node_t;

typedef struct _queue_t {
    node_t start;
    node_t end;
} _queue_t;

queue_t create_queue() {
	queue_t q = (queue_t)malloc(sizeof(_queue_t));
	empty_queue(q);
	return (q);
}

void empty_queue(queue_t q) {
	q->start = NULL;
	q->end = NULL;
}

/* pre: !is_full_queue(q) */
void enqueue(queue_t q, queue_elem e) {
	node_t new = (node_t)malloc(sizeof(_node_t));
	new->elem = e;
	new->next = NULL;
	if(q->end == NULL){
		q->start = new;
		q->end = new;
	} else {
		q->end->next = new;
		q->end = new;
	}
}

/* pre: !is_empty_queue(q) */
queue_elem first(queue_t q) {
	return(q->start->elem);
}

/* pre: !is_empty_queue(q) */
void dequeue(queue_t q) {
	node_t aux1 = NULL;
	node_t aux2 = NULL;
	aux1 = q->start;
	aux2 = q->start->next;
	if(aux2 == NULL){
		q->start = NULL;
		q->end = NULL;
	} else {
		q->start = aux2;
		aux1->next = NULL;
	}
	free(aux1);

}

bool is_empty_queue(queue_t q) {
	return((q->start == NULL) && (q->end == NULL));
}

bool is_full_queue(queue_t q) {
	return (q->start == NULL && q->start != NULL);
}

void destroy_queue(queue_t q) {
	while(!is_empty_queue(q)){
		dequeue(q);
	}
}

