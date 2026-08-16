#include <limits.h>

/*@
    predicate valid_input(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer expected_result(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
        valid_input(n, m) ==> 1 <= n - 1 <= 99 && 1 <= m - 1 <= 99;

    lemma product_bounds_lemma:
        \forall integer n, m;
        valid_input(n, m) ==> 1 <= expected_result(n, m) <= 9801;
*/

/*@
    requires valid_input(n, m);
    ensures \result == expected_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    // Variable declarations at scope top
    int n_minus_1;
    int m_minus_1;
    int result;

    //@ assert 2 <= n <= 100;
    //@ assert 2 <= m <= 100;

    n_minus_1 = n - 1;
    m_minus_1 = m - 1;

    //@ assert 1 <= n_minus_1 <= 99;
    //@ assert 1 <= m_minus_1 <= 99;

    result = n_minus_1 * m_minus_1;

    //@ assert result == (n - 1) * (m - 1);
    return result;
}
