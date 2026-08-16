struct ExtVal {
    int *a;
    int a_len;
    int *b;
    int b_len;
};

/*@
    requires \valid(s1+(0..len1-1)) && \valid(s2+(0..len2-1));
    requires \valid(set1+(0..len3-1)) && \valid(set2+(0..len4-1));
    requires \valid(&v1) && \valid(&v2);
    requires v1.a_len == v2.a_len && v1.b_len == v2.b_len;
    requires (\forall integer i; 0 <= i < (len1) ==> (s1)[i] == (s1)[i]) && (\forall integer i; 0 <= i < (len2) ==> (s2)[i] == (s2)[i]);
    requires ((\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j]) &&
        (\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j])) && ((\forall integer i; 0 <= i < (len4) ==> \exists integer j; 0 <= j < (len4) && (set2)[i] == (set2)[j]) &&
        (\forall integer i; 0 <= i < (len4) ==> \exists integer j; 0 <= j < (len4) && (set2)[i] == (set2)[j]));
    requires (\forall integer i; 0 <= i < (v1.a_len) ==> (v1.a)[i] == (v1.a)[i]) && (\forall integer i; 0 <= i < (v2.a_len) ==> (v2.a)[i] == (v2.a)[i]);
    requires ((\forall integer i; 0 <= i < (v1.b_len) ==> \exists integer j; 0 <= j < (v1.b_len) && (v1.b)[i] == (v1.b)[j]) &&
        (\forall integer i; 0 <= i < (v1.b_len) ==> \exists integer j; 0 <= j < (v1.b_len) && (v1.b)[i] == (v1.b)[j])) && ((\forall integer i; 0 <= i < (v2.b_len) ==> \exists integer j; 0 <= j < (v2.b_len) && (v2.b)[i] == (v2.b)[j]) &&
        (\forall integer i; 0 <= i < (v2.b_len) ==> \exists integer j; 0 <= j < (v2.b_len) && (v2.b)[i] == (v2.b)[j]));
    ensures ((\forall integer i; 0 <= i < ((v1.a_len)) ==> ((v1.a))[i] == ((v1.a))[i]) && (\forall integer i; 0 <= i < ((v2.a_len)) ==> ((v2.a))[i] == ((v2.a))[i]) &&
        ((\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j]) &&
        (\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j])) && ((\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j]) &&
        (\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j])));
*/
void test_extensional_equal(int *s1, int len1, int *s2, int len2,
                           int *set1, int len3, int *set2, int len4,
                           struct ExtVal v1, struct ExtVal v2) {
    //@ assert (\forall integer i; 0 <= i < (len1) ==> (s1)[i] == (s1)[i]);
    //@ assert ((\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j]) &&         (\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j]));
    //@ assert ((\forall integer i; 0 <= i < ((v1.a_len)) ==> ((v1.a))[i] == ((v1.a))[i]) && (\forall integer i; 0 <= i < ((v2.a_len)) ==> ((v2.a))[i] == ((v2.a))[i]) &&         ((\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j]) &&         (\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j])) && ((\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j]) &&         (\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j])));
}

/*@
    requires \valid(s1+(0..len1-1)) && \valid(s2+(0..len2-1));
    requires \valid(set1+(0..len3-1)) && \valid(set2+(0..len4-1));
    requires \valid(&v1) && \valid(&v2);
    requires v1.a_len == v2.a_len && v1.b_len == v2.b_len;
    requires (\forall integer i; 0 <= i < (len1 > len2 ? len1 : len2) ==> ((i) * 2) == ((i) * 2));
    requires (\forall integer i; 0 <= i < (len1) ==> (s1)[i] == (s1)[i]) && (\forall integer i; 0 <= i < (len2) ==> (s2)[i] == (s2)[i]);
    requires ((\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j]) &&
        (\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j])) && ((\forall integer i; 0 <= i < (len4) ==> \exists integer j; 0 <= j < (len4) && (set2)[i] == (set2)[j]) &&
        (\forall integer i; 0 <= i < (len4) ==> \exists integer j; 0 <= j < (len4) && (set2)[i] == (set2)[j]));
    requires (\forall integer i; 0 <= i < (v1.a_len) ==> (v1.a)[i] == (v1.a)[i]) && (\forall integer i; 0 <= i < (v2.a_len) ==> (v2.a)[i] == (v2.a)[i]);
    requires ((\forall integer i; 0 <= i < (v1.b_len) ==> \exists integer j; 0 <= j < (v1.b_len) && (v1.b)[i] == (v1.b)[j]) &&
        (\forall integer i; 0 <= i < (v1.b_len) ==> \exists integer j; 0 <= j < (v1.b_len) && (v1.b)[i] == (v1.b)[j])) && ((\forall integer i; 0 <= i < (v2.b_len) ==> \exists integer j; 0 <= j < (v2.b_len) && (v2.b)[i] == (v2.b)[j]) &&
        (\forall integer i; 0 <= i < (v2.b_len) ==> \exists integer j; 0 <= j < (v2.b_len) && (v2.b)[i] == (v2.b)[j]));
    ensures ((\forall integer i; 0 <= i < ((v1.a_len)) ==> ((v1.a))[i] == ((v1.a))[i]) && (\forall integer i; 0 <= i < ((v2.a_len)) ==> ((v2.a))[i] == ((v2.a))[i]) &&
        ((\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j]) &&
        (\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j])) && ((\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j]) &&
        (\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j])));
*/
void test_extensional_equal_fn(int *s1, int len1, int *s2, int len2,
                              int *set1, int len3, int *set2, int len4,
                              struct ExtVal v1, struct ExtVal v2) {
    //@ assert (\forall integer i; 0 <= i < (len1 > len2 ? len1 : len2) ==> ((i) * 2) == ((i) * 2));
    //@ assert (\forall integer i; 0 <= i < (len1) ==> (s1)[i] == (s1)[i]);
    //@ assert ((\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j]) &&         (\forall integer i; 0 <= i < (len3) ==> \exists integer j; 0 <= j < (len3) && (set1)[i] == (set1)[j]));
    //@ assert ((\forall integer i; 0 <= i < ((v1.a_len)) ==> ((v1.a))[i] == ((v1.a))[i]) && (\forall integer i; 0 <= i < ((v2.a_len)) ==> ((v2.a))[i] == ((v2.a))[i]) &&         ((\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j]) &&         (\forall integer i; 0 <= i < ((v1.b_len)) ==> \exists integer j; 0 <= j < ((v1.b_len)) && ((v1.b))[i] == ((v1.b))[j])) && ((\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j]) &&         (\forall integer i; 0 <= i < ((v2.b_len)) ==> \exists integer j; 0 <= j < ((v2.b_len)) && ((v2.b))[i] == ((v2.b))[j])));
}
