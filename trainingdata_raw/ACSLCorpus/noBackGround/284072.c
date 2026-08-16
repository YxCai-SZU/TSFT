/*@
    requires 0 <= x && x <= 1;
    requires 0 <= y && y <= 1;
    requires 0 <= z && z <= 1;
    ensures \result <= 1;
*/
int nonlinear_arith_example(int x, int y, int z) {
    //@ assert (0 <= (x) && (x) <= 1) && (0 <= (y) && (y) <= 1) && (0 <= (z) && (z) <= 1);
    //@ assert x * y <= 1;
    //@ assert x * y * z <= 1;
    return x * y * z;
}
