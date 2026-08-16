#include <stdint.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 314 / 100);
    assigns \nothing;
*/
int64_t func(uint64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t two;
    int64_t scale;
    int64_t numerator;
    int64_t quotient;
    int64_t remainder;
    
    // Initialization
    pi_approx = 314;
    two = 2;
    scale = 100;
    
    //@ assert pi_approx == 314;
    //@ assert two == 2;
    //@ assert scale == 100;
    
    numerator = 2 * (int64_t)r * pi_approx;
    quotient = 0;
    remainder = numerator;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 314;
        loop invariant two == 2;
        loop invariant scale == 100;
        loop invariant numerator == 2 * (int64_t)r * pi_approx;
        loop invariant quotient * scale + remainder == numerator;
        loop invariant quotient >= 0;
        loop invariant remainder >= 0;
        loop invariant remainder < numerator + scale;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= scale)
    {
        //@ assert remainder >= scale;
        quotient += 1;
        remainder -= scale;
        //@ assert quotient * scale + remainder == numerator;
    }
    
    //@ assert quotient * scale + remainder == numerator;
    //@ assert quotient == (2 * (r) * 314 / 100);
    
    return quotient;
}
