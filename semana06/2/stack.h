#ifndef _STACK_H
#define _STACK_H

#include <stdbool.h>

/* stack as pointers to structs to guarantee encapsulation
*/

typedef char stack_elem;

typedef struct _stack_t * stack_tt;

stack_tt create_stack();
/*
    Creates a new stack.
*/

void empty_stack(stack_tt s);
/*
    Sets s to be the empty stack.
*/

/* pre: !is_full_stack(s) */
void push(stack_elem e, stack_tt s);
/*
    Adds e to the stack.
*/

/* pre: !is_empty_stack(s) */
stack_elem top(stack_tt s);
/*
    Returns the top of the stack.
*/

/* pre: !is_empty_stack(s) */
void pop(stack_tt s);
/*
    Removes the top of the stack.
*/

bool is_empty_stack(stack_tt s);
/*
    Returns whether the stack s is empty or not.
*/

bool is_full_stack(stack_tt s);
/*
    Returns whether the stack s is full or not.
*/

void destroy_stack(stack_tt s);
/*
    Frees the dynamic memory used by the stack.
*/

#endif
