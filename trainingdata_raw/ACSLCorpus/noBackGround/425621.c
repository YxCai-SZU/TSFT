#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result = 0;
    uint32_t remainder = x;
    uint32_t count_500 = 0;
    uint32_t count_5 = 0;

    /*@
        loop invariant 0 <= count_500 <= x / 500;
        loop invariant remainder == x - 500 * count_500;
        loop invariant 0 <= remainder <= x;
        loop assigns remainder, count_500;
        loop variant remainder;
    */
    while (remainder >= 500)
    {
        remainder -= 500;
        count_500 += 1;
    }
    result += count_500 * 1000;

    /*@
        loop invariant 0 <= count_5 <= x / 5;
        loop invariant remainder == x - 500 * count_500 - 5 * count_5;
        loop invariant 0 <= remainder <= x;
        loop assigns remainder, count_5;
        loop variant remainder;
    */
    while (remainder >= 5)
    {
        remainder -= 5;
        count_5 += 1;
    }
    result += count_5 * 5;

    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return result;
}
