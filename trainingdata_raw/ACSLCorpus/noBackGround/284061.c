#include <stdint.h>

/*@
    requires (1 <= (l) <= 1000);
    ensures \result == ((l) * (l) * (l)) / 27;
    assigns \nothing;
*/
int64_t func(int64_t l)
{
    // Variable declarations at top of scope
    int64_t l_squared;
    int64_t result;
    int64_t quotient;
    int64_t divisor;
    
    //@ assert (1 <= (l) <= 1000);
    
    l_squared = l * l;
    //@ assert l_squared == ((l) * (l) * (l)) / l;
    
    result = l_squared * l;
    //@ assert result == ((l) * (l) * (l));
    
    quotient = 0;
    divisor = 27;
    
    /*@
        loop invariant 1 <= l <= 1000;
        loop invariant 0 <= result <= ((l) * (l) * (l));
        loop invariant 0 <= quotient;
        loop invariant result == ((l) * (l) * (l)) - quotient * divisor;
        loop assigns result, quotient;
        loop variant result;
    */
    while (result >= divisor)
    {
        result -= divisor;
        quotient += 1;
    }
    
    return quotient;
}
