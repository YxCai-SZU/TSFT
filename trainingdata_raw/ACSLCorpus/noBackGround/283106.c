#include <stdint.h>

/*@
    requires (1 <= (a) <= 100 &&
        1 <= (b) <= 100 &&
        1 <= (c) <= 100 &&
        1 <= (k) <= (a) + (b) + (c) &&
        (a) + (b) >= (k));
    ensures 0 <= \result <= k;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t cnt = 0;
    uint32_t a_cnt = a;
    uint32_t b_cnt = b;
    uint32_t c_cnt = c;
    uint32_t k_cnt = k;

    //@ assert (1 <= (a_cnt) <= 100 &&         1 <= (b_cnt) <= 100 &&         1 <= (c_cnt) <= 100 &&         1 <= (k_cnt) <= (a_cnt) + (b_cnt) + (c_cnt) &&         (a_cnt) + (b_cnt) >= (k_cnt));

    // Distribute as many candies as possible from A
    if (k_cnt >= a_cnt)
    {
        cnt += (int32_t)a_cnt;
        k_cnt -= a_cnt;
        a_cnt = 0;
    }
    else
    {
        cnt += (int32_t)k_cnt;
        a_cnt -= k_cnt;
        k_cnt = 0;
    }

    // We don't have any candies left to distribute
    if (k_cnt == 0)
    {
        //@ assert 0 <= cnt <= k;
        return cnt;
    }

    // At this point, we have distributed all candies from A and still have k_cnt candies left
    // Now we distribute from B
    if (k_cnt >= b_cnt)
    {
        k_cnt -= b_cnt;
        b_cnt = 0;
    }
    else
    {
        b_cnt -= k_cnt;
        k_cnt = 0;
    }

    // We still have candies left to distribute, which means we have to take from C
    if (k_cnt > 0)
    {
        cnt -= (int32_t)k_cnt;
        c_cnt -= k_cnt;
        k_cnt = 0;
    }

    //@ assert 0 <= cnt <= k;
    return cnt;
}
