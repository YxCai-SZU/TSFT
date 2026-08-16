#include <stdint.h>

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (n > 9 || m > 9) ==> \result == -1;
    ensures (n <= 9 && m <= 9) ==> \result == (int)(n * m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    uint32_t n_is_greater_than_9;
    uint32_t m_is_greater_than_9;
    uint32_t sum;
    int32_t result;

    n_is_greater_than_9 = (n > 9) ? 1U : 0U;
    m_is_greater_than_9 = (m > 9) ? 1U : 0U;
    sum = n_is_greater_than_9 + m_is_greater_than_9;

    if (sum > 0U)
    {
        result = -1;
        //@ assert (n > 9 || m > 9) ==> result == -1;
        return result;
    }

    //@ assert n <= 9 && m <= 9;
    //@ assert 1 <= n * m <= 81;
    result = (int32_t)(n * m);
    //@ assert (n <= 9 && m <= 9) ==> result == (int)(n * m);
    return result;
}
