/*@
    predicate f(integer i) = \true;

    lemma lemma_even_f:
        \forall integer i; i % 2 == 0 ==> f(i);

    lemma lemma_odd_f:
        \forall integer i; i % 2 != 0 ==> f(i);

    predicate g(integer i, integer j) = \true;

    lemma lemma_g_proves_f:
        \forall integer i, integer j; g(i, j) ==> f(i);

    predicate h(integer i, integer j) = \true;

    lemma lemma_h_proves_f:
        \forall integer i, integer j; h(i, j) ==> f(i);
*/

/*@
    requires \exists integer j; g(i, j);
    ensures f(i);
*/
void test_g_proves_f(int i) {
    //@ assert \exists integer j; g(i, j);
    //@ assert f(i);
}

/*@
    requires \exists integer j; h(i, j);
    ensures f(i);
*/
void test_h_proves_f(int i) {
    //@ assert \exists integer j; h(i, j);
    //@ assert f(i);
}

int main() {
    return 0;
}
