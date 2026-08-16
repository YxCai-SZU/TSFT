/*@
    requires 0 <= x && x <= 8;
    requires 0 <= y && y <= 8;
    ensures \result <= 64;
    ensures \result >= 0;
    ensures \result <= 1000;
    assigns \nothing;
*/
unsigned int multiply_with_bounds(unsigned int x, unsigned int y) {
    //@ assert (0 <= (x) && (x) <= 8 && 0 <= (y) && (y) <= 8);
    //@ assert x * y <= 64;
    //@ assert x * y >= 0;
    //@ assert x * y <= 1000;
    return x * y;
}

/*@
    assigns \nothing;
*/
int main() {
    return 0;
}
