#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer scaled_pi(integer r) = 2 * 314159 * r / 100000;
    
    lemma division_property: 
        \forall integer r; valid_range(r) ==> 2 * 314159 * 1 <= 2 * 314159 * r <= 2 * 314159 * 100;
*/

/*@
    requires valid_range(r);
    ensures \result == scaled_pi(r);
*/
int64_t func(int64_t r)
{
    int64_t pi;
    int64_t two;
    int64_t scale_factor;
    int64_t numerator;
    int64_t quotient;
    int64_t remainder;
    
    pi = 314159;
    two = 2;
    scale_factor = 100000;
    
    //@ assert 2 * 314159 * 1 <= 2 * pi * r <= 2 * 314159 * 100;
    numerator = two * pi * r;
    quotient = 0;
    remainder = numerator;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi == 314159;
        loop invariant two == 2;
        loop invariant scale_factor == 100000;
        loop invariant numerator == two * pi * r;
        loop invariant quotient * scale_factor + remainder == numerator;
        loop invariant 0 <= remainder < scale_factor + numerator;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= scale_factor)
    {
        quotient = quotient + 1;
        remainder = remainder - scale_factor;
    }
    
    return quotient;
}
