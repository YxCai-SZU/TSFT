#include <stdint.h>

/*@
    requires (2 <= (n) <= 100) && (2 <= (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
int32_t func(int32_t n, int32_t m)
{
    uint32_t n_un;
    uint32_t m_un;
    uint32_t result_un;
    int32_t result;
    
    n_un = (uint32_t)n;
    m_un = (uint32_t)m;
    
    //@ assert n_un > 1 && n_un <= 100;
    //@ assert m_un > 1 && m_un <= 100;
    
    //@ assert n_un - 1 >= 1;
    //@ assert m_un - 1 >= 1;
    
    //@ assert (n_un - 1) <= 99;
    //@ assert (m_un - 1) <= 99;
    //@ assert (n_un - 1) * (m_un - 1) <= 99 * 99;
    
    result_un = (n_un - 1) * (m_un - 1);
    result = (int32_t)result_un;
    
    return result;
}
