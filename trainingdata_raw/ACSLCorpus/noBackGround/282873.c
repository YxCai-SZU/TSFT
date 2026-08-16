/*@
    requires x >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_1(int x) {
    //@ assert 2 * (x + 2) == 2 * x + 4;
    //@ assert 2 * x + 4 <= 2 * x + 20;
    return 1;
}

/*@
    requires x >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_2(int x) {
    //@ assert 2 * (x + 2) == 2 * x + 4;
    //@ assert 2 * x + 4 <= 2 * x + 20;
    return 1;
}

int main() {
    int x;
    x = 0;
    calc_example_1(x);
    calc_example_2(x);
    return 0;
}
