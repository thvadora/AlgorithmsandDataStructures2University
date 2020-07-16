#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "helpers.h"
#include "sort.h"

static bool goes_before(player_t x, player_t y) {
    //x = x; y = y;        // just nonsense to make the compiler happy
    return (x->rank <= y->rank);   
}

/*static void swap(player_t a[], unsigned int i, unsigned int j) {
    player_t tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}*/

void swap(player_t *a, player_t *b){
    player_t tmp = NULL;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

static unsigned int partition(player_t a[], unsigned int izq, unsigned int der) {
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
            swap(&a[i],&a[j]);
            i++;
            j--;
        }
    }
    swap(&a[pivot],&a[j]);
    return j;
}

static void quick_sort_rec(player_t a[], unsigned int izq, unsigned int der) {
    unsigned int pivot;
    if(der > izq){
        pivot = partition(a,izq,der);
        quick_sort_rec(a,izq,(pivot == 0) ? 0 : pivot -1);
        quick_sort_rec(a,pivot+1,der);
    }
}

bool array_is_sorted(player_t atp[], unsigned int length) {
    unsigned int i = 1;
    while (i < length && goes_before(atp[i - 1], atp[i])) {
        i++;
    }
    return (i == length);
}

void sort(player_t a[], unsigned int length) {
    if (0 < length) {    // just nonsense to make the compiler happy 
        a[0] = a[0];     
    }
    quick_sort_rec(a, 0, (length == 0) ? 0 : length - 1);
}
