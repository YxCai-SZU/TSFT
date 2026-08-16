#include <stdbool.h>

/*@
    predicate is_valid_params(integer n, integer m) =
        1 <= n <= 20 && 1 <= m <= 20;

    predicate m_le_5(integer m) = m <= 5;
    predicate m_gt_5(integer m) = m > 5;
*/

/*@
    requires is_valid_params(n, m);
    ensures m_le_5(m) ==> \result == 0;
    ensures m_gt_5(m) ==> \result == n;
*/
int func(int n, int m)
{
    // Variable declarations at top of scope
    int result;

    if (m <= 5)
    {
        result = 0;
        //@ assert m_le_5(m);
    }
    else
    {
        //@ assert m_gt_5(m);
        //@ assert n >= 1 && n <= 20;
        //@ assert m >= 1 && m <= 20;
        result = n;
    }

    return result;
}
