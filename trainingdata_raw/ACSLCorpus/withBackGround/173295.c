/*@
    predicate valid_params(integer n, integer a) =
        1 <= n <= 10000 && 0 <= a <= 1000;
*/

/*@
    requires valid_params(n, a);
    ensures \result == ((n % 500 - a) <= 0);
    assigns \nothing;
*/
int func(int n, int a) {
    unsigned int n_unsigned;
    unsigned int remainder;
    int remainder_signed;
    int result;
    
    // Convert to unsigned
    if (n < 0) {
        n_unsigned = (unsigned int)(-n);
    } else {
        n_unsigned = (unsigned int)n;
    }
    
    remainder = n_unsigned;
    
    /*@
        loop invariant 0 <= remainder <= n_unsigned;
        loop invariant remainder == n_unsigned - 500 * ((n_unsigned - remainder) / 500);
        loop assigns remainder;
    */
    while (remainder >= 500) {
        remainder -= 500;
    }
    
    remainder_signed = (int)remainder;
    result = (remainder_signed - a) <= 0;
    
    //@ assert result == ((n % 500 - a) <= 0);
    return result;
}
