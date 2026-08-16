/*@
    requires a > 0 && b > 0;
    ensures \result == 0;
    ensures a * b < a * (b + 1);
*/
int non_linear_arith_example18(int a, int b) {
    //@ assert ((a) > 0 && (b) > 0);
    //@ assert a * b < a * (b + 1);
    return 0;
}
