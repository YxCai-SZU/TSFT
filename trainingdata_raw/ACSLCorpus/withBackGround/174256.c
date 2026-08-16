/*@
    predicate p_le_q(integer p, integer q) = p <= q;
    predicate q_le_r(integer q, integer r) = q <= r;
    predicate p_le_r(integer p, integer r) = p <= r;
    predicate p_eq_q(integer p, integer q) = p == q;
    predicate q_eq_r(integer q, integer r) = q == r;
    predicate p_eq_r(integer p, integer r) = p == r;

    lemma calc_mixed_example_1: \forall integer p, q, r; p == q && q <= r ==> p <= r;
    lemma calc_mixed_example_2: \forall integer p, q, r; p <= q && q <= r ==> p <= r;
    lemma calc_mixed_example_3: \forall integer p, q, r; p <= q && q == r ==> p <= r;
    lemma calc_mixed_example_4: \forall integer p, q, r; p == q && q == r ==> p == r;
    lemma nontrivial_property: \forall integer p, q, r; p <= q && q <= r ==> p <= r;
*/

/*@
    requires p == q;
    requires q <= r;
    ensures \result == 0;
    ensures p <= r;
*/
int calc_mixed_example_1(int p, int q, int r) {
    //@ assert p == q;
    //@ assert q <= r;
    //@ assert p <= r;
    return 0;
}

/*@
    requires p <= q;
    requires q <= r;
    ensures \result == 0;
    ensures p <= r;
*/
int calc_mixed_example_2(int p, int q, int r) {
    //@ assert p <= q;
    //@ assert q <= r;
    //@ assert p <= r;
    return 0;
}

/*@
    requires p <= q;
    requires q == r;
    ensures \result == 0;
    ensures p <= r;
*/
int calc_mixed_example_3(int p, int q, int r) {
    //@ assert p <= q;
    //@ assert q == r;
    //@ assert p <= r;
    return 0;
}

/*@
    requires p == q;
    requires q == r;
    ensures \result == 0;
    ensures p == r;
*/
int calc_mixed_example_4(int p, int q, int r) {
    //@ assert p == q;
    //@ assert q == r;
    //@ assert p == r;
    return 0;
}

/*@
    requires p <= q;
    requires q <= r;
    ensures \result == 0;
    ensures p <= r;
*/
int nontrivial_property(int p, int q, int r) {
    //@ assert p <= q;
    //@ assert q <= r;
    //@ assert p <= r;
    return 0;
}

int main() {
    return 0;
}
