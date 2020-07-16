#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(){
	stack_tt s = create_stack();
	char uno = '1';
	char dos = '2';
	char tres = '3';
	empty_stack(s);

	push(uno,s);
	push(dos,s);
	push(tres,s);
	assert(top(s) == tres);
	pop(s);
	assert(top(s) != tres); 
	assert(top(s) == dos);
	pop(s);
	assert(top(s) == uno);
	pop(s);
	assert(is_empty_stack(s));
	//pop(s);

	
	return 0;
}
