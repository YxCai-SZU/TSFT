#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000000000);
    ensures \result == ((n) / 3);
    assigns \nothing;
*/
uint32_t func(uint32_t n)
{
    uint32_t quotient = 0;
    uint32_t remainder = n;
    uint32_t three = 3;

    /*@
        loop invariant 0 <= quotient;
        loop invariant 0 <= remainder && remainder <= n;
        loop invariant remainder == n - 3 * quotient;
        loop invariant quotient <= ((n) / 3);
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= three)
    {
        //@ assert remainder >= three;
        quotient += 1;
        remainder -= three;
        //@ assert remainder == n - 3 * quotient;
    }

    //@ assert quotient == ((n) / 3);
    return quotient;
}
