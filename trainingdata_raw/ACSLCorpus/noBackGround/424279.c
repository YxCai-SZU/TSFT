#include <stdint.h>

/*@
    requires (0 <= (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + ((x) % 500) / 5 * 5);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    uint32_t temp_x;
    uint32_t count_500;
    uint32_t count_5;

    result = 0;
    temp_x = x;
    count_500 = 0;
    count_5 = 0;

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count_500 <= x / 500;
        loop invariant temp_x == x - count_500 * 500;
        loop assigns temp_x, count_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        count_500 += 1;
    }

    /*@
        loop invariant 0 <= temp_x <= x;
        loop invariant 0 <= count_5 <= x / 5;
        loop invariant temp_x == x - count_500 * 500 - count_5 * 5;
        loop assigns temp_x, count_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        count_5 += 1;
    }

    result = count_500 * 1000 + count_5 * 5;
    //@ assert result == (((x) / 500) * 1000 + ((x) % 500) / 5 * 5);
    return result;
}
