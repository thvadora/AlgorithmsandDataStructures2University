/* First, the standard lib includes, alphabetically ordered */
#include <stdio.h>
#include <stdlib.h>

/* Then, this project's includes, alphabetically ordered */
#include "match.h"

static void print_help(char *program_name) {
    /* Print the usage help of this program. */
    printf("Usage: %s <input file path>\n\n"
           "Check if in a given file there is a perfect match between all opening and closing delimiters.\n"
           "\n",
           program_name);
}

static FILE * open_input_file(const char *filepath) {
    /* opens an input file. NULL is returned if requested file does not exist*/
    FILE *file = NULL;
    file = fopen(filepath, "r");
    if (file == NULL) {
        fprintf(stderr, "File does not exist.\n");
        exit(EXIT_FAILURE);
    }
    return (file);
}

static char *parse_filepath(int argc, char *argv[]) {
    /* Parse the filepath given by command line argument. */
    char *result = NULL;

    if (argc < 2) {
        print_help(argv[0]);
        exit(EXIT_FAILURE);
    }

    result = argv[1];

    return (result);
}

int main(int argc, char *argv[]) {
    char *filepath = NULL;
    FILE *file = NULL;

    /* parse the filepath given in command line arguments */
    filepath = parse_filepath(argc, argv);
    
    /* open the input file */
    file = open_input_file(filepath);

    /* call the function for the matching parentheses check */

    if (matching_delimiters(file)) {
        printf("Delimeters match.\n");
    } else {
        printf("Delimeters mismatch.\n");
    }

    fclose(file);
    return (EXIT_SUCCESS);
}
