#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort.h"

static bool goes_before(int x, int y) {
    return (abs(x) < abs(y) || (abs(x) == abs(y) && x <= y));
}

static void swap(int a[], unsigned int i, unsigned int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

bool array_is_sorted(int array[], unsigned int length) {
    bool b = true;
    unsigned int i = 1;
    //i want to make it more efiiciant so i use while to break early
    while(i < length && b){
        b = b && (goes_before(array[i-1],array[i]));
        i++;
    }    
    return b;
}

static unsigned int min_pos_from(int a[], unsigned int i, unsigned int length) {
    unsigned int min_pos = i;
    for (unsigned int j = i + 1; j < length; j++) {
        if (goes_before(a[j],a[min_pos])) {
            min_pos = j;
        }
    }
    return (min_pos);
}

void selection_sort(int a[], unsigned int length) {
    for (unsigned int i = 0; i < length; i++) {
        unsigned int min_pos = min_pos_from(a, i, length);
        swap(a, i, min_pos);
    }
}


