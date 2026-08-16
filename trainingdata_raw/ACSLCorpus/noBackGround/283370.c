/*@
    requires a < b && b < 10 && a > -1000;
    ensures \result == 0;
    assigns \nothing;
*/
int func(int a, int b) {
    //@ assert a < b;
    //@ assert b < 10;
    //@ assert a < 10;
    return 0;
}

/*@
    requires a < b && b < 10 && a > -1000;
    ensures \result == 0;
    assigns \nothing;
*/
int func2(int a, int b) {
    //@ assert a < b;
    //@ assert b < 10;
    //@ assert a < 10;
    return 0;
}

/*@
    requires x + 2 == y;
    ensures \result == 0;
    assigns \nothing;
*/
int calc_example_2(int x, int y) {
    //@ assert x <= y;
    return 0;
}

int main() {
    return 0;
}
