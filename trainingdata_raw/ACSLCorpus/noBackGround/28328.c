/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void calc_example_12(int n, int m) {
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void main_12(int n, int m) {
    calc_example_12(n, m);
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void calc_example_13(int n, int m) {
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void main_13(int n, int m) {
    calc_example_13(n, m);
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void calc_example_14(int n, int m) {
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void main_14(int n, int m) {
    calc_example_14(n, m);
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void calc_example_15(int n, int m) {
    //@ assert 2 * n + 2 == 2 * (n + 1);
    //@ assert 2 * (n + 1) == 2 * m;
}

/*@
    requires ((n) + 1 == (m));
    ensures (2 * (n) + 2 == 2 * (m));
*/
void main_15(int n, int m) {
    calc_example_15(n, m);
}

int main() {
    return 0;
}
