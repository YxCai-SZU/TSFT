#include <stdint.h>

/*@
    requires (1 <= (n) <= 1000000000000 &&
        1 <= (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
uint32_t func(uint32_t n, uint32_t m)
{
    uint32_t n_half;
    uint32_t m_even;
    uint32_t result;

    //@ assert (1 <= (n) <= 1000000000000 &&         1 <= (m) <= 1000000000000);

    if (n < m / 2)
    {
        n_half = n;
    }
    else
    {
        n_half = m / 2;
    }

    //@ assert n_half == ((n) < (m) / 2 ? (n) : (m) / 2);

    m_even = m - n_half * 2;

    //@ assert m_even == ((m) - (((n)) < ((m)) / 2 ? ((n)) : ((m)) / 2) * 2);

    result = n_half + m_even / 4;

    //@ assert result == ((((n)) < ((m)) / 2 ? ((n)) : ((m)) / 2) + (((m)) - ((((n))) < (((m))) / 2 ? (((n))) : (((m))) / 2) * 2) / 4);
    //@ assert result <= n + m / 2;

    return result;
}
