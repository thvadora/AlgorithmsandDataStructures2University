#ifndef _TAD_NATURAL_H
#define _TAD_NATURAL_H

#include "TADBooleano.h"

typedef struct node_t * naturales;

void destruction(naturales a);

naturales init();

void inc(naturales a);

void dec(naturales a);

booleano es_cero(naturales a);

int contar(naturales a);

naturales sum(naturales a, naturales b);

naturales diff(naturales a, naturales b);

naturales times(naturales a, naturales b);

booleano less_or_eq(naturales a, naturales b);

booleano is_mult(naturales a, naturales b);


#endif

