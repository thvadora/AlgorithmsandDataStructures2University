#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "prop.h"

typedef enum _prop_type {True, False, Var, Not, And, Or, Then, Iff} prop_type;

/* prop_t is a pointer to a structure.
 */
typedef struct _prop_t {
    prop_type type;
    unsigned int var;
    struct _prop_t * left;
    struct _prop_t * right;
} _prop_t;

/* Creates the true/false proposition 
 */
prop_t prop_true() {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = True;
    new->var = 0;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

prop_t prop_false() {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = False;
    new->var = 0;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

/* Creates a propositional variable proposition 
 */
prop_t prop_var(unsigned int var) {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = Var;
    new->var = var;
    new->left = NULL;
    new->right = NULL;
    return (new);
}

/* Creates a negation, conjunction, disjunction, implication, biconditional
 */
prop_t prop_not(prop_t prop) {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = Not;
    new->var = 0;
    new->left = prop;
    new->right = NULL;
    return (new);
}

prop_t prop_and(prop_t left, prop_t right){
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = And;
    new->var = 0;
    new->left = left;
    new->right = right;
    return (new);
}

prop_t prop_or(prop_t left, prop_t right) {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = Or;
    new->var = 0;
    new->left = left;
    new->right = right;
    return (new);
}

prop_t prop_then(prop_t left, prop_t right) {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = Then;
    new->var = 0;
    new->left = left;
    new->right = right;
    return (new);
}

prop_t prop_iff(prop_t left, prop_t right) {
    prop_t new = NULL;
    new = (prop_t)malloc(sizeof(struct _prop_t));
    new->type = Iff;
    new->var = 0;
    new->left = left;
    new->right = right;
    return (new);
}

/* Returns true if the given prop is true/false/var/negation/binary/and/or/then/iff,
 * and false otherwise.
 */
bool is_prop_true(prop_t prop) {
    return (prop != NULL && prop->type == True);
}

bool is_prop_false(prop_t prop) {
    return (prop != NULL && prop->type == False);
}

bool is_prop_var(prop_t prop) {
    return (prop != NULL && prop->type == Var);
}

bool is_prop_not(prop_t prop) {
    return (prop != NULL && prop->type == Not);
}

bool is_prop_binary(prop_t prop) {
    return (prop != NULL &&
           (prop->type == And || prop->type == Or || prop->type == Then || prop->type == Iff));
}

bool is_prop_and(prop_t prop) {
    return (prop != NULL && prop->type == And);
}

bool is_prop_or(prop_t prop) {
    return (prop != NULL && prop->type == Or);
}

bool is_prop_then(prop_t prop) {
    return (prop != NULL && prop->type == Then);
}

bool is_prop_iff(prop_t prop) {
    return (prop != NULL && prop->type == Iff);
}

/* Returns the number of subformulae of the proposition
 */
unsigned int prop_size(prop_t prop) {
    unsigned int size = 0;
    if (is_prop_true(prop) || is_prop_false(prop) || is_prop_var(prop)) {
        size = 1;
    } else if (is_prop_not(prop)) {
        size = 1 + prop_size(get_sub_prop(prop));
    } else if (is_prop_binary(prop)) {
        size = 1 + prop_size(get_left_prop(prop)) + prop_size(get_right_prop(prop)); 
    }
    return (size);
}

/* Returns the "name" of the variable if is_prop_var is true,
   and zero otherwise.
 */
unsigned int get_var(prop_t prop) {
    return (prop->var);
}

static unsigned int max(unsigned int n, unsigned int m) {
    return ((n < m) ? m : n);
}

/* Returns the number of the maximum variable occurring in the proposition
 */
unsigned int get_max_var(prop_t prop) {
    unsigned int max_var = 0;
    if (is_prop_var(prop)) {
        max_var = get_var(prop);
    } else if (is_prop_not(prop)) {
        max_var = get_max_var(get_sub_prop(prop));
    } else if (is_prop_binary(prop)) {
        max_var = max(get_max_var(get_left_prop(prop)), get_max_var(get_right_prop(prop))); 
    }
    return (max_var);
}

/* Returns subproposition if is_prop_negation is true,
   and null otherwise.
 */
prop_t get_sub_prop(prop_t prop) {
    return (prop->left);
}

/* Returns left/right subproposition if is_prop_binary is true,
   and null otherwise.
 */
prop_t get_left_prop(prop_t prop) {
    return (prop->left);
}

prop_t get_right_prop(prop_t prop) {
    return (prop->right);
}

/* Prints the proposition to the given file.
 * Note: Use [prop_dump(prop, stdout)] to print to the screen.
 */
void prop_dump(prop_t prop, FILE *file) {
    if (prop != NULL) {
        switch (prop->type) {
            case True : fprintf(file, "%s", "T");
                        break;
            case False : fprintf(file, "%s", "F");
                         break;
            case Var : fprintf(file, "p%u", get_var(prop));
                       break;
            case Not : fprintf(file, "!(");
                       prop_dump(get_sub_prop(prop), file);
                       fprintf(file, ")");
                       break;
            case And : fprintf(file, "(");
                       prop_dump(get_left_prop(prop), file);
                       fprintf(file, ")&(");
                       prop_dump(get_right_prop(prop), file);
                       fprintf(file, ")");
                       break;
            case Or : fprintf(file, "(");
                       prop_dump(get_left_prop(prop), file);
                       fprintf(file, ")|(");
                       prop_dump(get_right_prop(prop), file);
                       fprintf(file, ")");
                       break;
            case Then : fprintf(file, "(");
                       prop_dump(get_left_prop(prop), file);
                       fprintf(file, ")=>(");
                       prop_dump(get_right_prop(prop), file);
                       fprintf(file, ")");
                       break;
            case Iff : fprintf(file, "(");
                       prop_dump(get_left_prop(prop), file);
                       fprintf(file, ")<=>(");
                       prop_dump(get_right_prop(prop), file);
                       fprintf(file, ")");
                       break;
        }
    }
}

/* Destroys the given proposition, freeing all the allocated resources.
 */
void prop_destroy(prop_t prop) {
    if (prop != NULL) {
        prop_destroy(prop->right);
        prop_destroy(prop->left);
        free(prop);
        prop = NULL;
    }
}


