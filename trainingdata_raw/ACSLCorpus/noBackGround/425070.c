#include <stdint.h>
/*@
    requires (1 <= (n) && (n) <= 100 &&
        1 <= (m) && (m) <= (n) &&
        (m) <= 5);
    ensures \result == (100 * ((n) - (m)) + 1900 * (m));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t n_;
    int32_t m_;
    int32_t ans;

    n_ = (int32_t)n;
    m_ = (int32_t)m;
    ans = 100 * (n_ - m_) + 1900 * m_;

    //@ assert 1 <= n_ && n_ <= 100;
    //@ assert 1 <= m_ && m_ <= n_ && m_ <= 5;
    //@ assert 0 <= n_ - m_ && n_ - m_ <= 100;
    //@ assert 0 <= 100 * (n_ - m_) && 100 * (n_ - m_) <= 10000;
    //@ assert 0 <= 1900 * m_ && 1900 * m_ <= 9500;
    //@ assert 0 <= 100 * (n_ - m_) + 1900 * m_ && 100 * (n_ - m_) + 1900 * m_ <= 19500;
    //@ assert ans == 100 * (n_ - m_) + 1900 * m_;
    //@ assert ans == 100 * ((int32_t)n - (int32_t)m) + 1900 * (int32_t)m;

    return ans;
}
