/*@
    predicate positive(integer v) = v > 0;
    predicate sum_le_100(integer a, integer b) = a + b <= 100;
    predicate in_range(integer v) = 1 <= v && v <= 100;
*/

/*@
    lemma calc_example_x: \forall integer x, y;
        positive(x) && positive(y) && sum_le_100(x, y) ==> x <= 100;
*/

/*@
    lemma func_helper_x: \forall integer x;
        in_range(x) ==> x <= 100;
*/

void main() {
    //@ assert \true;
}
