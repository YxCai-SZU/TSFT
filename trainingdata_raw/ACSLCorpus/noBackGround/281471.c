#include <stdint.h>

/*@
    requires 2 <= n && n <= 100;
    requires 2 <= m && m <= 100;
    ensures \result == (n * m) - (n + m - 1);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t n_m;
    uint32_t nm_1;
    int32_t result;

    //@ assert (2 <= (n) && (n) <= 100 &&         2 <= (m) && (m) <= 100);
    //@ assert ((n) * (m)) <= 10000;

    n_m = n * m;
    nm_1 = n + m - 1;

    //@ assert ((n) * (m)) >= ((n) + (m) - 1);
    //@ assert n_m >= nm_1;

    result = (int32_t)n_m - (int32_t)nm_1;

    return result;
}
