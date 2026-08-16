#include <stdint.h>

/*@
    requires (1 <= (n) && (n) <= 1000000000000 &&
        1 <= (m) && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t n_val;
    uint32_t res;

    //@ assert (1 <= (n) && (n) <= 1000000000000 &&         1 <= (m) && (m) <= 1000000000000);

    if (n > m / 2) {
        n_val = m / 2;
    } else {
        n_val = n;
    }

    //@ assert n_val <= m / 2;
    //@ assert n_val <= n;

    res = n_val + (m - n_val * 2) / 4;

    //@ assert res <= n + m / 2;
    //@ assert res >= m / 4;

    return res;
}
