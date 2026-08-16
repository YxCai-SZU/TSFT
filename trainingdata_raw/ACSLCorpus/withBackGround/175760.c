#include <stdbool.h>

/*@
    predicate map_contains_key{L}(int *keys, int *values, integer len, integer k) =
        \exists integer i; 0 <= i < len && keys[i] == k;

    predicate map_dom_subset_of{L}(int *keys1, integer len1, int *keys2, integer len2) =
        \forall integer i; 0 <= i < len1 ==> map_contains_key(keys2, (int *)0, len2, keys1[i]);

    predicate map_dom_disjoint{L}(int *keys1, integer len1, int *keys2, integer len2) =
        \forall integer i; 0 <= i < len1 ==> !map_contains_key(keys2, (int *)0, len2, keys1[i]);

    predicate map_equal{L}(int *keys1, int *values1, integer len1,
                          int *keys2, int *values2, integer len2) =
        len1 == len2 &&
        \forall integer i; 0 <= i < len1 ==> 
            keys1[i] == keys2[i] && values1[i] == values2[i];

    lemma map_domain_inclusion:
        \forall int *keys1, *keys2, *values1, *values2;
        \forall integer len1, len2;
        map_dom_subset_of(keys2, len2, keys1, len1) ==>
        (\forall integer k; map_contains_key(keys2, values2, len2, k) ==> 
         map_contains_key(keys1, values1, len1, k));
*/

void test_map_insert(void) {
    int keys[1];
    int values[1];
    int len = 0;
    
    keys[0] = 1;
    values[0] = 1;
    len = 1;
    
    //@ assert map_contains_key(&keys[0], &values[0], len, 1);
}

void test_map_remove(void) {
    int keys[1] = {1};
    int values[1] = {1};
    int len = 1;
    
    len = 0;
    
    //@ assert !map_contains_key(&keys[0], &values[0], len, 1);
}

void test_map_len(void) {
    int keys[2];
    int values[2];
    int len = 0;
    
    //@ assert len == 0;
    
    keys[0] = 1;
    values[0] = 1;
    len = 1;
    //@ assert len == 1;
    
    keys[1] = 2;
    values[1] = 2;
    len = 2;
    //@ assert len == 2;
}

void test_map_subset_of(void) {
    int keys1[2] = {1, 2};
    int values1[2] = {1, 2};
    int len1 = 2;
    
    int keys2[3] = {1, 2, 3};
    int values2[3] = {1, 2, 3};
    int len2 = 3;
    
    //@ assert map_dom_subset_of(&keys1[0], len1, &keys2[0], len2);
}

void test_map_choose(void) {
    int keys[2] = {1, 2};
    int values[2] = {1, 2};
    int len = 2;
    
    //@ assert len > 0;
    
    int k = keys[0];
    //@ assert map_contains_key(&keys[0], &values[0], len, k);
}

void test_map_disjoint(void) {
    int keys1[2] = {1, 2};
    int values1[2] = {1, 2};
    int len1 = 2;
    
    int keys2[2] = {3, 4};
    int values2[2] = {3, 4};
    int len2 = 2;
    
    //@ assert map_dom_disjoint(&keys1[0], len1, &keys2[0], len2);
}

void test_map_equality(void) {
    int keys1[2] = {1, 2};
    int values1[2] = {1, 2};
    int len1 = 2;
    
    int keys2[2] = {1, 2};
    int values2[2] = {1, 2};
    int len2 = 2;
    
    //@ assert map_equal(&keys1[0], &values1[0], len1, &keys2[0], &values2[0], len2);
}
