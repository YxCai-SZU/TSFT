#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 100);
    ensures \result == (800 * (n) - 200 * (((n)) / 15));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y = 0;
    uint32_t temp_n = n;

    //@ assert (1 <= (n) && (n) <= 100);
    x = 800 * (int32_t)n;

    /*@
        loop invariant 0 <= temp_n <= n;
        loop invariant y == 200 * (((n) / 15) - ((temp_n) / 15));
        loop invariant (1 <= (n) && (n) <= 100);
        loop assigns temp_n, y;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        //@ assert temp_n >= 15;
        temp_n -= 15;
        y += 200;
        //@ assert y == 200 * (((n) / 15) - ((temp_n) / 15));
    }

    int32_t ans = x - y;
    //@ assert ans == (800 * (n) - 200 * (((n)) / 15));
    return ans;
}
