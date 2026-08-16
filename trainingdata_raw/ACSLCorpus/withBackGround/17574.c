#include <stdbool.h>

/*@
    predicate seq_field_ext_equal{L}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate set_field_ext_equal{L}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate map_field_ext_equal{L}(int *keys1, int *values1, int *keys2, int *values2, integer len) =
        \forall integer i; 0 <= i < len ==> keys1[i] == keys2[i] && values1[i] == values2[i];

    lemma seq_field_equality:
        \forall int *s1, *s2, integer len;
        seq_field_ext_equal(s1, s2, len) ==> 
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    lemma set_field_equality:
        \forall int *s1, *s2, integer len;
        set_field_ext_equal(s1, s2, len) ==> 
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    lemma map_field_equality:
        \forall int *keys1, *values1, *keys2, *values2, integer len;
        map_field_ext_equal(keys1, values1, keys2, values2, len) ==> 
        \forall integer i; 0 <= i < len ==> keys1[i] == keys2[i] && values1[i] == values2[i];
*/

struct SeqField {
    int *s;
    int len;
};

struct SetField {
    int *s;
    int len;
};

struct MapField {
    int *keys;
    int *values;
    int len;
};

/*@
    requires \valid(s1->s + (0 .. s1->len-1));
    requires \valid(s2->s + (0 .. s2->len-1));
    requires s1->len == s2->len;
    requires seq_field_ext_equal(s1->s, s2->s, s1->len);
    ensures \result == true;
*/
bool seq_field_ext_equal_proof(struct SeqField *s1, struct SeqField *s2) {
    //@ assert seq_field_ext_equal(s1->s, s2->s, s1->len);
    return true;
}

/*@
    requires \valid(s1->s + (0 .. s1->len-1));
    requires \valid(s2->s + (0 .. s2->len-1));
    requires s1->len == s2->len;
    requires set_field_ext_equal(s1->s, s2->s, s1->len);
    ensures \result == true;
*/
bool set_field_ext_equal_proof(struct SetField *s1, struct SetField *s2) {
    //@ assert set_field_ext_equal(s1->s, s2->s, s1->len);
    return true;
}

/*@
    requires \valid(m1->keys + (0 .. m1->len-1));
    requires \valid(m1->values + (0 .. m1->len-1));
    requires \valid(m2->keys + (0 .. m2->len-1));
    requires \valid(m2->values + (0 .. m2->len-1));
    requires m1->len == m2->len;
    requires map_field_ext_equal(m1->keys, m1->values, m2->keys, m2->values, m1->len);
    ensures \result == true;
*/
bool map_field_ext_equal_proof(struct MapField *m1, struct MapField *m2) {
    //@ assert map_field_ext_equal(m1->keys, m1->values, m2->keys, m2->values, m1->len);
    return true;
}

int main() {
    return 0;
}
