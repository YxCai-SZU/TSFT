#include <stdint.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer calculate_result(integer r) = 
        (2 * r * 314159) / 100000;
*/

/*@
    requires valid_range(r);
    ensures \result == calculate_result(r);
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    // Variable declarations at top of scope
    int64_t pi_approx;
    int64_t two_r;
    int64_t product;
    int64_t divisor;
    int64_t quotient;
    int64_t remainder;
    
    pi_approx = 314159;
    two_r = 2 * r;
    
    //@ assert 2 * 1 <= two_r <= 2 * 100;
    
    product = two_r * pi_approx;
    divisor = 100000;
    quotient = 0;
    remainder = product;
    
    //@ assert 0 <= quotient * divisor + remainder <= 2 * 100 * 314159;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant two_r == 2 * r;
        loop invariant pi_approx == 314159;
        loop invariant product == two_r * pi_approx;
        loop invariant divisor == 100000;
        loop invariant quotient * divisor + remainder == product;
        loop invariant 0 <= remainder < divisor + product;
        loop invariant 0 <= quotient * divisor + remainder <= 2 * 100 * 314159;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        quotient = quotient + 1;
        remainder = remainder - divisor;
    }
    
    return quotient;
}
