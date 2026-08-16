#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result == (100 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m) {
    // Variable declarations at scope top
    int32_t l;
    int32_t n_i32 = (int32_t)n;
    int32_t m_i32 = (int32_t)m;
    
    //@ assert 1 <= n && n <= 100;
    //@ assert 1 <= m && m <= 5;
    //@ assert 0 <= n_i32 - m_i32 && n_i32 - m_i32 <= 100;
    //@ assert 0 <= 1900 * m_i32 && 1900 * m_i32 <= 9500;
    //@ assert 100 * (n_i32 - m_i32) <= 10000;
    //@ assert 100 * (n_i32 - m_i32) + 1900 * m_i32 <= 19500;
    
    l = 100 * (n_i32 - m_i32) + 1900 * m_i32;
    return l;
}
