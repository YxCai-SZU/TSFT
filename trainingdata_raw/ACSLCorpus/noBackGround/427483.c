#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100);
    ensures \result >= 0 && \result <= 200000;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c)
{
    int32_t ans = 0;
    uint32_t i = 0;

    if (a == b && b == c)
    {
        //@ assert 1 <= a * 2 <= 200;
        ans += (int32_t)(a * 2);
    }
    else if (a == b || a == c || b == c)
    {
        //@ assert 1 <= a + b + c - 1 <= 299;
        ans += (int32_t)(a + b + c - 1);
    }

    /*@
        loop invariant 0 <= i <= 10;
        loop invariant 1 <= a <= 100;
        loop invariant 1 <= b <= 100;
        loop invariant 1 <= c <= 100;
        loop invariant ans >= 0 && ans <= 200000;
        loop assigns i;
        loop variant 10 - i;
    */
    while (i < 10)
    {
        i++;
    }

    return ans;
}
