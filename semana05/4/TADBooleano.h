#ifndef _TAD_BOOLEANO_H
#define _TAD_BOOLEANO_H

typedef enum {falso,verdadero} booleano;

booleano f_and(booleano p, booleano q);

booleano f_or(booleano p, booleano q);

booleano f_not(booleano p);

#endif

