#include <stdbool.h>

#include "counter.h"

counter init(counter c) {
    c = 0;
    return c;
}

counter inc(counter c) {
return c += 1;
}

counter dec(counter c) {
    return c -= 1;
}

bool is_init(counter c) {
/*
    Needs implementation.
*/
    return (c == 0);
}

