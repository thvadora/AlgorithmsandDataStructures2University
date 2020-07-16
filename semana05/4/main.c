#include <stdio.h>
#include <stdlib.h>

#include "TADBooleano.h"
#include "TADNatural.h"
#include "criba.h"

int main(int argc, char const *argv[]){	

	 int number = 0;
	 number = atoi(argv[1]);
   	naturales criba[100000];
   	naturales n;
   	n = init();
   	for (int i = 0; i < number-1; ++i){
   		inc(n);
   	}
   	init_criba(criba,n);
   	proc_criba(criba,n);
   	int p = 0;
    for (int i = 0; i < number-1  ; ++i){
    	p = contar(criba[i]); 
    	if(p != 0){
    		printf("%d  ", contar(criba[i]));
    	}
    }
  

	return 0;
}

