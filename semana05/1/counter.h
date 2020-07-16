#ifndef _COUNTER_H
#define _COUNTER_H

#include <stdbool.h>

typedef unsigned int counter;

counter init(counter c);
/*
    Sets the counter c to the initial value.
*/

counter inc(counter c);
/*
    Increments the counter c.
*/

counter dec(counter c);
/*
    Decrements the counter c.
*/

bool is_init(counter c);
/*
    Return whether the counter c has the initial value.
*/

#endif
