#include <stdint.h>

/*@
    requires (1 <= (x) <= 10000) && (1 <= (y) <= 10000);
    ensures \result <= 2 * (x + y);
    ensures \result >= x + y;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t ans = 0;
    uint32_t temp = 0;

    if (x > y)
    {
        ans = x;
        //@ assert y <= 10000;
        temp = y * 2;
        if (x > temp)
        {
            ans += temp;
        }
        else
        {
            ans += x;
        }
    }
    else
    {
        ans = y;
        //@ assert x <= 10000;
        temp = x * 2;
        if (y > temp)
        {
            ans += temp;
        }
        else
        {
            ans += y;
        }
    }

    //@ assert ans <= 2 * (x + y);
    return ans;
}
