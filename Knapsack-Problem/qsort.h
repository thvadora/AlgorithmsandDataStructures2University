#ifndef QSORT_H
#define QSORT_H

#include <stdbool.h>
#include "item.h"

void sort(item_t a[], unsigned int length);
/*
    Sort the array 'a' using any sorting algorithm. The resulting sort
    will be ascending according to the goes_before funtion.

    The array 'a' must have exactly 'length' elements.
*/


#endif
