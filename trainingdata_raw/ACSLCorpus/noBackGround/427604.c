/*@
    requires a < b;
    ensures \result == 1;
*/
int calc_example_v(int a, int b) {
    //@ assert a - 1 < b - 1;
    return 1;
}

/*@
    requires a < b && b < c;
    ensures \result == 1;
*/
int less_than_and_greater_than(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a < c && b < c;
    return 1;
}

/*@
    requires a > b && b > c;
    ensures \result == 1;
*/
int proof_greater_than(int a, int b, int c) {
    //@ assert a > b && b > c;
    //@ assert a > c;
    return 1;
}

/*@
    requires a < b && b < c && c < d;
    ensures \result == 1;
*/
int less_than_and_greater_than_chain(int a, int b, int c, int d) {
    //@ assert a < b && b < c && c < d;
    //@ assert a < d;
    return 1;
}

/*@
    requires a < b && b < c;
    ensures \result == 1;
*/
int strictly_monotonic_chain(int a, int b, int c) {
    //@ assert a < b && b < c;
    //@ assert a < c;
    return 1;
}

int main() {
    return 0;
}
