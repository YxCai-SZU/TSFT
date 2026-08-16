#include <stdint.h>

/*@
    requires 2 <= n && n <= 100;
    requires 2 <= m && m <= 100;
    ensures \result == (n * m) - (n + m - 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at top of scope
    int32_t result;

    //@ assert (2 <= (n) && (n) <= 100 &&         2 <= (m) && (m) <= 100);
    //@ assert n * m <= 10000;
    //@ assert n + m - 1 <= 199;
    //@ assert n * m >= n + m - 1;

    result = (int32_t)((n * m) - (n + m - 1));
    return result;
}
