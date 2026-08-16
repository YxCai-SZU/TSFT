/*@
requires n > 0 && n < 100;
ensures \result > n;
ensures \result < 101;
*/
int assert_calc_transitivity(int n) {
    //@ assert n + 1 > n;
    //@ assert n + 1 < 101;
    return n + 1;
}

/*@
requires x < y && y < x + 10;
ensures \result == 1;
*/
int assert_complex_transitivity(int x, int y) {
    //@ assert x < y;
    //@ assert y < x + 10;
    return 1;
}

/*@
requires x < y && y < x + 10 && x > 0 && y > 0;
ensures \result == 1;
*/
int assert_multiple_transitivities(int x, int y) {
    //@ assert x < y;
    //@ assert y < x + 10;
    //@ assert x + 1 < y + 1;
    //@ assert y + 1 < x + 11;
    return 1;
}

int main() {
    return 0;
}
