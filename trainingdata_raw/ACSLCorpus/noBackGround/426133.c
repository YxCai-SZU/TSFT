/*@
    requires x > 4;
    ensures \result == 0;
    assigns \nothing;
*/
int assert_x_greater_than_4_proof(int x) {
    //@ assert x > 4;
    return 0;
}

/*@
    requires x == 5;
    ensures \result == 0;
    assigns \nothing;
*/
int assert_x_equal_5_proof(int x) {
    //@ assert x == 5;
    return 0;
}

/*@
    requires x < 9;
    ensures \result == 0;
    assigns \nothing;
*/
int assert_x_less_than_9_proof(int x) {
    //@ assert x < 9;
    return 0;
}

/*@
    requires x > 4 && x == 5 && x < 9;
    ensures \result == 0;
    assigns \nothing;
*/
int assert_all_conditions_proof(int x) {
    //@ assert x == 5;
    return 0;
}

int main() {
    return 0;
}
