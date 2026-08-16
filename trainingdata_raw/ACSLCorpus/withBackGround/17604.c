/*@
    predicate valid_range(integer n) = 1 <= n <= 1000;
    
    logic integer division_result(integer n, integer d) = n / d;
    
    predicate division_invariant(integer n, integer q, integer r, integer d) =
        0 <= q <= division_result(n, d) &&
        0 <= r <= n &&
        r == n - q * d;
*/

/*@
    requires valid_range(n);
    ensures \result == division_result(n, 3);
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n;
    const int divisor = 3;
    
    /*@
        loop invariant division_invariant(n, quotient, remainder, divisor);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder == n - quotient * divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert remainder == n - quotient * divisor;
    }
    
    //@ assert remainder == n - quotient * divisor;
    //@ assert 0 <= remainder < 3;
    
    return quotient;
}
