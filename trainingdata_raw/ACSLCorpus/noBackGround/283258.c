/*@
    requires x < y;
    ensures \result == 1;
*/
int calc_example_1_impl(int x, int y) {
    //@ assert x + 2 < y + 4;
    return 1;
}

/*@
    requires x < y;
    ensures \result == 1;
*/
int calc_example_2_impl(int x, int y) {
    //@ assert x * 2 < y * 2;
    return 1;
}

/*@
    requires x < y && y <= z;
    ensures \result == 1;
*/
int calc_example_3_impl(int x, int y, int z) {
    //@ assert x < z;
    return 1;
}

int main() {
    return 0;
}
