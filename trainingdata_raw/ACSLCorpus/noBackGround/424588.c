#include <limits.h>

/*@
    requires (1 <= (n) && (n) <= 100000 &&
        1 <= (m) && (m) <= 100000);
    ensures \result >= 0;
    ensures \result <= n + m;
*/
long func(long n, long m) {
    long ans = 0;
    long n_abs = 0;
    long m_abs = 0;
    
    //@ assert n >= 1 && n <= 100000;
    //@ assert m >= 1 && m <= 100000;
    
    n_abs = (n < 0) ? -n : n;
    m_abs = (m < 0) ? -m : m;
    
    //@ assert n_abs >= 0;
    //@ assert m_abs >= 0;
    //@ assert n_abs <= n;
    //@ assert m_abs <= m;
    
    if (n_abs > m_abs) {
        ans += m_abs;
        n_abs -= m_abs;
        ans += n_abs;
        
        //@ assert ans == m_abs + n_abs;
        //@ assert ans >= 0;
    } else {
        ans += n_abs;
        m_abs -= n_abs;
        ans += m_abs;
        
        //@ assert ans == n_abs + m_abs;
        //@ assert ans >= 0;
    }
    
    //@ assert ans <= n_abs + m_abs;
    //@ assert n_abs + m_abs <= n + m;
    //@ assert ans <= n + m;
    
    return ans;
}
