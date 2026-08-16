#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= (1900 * (n));
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t ans = 0;

    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (m) <= 5);
    ans += 100 * ((int32_t)n - (int32_t)m);
    ans += 1900 * (int32_t)m;

    //@ assert ans == (100 * ((n) - (m)) + 1900 * (m));
    //@ assert ans >= (100 * ((n) - (m)) + 1900 * (m));
    //@ assert ans <= (1900 * (n));

    return ans;
}
