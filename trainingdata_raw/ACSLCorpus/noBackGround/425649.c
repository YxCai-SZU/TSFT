/*@
    requires x < 5;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_t(int x) {
    //@ assert x < 5;
    //@ assert x + 1 <= 6;
    return 1;
}

/*@
    requires x < 5;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_t2(int x) {
    //@ assert x < 5;
    //@ assert x + 2 <= 7;
    return 1;
}

/*@
    requires x < 5;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_t3(int x) {
    //@ assert x < 5;
    //@ assert x + 3 <= 8;
    return 1;
}

/*@
    requires x < 5;
    ensures \result == 1;
    assigns \nothing;
*/
int calc_example_t4(int x) {
    //@ assert x < 5;
    //@ assert x + 4 <= 9;
    return 1;
}

/*@
    requires x < 5;
    ensures \result == 1;
    assigns \nothing;
*/
int complex_calc(int x) {
    //@ assert x < 5;
    //@ assert x + 1 <= 6;
    //@ assert x + 2 <= 7;
    //@ assert x + 3 <= 8;
    //@ assert x + 4 <= 9;
    return 1;
}

int main() {
    return 0;
}
