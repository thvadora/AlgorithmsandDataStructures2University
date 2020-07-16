#include <stdio.h>
#include "TADBooleano.h"


booleano f_and(booleano p, booleano q){
	if(p == verdadero && q == verdadero){
		return verdadero;
	} else {
		return falso;
	}
}

booleano f_or(booleano p, booleano q){
	if(p == falso && q == falso){
		return falso;
	} else {
		return verdadero;
	}
}

booleano f_not(booleano p){
	if(p == verdadero){
		return falso;
	} else {
		return verdadero;
	}
}

