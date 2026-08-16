#include <limits.h>

/*@
    predicate is_nonnegative(integer x) = x >= 0;
    predicate is_bounded(integer x) = 0 <= x <= 99;
    predicate product_bounded(integer a, integer b) = 0 <= a * b <= 9801;
*/

/*@
    logic integer max_zero(integer x) = (x > 0) ? x : 0;
*/

/*@
    lemma max_zero_nonnegative:
        \forall integer x; max_zero(x) >= 0;
    
    lemma max_zero_bounded:
        \forall integer x; 2 <= x <= 100 ==> max_zero(x - 1) <= 99;
    
    lemma product_correctness:
        \forall integer n, m;
            2 <= n <= 100 && 2 <= m <= 100 ==>
            max_zero(n - 1) * max_zero(m - 1) == (n - 1) * (m - 1);
*/

/*@
    requires 2 <= n <= 100;
    requires 2 <= m <= 100;
    ensures \result == (n - 1) * (m - 1);
    assigns \nothing;
*/
int func(int n, int m)
{
    int n_max;
    int m_max;
    int result;
    
    //@ assert 2 <= n <= 100;
    //@ assert 2 <= m <= 100;
    
    // Calculate max(0, n-1)
    if (n - 1 > 0) {
        n_max = n - 1;
    } else {
        n_max = 0;
    }
    
    // Calculate max(0, m-1)
    if (m - 1 > 0) {
        m_max = m - 1;
    } else {
        m_max = 0;
    }
    
    // Verification properties
    //@ assert n_max == max_zero(n - 1);
    //@ assert m_max == max_zero(m - 1);
    //@ assert is_nonnegative(n_max);
    //@ assert is_nonnegative(m_max);
    //@ assert is_bounded(n_max);
    //@ assert is_bounded(m_max);
    //@ assert product_bounded(n_max, m_max);
    
    result = n_max * m_max;
    
    // Final correctness check
    //@ assert result == (n - 1) * (m - 1);
    
    return result;
}
