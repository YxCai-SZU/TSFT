/*@
    predicate less_eq(integer a, integer b) = a <= b;
    predicate greater_eq(integer a, integer b) = a >= b;
    predicate eq(integer a, integer b) = a == b;

    lemma complex_inequality: \forall integer x; less_eq(x, x + 5);
    lemma transitive_equality: \forall integer x; eq(x + 1, x + 1);
    lemma compound_inequality: \forall integer x; less_eq(x, x + 3);
    lemma calculation_chain: \forall integer x; 0 <= x <= 100 ==> less_eq(x, 100);
    lemma less_than_and_equal_to: \forall integer x; less_eq(x, x);
    lemma greater_than_or_equal_to: \forall integer x; greater_eq(x, x);
*/

int main() {
    return 0;
}
