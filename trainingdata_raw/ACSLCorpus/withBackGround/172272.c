/*@
    predicate is_even(integer x) = x % 2 == 0;

    lemma lemma_odd:
        \forall integer x; x % 2 == 1 ==> !is_even(x);
*/

void test() {
    //@ assert !is_even(1);
}
