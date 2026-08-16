#include <stdbool.h>
#include <stdint.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures \result == 0 || \result == 1;
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    bool n_is_even;
    bool m_is_even;
    int32_t result;

    if (n == 1 && m == 1)
    {
        result = 1;
        //@ assert result == 0 || result == 1;
        return result;
    }

    n_is_even = ((n & 1) == 0);
    m_is_even = ((m & 1) == 0);

    if (n_is_even && m_is_even)
    {
        result = 0;
        //@ assert result == 0 || result == 1;
        return result;
    }
    else if (n_is_even || m_is_even)
    {
        result = 0;
        //@ assert result == 0 || result == 1;
        return result;
    }
    else
    {
        //@ assert !(((n) % 2) == 0) && !(((m) % 2) == 0);
        result = 0;
        //@ assert result == 0 || result == 1;
        return result;
    }
}
