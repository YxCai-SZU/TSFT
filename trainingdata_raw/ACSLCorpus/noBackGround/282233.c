#include <stdint.h>

/*@
    requires (1 <= (x) <= 1000000000000000);
    ensures \result <= 2 * (x / 11) + 2;
    ensures \result >= 2 * (x / 11);
*/
uint64_t func(uint64_t x)
{
    uint64_t ans;

    if (x % 11 == 0)
    {
        ans = 2 * (x / 11);
        //@ assert ans == 2 * (x / 11);
    }
    else if (x % 11 <= 5)
    {
        ans = 2 * (x / 11) + 1;
        //@ assert ans == 2 * (x / 11) + 1;
    }
    else
    {
        ans = 2 * (x / 11) + 2;
        //@ assert ans == 2 * (x / 11) + 2;
    }

    return ans;
}
