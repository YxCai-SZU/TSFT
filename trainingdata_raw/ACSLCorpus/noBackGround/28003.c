/*@
requires a <= b;
ensures \result == 0;
assigns \nothing;
*/
int calc_context_example_1_impl(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int calc_context_example_2_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int calc_context_example_3_impl(int a, int b, int c) {
    //@ assert a <= b;
    //@ assert b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires a <= b;
ensures \result == 0;
assigns \nothing;
*/
int calc_context_example_4_impl(int a, int b) {
    //@ assert a <= b;
    return 0;
}

/*@
requires d <= e && e <= f && f <= g;
ensures \result == 0;
assigns \nothing;
*/
int some_complex_proof_impl(int d, int e, int f, int g) {
    //@ assert d <= e;
    //@ assert e <= f;
    //@ assert f <= g;
    //@ assert d <= g;
    return 0;
}

int main() {
    return 0;
}
