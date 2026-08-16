#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 &&
        0 <= (m) <= (n) * (n));
    ensures \result == ((n) * (n) - (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    // Variable declarations at scope top
    int32_t n_signed;
    int32_t m_signed;
    int32_t result;

    // Precondition assertions
    //@ assert 1 <= n && n <= 100;
    //@ assert 0 <= m && m <= n * n;

    // Mathematical property verification
    //@ assert n * n <= 10000;
    //@ assert n * n >= m;

    // Type conversions
    n_signed = (int32_t)n;
    m_signed = (int32_t)m;

    // Core computation
    result = n_signed * n_signed - m_signed;

    // Postcondition verification
    //@ assert result == ((n) * (n) - (m));

    return result;
}
