#include <limits.h>

/*@
    requires (1 <= (r) <= 100);
    ensures \result == (2 * (r) * 3142 / 1000);
*/
int func(int r)
{
    // Variable declarations at scope top
    int pi_approx;
    int scaled_value;
    int divisor;
    int quotient;
    int remainder;
    int abs_divisor;
    
    pi_approx = 3142;
    //@ assert pi_approx == 3142;
    
    scaled_value = r * 2 * pi_approx;
    //@ assert scaled_value == ((r) * 2 * 3142);
    
    divisor = 1000;
    //@ assert divisor == 1000;
    
    quotient = 0;
    remainder = (scaled_value < 0) ? -scaled_value : scaled_value;
    abs_divisor = (divisor < 0) ? -divisor : divisor;
    //@ assert abs_divisor == 1000;
    
    /*@
        loop invariant 1 <= r <= 100;
        loop invariant pi_approx == 3142;
        loop invariant divisor == 1000;
        loop invariant quotient >= 0;
        loop invariant scaled_value == r * 2 * pi_approx;
        loop invariant abs_divisor == 1000;
        loop invariant (scaled_value < 0) ==> (remainder == -scaled_value - quotient * abs_divisor);
        loop invariant (scaled_value >= 0) ==> (remainder == scaled_value - quotient * abs_divisor);
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= abs_divisor)
    {
        remainder -= abs_divisor;
        quotient += 1;
    }
    
    if (scaled_value < 0)
    {
        quotient = -quotient;
    }
    
    //@ assert r * 2 * 3142 <= 100 * 2 * 3142;
    //@ assert 0 <= quotient;
    
    return quotient;
}

int main()
{
    return 0;
}
