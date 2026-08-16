#include <stddef.h>

/*@
    requires (1 <= (x) && (x) <= 100000);
    ensures \result <= 2 * (x / 11) + 2;
    ensures \result >= 2 * (x / 11);
*/
size_t func(size_t x)
{
    size_t q;
    size_t r;
    size_t ans;

    q = x / 11;
    r = x % 11;
    ans = 2 * q;

    if (r > 6)
    {
        ans += 2;
    }
    else
    {
        ans += 1;
    }

    //@ assert ans <= 2 * q + 2;
    //@ assert ans >= 2 * q;

    return ans;
}
