#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "item.h"
#include "qsort.h"

static bool goes_before(item_t x, item_t y) {
    //x = x; y = y;        // just nonsense to make the compiler happy
    return (item_value(x) >= item_value(y));   
}

static void swap(item_t a[], unsigned int i, unsigned int j) {
    item_t tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}

static unsigned int partition(item_t a[], unsigned int izq, unsigned int der) {
    unsigned i,j,pivot;
    pivot = izq;
    i = izq +1;
    j = der;
    while(i<=j){
        if(goes_before(a[i],a[pivot])){
            i++;
        } else if(goes_before(a[pivot],a[j])){
            j--;
        } else if(goes_before(a[pivot],a[i]) && goes_before(a[j],a[pivot])){
            swap(a,i,j);
            i++;
            j--;
        }
    }
    swap(a,pivot,j);
    return j;
}

static void quick_sort_rec(item_t a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    if(der > izq){
        pivot = partition(a,izq,der);
        quick_sort_rec(a,izq,(pivot == 0) ? 0 : pivot -1);
        quick_sort_rec(a,pivot+1,der);
    }
}

void sort(item_t a[], unsigned int length) {
    if (0 < length) {    // just nonsense to make the compiler happy 
        a[0] = a[0];     
    }
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}

