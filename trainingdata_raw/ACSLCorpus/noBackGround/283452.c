/*@
    requires 1 <= n && n <= 100;
    ensures \result == ((((n)) * 800) - (((n)) / 15) * 200);
*/
int func(int n) {
    int result;
    int quotient;
    int remainder;
    int divisor;
    
    //@ assert (1 <= (n) && (n) <= 100);
    
    result = n * 800;
    quotient = 0;
    remainder = n;
    divisor = 15;
    
    /*@
        loop invariant 0 <= quotient && quotient <= n / 15;
        loop invariant remainder + quotient * 15 == n;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder + quotient * 15 == n;
    }
    
    //@ assert quotient == n / 15;
    result -= quotient * 200;
    
    //@ assert result == ((((n)) * 800) - (((n)) / 15) * 200);
    return result;
}
