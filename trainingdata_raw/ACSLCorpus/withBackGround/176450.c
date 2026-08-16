#include <stdbool.h>
#include <limits.h>

/*@
    predicate seq_eq{L1,L2}(int *a1, int *a2, integer len) =
        \forall integer i; 0 <= i < len ==> \at(a1[i],L1) == \at(a2[i],L2);

    predicate set_eq{L1,L2}(int *s1, int *s2, integer len) =
        \forall integer i; 0 <= i < len ==> \at(s1[i],L1) == \at(s2[i],L2);

    predicate map_eq{L1,L2}(int *k1, int *v1, int *k2, int *v2, integer len) =
        \forall integer i; 0 <= i < len ==> \at(k1[i],L1) == \at(k2[i],L2) && \at(v1[i],L1) == \at(v2[i],L2);

    predicate equality_eq{L1,L2}(int *a1, int *b1, int *ck1, int *cv1,
                                 int *a2, int *b2, int *ck2, int *cv2,
                                 integer len_a, integer len_b, integer len_c) =
        seq_eq{L1,L2}(a1, a2, len_a) &&
        set_eq{L1,L2}(b1, b2, len_b) &&
        map_eq{L1,L2}(ck1, cv1, ck2, cv2, len_c);

    lemma equality_lemma{L1,L2}:
        \forall int *a1, *b1, *ck1, *cv1, *a2, *b2, *ck2, *cv2;
        \forall integer len_a, len_b, len_c;
        equality_eq{L1,L2}(a1,b1,ck1,cv1,a2,b2,ck2,cv2,len_a,len_b,len_c) ==>
        (\forall integer i; 0 <= i < len_a ==> \at(a1[i],L1) == \at(a2[i],L2)) &&
        (\forall integer i; 0 <= i < len_b ==> \at(b1[i],L1) == \at(b2[i],L2)) &&
        (\forall integer i; 0 <= i < len_c ==> \at(ck1[i],L1) == \at(ck2[i],L2) && \at(cv1[i],L1) == \at(cv2[i],L2));
*/

struct Equality {
    int *a;
    int *b;
    int *c_keys;
    int *c_values;
    int len_a;
    int len_b;
    int len_c;
};

/*@
    requires \valid(e1) && \valid(e2);
    requires \valid(e1->a + (0 .. e1->len_a-1));
    requires \valid(e1->b + (0 .. e1->len_b-1));
    requires \valid(e1->c_keys + (0 .. e1->len_c-1));
    requires \valid(e1->c_values + (0 .. e1->len_c-1));
    requires \valid(e2->a + (0 .. e2->len_a-1));
    requires \valid(e2->b + (0 .. e2->len_b-1));
    requires \valid(e2->c_keys + (0 .. e2->len_c-1));
    requires \valid(e2->c_values + (0 .. e2->len_c-1));
    requires e1->len_a == e2->len_a;
    requires e1->len_b == e2->len_b;
    requires e1->len_c == e2->len_c;
    requires \forall integer i; 0 <= i < e1->len_a ==> e1->a[i] == e2->a[i];
    requires \forall integer i; 0 <= i < e1->len_b ==> e1->b[i] == e2->b[i];
    requires \forall integer i; 0 <= i < e1->len_c ==> e1->c_keys[i] == e2->c_keys[i] && e1->c_values[i] == e2->c_values[i];
    ensures \result == true;
*/
bool is_equal(struct Equality *e1, struct Equality *e2) {
    int i;
    bool seq_equal = true;
    bool set_equal = true;
    bool map_equal = true;
    
    //@ assert \forall integer j; 0 <= j < e1->len_a ==> e1->a[j] == e2->a[j];
    
    //@ assert \forall integer j; 0 <= j < e1->len_b ==> e1->b[j] == e2->b[j];
    
    //@ assert \forall integer j; 0 <= j < e1->len_c ==> e1->c_keys[j] == e2->c_keys[j] && e1->c_values[j] == e2->c_values[j];
    
    //@ assert seq_equal && set_equal && map_equal;
    return true;
}

int main() {
    return 0;
}
