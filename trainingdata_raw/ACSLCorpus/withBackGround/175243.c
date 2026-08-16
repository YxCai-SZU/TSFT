#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_d(integer d) = 1 <= d <= 365;
    logic integer remainder_formula(integer d, integer q) = d + 23 - q * 24;
*/

/*@
    requires valid_d(d);
    ensures \result == (d + 23) / 24;
    assigns \nothing;
*/
uint32_t func(uint32_t d)
{
    uint32_t quotient = 0;
    uint32_t remainder = d + 23;
    
    /*@
        loop invariant 1 <= d <= 365;
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder;
        loop invariant remainder == remainder_formula(d, quotient);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 24)
    {
        //@ assert remainder >= 24;
        quotient += 1;
        remainder -= 24;
    }
    
    //@ assert quotient == (d + 23) / 24;
    return quotient;
}

int main()
{
    return 0;
}
