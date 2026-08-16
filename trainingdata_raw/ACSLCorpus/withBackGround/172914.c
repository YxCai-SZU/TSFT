#include <stdbool.h>

/*@
    predicate valid_range(integer r) = 1 <= r <= 100;
    
    logic integer pi_approx = 3142;
    
    logic integer expected_result(integer r) = 
        (2 * r * pi_approx) / 1000;
*/

/*@
    requires valid_range(r);
    ensures \result == expected_result(r);
*/
int func(int r)
{
    // Variable declarations at top of scope
    int pi_approx;
    int scaled_r;
    int circumference;
    int temp;
    int quotient;
    int remainder;
    int divisor;
    
    pi_approx = 3142;
    scaled_r = r * 1000;
    circumference = 0;
    temp = 2 * pi_approx * r;
    quotient = 0;
    remainder = 0;
    divisor = 1000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant scaled_r == r * 1000;
        loop invariant 2 * pi_approx * r == temp + quotient * divisor;
        loop invariant quotient >= 0;
        loop invariant temp >= 0;
        loop assigns temp, quotient;
    */
    while (temp >= divisor)
    {
        //@ assert temp >= divisor;
        temp -= divisor;
        quotient += 1;
    }
    remainder = temp;
    circumference = quotient;
    
    //@ assert circumference == expected_result(r);
    return circumference;
}
