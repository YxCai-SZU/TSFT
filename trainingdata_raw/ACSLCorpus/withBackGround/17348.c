/*@
predicate complex_condition(integer a, integer b) =
    a > b * b && a < b * b * b;

lemma complex_condition_proof:
    !complex_condition(10, 2);

lemma complex_condition_noproof:
    !complex_condition(10, 2) ==> \true;

lemma complex_condition_chain:
    10 > 2 * 2 && 10 < 2 * 2 * 2 ==> complex_condition(10, 2);

lemma complex_condition_chain_noproof:
    10 > 2 * 2 && 10 < 2 * 2 * 2 && complex_condition(10, 2) ==> \true;

lemma complex_condition_loop:
    10 > 2 * 2 && 10 < 2 * 2 * 2 ==> complex_condition(10, 2);

lemma complex_condition_loop_noproof:
    10 > 2 * 2 && 10 < 2 * 2 * 2 && complex_condition(10, 2) ==> \true;

lemma assertion_subtraction_inv:
    5 - 5 == 0;

lemma assertion_subtraction:
    5 - 5 == 0;
*/

int main() {
    //@ assert !complex_condition(10, 2);
    return 0;
}
