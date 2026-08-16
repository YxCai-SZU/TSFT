#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * 314159 * r) / 100000;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_scaled;
    int64_t scale_factor;
    int64_t numerator;
    int64_t quotient;
    
    pi_scaled = 314159;
    scale_factor = 100000;
    
    //@ assert pi_scaled == (314159);
    //@ assert scale_factor == (100000);
    
    numerator = 2 * pi_scaled * r;
    quotient = 0;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_scaled == 314159;
        loop invariant scale_factor == 100000;
        loop invariant numerator >= 0;
        loop invariant numerator < scale_factor || quotient * scale_factor + numerator == 2 * pi_scaled * r;
        loop invariant numerator < scale_factor ==> quotient * scale_factor + numerator == 2 * pi_scaled * r;
        loop assigns numerator, quotient;
        loop variant numerator;
    */
    while (numerator >= scale_factor)
    {
        numerator -= scale_factor;
        quotient += 1;
    }
    
    //@ assert quotient == (2 * 314159 * r) / 100000;
    return quotient;
}
