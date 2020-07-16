#ifndef _SORT_H
#define _SORT_H

#include <stdbool.h>

void permutation_sort(int a[], unsigned int length);
/*
    Sort the array 'a' building all the posible permutations and selecting one which
    is sorted. The resulting sort will be ascending according to the goes_before funtion.

    The array 'a' must have exactly 'length' elements.

*/

#endif
