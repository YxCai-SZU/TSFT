/*@
    predicate seq_eq(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate set_eq(int *set1, int *set2, integer len) =
        \forall integer i; 0 <= i < len ==> set1[i] == set2[i];

    lemma complex_equal:
        \forall int *s1_1, *s1_2, *s2_1, *s2_2, *set1, *set2, integer len;
        seq_eq(s1_1, s1_2, len) &&
        seq_eq(s2_1, s2_2, len) &&
        set_eq(set1, set2, len) ==>
        seq_eq(s1_1, s1_2, len) &&
        set_eq(set1, set2, len);
*/

struct Complex {
    int *s1;
    int *s2;
    int *set;
    int len;
};

/*@
    requires \valid(s1+(0..len-1)) && \valid(s2+(0..len-1)) && \valid(set+(0..len-1));
    requires seq_eq(s1, s2, len);
    requires set_eq(set, set, len);
    ensures seq_eq(s1, s2, len);
    ensures set_eq(set, set, len);
*/
void assert_extensional_equivalence(int *s1, int *s2, int *set, int len) {
    //@ assert seq_eq(s1, s2, len);
    //@ assert set_eq(set, set, len);
}

int main() {
    return 0;
}
