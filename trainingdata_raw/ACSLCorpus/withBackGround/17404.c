/*@
    predicate non_negative(integer x) = x >= 0;
    predicate non_negative_pair(integer x, integer y) = x >= 0 && y >= 0;
    predicate negative(integer x) = x <= -1;

    logic integer abs(integer x) = (x >= 0) ? x : -x;

    lemma calc_example_1: \forall integer x; non_negative(x) ==> x <= x + 5;
    lemma calc_example_2: \forall integer x, integer y; non_negative_pair(x, y) ==> x <= x + y;
    lemma calc_example_3: \forall integer x; non_negative(x) ==> x <= x + 10;
    lemma calc_example_abs: \forall integer x; negative(x) ==> abs(x) > 0;
*/

/*@
    requires \true;
    assigns \nothing;
    ensures \true;
*/
void main(void) {
    // No implementation needed for proof functions
}

/*@
    requires x >= 0;
    assigns \nothing;
    ensures \result == 1;
*/
int calc_example_1_impl(int x) {
    //@ assert x <= x + 5;
    return 1;
}

/*@
    requires x >= 0 && y >= 0;
    assigns \nothing;
    ensures \result == 1;
*/
int calc_example_2_impl(int x, int y) {
    //@ assert x <= x + y;
    return 1;
}

/*@
    requires x >= 0;
    assigns \nothing;
    ensures \result == 1;
*/
int calc_example_3_impl(int x) {
    //@ assert x <= x + 10;
    return 1;
}

/*@
    requires x <= -1;
    assigns \nothing;
    ensures \result == 1;
*/
int calc_example_abs_impl(int x) {
    //@ assert (x >= 0 ? x : -x) > 0;
    return 1;
}
