#include <stddef.h>

/*@
    requires 1 <= x <= 100000;
    ensures \result == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    assigns \nothing;
*/
size_t func(size_t x)
{
    size_t ans = 0;
    size_t temp_x = x;
    size_t count500 = 0;
    size_t count5 = 0;

    /*@
        loop invariant (1 <= (x) <= 100000 &&
        0 <= (temp_x) <= (x) &&
        0 <= (count500) <= (x) / 500 &&
        (temp_x) == (x) - 500 * (count500));
        loop assigns temp_x, count500;
        loop variant temp_x;
    */
    while (temp_x >= 500)
    {
        //@ assert temp_x >= 500;
        count500 += 1;
        temp_x -= 500;
    }

    /*@
        loop invariant (1 <= (x) <= 100000 &&
        0 <= (temp_x) <= (x) &&
        0 <= (count5) <= ((x) - 500 * (count500)) / 5 &&
        (temp_x) == (x) - 500 * (count500) - 5 * (count5));
        loop assigns temp_x, count5;
        loop variant temp_x;
    */
    while (temp_x >= 5)
    {
        //@ assert temp_x >= 5;
        count5 += 1;
        temp_x -= 5;
    }

    ans += count500 * 1000;
    ans += count5 * 5;

    //@ assert ans == (((x) / 500) * 1000 + (((x) % 500) / 5) * 5);
    return ans;
}
