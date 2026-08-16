/*@
    predicate is_valid_range(integer r) = 1 <= r && r <= 100;
    
    logic integer pi_approx_const = 31415;
    
    logic integer two_pi_r(integer r) = 2 * pi_approx_const * r;
    
    predicate division_invariant(integer r, integer pi_approx, integer two_pi_r_val, 
                                 integer quotient, integer remainder, integer divisor) =
        is_valid_range(r) &&
        pi_approx == pi_approx_const &&
        two_pi_r_val == two_pi_r(r) &&
        quotient * divisor + remainder == two_pi_r_val &&
        quotient >= 0 &&
        remainder >= 0;
    
    lemma overflow_safe:
        \forall integer r; is_valid_range(r) ==> 
        2 * pi_approx_const * r <= 2 * 31415 * 100;
*/

#include <stdint.h>

/*@
    requires is_valid_range(r);
    ensures \result == 2 * 31415 * r / 10000;
*/
int64_t func(int64_t r)
{
    // Variable declarations at scope top
    int64_t pi_approx;
    int64_t two_pi_r_val;
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    
    pi_approx = 31415;
    
    //@ assert 2 * pi_approx * r <= 2 * 31415 * 100;
    
    two_pi_r_val = 2 * pi_approx * r;
    quotient = 0;
    remainder = two_pi_r_val;
    divisor = 10000;
    
    /*@
        loop invariant division_invariant(r, pi_approx, two_pi_r_val, quotient, remainder, divisor);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor) {
        //@ assert remainder >= divisor;
        quotient += 1;
        remainder -= divisor;
        //@ assert quotient * divisor + remainder == two_pi_r_val;
    }
    
    return quotient;
}
