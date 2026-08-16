#include <stdbool.h>

/*@
    predicate n_condition(integer a, integer n) = a < n;
    predicate m_condition(integer b, integer m) = b < m;
*/

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    requires 0 <= a <= n;
    requires 0 <= b <= m;
    ensures \result == (a < n && b < m);
*/
bool func(int n, int m, int a, int b)
{
    bool n_flag;
    bool m_flag;
    
    n_flag = false;
    m_flag = false;
    
    if (a < n) {
        n_flag = true;
    }
    
    //@ assert n_flag == (a < n);
    
    if (b < m) {
        m_flag = true;
    }
    
    //@ assert m_flag == (b < m);
    
    return n_flag && m_flag;
}
