#include <stdio.h>
#include <assert.h>

#include "queue.h"

int main(){
	queue_t q = create_queue();
	empty_queue(q);
	unsigned int uno = 1;
	unsigned int dos = 2;
	unsigned int tres = 3;

	enqueue(q,tres);
	enqueue(q,dos);
	enqueue(q,uno);
	assert(first(q) == tres);
	dequeue(q);
	assert(first(q) == dos);
	dequeue(q);
	assert(first(q) == uno);
	dequeue(q);
	assert(is_empty_queue(q));
	enqueue(q,tres);
	assert(first(q) == tres);
	dequeue(q);
	assert(is_empty_queue(q));
	

	
	return 0;
}

