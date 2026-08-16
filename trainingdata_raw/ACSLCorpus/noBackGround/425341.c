#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 10000);
    ensures \result == (n / 1000 + 1) * 1000 - n;
    assigns \nothing;
*/
int64_t func(int64_t n)
{
    int64_t result;
    int64_t quotient;
    int64_t remainder;
    int64_t divisor;
    
    result = -1;
    quotient = 0;
    remainder = n;
    divisor = 1000;
    
    /*@
        loop invariant 0 <= quotient <= ((n) / (1000));
        loop invariant remainder == n - quotient * divisor;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }
    
    result = (quotient + 1) * divisor - n;
    
    //@ assert quotient == ((n) / (1000));
    //@ assert remainder == n % 1000;
    //@ assert result == (quotient + 1) * 1000 - n;
    
    return result;
}
