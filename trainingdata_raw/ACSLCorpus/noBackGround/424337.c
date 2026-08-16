#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    ensures \result == (800 * (n) - 200 * ((n) / 15));
    assigns \nothing;
*/
int32_t func(uint32_t n)
{
    int32_t x;
    int32_t y;
    int32_t ans;

    x = 800 * (int32_t)n;
    y = 200 * (int32_t)(n / 15);
    ans = x - y;

    //@ assert ans == 800 * (int32_t)n - 200 * (int32_t)(n / 15);

    return ans;
}
