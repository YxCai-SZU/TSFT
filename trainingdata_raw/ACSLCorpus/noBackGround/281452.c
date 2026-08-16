#include <stdint.h>

/*@
    requires (0 <= (x) && (x) <= 1000000000);
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
uint64_t func(uint64_t x)
{
    uint64_t result = 0;
    uint64_t temp_x = x;
    uint64_t count_500 = 0;
    uint64_t count_5 = 0;

    //@ assert temp_x == x;

    /*@
        loop invariant 0 <= temp_x && temp_x <= x;
        loop invariant count_500 <= x / 500;
        loop invariant temp_x == x - count_500 * 500;
        loop invariant count_500 * 500 <= x;
        loop assigns temp_x, count_500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        temp_x -= 500;
        count_500 += 1;
        //@ assert temp_x == x - count_500 * 500;
    }

    //@ assert temp_x < 500;
    //@ assert temp_x == x % 500;

    /*@
        loop invariant 0 <= temp_x && temp_x <= x;
        loop invariant count_5 <= x / 5;
        loop invariant temp_x == x - count_500 * 500 - count_5 * 5;
        loop invariant count_5 * 5 <= temp_x + count_5 * 5;
        loop assigns temp_x, count_5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        temp_x -= 5;
        count_5 += 1;
        //@ assert temp_x == x - count_500 * 500 - count_5 * 5;
    }

    //@ assert temp_x < 5;
    //@ assert temp_x == (x % 500) % 5;

    result = count_500 * 1000 + count_5 * 5;

    //@ assert count_500 == x / 500;
    //@ assert count_5 == (x % 500) / 5;
    //@ assert result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);

    return result;
}
