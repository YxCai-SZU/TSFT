#include <stdbool.h>

/*@
    predicate valid_range(integer n) = 1 <= n <= 10000;
    
    logic integer remainder_formula(integer n, integer q) = n + 1000 - 1 - q * 1000;
    
    lemma remainder_nonnegative:
        \forall integer n, q; valid_range(n) && 0 <= q && q <= (n + 1000 - 1)/1000 ==> remainder_formula(n, q) >= 0;
*/

/*@
    requires valid_range(n);
    ensures \result >= 0;
    ensures \result < 1000;
    ensures (n + \result) % 1000 == 0;
    assigns \nothing;
*/
int func(int n)
{
    int quotient = 0;
    int remainder = n + 1000 - 1;
    int divisor = 1000;
    
    //@ ghost int original_n = n;
    
    /*@
        loop invariant 1 <= original_n <= 10000;
        loop invariant 0 <= quotient;
        loop invariant 0 <= quotient <= (original_n + 1000 - 1)/1000;
        loop invariant remainder >= 0;
        loop invariant remainder == original_n + 1000 - 1 - quotient * divisor;
        loop invariant divisor == 1000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        //@ assert remainder >= divisor;
        remainder -= divisor;
        quotient += 1;
        //@ assert remainder == original_n + 1000 - 1 - quotient * divisor;
    }
    
    //@ assert remainder < divisor;
    //@ assert remainder >= 0;
    
    int result = quotient * 1000 - n;
    
    //@ assert result >= 0;
    //@ assert result < 1000;
    //@ assert (n + result) % 1000 == 0;
    
    return result;
}
