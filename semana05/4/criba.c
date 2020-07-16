#include <stdio.h>

#include "TADBooleano.h"
#include "TADNatural.h"
#include "criba.h"


void delete_mult(naturales crib[], naturales n, naturales d){
	naturales i;
	i = init();
	int p = 0;
	while(less_or_eq(i,n)){
		p = contar(i);
		if(is_mult(crib[p],d)){
			destruction(crib[p]);
		}
		inc(i);
	}
}

void init_criba(naturales crib[], naturales n){
	naturales i;
	int p = 0;
	i = init();
	naturales var;
	var = init();
	inc(var);
	inc(var);
	//dec(n);
	while(less_or_eq(i,n)){
		p = contar(i);
		crib[p] = sum(i,var);
		inc(i);
	}
}

void proc_criba(naturales crib[], naturales n){
	naturales i;
	i = init();
	naturales var;
	var = init();
	inc(var);
	inc(var);
	//dec(n);
	while(less_or_eq(i,n)){
		delete_mult(crib,n,var);
		inc(var);
		inc(i);
	}
}


