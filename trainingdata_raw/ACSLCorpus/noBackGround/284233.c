#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100);
    ensures ((\result) >= 1 && (\result) <= 3);
    ensures ((\result) == 1 || (\result) == 2 || (\result) == 3);
    assigns \nothing;
*/
uint64_t func(uint64_t a, uint64_t b, uint64_t c)
{
    uint64_t ans;

    ans = 0;

    if (a == b && b == c)
    {
        ans = 1;
    }
    else if (a == b || b == c || a == c)
    {
        ans = 2;
    }
    else
    {
        ans = 3;
    }

    //@ assert ((ans) >= 1 && (ans) <= 3);
    //@ assert ((ans) == 1 || (ans) == 2 || (ans) == 3);

    return ans;
}
