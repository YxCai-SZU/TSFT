/*@
predicate is_nonnegative(integer n) = n >= 0;
predicate is_less_than_ten(integer n) = n < 10;
predicate is_in_range(integer n) = 0 <= n && n < 10;

logic integer difference(integer a, integer b) = a - b;

lemma lemma_no_abs_difference: \forall integer a, b; a >= b && b >= 0 ==> difference(a,b) >= 0;
lemma lemma_repeating_value: \forall integer n; n >= 0 && n < 10 ==> n < 10;
lemma lemma_triangle_inequality: \forall integer n; n > 0 && n < 10 ==> is_in_range(n);
lemma lemma_abs_triangular: \forall integer a, b; a >= b && b >= 0 && a < 10 && b < 10 ==> difference(a,b) >= 0 && difference(a,b) < 10;
*/

void main() {
    //@ assert \true;
}
