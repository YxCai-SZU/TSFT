#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 10 &&
        1 <= (b) && (b) <= 10 &&
        1 <= (c) && (c) <= 10 &&
        1 <= (d) && (d) <= 10);
    ensures \result == (a + b + c + d) / 2;
    ensures \result >= 2 && \result <= 30;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t d)
{
    uint32_t ans;
    uint32_t res;
    uint32_t count;

    ans = a + b + c + d;
    res = 0;
    count = 0;

    /*@
        loop invariant 1 <= a && a <= 10;
        loop invariant 1 <= b && b <= 10;
        loop invariant 1 <= c && c <= 10;
        loop invariant 1 <= d && d <= 10;
        loop invariant ans >= 0;
        loop invariant res >= 0;
        loop invariant count >= 0;
        loop invariant ans + 2 * count == a + b + c + d;
        loop invariant res == count;
        loop assigns ans, res, count;
        loop variant ans;
    */
    while (ans >= 2)
    {
        ans -= 2;
        res += 1;
        count += 1;
    }

    //@ assert res == (a + b + c + d) / 2;

    return res;
}
