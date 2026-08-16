#include <stdint.h>

/*@
    requires (0 <= (n) <= 100 && 0 <= (m) <= 100 && 2 <= (n) + (m));
    ensures \result == ((n) * ((n) - 1) / 2 + (m) * ((m) - 1) / 2);
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    // Declare all variables at the top
    uint64_t t = 0;
    uint64_t u = 0;
    uint64_t result = 0;

    //@ assert 0 <= n <= 100;
    //@ assert 0 <= m <= 100;
    //@ assert 2 <= n + m;

    //@ assert n * (n - 1) / 2 <= 100 * 99 / 2;
    //@ assert m * (m - 1) / 2 <= 100 * 99 / 2;

    if (n > 0) {
        t = n * (n - 1) / 2;
    } else {
        t = 0;
    }

    if (m > 0) {
        u = m * (m - 1) / 2;
    } else {
        u = 0;
    }

    //@ assert t == n * (n - 1) / 2 || t == 0;
    //@ assert u == m * (m - 1) / 2 || u == 0;

    result = t + u;
    //@ assert result == ((n) * ((n) - 1) / 2 + (m) * ((m) - 1) / 2);
    return result;
}
