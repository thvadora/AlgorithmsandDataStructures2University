#include "prop.h"
#include "evaluation.h"


bool eval(prop_t prop, bool line[]) {
/* evaluates the proposition in the given line of the truth table
 * assumes array line has the values for all the propositional letters
 * in the proposition
 */
    bool res = false;
    if (is_prop_true(prop)) {
        res = true;
    } else if (is_prop_false(prop)) {
        res = false;
    } else if (is_prop_var(prop)) {
        res = line[get_var(prop)];
    } else if (is_prop_not(prop)) {
        res = !eval(get_sub_prop(prop),line);
    } else if (is_prop_and(prop)) {
        res = eval(get_left_prop(prop),line) && eval(get_right_prop(prop),line);
    } else if (is_prop_or(prop)) {
        res = eval(get_left_prop(prop),line) || eval(get_right_prop(prop),line);
    } else if (is_prop_then(prop)) {
        res = !eval(get_left_prop(prop),line) || eval(get_right_prop(prop),line);
    } else if (is_prop_iff(prop)) {
        res = eval(get_left_prop(prop),line) == eval(get_right_prop(prop),line);
    } 
    return (res);
}

static void next_line(bool line[], unsigned int length) {
    bool change = true;
    line[length-1] = ((line[length-1] == true) ? false : true);
    for (int i = length-2; i >= 0 ; i--){
        if ((line[i+1] == false) && change){
            line[i] = ((line[i] == true) ? false : true);
        } else{
            change = false;
        }
    }
}


static void mk_fst_line(bool line[], unsigned int length) {
    for (unsigned int i = 0; i < length; ++i){
        line[i] = false;
    }
}

static bool last_line(bool line[], unsigned int length) {
    bool b = true;
    for (unsigned int i = 0; i < length; ++i){
        b = b && !line[i];
    }
return b;
}



bool is_tautology(prop_t prop){
  unsigned int length = (get_max_var(prop) == 0 ? 1 : get_max_var(prop));
  bool line[length];
  bool tau = true;
  mk_fst_line(line,length);
  tau = tau && eval(prop,line);
  next_line(line,length);
  while(tau && !last_line(line,length)){
    tau = tau && eval(prop,line);
    next_line(line,length);
  }
return tau;
}


