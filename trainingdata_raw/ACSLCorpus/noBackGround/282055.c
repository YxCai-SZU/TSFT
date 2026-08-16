/*@
    requires x <= 8 && y <= 8;
    ensures \result <= 1000;
*/
unsigned int check_bound_check(unsigned int x, unsigned int y) {
    unsigned int result;
    //@ assert x * y <= 64;
    result = x * y;
    //@ assert result <= 1000;
    return result;
}

/*@
    requires y > 0;
    ensures \result * y + x % y == x;
*/
unsigned int check_division(unsigned int x, unsigned int y) {
    unsigned int quotient;
    quotient = x / y;
    //@ assert quotient * y + x % y == x;
    return quotient;
}

/*@
    requires y > 0;
    ensures \result == x % y;
*/
unsigned int check_modulo(unsigned int x, unsigned int y) {
    unsigned int remainder;
    remainder = x % y;
    //@ assert remainder == x % y;
    return remainder;
}

int main() {
    return 0;
}
