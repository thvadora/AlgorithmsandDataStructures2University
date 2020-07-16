#include <stdbool.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#include "stack.h"

/* node_t the type of pointers to nodes
*/
typedef struct _node_t * node_t;

/* _node_t the type of nodes
*/
struct _node_t {
    stack_elem elem;
    node_t next;
} _node_t ;

/* one more indirection to deal with language c parameter passing properties
*/
typedef struct _stack_t {
    node_t the_stack;
} _stack_t;

stack_tt create_stack() {
    stack_tt s = (stack_tt)malloc(sizeof(_stack_t));
    s->the_stack = NULL;
    return (s);
}

void empty_stack(stack_tt s) {
    while (!is_empty_stack(s)) {
        pop(s);
    }
}

/* pre: !is_full_stack(s) */
void push(stack_elem e, stack_tt s) {
   node_t new = (node_t)malloc(sizeof(_node_t));
   new->elem = e;
   new->next = NULL;
   node_t aux = s->the_stack;
   if(aux == NULL){
    s->the_stack = new;
   } else {
       while(aux->next != NULL){
            aux = aux->next;
        }
        aux->next = new;
   }
}

/* pre: !is_empty_stack(s) */
stack_elem top(stack_tt s) {
    node_t aux = s->the_stack;
    while(aux->next != NULL){
        aux = aux->next;
    }
    return(aux->elem);  

}

/* pre: !is_empty_stack(s) */
void pop(stack_tt s) {
      assert(!is_empty_stack(s));
      node_t aux1 = NULL;
      node_t aux2 = NULL;
      aux1 = s->the_stack;
      aux2 = s->the_stack->next;
      if(aux2 == NULL){
          s->the_stack = NULL;
      } else {
          while(aux2->next != NULL){
             aux2 = aux2->next;
             aux1 = aux1->next;
          }
          aux1->next = NULL;
      }   
    free(aux2);
}

bool is_empty_stack(stack_tt s) {
    return (s->the_stack == NULL);
}

bool is_full_stack(stack_tt s) {
    return (s == NULL && s != NULL);  //always returns false (trick to make the compiler happy)
}

void destroy_stack(stack_tt s) {
    while (!is_empty_stack(s)) {
        pop(s);
    }
    free(s);
}

