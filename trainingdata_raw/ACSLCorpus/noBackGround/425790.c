/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    ensures (2 * (x)) == 2 * x;
    ensures ((10) + (y)) == 10 + y;
    ensures ((2) * (y)) == 2 * y;
*/
void verify_fns(int x, int y) {
    //@ assert (2 * (x)) == 2 * x;
    //@ assert ((10) + (y)) == 10 + y;
    //@ assert ((2) * (y)) == 2 * y;
}

/*@
    requires 0 <= x <= 100;
    requires 0 <= y <= 100;
    requires 2 * x <= 200;
    requires 10 + y <= 110;
    requires 2 * y <= 200;
*/
void verify_fns_bounds(int x, int y) {
    //@ assert (2 * (x)) == 2 * x;
    //@ assert (2 * (x)) <= 200;
    //@ assert ((10) + (y)) == 10 + y;
    //@ assert ((10) + (y)) <= 110;
    //@ assert ((2) * (y)) == 2 * y;
    //@ assert ((2) * (y)) <= 200;
}

int main() {
    return 0;
}
