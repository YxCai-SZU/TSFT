/*@
    requires a > 0 && b > 0 && c > 0;
    ensures \result == (a * b) / c;
    assigns \nothing;
*/
int non_linear_arith_example(int a, int b, int c) {
    //@ assert a > 0;
    //@ assert b > 0;
    //@ assert c > 0;
    //@ assert (a * b) / c == (a * b) / c;
    return (a * b) / c;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
