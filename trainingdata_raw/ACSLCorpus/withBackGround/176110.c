#include <limits.h>

/*@
    predicate is_valid_range(integer n) = 1 <= n <= 10000;
    
    logic integer division_result(integer n, integer divisor) = n / divisor;
*/

/*@
    requires is_valid_range(n);
    ensures \result >= 0;
    ensures \result <= n;
    ensures \result == division_result(n, 3);
    assigns \nothing;
*/
int func(int n)
{
    int quotient;
    int remainder;
    int divisor;
    
    quotient = 0;
    remainder = (n < 0) ? -n : n;
    divisor = 3;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder == n - quotient * divisor;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
    }
    
    if (n < 0)
    {
        quotient = -quotient;
    }
    
    //@ assert quotient == n / 3;
    return quotient;
}
