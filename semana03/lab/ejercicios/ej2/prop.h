#ifndef PROP_H
#define PROP_H

#include <stdio.h>
#include <stdbool.h>

/* prop_t is a pointer to a structure.
 * Note: The definition of the structure should be in [prop.c], not here.
 */
typedef struct _prop_t *prop_t;

/* Creates the true/false proposition 
 */
prop_t prop_true();
prop_t prop_false();

/* Creates a propositional variable proposition 
 */
prop_t prop_var(unsigned int var);

/* Creates a negation, conjunction, disjunction, implication, biconditional
 */
prop_t prop_not(prop_t prop);
prop_t prop_and(prop_t left, prop_t right);
prop_t prop_or(prop_t left, prop_t right);
prop_t prop_then(prop_t left, prop_t right);
prop_t prop_iff(prop_t left, prop_t right);

/* Returns true if the given prop is true/false/var/negation/binary/and/or/then/iff,
 * and false otherwise.
 */
bool is_prop_true(prop_t prop);
bool is_prop_false(prop_t prop);
bool is_prop_var(prop_t prop);
bool is_prop_not(prop_t prop);
bool is_prop_binary(prop_t prop);
bool is_prop_and(prop_t prop);
bool is_prop_or(prop_t prop);
bool is_prop_then(prop_t prop);
bool is_prop_iff(prop_t prop);

/* Returns the number of subformulae of the proposition
 */
unsigned int prop_size(prop_t prop);

/* Returns the name of the variable if is_prop_var is true,
   and zero otherwise.
 */
unsigned int get_var(prop_t prop);

/* Returns the number of the maximum variable occurring in the proposition
 */
unsigned int get_max_var(prop_t prop);

/* Returns subproposition if is_prop_not is true,
   and null otherwise.
 */
prop_t get_sub_prop(prop_t prop);

/* Returns left/right subproposition if is_prop_binary is true,
   and null otherwise.
 */
prop_t get_left_prop(prop_t prop);
prop_t get_right_prop(prop_t prop);

/* Prints the proposition to the given file.
 * Note: Use [prop_dump(prop, stdout)] to print to the screen.
 */
void prop_dump(prop_t prop, FILE *file);

/* Destroys the given proposition, freeing all the allocated resources.
 */
void prop_destroy(prop_t prop);

#endif
