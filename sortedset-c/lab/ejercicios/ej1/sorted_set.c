#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "sorted_set.h"

struct  _sorted_set{
    t_elem elem;
    struct _sorted_set * next;

};

bool contains(sorted_set s, t_elem e){
    sorted_set aux = s->next;
    bool b = false;    
    while(aux!=NULL){
        if(aux->elem == e){
            b = true;        
        }
        aux = aux->next;
    }
    return b;
}

sorted_set create_sorted_set(){
    sorted_set s = (sorted_set)malloc(sizeof(struct _sorted_set));
    s->next = NULL;       
    return s;
}

void add(sorted_set s, t_elem e){
    sorted_set new = (sorted_set)malloc(sizeof(struct _sorted_set));
    new->elem = e;
    bool b = true;
    if(is_empty(s)){
        new->next = NULL;
        s->next = new;
    } else if(!contains(s,e)){
        sorted_set aux = s->next;
        sorted_set prev = s;
        while(prev->next != NULL && b){
            if(aux->elem < e){
                aux = aux->next;
                prev = prev->next;
            } else if(aux->elem > e){
                new->next = aux;
                prev->next = new;
                b = false;        
            }
        }
        if(prev->next == NULL && b){
            prev->next = new;
            new->next = NULL;
        }
    }
    

}

void rm(sorted_set s, t_elem e){
    if(contains(s,e)){
        sorted_set aux = s->next;
        sorted_set prev = s;
        bool b = true;
        while(prev->next != NULL && b){
            if(aux->elem != e){
                aux = aux->next;
                prev = prev->next;
            } else {
                sorted_set r = aux;
                aux = aux->next;
                r->next = NULL;
                free(r);
                prev->next = aux;
            }
        }
    }
}

t_elem first(sorted_set s){
    return(s->next->elem);
}

t_elem last(sorted_set s){
    sorted_set aux = s->next;
    while(aux->next != NULL){
        aux = aux->next;
    }
    return(aux->elem);    
}

void dump_sorted_set(sorted_set s){
    if(!is_empty(s)){    
        sorted_set aux = s->next;    
        while(aux != NULL){
            printf("%d ", aux->elem);
            aux = aux->next;
        }
    }
}

bool is_empty(sorted_set s){
    return(s->next == NULL);
}

int size(sorted_set s){
    int count = 0;
    sorted_set aux = s->next;
    while(aux != NULL){
        count++;
        aux = aux->next;
    } 
return count;
}

void destroy_sorted_set(sorted_set s){
    while(!is_empty(s)){
       rm(s,first(s));     
    }
    free(s);
}


