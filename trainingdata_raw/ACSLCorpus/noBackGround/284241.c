/*@
    requires a < b && b < c;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_7_impl(int a, int b, int c) {
    //@ assert a < c;
    return 0;
}

/*@
    requires d > e && e > f;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_8_impl(int d, int e, int f) {
    //@ assert d > f;
    return 0;
}

/*@
    requires a < b && b < c && d > e && e > f;
    ensures \result == 0;
    assigns \nothing;
*/
int combined_example_impl(int a, int b, int c, int d, int e, int f) {
    calc_example_7_impl(a, b, c);
    calc_example_8_impl(d, e, f);
    return 0;
}

/*@
    requires a < b && b < c && d > e && e > f;
    ensures \result == 0;
    assigns \nothing;
*/
int combined_example_2_impl(int a, int b, int c, int d, int e, int f) {
    //@ assert a < c;
    //@ assert d > f;
    return 0;
}

/*@
    requires a < b && b < c && d > e && e > f;
    ensures \result == 0;
    assigns \nothing;
*/
int combined_example_3_impl(int a, int b, int c, int d, int e, int f) {
    //@ assert a < c;
    //@ assert d > f;
    return 0;
}

/*@
    requires a < b && b < c && d > e && e > f;
    ensures \result == 0;
    assigns \nothing;
*/
int combined_example_4_impl(int a, int b, int c, int d, int e, int f) {
    //@ assert a < c;
    //@ assert d > f;
    return 0;
}

int main() {
    return 0;
}
