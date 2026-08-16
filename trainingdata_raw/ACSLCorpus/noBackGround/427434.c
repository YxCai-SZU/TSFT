/*@
    requires x <= 8 && y <= 8;
    ensures \result <= 1000;
    assigns \nothing;
*/
unsigned int bound_check(unsigned int x, unsigned int y) {
    //@ assert x * y <= 64;
    return x * y;
}

/*@
    requires x <= 8 && y <= 8;
    ensures \result <= 64;
    assigns \nothing;
*/
unsigned int bound_check2(unsigned int x, unsigned int y) {
    //@ assert x * y <= 64;
    return x * y;
}

/*@
    requires 0 <= x && x <= 100 && 0 <= y && y <= 100;
    ensures \result <= 10000;
    assigns \nothing;
*/
unsigned int verify_arith_props(unsigned int x, unsigned int y) {
    //@ assert x * y <= 10000;
    return x * y;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
