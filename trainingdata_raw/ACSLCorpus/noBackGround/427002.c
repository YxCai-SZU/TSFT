#include <stdint.h>

/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result >= (110 * ((n) - (m)) + 190 * (m));
    ensures \result <= (190 * (n));
    assigns \nothing;
*/
int32_t func(uint32_t n, uint32_t m)
{
    int32_t res = 0;
    uint32_t i = 0;

    //@ ghost uint32_t m_val = m;
    //@ ghost uint32_t n_val = n;

    /*@
        loop invariant 0 <= i <= m_val;
        loop invariant res == 190 * (int32_t)i;
        loop invariant (1 <= (n_val) <= 100 && 1 <= (m_val) <= (n_val) && (m_val) <= 5);
        loop invariant res >= 0;
        loop invariant res <= (190 * (n_val));
        loop assigns i, res;
        loop variant m_val - i;
    */
    while (i < m)
    {
        res += 190;
        i += 1;
    }

    i = 0;

    /*@
        loop invariant 0 <= i <= n_val - m_val;
        loop invariant res == 190 * (int32_t)m_val + 110 * (int32_t)i;
        loop invariant (1 <= (n_val) <= 100 && 1 <= (m_val) <= (n_val) && (m_val) <= 5);
        loop invariant res >= 0;
        loop invariant res <= (190 * (n_val));
        loop assigns i, res;
        loop variant n_val - m_val - i;
    */
    while (i < (n - m))
    {
        res += 110;
        i += 1;
    }

    //@ assert res >= (110 * ((n_val) - (m_val)) + 190 * (m_val));
    //@ assert res <= (190 * (n_val));

    return res;
}
