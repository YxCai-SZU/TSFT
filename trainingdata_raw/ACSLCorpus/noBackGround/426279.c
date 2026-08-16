#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 100 &&
        1 <= (b) && (b) <= 100 &&
        1 <= (c) && (c) <= 100 &&
        (a) + (b) + (c) >= 1 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 200);
    ensures \result >= -1 * (int)c;
    ensures \result <= (int)a;
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b, uint32_t c, uint32_t k)
{
    int32_t ans = 0;
    uint32_t k_flag = 0;

    //@ assert (1 <= (a) && (a) <= 100 &&         1 <= (b) && (b) <= 100 &&         1 <= (c) && (c) <= 100 &&         (a) + (b) + (c) >= 1 &&         1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 200);

    if (k <= a)
    {
        ans += (int32_t)k;
        //@ assert ans == (int32_t)k;
    }
    else
    {
        ans += (int32_t)a;
        k_flag += k - a;
        //@ assert ans == (int32_t)a;
        //@ assert k_flag == k - a;
    }

    //@ assert ans >= -1 * (int32_t)c || k_flag <= b;
    if (k_flag > b)
    {
        //@ assert k_flag - b <= 100;
        //@ assert ans >= -1 * (int32_t)c;
        ans -= (int32_t)(k_flag - b);
    }

    //@ assert ans >= -1 * (int32_t)c;
    //@ assert ans <= (int32_t)a;
    return ans;
}
