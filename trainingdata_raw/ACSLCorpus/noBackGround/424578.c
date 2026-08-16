/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_x(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
    requires a == b && b == c;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_y(int a, int b, int c) {
    //@ assert a == b;
    //@ assert b == c;
    //@ assert a == c;
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    assigns \nothing;
*/
int example_sub(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    assigns \nothing;
*/
int example_or(int a, int b) {
    //@ assert a <= b;
    return 0;
}

int main() {
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_n_inequality(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
    ensures \result == 0;
    assigns \nothing;
*/
int verify_equality(int a) {
    //@ assert a == a;
    return 0;
}

/*@
    requires a < b;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_strict_inequality(int a, int b) {
    //@ assert a < b;
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_non_strict_inequality(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
    requires a == b && b == c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_equality_chain(int a, int b, int c) {
    //@ assert a == c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_inequality_chain(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

/*@
    requires a < b && b < c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_strict_inequality_chain(int a, int b, int c) {
    //@ assert a < c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_non_strict_inequality_chain(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

/*@
    requires a == b && b == c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_equality_complex(int a, int b, int c) {
    //@ assert a == c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_inequality_complex(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

/*@
    requires a < b && b < c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_strict_inequality_complex(int a, int b, int c) {
    //@ assert a < c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_non_strict_inequality_complex(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

/*@
    requires a == b && b == c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_chain_equality(int a, int b, int c) {
    //@ assert a == c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_chain_inequality(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

/*@
    requires a < b && b < c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_chain_strict_inequality(int a, int b, int c) {
    //@ assert a < c;
    return 0;
}

/*@
    requires a <= b && b <= c;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_chain_non_strict_inequality(int a, int b, int c) {
    //@ assert a <= c;
    return 0;
}

/*@
    ensures \result == 0;
    assigns \nothing;
*/
int verify_loop_equality(int a) {
    //@ assert a == a;
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_loop_inequality(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
    requires a < b;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_loop_strict_inequality(int a, int b) {
    //@ assert a < b;
    return 0;
}

/*@
    requires a <= b;
    ensures \result == 0;
    assigns \nothing;
*/
int verify_loop_non_strict_inequality(int a, int b) {
    //@ assert a <= b;
    return 0;
}
