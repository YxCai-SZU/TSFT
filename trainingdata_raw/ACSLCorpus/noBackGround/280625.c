/*@
    requires x == y;
    ensures \result == 0;
*/
int verify_calc_example(int x, int y) {
    //@ assert x == y;
    //@ assert 2 * x == 2 * y;
    return 0;
}

int main() {
    return 0;
}
