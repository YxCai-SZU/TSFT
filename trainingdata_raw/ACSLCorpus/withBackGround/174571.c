#include <limits.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer pi_approx_const = 31415;
    logic integer scale_const = 10000;
    
    logic integer expected_result(integer r) = 
        (2 * pi_approx_const * r) / scale_const;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int func(int r)
{
    // Variable declarations at scope top
    int pi_approx;
    int scale;
    int numerator;
    int quotient;
    
    pi_approx = 31415;
    scale = 10000;
    numerator = 2 * pi_approx * r;
    quotient = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == pi_approx_const;
        loop invariant scale == scale_const;
        loop invariant numerator >= 0;
        loop invariant numerator == 2 * pi_approx_const * r - quotient * scale_const;
        loop invariant quotient >= 0;
        loop assigns numerator, quotient;
        loop variant numerator;
    */
    while (numerator >= scale)
    {
        numerator -= scale;
        quotient += 1;
    }
    
    //@ assert numerator < scale;
    //@ assert quotient * scale_const + numerator == 2 * pi_approx_const * r;
    //@ assert quotient * scale_const + numerator <= INT_MAX;
    
    return quotient;
}
