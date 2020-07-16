#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#include "array_helpers.h"
#include "sort_helpers.h"
#include "sort.h"

static void next_permutation(unsigned int perm[], unsigned int length) {
    unsigned int i, j;
    // taken (and modified) from
    // https://www.nayuki.io/page/next-lexicographical-permutation-algorithm 

    // Find non-increasing suffix
    i = length - 1;
    while (i > 0 && perm[i - 1] >= perm[i]) {
        i--;
    }
    
    // Find successor to pivot
    j = length - 1;
    while (perm[j] <= perm[i - 1]) {
        j--;
    }

    swap(perm, i - 1, j);
    
    // Reverse suffix
    j = length - 1;
    while (i < j) {
        swap(perm, i, j);
        i++;
        j--;
    }
}

static void mk_fst_permutation(unsigned int perm[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i){
        perm[i] = i;
    }
}

static bool sorted(int a[], unsigned int perm[], unsigned int length) {
    bool b = true;
    for (unsigned int i = 1; i < length; ++i){
        b = b && (goes_before(a[perm[i-1]],a[perm[i]]));
    }
    return b;
}

static void update(int a[], unsigned int perm[], unsigned int length) {
    int tmp[length];
    for (unsigned int i = 0; i < length; ++i){
        tmp[i] = a[perm[i]];
    }
    for (unsigned int i = 0; i < length; ++i){
        a[i] = tmp[i];
    }
}

void permutation_sort(int a[], unsigned int length) {
/* tries systematically with all te possible permutations
 * until a sorted one is found
 */
    unsigned int perm[length];
    mk_fst_permutation(perm, length);
    while (!sorted(a, perm, length)) {
        next_permutation(perm, length);
    }
    update(a, perm, length);
}

