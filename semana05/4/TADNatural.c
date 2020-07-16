#include <stdio.h>
#include <stdlib.h>
#include "TADNatural.h"
#include "TADBooleano.h"


typedef struct node_t{
	char current;
	struct node_t *sucesor;
}node_t;

void destruction(naturales a){
	while(a->sucesor != NULL){
		dec(a);
	}
}

naturales init(){
	naturales aux = NULL;
	aux = (naturales)malloc(sizeof(struct node_t));
	aux->current = 'c';
	aux->sucesor = NULL;
	return(aux);
}

void inc(naturales a){
	naturales aux = a;
	while(aux->sucesor != NULL){
		aux = aux->sucesor;
	}
	naturales sig = NULL;
	sig = (naturales)malloc(sizeof(struct node_t));
	sig -> sucesor = NULL;
	sig -> current = 's';
	aux -> sucesor = sig;
}


void dec(naturales a){
	if (a->sucesor != NULL){
		naturales aux1 = NULL;
		naturales aux2 = NULL;
		aux1 = a;
		aux2 = a->sucesor;
		while(aux2->sucesor != NULL){
			aux1 = aux1->sucesor;
			aux2 = aux2->sucesor;
		}
		free(aux2);
		aux1->sucesor = NULL;

	}
	
}

booleano es_cero(naturales a){
	if(a->sucesor == NULL){
		return verdadero;
	} else {
		return falso;
	}
}

int contar(naturales a){
	int count = 0;
	while(a->sucesor != NULL){
		count++;
		a = a->sucesor;
	}
	return count;
}


naturales sum(naturales a, naturales b){
	naturales total = NULL,aux = NULL;
	aux = a;
	total = init();
	while(aux->sucesor != NULL){
		inc(total);
		aux = aux->sucesor;
	}
	aux = b;
	while(aux->sucesor != NULL){
		inc(total);
		aux = aux->sucesor;
	}
	return total;
}

naturales diff(naturales a, naturales b){
	naturales total = NULL, aux = NULL;
	aux = a;
	total = init();
	while(aux->sucesor != NULL){
		inc(total);
		aux = aux->sucesor;
	}
	aux = b;
	while(aux->sucesor != NULL){
		dec(total);
		aux = aux->sucesor;
	}
	return total;
}

naturales times(naturales a, naturales b){
	naturales total = NULL, aux = NULL;
	total = init();
	aux = a;
	while(aux->sucesor != NULL){
		total = sum(total,b);
		aux = aux -> sucesor;
	}
	return total;
}

booleano less_or_eq(naturales a, naturales b){
	if(contar(a) <= contar(b)){
		return verdadero;
	} else {
		return falso;
	}
}


booleano is_mult(naturales a, naturales b){
	naturales r;
	r = init();
	naturales aux = NULL;
	aux = a;
	while(aux->sucesor != NULL){
		inc(r);
		aux = aux->sucesor;
	}
	while(verdadero){
		r = diff(r,b);
		if(contar(r) == contar(b)){
			return verdadero;
		} else if(less_or_eq(r,b)){
			return falso;
		}
	}
}




