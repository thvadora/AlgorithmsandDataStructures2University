#include <stdbool.h>
#include <stdlib.h>

#include "stack.h"

#define MAX_STACK 100

typedef struct _stack_t {
    unsigned int size;
    stack_elem elems[MAX_STACK];
} _stack_t;

stack_tt create_stack(){
    stack_tt s = (stack_tt)malloc(sizeof(_stack_t));
    empty_stack(s);
    return (s);
}

void empty_stack(stack_tt s) {
    s->size = 0;
}

/* pre: !is_full_stack(s) */
void push(stack_elem e, stack_tt s) {
	s->elems[s->size] = e;
	s->size = (s->size) +1;
}

/* pre: !is_empty_stack(s) */
stack_elem top(stack_tt s) {
	return (s->elems[(s->size)-1]);
}

/* pre: !is_empty_stack(s) */
void pop(stack_tt s) {
	s->elems[(s->size)-1] = 0;
	s->size = (s->size) -1;
}

bool is_empty_stack(stack_tt s) {
	return (s->size == 0);
}

bool is_full_stack(stack_tt s) {
	return (s->size == MAX_STACK);
}

void destroy_stack(stack_tt s) {
	while(!is_empty_stack(s)){
		pop(s);
	}
	free(s);
}


