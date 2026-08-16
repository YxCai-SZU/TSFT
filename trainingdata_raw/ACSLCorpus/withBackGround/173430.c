#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 20;

    logic integer compute_base(integer n, integer m) =
        (n * 2 - 1) * 2 + (m - 1) * 2;

    lemma result_cases:
        \forall integer n, m;
        valid_range(n) && valid_range(m) ==>
        compute_base(n, m) == (n * 2 - 1) * 2 + (m - 1) * 2;
*/

/*@
    requires valid_range(n) && valid_range(m);
    ensures \result == compute_base(n, m) || \result == compute_base(n, m) + 1;
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    uint32_t n_unsigned;
    uint32_t m_unsigned;
    uint32_t result_unsigned;
    int32_t result;

    n_unsigned = (uint32_t)n;
    m_unsigned = (uint32_t)m;

    result_unsigned = (n_unsigned * 2 - 1) * 2 + (m_unsigned - 1) * 2;

    if (n_unsigned > 0 && m_unsigned > 0)
    {
        if (n_unsigned * 2 - 1 > m_unsigned - 1)
        {
            result = (int32_t)result_unsigned;
        }
        else
        {
            result = (int32_t)result_unsigned + 1;
        }
    }
    else
    {
        result = (int32_t)result_unsigned;
    }

    //@ assert result == compute_base(n, m) || result == compute_base(n, m) + 1;

    return result;
}
