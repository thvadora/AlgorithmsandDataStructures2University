#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

/* counter as pointers to structs to guarantee encapsulation
*/

typedef struct _counter * counter;


/* Declarations are just like they were before doing exercise 1 today.
   They didn't work then, but they work fine now since counter is
   in fact a pointer to... 
   ... to something we still don't know.
*/

void init(counter c);
/*
    Sets the counter c to the initial value.
*/

void inc(counter c);
/*
    Increments the counter c.
*/

void dec(counter c);
/*
    Decrements the counter c.
*/

bool is_init(counter c);
/*
    Return whether the counter c has the initial value.
*/

#endif
