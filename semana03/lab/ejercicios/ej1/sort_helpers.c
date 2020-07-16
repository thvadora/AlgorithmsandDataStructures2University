#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"

void swap(unsigned int array[], unsigned int i, unsigned int j) {
    unsigned int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

bool goes_before(int x, int y) {
    return (abs(x) < abs(y) || (abs(x) == abs(y) && x <= y));
}

bool array_is_sorted(int array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(array[i-1], array[i])) {
        i++;
    }
    return (i >= length);
}


