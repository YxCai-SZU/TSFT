#include <stdint.h>

/*@
  requires a >= 0 && b >= 0 && c >= 0 && k >= 1;
  requires a + b + c >= k;
  ensures \result >= -c;
  ensures \result <= a;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_cnt;
    int32_t k_cnt;
    int32_t c_cnt;
    int32_t ans;

    a_cnt = a;
    k_cnt = k;

    // takes A
    if (k_cnt >= a_cnt)
    {
        k_cnt = k_cnt - a_cnt;
    }
    else
    {
        a_cnt = k_cnt;
        k_cnt = 0;
    }

    // takes B
    //@ assert k_cnt >= 0 && b >= 0;
    if (k_cnt >= b)
    {
        k_cnt = k_cnt - b;
    }
    else
    {
        k_cnt = 0;
    }

    // takes C
    if (k_cnt < c)
    {
        c_cnt = k_cnt;
    }
    else
    {
        c_cnt = c;
    }

    ans = a_cnt - c_cnt;

    //@ assert ans >= -c && ans <= a;

    return ans;
}
