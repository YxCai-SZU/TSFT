/*@
    predicate is_even(integer x) =
        (x < 0 ==> (x + 2) % 2 == 0) &&
        (x >= 0 ==> x % 2 == 0);

    lemma lemma_is_even:
        \forall integer x;
            is_even(x) <==> (x % 2 == 0 || (x < 0 && (x + 2) % 2 == 0));
*/

void test(void) {
    //@ assert is_even(10);
    //@ assert !is_even(15);
}
