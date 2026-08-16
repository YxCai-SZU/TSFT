#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result >= 0;
    ensures \result == 800 * n - (n / 15) * 200;
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t count = 0;
    uint32_t temp_n = n;
    int32_t ans;

    x = 800 * (int32_t)n;

    /*@
        loop invariant 1 <= n <= 100;
        loop invariant 0 <= count <= n / 15;
        loop invariant temp_n == n - 15 * count;
        loop invariant x == 800 * (int32_t)n;
        loop assigns count, temp_n;
        loop variant temp_n;
    */
    while (temp_n >= 15)
    {
        count = count + 1;
        temp_n = temp_n - 15;
    }

    y = count * 200;

    //@ assert x == 800 * (int32_t)n;
    //@ assert y == count * 200;
    //@ assert 0 <= count * 200 <= (n / 15) * 200;

    ans = x - y;
    //@ assert ans == 800 * (int32_t)n - (n / 15) * 200;
    return ans;
}
