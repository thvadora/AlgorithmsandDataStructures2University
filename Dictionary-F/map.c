#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include "map.h"

struct _node_t {
    map_t left;
    map_t right;
    key_t key;
    value_t value;
};

map_t map_empty() {
    return (NULL);
}

static map_t create_node(key_t key, value_t value, map_t left, map_t right) {
    map_t node = NULL;
    node = (map_t)malloc(sizeof(struct _node_t));
    node->key = key;
    node->value = value;
    node->right = right;
    node->left = left;
    return (node);
}

static map_t free_node(map_t node) {
    free(node);
    return (NULL);
}

map_t map_put(map_t map, key_t key, value_t value) {
    assert(key != NULL);
    assert(value != NULL);
    map_t node = map;
    map_t new = NULL;
    if(map != NULL){
        if(key_eq(map->key,key)){
            map->value = value;
        } else if(key_less(map->key,key)){
            map->right = map_put(map->right,key,value);
        } else {
            map->left = map_put(map->left,key,value);
        }
    } else {
        new = create_node(key,value,NULL,NULL);
        node = new;
    }
    return (node);
}

value_t map_get(map_t map, key_t key) {
    assert(key != NULL);
    value_t value = NULL;
    if(map != NULL){
        if(key_eq(map->key,key)){
            value = map->value;
        } else if(key_less(map->key,key)){
            value = map_get(map->right,key);
        } else {
            value = map_get(map->left,key);
        }
    }
    return (value);
}

bool map_contains(map_t map, key_t key) {
    assert(key != NULL);
    bool b = false;
    if(map != NULL){
        if(key_eq(map->key,key)){
            b = true;
        } else if (key_less(map->key,key)){
            b = map_contains(map->right,key);
        } else {
            b = map_contains(map->left,key);
        }
    }
    return b;
}

map_t map_remove(map_t map, key_t key) {
    map_t result = map;
    if (map != NULL) {
        if (key_eq(map->key, key)) {
            if (map->left == NULL) {
                result = map->right;
                map = free_node(map);
            } else {
                map_t father = NULL;
                map_t max = map->left;
                while (max->right != NULL) {
                    father = max;
                    max = max->right;
                }
                if (father == NULL) {
                    max->right = map->right;
                    map = free_node(map);
                    result = max;
                } else {
                    map->key = key_destroy(map->key);
                    map->value = value_destroy(map->value);
                    map->key = max->key;
                    map->value = max->value;
                    father->right = max->left;
                    free(max);
                }
            } 
        } else if(key_less(map->key, key)) {
            map->right = map_remove(map->right, key);
        } else {
            map->left = map_remove(map->left, key);
        }
    }
    return (result);
}

map_t map_destroy(map_t map){
    map_t node = map;
    map_t aux1 = NULL;
    map_t aux2 = NULL;
    if(map != NULL){
        aux1 = map->left;
        aux2 = map->right;
        free(map);
        if(aux1 != NULL){
            aux1 = map_destroy(aux1);
        }
        if(aux2 != NULL){
            aux2 = map_destroy(aux2);
        }
    }
    return node;
}

void map_dump(map_t map, FILE *file) {
    if (map != NULL) {
        map_dump(map->left, file);
        key_dump(map->key, file);
        fprintf(file, ": ");
        value_dump(map->value, file);
        fprintf(file, "\n");
        map_dump(map->right, file);
    }
}
