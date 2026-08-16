/*@
requires a > 0 && b > 0;
ensures \result > 0;
*/
int nonlinear_arithmetic_example_5(int a, int b) {
    //@ assert ((a) > 0) && ((b) > 0);
    //@ assert ((a * b) > 0);
    return a * b;
}

/*@
requires a > 0 && b > 0;
ensures \result > 0;
*/
int nonlinear_arithmetic_example_6(int a, int b) {
    //@ assert ((a) > 0) && ((b) > 0);
    //@ assert ((a * b) > 0);
    return a * b;
}
