#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 && 1 <= (b) <= 100 && 1 <= (c) <= 100 && 1 <= (k) <= (a) + (b) + (c));
    ensures \result >= -(int)k && \result <= (int)k;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t result = 0;
    uint32_t a_cnt = a;
    uint32_t b_cnt = b;
    uint32_t c_cnt = c;
    uint32_t k_cnt = k;

    //@ assert a_cnt == a;
    //@ assert k_cnt == k;
    if (k_cnt >= a_cnt)
    {
        result += (int32_t)a_cnt;
        k_cnt -= a_cnt;
    }
    else
    {
        result += (int32_t)k_cnt;
        a_cnt -= k_cnt;
        k_cnt = 0;
    }

    //@ assert b_cnt == b;
    //@ assert k_cnt <= k;
    if (k_cnt >= b_cnt)
    {
        k_cnt -= b_cnt;
    }
    else
    {
        k_cnt = 0;
    }

    //@ assert c_cnt == c;
    //@ assert k_cnt <= k;
    if (k_cnt >= c_cnt)
    {
        result -= (int32_t)c_cnt;
        k_cnt -= c_cnt;
    }
    else
    {
        result -= (int32_t)k_cnt;
        c_cnt -= k_cnt;
        k_cnt = 0;
    }

    //@ assert result >= -(int32_t)k;
    return result;
}
