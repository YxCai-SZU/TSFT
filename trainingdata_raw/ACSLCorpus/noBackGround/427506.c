/*@
    requires n > 0;
    ensures \result == n;
    assigns \nothing;
*/
int calc_example_6(int n) {
    //@ assert n < n + 1;
    //@ assert n + 1 < n + 2;
    //@ assert n < n + 2;
    return n;
}

/*@
    requires n >= 0;
    ensures \result == n;
    assigns \nothing;
*/
int example_with_calc(int n) {
    //@ assert n < n + 1;
    //@ assert n + 1 < n + 2;
    //@ assert n < n + 2;
    //@ assert n + 2 < n + 3;
    //@ assert n < n + 3;
    return n;
}

int main() {
    int n1 = 5;
    int n2 = 0;
    int result1 = calc_example_6(n1);
    int result2 = example_with_calc(n2);
    return 0;
}
