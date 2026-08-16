#include <stddef.h>

/*@
    requires (2 <= (n) && (n) <= 100 &&
        2 <= (m) && (m) <= 100);
    ensures \result == (((n) - 1) * ((m) - 1));
    assigns \nothing;
*/
size_t func(size_t n, size_t m)
{
    // Variable declarations at scope top
    size_t n_minus_one;
    size_t m_minus_one;
    size_t result;

    //@ assert 2 <= n && n <= 100;
    //@ assert 2 <= m && m <= 100;
    
    //@ assert 1 <= n - 1 && n - 1 <= 99;
    n_minus_one = n - 1;
    
    //@ assert 1 <= m - 1 && m - 1 <= 99;
    m_minus_one = m - 1;
    
    //@ assert n_minus_one * m_minus_one <= 99 * 99;
    result = n_minus_one * m_minus_one;
    
    //@ assert result == (n - 1) * (m - 1);
    return result;
}
