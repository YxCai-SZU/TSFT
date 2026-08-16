/*@
predicate is_even(integer i) = i % 2 == 0;

lemma lemma_even_f:
    \forall integer i; is_even(i) ==> i % 2 == 0;

lemma test_even_f:
    \forall integer i; is_even(i) ==> i % 2 == 0;
*/

/*@
    requires is_even(i);
    ensures \result == 0;
*/
int check_even(int i) {
    //@ assert is_even(i);
    return i % 2;
}
