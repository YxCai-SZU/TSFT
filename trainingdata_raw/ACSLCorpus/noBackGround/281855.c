#include <stddef.h>

/*@
    requires (1 <= (n) <= 10000);
    ensures \result == (((n) + 999) / 1000);
    assigns \nothing;
*/
size_t func(size_t n)
{
    size_t result;
    size_t quotient;
    size_t divisor;
    
    //@ assert (1 <= (n) <= 10000);
    
    result = n + 999;
    quotient = 0;
    divisor = 1000;
    
    /*@
        loop invariant 1 <= n <= 10000;
        loop invariant 0 <= result;
        loop invariant result == n + 999 - quotient * divisor;
        loop invariant quotient <= (((n) + 999) / 1000);
        loop invariant quotient > 0 ==> result < n + 999;
        loop assigns result, quotient;
        loop variant result;
    */
    while (result >= divisor)
    {
        //@ assert result >= divisor;
        result -= divisor;
        quotient += 1;
        //@ assert result == n + 999 - quotient * divisor;
    }
    
    //@ assert result == n + 999 - quotient * divisor;
    //@ assert result < divisor;
    //@ assert quotient == (((n) + 999) / 1000);
    
    return quotient;
}
