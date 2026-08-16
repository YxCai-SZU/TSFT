/*@
    predicate is_even(integer i) = \true;
    predicate f(integer i) = \true;

    lemma lemma_even_f:
        \forall integer i; is_even(i) ==> f(i);
*/

/*@
    requires \true;
    ensures \forall integer i; is_even(i) ==> f(i);
*/
void test_even_f(void) {
    //@ assert \forall integer i; is_even(i) ==> f(i);
}
