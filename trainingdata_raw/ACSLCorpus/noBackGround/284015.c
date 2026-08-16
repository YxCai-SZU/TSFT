#include <stdint.h>

/*@
    requires (2 <= (n) && (n) <= 100) && (2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    uint32_t n_unsigned;
    uint32_t m_unsigned;
    uint32_t result_unsigned;
    
    //@ assert (2 <= (n) && (n) <= 100) && (2 <= (m) && (m) <= 100);
    
    if (n < 0) {
        n_unsigned = (uint32_t)(-n);
    } else {
        n_unsigned = (uint32_t)n;
    }
    
    if (m < 0) {
        m_unsigned = (uint32_t)(-m);
    } else {
        m_unsigned = (uint32_t)m;
    }
    
    //@ assert n_unsigned == (unsigned)n;
    //@ assert m_unsigned == (unsigned)m;
    //@ assert 1 <= n_unsigned && n_unsigned <= 100;
    //@ assert 1 <= m_unsigned && m_unsigned <= 100;
    //@ assert n_unsigned - 1 <= 99;
    //@ assert m_unsigned - 1 <= 99;
    //@ assert (n_unsigned - 1) * (m_unsigned - 1) <= 99 * 99;
    
    result_unsigned = (n_unsigned - 1) * (m_unsigned - 1);
    
    //@ assert result_unsigned == (((n) - 1) * ((m) - 1));
    
    return (int32_t)result_unsigned;
}
