/*@
    predicate is_ge_10(integer x) = x >= 10;
    predicate is_le_20(integer x) = x <= 20;
    predicate leq(integer a, integer b) = a <= b;

    lemma calc_example_h: \forall integer x; is_ge_10(x) ==> leq(x - 2, x + 3);
    lemma calc_example_i: \forall integer x; is_ge_10(x) ==> leq(x - 3, x + 2);
    lemma calc_example_j: \forall integer x; is_ge_10(x) ==> leq(x - 1, x + 4);
    lemma example_helper: \forall integer x; is_ge_10(x) && is_le_20(x) ==> leq(x - 2, x + 3);
*/

/*@
    requires \valid(out);
    requires is_ge_10(x) && is_le_20(x);
    assigns *out;
    ensures *out == 1;
    ensures leq(x - 2, x + 3);
*/
void example_with_assert(int x, int *out) {
    int result;
    //@ assert is_ge_10(x);
    //@ assert leq(x - 2, x + 3);
    result = 1;
    *out = result;
}
