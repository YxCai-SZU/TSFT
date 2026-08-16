#include <limits.h>

/*@
    predicate m_ge_13(integer m) = m >= 13;
    predicate m_eq_12(integer m) = m == 12;
    predicate m_le_11(integer m) = m <= 11;
    predicate m_between_11_13(integer m) = m > 11 && m < 13;
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures (m >= 13 ==> \result == 1) &&
            (m == 12 ==> \result == 2) &&
            (m <= 11 ==> \result == 3) ||
            \result == 4;
*/
int func(int n, int m)
{
    int res;
    
    if (m >= 13)
    {
        //@ assert m_ge_13(m);
        res = 1;
    }
    else if (m == 12)
    {
        //@ assert m_eq_12(m);
        res = 2;
    }
    else if (m <= 11)
    {
        //@ assert m_le_11(m);
        res = 3;
    }
    else
    {
        //@ assert m_between_11_13(m);
        res = 4;
    }
    
    return res;
}
