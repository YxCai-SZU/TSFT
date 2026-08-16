#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        1 <= (m) <= (n) &&
        (m) <= 5);
    ensures \result >= (100 * ((n) - (m)) + 1900 * (m));
    ensures \result <= ((100 * (((n)) - ((m))) + 1900 * ((m))) + 100 * ((m) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t ans;
    uint32_t rem;

    //@ assert (1 <= (n) <= 100 &&         1 <= (m) <= (n) &&         (m) <= 5);
    ans = 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;
    rem = m - 1;

    if (rem > 0)
    {
        ans += 100 * (int32_t)rem;
    }

    //@ assert ans >= (100 * ((n) - (m)) + 1900 * (m));
    //@ assert ans <= ((100 * (((n)) - ((m))) + 1900 * ((m))) + 100 * ((m) - 1));
    return ans;
}
