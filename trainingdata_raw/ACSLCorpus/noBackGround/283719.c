#include <stdint.h>

/*@
    requires (1 <= (n) && 1 <= (m) && (n) <= 1000000000000 && (m) <= 1000000000000);
    ensures \result <= n + m / 2;
    ensures \result >= m / 4;
    assigns \nothing;
*/
uint64_t func(uint64_t n, uint64_t m)
{
    uint64_t m_local = m;
    uint64_t res = 0;
    
    //@ assert res == 0;
    res += (n > m_local / 2) ? (m_local / 2) : n;
    
    //@ assert res == (n > m / 2 ? m / 2 : n);
    m_local = (m_local > 2 * n) ? (m_local - 2 * n) : 0;
    
    //@ assert m_local == (m > 2 * n ? m - 2 * n : 0);
    res += m_local / 4;
    
    //@ assert res == (((n) > (m) / 2 ? (m) / 2 : (n)) + ((m) > 2 * (n) ? (m) - 2 * (n) : 0) / 4);
    return res;
}
