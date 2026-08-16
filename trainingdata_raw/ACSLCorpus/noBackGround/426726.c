#include <stdint.h>

/*@
    requires 1 <= n && n <= 100;
    ensures \result == ((n) * 800 - ((n) / 15) * 200);
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t ans;

    //@ assert (1 <= (n) && (n) <= 100);
    //@ assert 800 * n <= 800 * 100;
    x = 800 * (int32_t)n;

    //@ assert n / 15 <= n / 1;
    //@ assert 200 * (n / 15) <= 200 * n;
    y = 200 * (int32_t)(n / 15);

    //@ assert 800 * n >= 200 * (n / 15);
    ans = x - y;

    //@ assert ans == ((n) * 800 - ((n) / 15) * 200);
    return ans;
}
