#include <stdint.h>

/*@
    requires (1 <= (n) <= 100);
    ensures \result >= 800 * n - 200 * (n / 15);
*/
int32_t func(uint32_t n)
{
    // Variable declarations
    int32_t x;
    int32_t y;
    uint32_t quotient = 0;
    uint32_t remainder = n;
    int32_t result;

    x = 800 * (int32_t)n;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= quotient <= n / 15;
        loop invariant remainder == n - quotient * 15;
        loop invariant remainder >= 0;
        loop assigns quotient, remainder;
        loop variant remainder;
    */
    while (remainder >= 15)
    {
        //@ assert remainder >= 15;
        remainder -= 15;
        quotient += 1;
        //@ assert quotient * 15 <= n;
    }

    //@ assert quotient == n / 15;
    y = 200 * (int32_t)quotient;
    result = x - y;

    //@ assert result >= 800 * n - 200 * (n / 15);
    return result;
}
