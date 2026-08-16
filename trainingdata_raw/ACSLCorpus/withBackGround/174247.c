/*@
predicate le(integer a, integer b) = a <= b;
predicate ge(integer a, integer b) = a >= b;
predicate eq(integer a, integer b) = a == b;

lemma calc_example_7: \forall integer a, b; a <= b ==> a * 2 <= b * 2;
lemma intermediate_example_3: \forall integer a, b, c; a == b && b == c ==> a == c;
lemma less_than_example_4: \forall integer a, b, c; a <= b && b <= c ==> a <= c;
lemma greater_than_example_5: \forall integer a, b, c; a >= b && b >= c ==> a >= c;
lemma less_than_or_equal_example_6: \forall integer a, b, c; a <= b && b <= c ==> a <= c;
lemma greater_than_or_equal_example_8: \forall integer a, b, c; a >= b && b >= c ==> a >= c;
lemma complex_example_9: \forall integer a, b, c, d; a <= b && b <= c && c <= d ==> a <= d;
lemma very_complex_example_10: \forall integer a, b, c, d, e, f; a <= b && b <= c && c <= d && d <= e && e <= f ==> a <= f;
*/

int main() {
    return 0;
}
