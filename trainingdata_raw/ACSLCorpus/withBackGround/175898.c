/*@
    predicate a_less_b(integer a, integer b) = a < b;
    predicate a_leq_b(integer a, integer b) = a <= b;
    predicate a_geq_b(integer a, integer b) = a >= b;
*/

/*@
    lemma calc_example_13: \forall integer a, b; a < b ==> a < b + 3;
    lemma calc_example_14: \forall integer a, b; a <= b ==> a <= b + 3;
    lemma calc_example_15: \forall integer a, b; a >= b ==> a >= b - 3;
    lemma calc_example_16: \forall integer a, b; a >= b ==> a >= b - 3;
    lemma calc_example_17: \forall integer a, b; a <= b ==> a <= b + 3;
*/

int main() {
    return 0;
}
