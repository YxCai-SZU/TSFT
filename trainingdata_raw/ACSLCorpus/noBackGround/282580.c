#include <stdint.h>

/*@
    requires (1 <= (n) <= 10000 &&
        1 <= (x) <= 10000 &&
        1 <= (y) <= 10000);
    ensures \result == n * x || \result == (n - 1) * x + y;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t x, uint64_t y)
{
    // Variable declarations at scope top
    uint64_t ans;

    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= y && y <= 10000;
    //@ assert 1 <= n && n <= 10000;

    //@ assert n * x <= 100000000;
    //@ assert (n - 1) * x + y <= 100010000;

    if (n * x < (n - 1) * x + y)
    {
        ans = n * x;
    }
    else
    {
        ans = (n - 1) * x + y;
    }

    return ans;
}
