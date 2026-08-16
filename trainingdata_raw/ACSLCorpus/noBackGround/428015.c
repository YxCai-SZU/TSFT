/*@
    requires x >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int example_2(int x) {
    //@ assert 2 * x <= 3 * x;
    return 1;
}

/*@
    requires x >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int example_3(int x) {
    //@ assert 2 * x >= x;
    return 1;
}

/*@
    requires x >= 0;
    ensures \result == 1;
    assigns \nothing;
*/
int example_4(int x) {
    //@ assert x - x <= x;
    return 1;
}

int main() {
    return 0;
}
