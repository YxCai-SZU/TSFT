/*@
    requires (0 <= (x) && (x) <= 8 &&
        0 <= (y) && (y) <= 8 &&
        0 <= (z) && (z) <= 100);
    ensures \result == (((x) * (y)) <= z);
*/
int non_linear_arith_example(unsigned int x, unsigned int y, unsigned int z) {
    //@ assert ((x) * (y)) <= 64;
    return (x * y) <= z;
}
