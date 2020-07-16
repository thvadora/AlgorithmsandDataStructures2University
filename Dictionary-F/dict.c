#include <assert.h>
#include "dict.h"
#include "map.h"
#include <stdlib.h>

struct _dict_t {
    map_t map;
    unsigned int length;
};

dict_t dict_empty() {
    dict_t dict = calloc(1, sizeof(struct _dict_t));
    assert(dict != NULL);
    dict->map = map_empty();
    dict->length = 0;
    return (dict);
}

dict_t dict_add(dict_t dict, string_t word, string_t def) {
    assert(dict != NULL);
    assert(word != NULL);
    assert(def != NULL);
    if (!map_contains(dict->map, word)) {
        dict->length++;
    }
    dict->map = map_put(dict->map, word, def);
    return(dict);
}

string_t dict_search(dict_t dict, string_t word) {
    assert(dict != NULL);
    assert(word != NULL);
    string_t def = map_get(dict->map, word);
    return (def);
}

bool dict_exists(dict_t dict, string_t word) {
    assert(dict != NULL);
    assert(word != NULL);
    return (dict_search(dict, word) != NULL);
}

unsigned int dict_length(dict_t dict) {
    assert(dict != NULL);
    return (dict->length);
}

dict_t dict_remove(dict_t dict, string_t word) {
    assert(dict != NULL);
    assert(word != NULL);
    if (map_contains(dict->map, word)) {
        dict->map = map_remove(dict->map, word);
        dict->length--;
    }
    return (dict);
}

dict_t dict_remove_all(dict_t dict) {
    dict = dict_destroy(dict);
    dict = dict_empty();
    return (dict);
}

void dict_dump(dict_t dict, FILE *file) {
    assert(dict != NULL);
    map_dump(dict->map, file);
}

dict_t dict_destroy(dict_t dict) {
    assert(dict != NULL);
    dict->map = map_destroy(dict->map);
    free(dict);
    dict = NULL;
    return (dict);
}
