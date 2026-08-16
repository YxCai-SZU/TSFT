/*@
    predicate equal_seq{L}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate equal_map{L}(int *m1_keys, int *m1_vals, int *m2_keys, int *m2_vals, integer len) =
        \forall integer i; 0 <= i < len ==> 
            m1_keys[i] == m2_keys[i] && equal_seq(m1_vals + i*len, m2_vals + i*len, len);

    lemma two_equal_struct{L}:
        \forall int key1, int key2, int *s1, int *s2, integer len;
            key1 == key2 && equal_seq(s1, s2, len) ==> 
            \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    lemma two_equal_map_struct{L}:
        \forall int key1, int key2, int *m1_keys, int *m1_vals, int *m2_keys, int *m2_vals, integer len;
            key1 == key2 && equal_map(m1_keys, m1_vals, m2_keys, m2_vals, len) ==>
            \forall integer i; 0 <= i < len ==> m1_keys[i] == m2_keys[i];
*/

struct TestStruct {
    int key;
    int *s;
    int s_len;
};

struct TestMapStruct {
    int key;
    int *m_keys;
    int *m_vals;
    int map_len;
    int seq_len;
};

/*@
    requires s1->key == s2->key;
    requires s1->s_len == s2->s_len;
    requires \valid(s1->s + (0 .. s1->s_len-1));
    requires \valid(s2->s + (0 .. s2->s_len-1));
    requires \forall integer i; 0 <= i < s1->s_len ==> s1->s[i] == s2->s[i];
    ensures \result == 1;
*/
int two_equal_struct(struct TestStruct *s1, struct TestStruct *s2) {
    //@ assert s1->key == s2->key;
    //@ assert s1->s_len == s2->s_len;
    //@ assert \forall integer i; 0 <= i < s1->s_len ==> s1->s[i] == s2->s[i];
    return 1;
}

/*@
    requires m1->key == m2->key;
    requires m1->map_len == m2->map_len;
    requires m1->seq_len == m2->seq_len;
    requires \valid(m1->m_keys + (0 .. m1->map_len-1));
    requires \valid(m2->m_keys + (0 .. m2->map_len-1));
    requires \valid(m1->m_vals + (0 .. m1->map_len*m1->seq_len-1));
    requires \valid(m2->m_vals + (0 .. m2->map_len*m2->seq_len-1));
    requires \forall integer i; 0 <= i < m1->map_len ==> m1->m_keys[i] == m2->m_keys[i];
    requires \forall integer i,j; 0 <= i < m1->map_len && 0 <= j < m1->seq_len ==> 
                m1->m_vals[i*m1->seq_len + j] == m2->m_vals[i*m2->seq_len + j];
    ensures \result == 1;
*/
int two_equal_map_struct(struct TestMapStruct *m1, struct TestMapStruct *m2) {
    //@ assert m1->key == m2->key;
    //@ assert \forall integer i; 0 <= i < m1->map_len ==> m1->m_keys[i] == m2->m_keys[i];
    return 1;
}

int main() {
    return 0;
}
