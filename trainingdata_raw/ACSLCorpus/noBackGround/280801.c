/*@
    requires 1 <= y <= 10;
    requires 1 <= x <= 10;
    ensures \result <= x;
*/
unsigned int verify_div_ordered_by_denominator(unsigned int x, unsigned int y) {
    //@ assert x / y <= x;
    return x / y;
}

/*@
    requires 1 <= y <= 10;
    requires 1 <= x <= 10;
    ensures \result <= 10;
*/
unsigned int verify_div_is_monotonic(unsigned int x, unsigned int y) {
    //@ assert x / y <= 10;
    return x / y;
}

int main() {
    return 0;
}
