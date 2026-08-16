/*@
predicate a_le_b_plus_one(integer a, integer b) = a <= b + 1;
predicate a_eq_b_plus_zero(integer a, integer b) = a == b + 0;

lemma calc_example_11: \forall integer a, b; a <= b ==> a_le_b_plus_one(a, b);
lemma calc_example_12: \forall integer a, b; a == b ==> a_eq_b_plus_zero(a, b);
lemma calc_example_13: \forall integer a, b; a <= b ==> a_le_b_plus_one(a, b);
lemma calc_example_14: \forall integer a, b; a == b ==> a_eq_b_plus_zero(a, b);
lemma calc_example_15: \forall integer a, b; a <= b ==> a_le_b_plus_one(a, b);
lemma calc_example_16: \forall integer a, b; a == b ==> a_eq_b_plus_zero(a, b);
*/

int main() {
    //@ assert \true;
    return 0;
}
