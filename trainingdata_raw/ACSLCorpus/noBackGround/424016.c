#include <stdint.h>

/*@
    requires 1 <= x <= 205;
    requires 1 <= y <= 205;
    ensures \result <= 1000000;
    ensures \result == 1000000 ==> x == 1 && y == 1;
    ensures \result < 1000000 ==> \result >= 0;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t ans;

    ans = 1000000;

    if (x == 1 && y == 1)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else if (x == 1 || y == 1)
    {
        ans = 1;
        //@ assert ans == 1;
    }
    else
    {
        ans = 2;
        //@ assert ans == 2;
    }

    return ans;
}
