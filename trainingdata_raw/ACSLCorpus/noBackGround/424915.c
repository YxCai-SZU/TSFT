#include <stdint.h>

/*@
    requires ((((x)) >= 0) && (((x)) <= 1));
    ensures \result == (((x) * 3 + 3) / 2);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    // Variable declarations at scope top
    uint32_t x_prime;
    uint32_t result;
    uint32_t remainder;
    uint32_t divisor;

    //@ assert ((((x)) >= 0) && (((x)) <= 1));
    
    //@ assert x * 3 + 3 <= 6;
    x_prime = x * 3 + 3;

    result = 0;
    remainder = x_prime;
    divisor = 2;

    /*@
        loop invariant 0 <= result;
        loop invariant result <= (((x) * 3 + 3) / 2);
        loop invariant remainder == x_prime - 2 * result;
        loop invariant x_prime - 2 * result <= 6;
        loop invariant x_prime - 2 * result >= 0;
        loop assigns result, remainder;
        loop variant remainder;
    */
    while (remainder >= divisor)
    {
        remainder -= divisor;
        result += 1;
    }

    //@ assert result == (((x) * 3 + 3) / 2);
    return result;
}
