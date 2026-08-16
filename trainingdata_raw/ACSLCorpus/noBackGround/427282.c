/*@
requires a < b && b < c;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_1_impl(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a < c;
    return 0;
}

/*@
requires x <= y && y <= z;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_2_impl(int x, int y, int z) {
    //@ assert x <= y && y <= z;
    //@ assert x <= z;
    return 0;
}

/*@
requires a <= b && b <= c;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_3_impl(int a, int b, int c) {
    //@ assert a <= b && b <= c;
    //@ assert a <= c;
    return 0;
}

/*@
requires x >= y && y >= z;
ensures \result == 0;
assigns \nothing;
*/
int calc_example_4_impl(int x, int y, int z) {
    //@ assert x >= y && y >= z;
    //@ assert x >= z;
    return 0;
}

int main() {
    return 0;
}
