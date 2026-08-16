#include <stdbool.h>

/*@
    predicate seq_eq{L}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> s1[i] == s2[i];

    predicate seq_ext_eq{L}(int *s1, int *s2, integer len) =
        seq_eq(s1, s2, len);

    lemma seq_ext_eq_implies_eq{L}:
        \forall int *s1, int *s2, integer len;
            seq_ext_eq(s1, s2, len) ==> seq_eq(s1, s2, len);

    lemma seq_ext_eq_with_len_implies_eq{L}:
        \forall int *s1, int *s2, integer len1, integer len2;
            seq_ext_eq(s1, s2, len1) && len1 == len2 ==> seq_eq(s1, s2, len2);
*/

/*@
    requires \valid(s1+(0..len-1)) && \valid(s2+(0..len-1));
    requires seq_ext_eq(s1, s2, len);
    ensures seq_eq(s1, s2, len);
*/
void main_1(int *s1, int *s2, int len) {
    //@ assert seq_ext_eq(s1, s2, len);
    //@ assert seq_eq(s1, s2, len);
}

/*@
    requires \valid(s1+(0..len1-1)) && \valid(s2+(0..len2-1));
    requires seq_ext_eq(s1, s2, len1);
    requires len1 == len2;
    ensures seq_eq(s1, s2, len2);
*/
void main_2(int *s1, int *s2, int len1, int len2) {
    //@ assert seq_ext_eq(s1, s2, len1);
    //@ assert len1 == len2;
    //@ assert seq_eq(s1, s2, len2);
}

struct Foo {
    int *a;
    int a_len;
    int *b;
    int b_len;
};

/*@
    predicate foo_eq{L}(struct Foo f1, struct Foo f2) =
        seq_eq(f1.a, f2.a, f1.a_len) &&
        seq_eq(f1.b, f2.b, f1.b_len);

    predicate foo_ext_eq{L}(struct Foo f1, struct Foo f2) =
        seq_ext_eq(f1.a, f2.a, f1.a_len) &&
        seq_ext_eq(f1.b, f2.b, f1.b_len);

    lemma foo_ext_eq_implies_eq{L}:
        \forall struct Foo f1, struct Foo f2;
            foo_ext_eq(f1, f2) ==> foo_eq(f1, f2);
*/

/*@
    requires \valid(f1.a+(0..f1.a_len-1)) && \valid(f2.a+(0..f2.a_len-1));
    requires \valid(f1.b+(0..f1.b_len-1)) && \valid(f2.b+(0..f2.b_len-1));
    requires seq_ext_eq(f1.a, f2.a, f1.a_len);
    requires seq_ext_eq(f1.b, f2.b, f1.b_len);
    ensures foo_eq(f1, f2);
*/
void main_3(struct Foo f1, struct Foo f2) {
    //@ assert foo_ext_eq(f1, f2);
    //@ assert foo_eq(f1, f2);
}

/*@
    requires \valid(s1+(0..len1-1)) && \valid(s2+(0..len2-1));
    requires seq_ext_eq(s1, s2, len1);
    requires len1 == len2;
    ensures seq_eq(s1, s2, len2);
*/
void main_4(int *s1, int *s2, int len1, int len2) {
    //@ assert seq_ext_eq(s1, s2, len1);
    //@ assert len1 == len2;
    //@ assert seq_eq(s1, s2, len2);
}

/*@
    requires \valid(s1+(0..len1-1)) && \valid(s2+(0..len2-1));
    requires seq_ext_eq(s1, s2, len1);
    requires len1 == len2;
    ensures seq_eq(s1, s2, len2);
*/
void main_5(int *s1, int *s2, int len1, int len2) {
    //@ assert seq_ext_eq(s1, s2, len1);
    //@ assert len1 == len2;
    //@ assert seq_eq(s1, s2, len2);
}

int main() {
    return 0;
}
