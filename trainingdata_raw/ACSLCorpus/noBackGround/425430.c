/*@
    requires a > 0;
    ensures \result > 0;
*/
int calc_example_nonlinear_arith(int a) {
    //@ assert a > 0;
    //@ assert a * a > 0;
    //@ assert a * a + a > 0;
    return a * a + a;
}

int main() {
    return 0;
}
