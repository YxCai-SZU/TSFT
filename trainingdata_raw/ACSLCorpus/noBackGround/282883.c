/*@
    requires a <= b;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_4_impl(int a, int b) {
    //@ assert a <= b;
    //@ assert a + 1 <= b + 1;
    return 1;
}

/*@
    requires a >= b;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_5_impl(int a, int b) {
    //@ assert a >= b;
    //@ assert a - b >= 0;
    return 1;
}

/*@
    requires a >= b;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_6_impl(int a, int b) {
    //@ assert a >= b;
    return 1;
}

/*@
    requires a >= 0 && b >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_7_impl(int a, int b) {
    //@ assert a >= 0 && b >= 0;
    //@ assert a + b >= a;
    return 1;
}

/*@
    requires a >= 0 && b >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_8_impl(int a, int b) {
    //@ assert a >= 0 && b >= 0;
    //@ assert a * b >= 0;
    return 1;
}

/*@
    requires a >= 0 && b >= 0 && c >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_9_impl(int a, int b, int c) {
    //@ assert a >= 0 && b >= 0 && c >= 0;
    //@ assert a + b + c >= a;
    return 1;
}

int main() {
    return 0;
}
