/*@
    requires y != 0;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_division_product(unsigned int x, unsigned int y) {
    //@ assert (x / y) * y + x % y == x;
    return 1;
}

/*@
    requires x <= 8 && y <= 8;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_bounds(unsigned int x, unsigned int y) {
    //@ assert x * y <= 64;
    return 1;
}

/*@
    requires x <= 8 && y <= 8;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_absorption(unsigned int x, unsigned int y) {
    //@ assert x * (y + 1) <= 72;
    return 1;
}

/*@
    requires x <= 8 && y <= 8;
    ensures \result == 1;
    assigns \nothing;
*/
int assert_cancellation(unsigned int x, unsigned int y) {
    //@ assert x * (y - 1) <= x * y;
    return 1;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
