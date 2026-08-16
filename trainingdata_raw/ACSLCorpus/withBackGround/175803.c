#include <stdint.h>

/*@
    predicate valid_range(integer n, integer m) =
        2 <= n <= 100 && 2 <= m <= 100;

    logic integer product(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma product_bounds:
        \forall integer n, m;
            valid_range(n, m) ==>
            1 <= (n - 1) <= 99 &&
            1 <= (m - 1) <= 99 &&
            (n - 1) * (m - 1) <= 99 * 99;
*/

/*@
    requires valid_range(n, m);
    ensures \result == product(n, m);
    assigns \nothing;
*/
int64_t func(int64_t n, int64_t m)
{
    int64_t n_minus_1;
    int64_t m_minus_1;
    int64_t ans;

    n_minus_1 = n - 1;
    m_minus_1 = m - 1;

    //@ assert n_minus_1 >= 1;
    //@ assert m_minus_1 >= 1;
    //@ assert n_minus_1 <= 99;
    //@ assert m_minus_1 <= 99;
    //@ assert n_minus_1 * m_minus_1 <= 99 * 99;

    ans = n_minus_1 * m_minus_1;

    return ans;
}
