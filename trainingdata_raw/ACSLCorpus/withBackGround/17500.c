#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 20;

    logic integer compute_result(integer n, integer m) =
        m < 10 ? n * m : n * -1;

    lemma result_bounds_m_lt_10:
        \forall integer n, m;
            valid_range(n) && valid_range(m) && m < 10 ==>
                n * m >= 1 && n * m <= 180;

    lemma result_bounds_m_ge_10:
        \forall integer n, m;
            valid_range(n) && valid_range(m) && m >= 10 ==>
                n * -1 >= -20 && n * -1 <= -1;
*/

/*@
    requires valid_range(n);
    requires valid_range(m);
    ensures (m < 10 ==> \result == n * m);
    ensures (m >= 10 ==> \result == n * -1);
    ensures INT_MIN <= \result <= INT_MAX;
*/
int func(int n, int m)
{
    // Declare all variables at the top
    int result;

    if (m < 10)
    {
        //@ assert 1 <= n <= 20;
        //@ assert 1 <= m < 10;
        //@ assert n * m >= 1 && n * m <= 180;
        result = n * m;
    }
    else
    {
        //@ assert 1 <= n <= 20;
        //@ assert 10 <= m <= 20;
        //@ assert n * -1 >= -20 && n * -1 <= -1;
        result = n * -1;
    }

    return result;
}
