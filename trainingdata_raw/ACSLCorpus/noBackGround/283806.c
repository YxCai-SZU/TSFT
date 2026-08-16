#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == ((n) * (m) - ((n) + (m) - 1));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    // Variable declarations at scope top
    uint32_t n_mul_m;
    uint32_t n_plus_m_minus_1;
    int32_t result;

    //@ assert n * m <= 100 * 100;
    n_mul_m = n * m;

    //@ assert n + m - 1 <= 100 + 100 - 1;
    n_plus_m_minus_1 = n + m - 1;

    //@ assert n * m >= n + m - 1;
    result = (int32_t)(n_mul_m - n_plus_m_minus_1);

    return result;
}
