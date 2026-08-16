#include <stdint.h>

/*@
    requires (1 <= (l) && (l) <= 1000);
    ensures \result == (l * l * l) / 27;
    assigns \nothing;
*/
uint64_t func(uint64_t l)
{
    //@ assert l * l <= 1000 * 1000;
    //@ assert l * l * l <= 1000 * 1000 * 1000;
    
    uint64_t l_cubed = l * l * l;
    uint64_t quotient = 0;
    uint64_t remainder = l_cubed;
    uint64_t divisor = 27;

    /*@
        loop invariant 1 <= l && l <= 1000;
        loop invariant l_cubed == l * l * l;
        loop invariant quotient <= l_cubed / divisor;
        loop invariant remainder == l_cubed - quotient * divisor;
        loop invariant 0 <= remainder;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        quotient += 1;
    }

    //@ assert quotient == l_cubed / 27;
    return quotient;
}
