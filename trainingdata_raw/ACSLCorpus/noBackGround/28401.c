/*@
    requires x == y;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_6_impl(int x, int y) {
    //@ assert x == y;
    //@ assert x + 1 == y + 1;
    return 1;
}

/*@
    requires 3 * x <= y;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_times_3_leq_y_impl(int x, int y) {
    //@ assert 3 * x <= y;
    return 1;
}

/*@
    requires 3 * x <= y;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_times_3_leq_y_by_calc_impl(int x, int y) {
    //@ assert 3 * x <= y;
    return 1;
}

/*@
    requires x <= y;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_leq_y_impl(int x, int y) {
    //@ assert x <= y;
    return 1;
}

/*@
    requires x <= y;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_leq_y_by_calc_impl(int x, int y) {
    //@ assert x <= y;
    return 1;
}

/*@
    requires x <= x + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_leq_x_plus_1_impl(int x) {
    //@ assert x <= x + 1;
    return 1;
}

/*@
    requires x <= x + 1;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_leq_x_plus_1_by_calc_impl(int x) {
    //@ assert x <= x + 1;
    return 1;
}

/*@
    requires x <= x + 2;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_leq_x_plus_2_impl(int x) {
    //@ assert x <= x + 2;
    return 1;
}

/*@
    requires x <= x + 2;
    ensures \result == 1;
    assigns \nothing;
*/
int prove_x_leq_x_plus_2_by_calc_impl(int x) {
    //@ assert x <= x + 2;
    return 1;
}

int main() {
    return 0;
}
