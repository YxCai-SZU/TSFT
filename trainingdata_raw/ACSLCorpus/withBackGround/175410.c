/*@
    predicate is_valid_range(integer a, integer b) =
        1 <= a <= 10 && 1 <= b <= 10;

    logic integer safe_mult(integer a, integer b) = a * b;

    lemma mult_bound: \forall integer a, b; is_valid_range(a, b) ==> safe_mult(a, b) <= 100;
*/

/*@
    requires is_valid_range(a, b);
    ensures \result == (a * b) / 2;
    assigns \nothing;
*/
unsigned int func(unsigned int a, unsigned int b) {
    // Variable declarations at top of scope
    unsigned int result;
    unsigned int quotient = 0;
    unsigned int remainder;
    const unsigned int divisor = 2;

    //@ assert is_valid_range(a, b);
    
    // Ensure multiplication does not overflow
    //@ assert a * b <= 100;
    
    result = a * b;
    remainder = result;

    /*@
        loop invariant 1 <= a <= 10;
        loop invariant 1 <= b <= 10;
        loop invariant result == a * b;
        loop invariant quotient <= result / 2;
        loop invariant remainder == result - quotient * 2;
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant result <= 100;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        quotient += 1;
        remainder -= divisor;
    }
    
    return quotient;
}

int main() {
    return 0;
}
