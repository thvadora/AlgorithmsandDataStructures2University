#include <stdio.h>
#include <stdlib.h>
#include "prop.h"

static int skip_spaces(FILE * file) {
    int c;
    while ((c = fgetc(file)) == ' ' || c == '\t') {
    }
    return (c);
}

static void match_char(char x, FILE * file) {
    int c = skip_spaces(file);
    if (c != x) {
        fprintf(stderr, "Invalid prop.\n");
        exit(EXIT_FAILURE);
    }    
}

static prop_t prop_from_FILE(FILE *file) {
    prop_t prop = NULL;
    prop_t left = NULL;
    prop_t right = NULL;
    unsigned int n = 0;
    int res = 0;
    int c = skip_spaces(file);
    switch (c) {
        case 'T' : prop = prop_true();
                   break;
        case 'F' : prop = prop_false();	
                   break;
        case 'p' : res = fscanf(file, "%u", &n);
                   if (res != 1) {
                       fprintf(stderr, "Invalid prop.\n");
                       exit(EXIT_FAILURE);
                   }
                   prop = prop_var(n);
                   break;
        case '!' : match_char('(', file);
                   prop = prop_from_FILE(file);
                   match_char(')', file);
                   prop = prop_not(prop);
                   break;
        case '(' : left = prop_from_FILE(file);
                   match_char(')', file);
                   c = skip_spaces(file);
                   switch (c) {
                       case '<' : if (fgetc(file) != '=') {
                                      fprintf(stderr, "Invalid prop.\n");
                                      exit(EXIT_FAILURE);
                                  }
                       case '=' : if (fgetc(file) != '>') {
                                      fprintf(stderr, "Invalid prop.\n");
                                      exit(EXIT_FAILURE);
                                  }
                       case '&' :
                       case '|' : match_char('(', file);
                                  right = prop_from_FILE(file);
                                  match_char(')', file);
                                  break;
                       default : fprintf(stderr, "Invalid prop.\n");
                                 exit(EXIT_FAILURE);
                   }
                   switch (c) {
                       case '<' : prop = prop_iff(left, right);
                                  break;
                       case '=' : prop = prop_then(left, right);
                                  break;
                       case '&' : prop = prop_and(left, right);
                                  break;
                       case '|' : prop = prop_or(left, right);
                                  break;
                   }
    }
    return (prop);
}

prop_t prop_from_file(const char *filepath) {
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
	fprintf(stderr, "File does not exist.\n");
	exit(EXIT_FAILURE);
    }
    prop_t prop = prop_from_FILE(file);
    fclose(file);
    return (prop);
}
