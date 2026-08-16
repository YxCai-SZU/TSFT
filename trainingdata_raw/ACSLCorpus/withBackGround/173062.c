#include <stdbool.h>

/*@
    predicate m_ge_13(integer m) = m >= 13;
    predicate m_in_6_to_12(integer m) = 6 <= m && m < 13;
    predicate m_le_5(integer m) = m <= 5;
*/

/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result == n || \result == n + 1 || \result == n + (m - 1) * 2;
    ensures m_ge_13(m) ==> \result == n;
    ensures m_in_6_to_12(m) ==> \result == n + 1;
    ensures m_le_5(m) ==> \result == n + (m - 1) * 2;
*/
int func(int n, int m)
{
    int result;
    result = n;

    if (m > 12)
    {
        result = n;
        //@ assert m_ge_13(m) ==> result == n;
    }
    else if (m >= 6)
    {
        result = n + 1;
        //@ assert m_in_6_to_12(m) ==> result == n + 1;
    }
    else
    {
        result = n + (m - 1) * 2;
        //@ assert m_le_5(m) ==> result == n + (m - 1) * 2;
    }

    //@ assert (m_ge_13(m) ==> result == n) && (m_in_6_to_12(m) ==> result == n + 1) && (m_le_5(m) ==> result == n + (m - 1) * 2);
    return result;
}
