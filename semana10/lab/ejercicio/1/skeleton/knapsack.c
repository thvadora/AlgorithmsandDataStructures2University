#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <assert.h>
#include "item.h"
#include "helpers.h"
#include "knapsack.h"
#include "string.h"
#include "qsort.h"


static value_t max(value_t x, value_t y){
    value_t maxx = 0;
    if(x >= y){
        maxx = x;
    } else {
        maxx = y;
    }
    return maxx;
}

static value_t backtrack0(item_t *items, unsigned int i, weight_t w){
    value_t res;
    if(i == -1){
        res = 0;
    } else if(w == 0){
        res = 0;
    } else if(item_weight(items[i]) > w){
        res = backtrack0(items,i-1,w);
    } else {
        res = max(backtrack0(items,i-1,w), item_value(items[i]) + backtrack0(items,i-1,w - item_weight(items[i])));
    }

    return res;
}

static value_t backtrack1(value_t **dp,item_t *items, value_t amount_items, value_t capacity){
    for(int i = 0; i <= amount_items; i++){
        for(int j = 0; j <= capacity; j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            } else if(item_weight(items[i-1]) > j){
                dp[i][j] = dp[i-1][j];
            } else {
                dp[i][j] = max(item_value(items[i-1]) + dp[i-1][j- item_weight(items[i-1])], dp[i-1][j]);
            }
        }
    }
    return dp[amount_items][capacity];
}



value_t knapsack_backtracking(item_t *items, unsigned int array_length, weight_t max_weight){
    unsigned int n = array_length-1;
    value_t res = backtrack0(items,n,max_weight);
    return res;
}

value_t knapsack_dynamic(item_t *items, unsigned array_length, weight_t max_weight){
    unsigned int n = array_length;
    value_t *dp[n+1];
    for (int i=1; i< n+1 ; i++){
        dp[i] = (value_t *)malloc((max_weight+1) * sizeof(value_t));
    }
    value_t res = backtrack1(dp,items,n,max_weight);
    for (int i = 0; i < n+1; ++i){
        free(dp[i]);
    }
    return res;

}

value_t knapsack_dynamic_selection(item_t *items, bool *coins, unsigned int array_length, weight_t max_weight, bool want_order) {
    value_t amount_items = array_length;
    value_t capacity = max_weight;
    if(want_order) {
        sort(items, amount_items);
    }
    value_t *dps[amount_items + 1];
    for (int i = 0; i < amount_items + 1; i++) {
        dps[i] = (value_t *) malloc((capacity) * sizeof(value_t));
    }
    for (int i = 0; i <= amount_items; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dps[i][j] = 0;
            } else if (item_weight(items[i - 1]) > j) {
                dps[i][j] = dps[i - 1][j];
            } else {
                dps[i][j] = max(item_value(items[i - 1]) + dps[i - 1][j - item_weight(items[i - 1])], dps[i - 1][j]);
            }
        }
    }

    value_t r = amount_items;
    value_t s = max_weight;
    while (dps[r][s] > 0) {
        if (dps[r][s] == dps[r - 1][s]) {
            coins[r - 1] = false;
        } else {
            coins[r - 1] = true;
            s = s - item_weight(items[r - 1]);
        }
        r--;
    }

    value_t res = 0;
    for (int i = 0; i < amount_items; ++i) {
        //printf("%d\n",coins[i]);
        if (coins[i]) {
            res += item_value(items[i]);
        }
    }

    for (int i = 0; i < amount_items + 1; ++i) {
        free(dps[i]);
    }

    return res;

}
