#ifndef EVALUATION_H
#define EVALUATION_H

#include "prop.h"

/* evaluates the proposition in the given line of the truth table
 * assumes array line has the values for all the propositional letters
 * in the proposition
 */
bool eval(prop_t prop, bool line[]); 

/* determines if prop is a tautology
 * needs implementation
 */
bool is_tautology(prop_t prop);


#endif
