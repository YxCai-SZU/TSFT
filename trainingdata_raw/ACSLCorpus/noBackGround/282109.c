/*@
    requires n > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_6(int n) {
    //@ assert n < n + 1;
    //@ assert n < n + 2;
    return 0;
}

/*@
    requires n > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_7(int n) {
    //@ assert n < n * 2;
    //@ assert n < n * 2 + 1;
    return 0;
}

/*@
    requires n > 0;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_8(int n) {
    //@ assert n < n * 2;
    //@ assert n < n * 3;
    //@ assert n < n * 3 + 1;
    return 0;
}

int main() {
    return 0;
}
