/*@
    requires x >= y && y >= z;
    ensures \result >= z;
*/
int calc_example_10_impl(int x, int y, int z) {
    //@ assert x >= y;
    //@ assert y >= z;
    //@ assert x >= z;
    return x;
}

int main() {
    return 0;
}
