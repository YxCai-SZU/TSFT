/*@
    requires x > 1;
    ensures \result > 0;
    assigns \nothing;
*/
int division_by_two_correctness_func(int x) {
    //@ assert x > 0;
    //@ assert x/2 > 0;
    return x / 2;
}

/*@
    requires 1 < x && x < 100;
    ensures \result < 50;
    assigns \nothing;
*/
int division_by_two_monotonic_func(int x) {
    //@ assert x < 100;
    //@ assert x/2 < 50;
    return x / 2;
}

/*@
    requires -100 < x && x < -1;
    ensures \result < 0;
    assigns \nothing;
*/
int division_by_two_monotonic_negative_func(int x) {
    //@ assert x < 0;
    //@ assert x/2 < 0;
    return x / 2;
}

int main() {
    return 0;
}
