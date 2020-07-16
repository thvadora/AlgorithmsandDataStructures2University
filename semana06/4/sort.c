#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort.h"
#include "queue.h"


bool array_is_sorted(unsigned int array[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && array[i - 1] <= array[i]) {
        i++;
    }
    return (i == length);
}

void radix_sort(unsigned int a[], unsigned int length) {
    queue_t q[2] = {create_queue(), create_queue()};
    empty_queue(q[0]);
    empty_queue(q[1]);
    for (unsigned int bit = 1; bit < 0x80000000; bit = bit << 1) {
        for (unsigned int i = 0; i < length; i++) {
            enqueue(q[(a[i] & bit) == bit], a[i]);
        }
       unsigned int i = 0;
        for (unsigned int j = 0; j <= 1; j++) {
            while (!is_empty_queue(q[j])) {
                a[i] = first(q[j]);
                dequeue(q[j]);
                i++;
            }
        }
    }
    destroy_queue(q[0]);
    destroy_queue(q[1]);
}


