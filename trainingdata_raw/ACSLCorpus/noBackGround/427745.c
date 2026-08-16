/*@
    requires n >= 0;
    ensures \result > n - 10;
*/
int calc_example_10(int n) {
    //@ assert n + 10 > n;
    return n + 10;
}

/*@
    requires n >= 0;
    ensures \result > n - 11;
*/
int calc_example_11(int n) {
    //@ assert n + 10 > n;
    return n + 10;
}

/*@
    requires n >= 0;
    ensures \result > n - 12;
*/
int calc_example_12(int n) {
    //@ assert n + 10 > n;
    return n + 10;
}

/*@
    requires n >= 0;
    ensures \result > n - 13;
*/
int calc_example_13(int n) {
    //@ assert n + 10 > n;
    return n + 10;
}

/*@
    requires n >= 0;
    ensures \result > n - 14;
*/
int calc_example_14(int n) {
    //@ assert n + 10 > n;
    return n + 10;
}

int main() {
    return 0;
}
