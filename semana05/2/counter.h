#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

typedef unsigned int counter;

void init(counter *pc);
/*
    Sets the counter referred by pc to the initial value.
*/

void inc(counter *pc);
/*
    Increments the counter referred by pc.
*/

void dec(counter *pc);
/*
    Decrements the counter referred by pc.
*/

bool is_init(counter c);
/*
    Return whether the counter c has the initial value.
*/

#endif
