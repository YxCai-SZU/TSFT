/*@
    predicate non_negative(integer a, integer b) = a >= 0 && b >= 0;
    predicate mul_le(integer a, integer b) = a * b <= a + b * a;
    predicate mul_zero(integer x, integer y) = x * y == 0;
    predicate zero_or(integer x, integer y) = x == 0 || y == 0;
*/

/*@
    requires non_negative(a, b);
    ensures mul_le(a, b);
    assigns \nothing;
*/
void non_linear_arith_example(int a, int b) {
    //@ assert mul_le(a, b);
}

/*@
    lemma lemma_mul_is_idempotent:
        \forall integer x, y; non_negative(x, y) && mul_zero(x, y) ==> zero_or(x, y);
*/
