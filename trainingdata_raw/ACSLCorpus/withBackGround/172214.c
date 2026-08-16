#include <stdint.h>

/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 &&
        1 <= m <= n &&
        m <= 5;

    logic integer compute_result(integer n, integer m) =
        100 * (n - m) + 1900 * m;
*/

/*@
    requires valid_params(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t n_;
    int32_t m_;
    int32_t ans;

    n_ = (int32_t)n;
    m_ = (int32_t)m;

    //@ assert valid_params(n, m);
    //@ assert n_ == (int32_t)n && m_ == (int32_t)m;
    //@ assert 100 * (n_ - m_) + 1900 * m_ == compute_result(n, m);

    ans = 100 * (n_ - m_) + 1900 * m_;
    return ans;
}
