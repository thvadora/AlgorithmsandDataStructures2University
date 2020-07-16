#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

bool array_is_sorted(unsigned int a[], unsigned int length);
/* Checks if the array 'a' is in ascending order */

void radix_sort(unsigned int a[], unsigned int length);
/*
    Sort the array 'a' using the Radix sort algorithm. The resulting sort
    will be ascending.

    The array 'a' must have exactly 'length' elements.

*/

#endif
