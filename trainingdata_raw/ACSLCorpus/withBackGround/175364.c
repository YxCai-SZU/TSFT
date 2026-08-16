#include <limits.h>

/*@
    predicate is_valid_range(integer r) = 1 <= r <= 100;
    
    logic integer scaled_value(integer r) = r * 2 * 3142;
    
    logic integer expected_result(integer r) = 2 * r * 3142 / 1000;
*/

/*@
    requires is_valid_range(r);
    ensures \result == expected_result(r);
    assigns \nothing;
*/
int func(int r)
{
    int pi_approx;
    int scaled_r;
    int divisor;
    int quotient;
    int remainder;
    int divisor_abs;
    
    pi_approx = 3142;
    scaled_r = r * 2 * pi_approx;
    divisor = 1000;
    quotient = 0;
    
    if (scaled_r < 0) {
        remainder = -scaled_r;
    } else {
        remainder = scaled_r;
    }
    
    if (divisor < 0) {
        divisor_abs = -divisor;
    } else {
        divisor_abs = divisor;
    }
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant divisor == 1000;
        loop invariant quotient >= 0;
        loop invariant scaled_r == r * 2 * pi_approx;
        loop invariant scaled_r < 0 ==> remainder == -scaled_r - quotient * divisor_abs;
        loop invariant scaled_r >= 0 ==> remainder == scaled_r - quotient * divisor_abs;
        loop invariant quotient <= 2 * r * 3142 / 1000;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor_abs) {
        remainder -= divisor_abs;
        quotient += 1;
    }
    
    if (scaled_r < 0) {
        quotient = -quotient;
    }
    
    //@ assert quotient == 2 * r * 3142 / 1000;
    
    return quotient;
}
