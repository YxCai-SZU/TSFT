#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    assigns \nothing;
    ensures \result == ((n) * 800 - ((((n)) >= 0 ? ((n)) / 15 : -((-((n))) / 15)) * 200));
*/
long func(long n)
{
    long result;
    long count;
    long temp_n;
    long quotient;
    long remainder;
    long abs_n;
    
    result = n * 800;
    count = 0;
    temp_n = n;
    quotient = 0;
    remainder = 0;
    abs_n = (temp_n < 0) ? -temp_n : temp_n;
    
    /*@
        loop invariant 0 <= abs_n <= 100;
        loop invariant quotient >= 0;
        loop invariant abs_n == temp_n - quotient * 15;
        loop invariant 1 <= n <= 100;
        loop invariant temp_n == n;
        loop assigns abs_n, quotient;
        loop variant abs_n;
    */
    while (abs_n >= 15)
    {
        abs_n -= 15;
        quotient += 1;
    }
    remainder = abs_n;
    
    if (temp_n < 0)
    {
        quotient = -quotient;
    }
    
    count = quotient;
    result -= count * 200;
    
    //@ assert result == ((n) * 800 - ((((n)) >= 0 ? ((n)) / 15 : -((-((n))) / 15)) * 200));
    return result;
}
