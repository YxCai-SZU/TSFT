#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10);
    ensures \result == ((a) * 100 + ((a) * 100) / 100);
*/
int32_t func(uint32_t a)
{
    // Variable declarations
    uint32_t result;
    uint32_t quotient = 0;
    uint32_t remainder;
    
    // Initial assignments
    result = a * 100;
    remainder = a * 100;
    
    /*@
        loop invariant 0 <= quotient <= (a * 100) / 100;
        loop invariant remainder == a * 100 - quotient * 100;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 100)
    {
        //@ assert remainder == a * 100 - quotient * 100;
        quotient += 1;
        remainder -= 100;
        //@ assert remainder == a * 100 - quotient * 100;
    }
    
    //@ assert remainder == a * 100 - quotient * 100;
    result += quotient;
    //@ assert result == a * 100 + quotient;
    
    return (int32_t)result;
}
