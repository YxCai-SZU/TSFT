/*@
predicate set_ext_eq{L}(int *s1, int *s2, integer n) =
    \forall integer i; 0 <= i < n ==> s1[i] == s2[i];

predicate map_ext_eq{L}(int *k1, int *v1, int *k2, int *v2, integer n) =
    \forall integer i; 0 <= i < n ==> k1[i] == k2[i] && v1[i] == v2[i];

predicate setmap_ext_eq{L}(int *s1, int *m_k1, int *m_v1,
                           int *s2, int *m_k2, int *m_v2, integer n) =
    set_ext_eq(s1, s2, n) && map_ext_eq(m_k1, m_v1, m_k2, m_v2, n);

lemma compare_setmap:
    \forall int *s1, int *m_k1, int *m_v1,
           int *s2, int *m_k2, int *m_v2, integer n;
    setmap_ext_eq(s1, m_k1, m_v1, s2, m_k2, m_v2, n) ==>
    setmap_ext_eq(s1, m_k1, m_v1, s2, m_k2, m_v2, n);

lemma setmap_distinct:
    \forall int *s1, int *m_k1, int *m_v1,
           int *s2, int *m_k2, int *m_v2, integer n;
    set_ext_eq(s1, s2, n) && map_ext_eq(m_k1, m_v1, m_k2, m_v2, n) ==>
    set_ext_eq(s1, s2, n) && map_ext_eq(m_k1, m_v1, m_k2, m_v2, n);

lemma setmap_distinct_in_struct:
    \forall int *s1, int *m_k1, int *m_v1,
           int *s2, int *m_k2, int *m_v2, integer n;
    set_ext_eq(s1, s2, n) && map_ext_eq(m_k1, m_v1, m_k2, m_v2, n) ==>
    setmap_ext_eq(s1, m_k1, m_v1, s2, m_k2, m_v2, n);
*/

struct SetMap {
    int *s;
    int *m_keys;
    int *m_values;
    int size;
};

/*@
requires \valid(sm1) && \valid(sm2);
requires sm1->size == sm2->size;
requires \valid(sm1->s + (0 .. sm1->size-1));
requires \valid(sm2->s + (0 .. sm2->size-1));
requires \valid(sm1->m_keys + (0 .. sm1->size-1));
requires \valid(sm2->m_keys + (0 .. sm2->size-1));
requires \valid(sm1->m_values + (0 .. sm1->size-1));
requires \valid(sm2->m_values + (0 .. sm2->size-1));
requires set_ext_eq(sm1->s, sm2->s, sm1->size);
requires map_ext_eq(sm1->m_keys, sm1->m_values, sm2->m_keys, sm2->m_values, sm1->size);
ensures setmap_ext_eq(sm1->s, sm1->m_keys, sm1->m_values,
                      sm2->s, sm2->m_keys, sm2->m_values, sm1->size);
*/
void compare_set_map(struct SetMap *sm1, struct SetMap *sm2) {
    //@ assert setmap_ext_eq(sm1->s, sm1->m_keys, sm1->m_values, sm2->s, sm2->m_keys, sm2->m_values, sm1->size);
}

/*@
requires \valid(s1 + (0 .. n-1)) && \valid(s2 + (0 .. n-1));
requires \valid(m1_k + (0 .. n-1)) && \valid(m1_v + (0 .. n-1));
requires \valid(m2_k + (0 .. n-1)) && \valid(m2_v + (0 .. n-1));
requires set_ext_eq(s1, s2, n);
requires map_ext_eq(m1_k, m1_v, m2_k, m2_v, n);
ensures set_ext_eq(s1, s2, n) && map_ext_eq(m1_k, m1_v, m2_k, m2_v, n);
*/
void set_map_distinct(int *s1, int *m1_k, int *m1_v,
                      int *s2, int *m2_k, int *m2_v, int n) {
    //@ assert set_ext_eq(s1, s2, n);
    //@ assert map_ext_eq(m1_k, m1_v, m2_k, m2_v, n);
}

/*@
requires \valid(sm1) && \valid(sm2);
requires sm1->size == sm2->size;
requires \valid(sm1->s + (0 .. sm1->size-1));
requires \valid(sm2->s + (0 .. sm2->size-1));
requires \valid(sm1->m_keys + (0 .. sm1->size-1));
requires \valid(sm2->m_keys + (0 .. sm2->size-1));
requires \valid(sm1->m_values + (0 .. sm1->size-1));
requires \valid(sm2->m_values + (0 .. sm2->size-1));
requires set_ext_eq(sm1->s, sm2->s, sm1->size);
requires map_ext_eq(sm1->m_keys, sm1->m_values, sm2->m_keys, sm2->m_values, sm1->size);
ensures setmap_ext_eq(sm1->s, sm1->m_keys, sm1->m_values,
                      sm2->s, sm2->m_keys, sm2->m_values, sm1->size);
*/
void set_map_distinct_in_struct(struct SetMap *sm1, struct SetMap *sm2) {
    //@ assert setmap_ext_eq(sm1->s, sm1->m_keys, sm1->m_values, sm2->s, sm2->m_keys, sm2->m_values, sm1->size);
}

int main() {
    return 0;
}
