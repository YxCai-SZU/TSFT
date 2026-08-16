#include <stdint.h>

/*@
  requires 1 <= n <= 1000000000000;
  requires 1 <= m <= 1000000000000;
  ensures \result >= 0;
  ensures \result <= n + m / 4;
  assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t n_local;
    uint64_t m_local;
    uint64_t res;

    n_local = n;
    m_local = m;
    res = 0;

    if (n_local > m_local / 2)
    {
        res = m_local / 2;
        //@ assert ((res) >= 0);
    }
    else
    {
        res = n_local;
        m_local = m_local - 2 * n_local;
        res = res + m_local / 4;
        //@ assert ((res) >= 0);
    }

    return res;
}
