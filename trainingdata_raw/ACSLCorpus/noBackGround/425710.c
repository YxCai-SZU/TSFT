#include <stdint.h>
/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result <= a + b + c;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    uint32_t ans = 0;
    uint32_t a_cnt = a;
    uint32_t b_cnt = b;
    uint32_t c_cnt = c;
    uint32_t k_cnt = k;

    //@ assert a_cnt <= a;
    if (k_cnt > a_cnt)
    {
        ans += a_cnt;
        k_cnt -= a_cnt;
        a_cnt = 0;
    }
    else
    {
        ans += k_cnt;
        a_cnt -= k_cnt;
        k_cnt = 0;
    }

    //@ assert b_cnt <= b;
    if (k_cnt > b_cnt)
    {
        b_cnt = 0;
        k_cnt -= b_cnt;
    }
    else
    {
        b_cnt -= k_cnt;
        k_cnt = 0;
    }

    //@ assert c_cnt <= c;
    if (k_cnt > c_cnt)
    {
        c_cnt = 0;
        k_cnt -= c_cnt;
    }
    else
    {
        c_cnt -= k_cnt;
        k_cnt = 0;
    }

    return ans;
}
