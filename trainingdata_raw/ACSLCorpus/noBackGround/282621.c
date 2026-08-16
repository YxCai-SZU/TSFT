#include <stdint.h>

/*@
    requires 0 <= x <= 1000000000;
    ensures \result == (x / 500 * 1000 + (x % 500) / 5 * 5);
*/
uint32_t func(uint32_t x)
{
    uint32_t ans;
    uint32_t temp_x;
    uint32_t div_500;
    uint32_t remainder_500;
    uint32_t div_5;
    uint32_t remainder_5;

    ans = 0;
    temp_x = x;
    div_500 = 0;
    remainder_500 = temp_x;

    /*@
        loop invariant (0 <= (remainder_500) <= (temp_x) &&
        0 <= (div_500) <= (temp_x) / 500 &&
        (remainder_500) == (temp_x) - (div_500) * 500);
        loop assigns remainder_500, div_500;
        loop variant remainder_500;
    */
    while (remainder_500 >= 500)
    {
        //@ assert remainder_500 >= 500;
        remainder_500 -= 500;
        div_500 += 1;
    }

    ans += div_500 * 1000;
    div_5 = 0;
    remainder_5 = remainder_500;

    /*@
        loop invariant (0 <= (remainder_5) <= (remainder_500) &&
        0 <= (div_5) <= (remainder_500) / 5 &&
        (remainder_5) == (remainder_500) - (div_5) * 5);
        loop assigns remainder_5, div_5;
        loop variant remainder_5;
    */
    while (remainder_5 >= 5)
    {
        //@ assert remainder_5 >= 5;
        remainder_5 -= 5;
        div_5 += 1;
    }

    ans += div_5 * 5;
    return ans;
}
