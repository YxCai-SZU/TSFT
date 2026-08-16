#include <stdint.h>

/*@
    requires 1 <= r <= 100;
    ensures \result == 2 * r * 314 / 100;
    assigns \nothing;
*/
int64_t func(int64_t r)
{
    int64_t pi_approx = 314;
    int64_t product = 2 * r * pi_approx;
    int64_t divisor = 100;
    int64_t quotient = 0;
    int64_t remainder = product;
    int64_t abs_product;
    int64_t abs_divisor;
    
    //@ assert (1 <= (r) <= 100 ==>         2 * (r) * 314 >= 0 && 2 * (r) * 314 <= 2 * 100 * 314);
    
    if (product < 0) {
        abs_product = -product;
    } else {
        abs_product = product;
    }
    
    if (divisor < 0) {
        abs_divisor = -divisor;
    } else {
        abs_divisor = divisor;
    }
    
    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= abs_product;
        loop invariant abs_product + quotient * abs_divisor == product;
        loop invariant quotient <= product / abs_divisor;
        loop invariant abs_product <= 2 * 100 * 314;
        loop assigns abs_product, quotient;
        loop variant abs_product;
    */
    while (abs_product >= abs_divisor) {
        abs_product -= abs_divisor;
        quotient += 1;
    }
    
    if ((product < 0) != (divisor < 0)) {
        quotient = -quotient;
    }
    
    //@ assert quotient == 2 * r * 314 / 100;
    return quotient;
}
