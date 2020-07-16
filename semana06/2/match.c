#include <stdio.h>
#include <stdlib.h>

#include "stack.h"
#include "match.h"

static bool left_delimiter(char c) {
    return (c == '(' || c == '[' || c == '{' || c == '<');
}

static bool right_delimiter(char c) {
    return (c == ')' || c == ']' || c == '}' || c == '>');
}

static char match(char c) {
    char m = 'i';
    if (c == '(') {
        m = ')';
    } else if (c == '[') {
        m = ']';
    } else if (c == '{') {
        m = '}';
    } else if (c == '<') {
        m = '>';
    }
    return (m);
}

bool matching_delimiters(FILE * file) {
    stack_tt s = create_stack();
    bool balanced = true;
    char letter;

    empty_stack(s);
    while (!feof(file) && balanced) {
        letter = fgetc(file);
        if (left_delimiter(letter)) {
            push(match(letter), s);
        } else if (right_delimiter(letter)) {
            if (!is_empty_stack(s) && letter == top(s)) {
                pop(s);
            } else {
                balanced = false;
            }
        }
    }
    balanced = balanced && is_empty_stack(s);
    destroy_stack(s);
    return (balanced);
}

