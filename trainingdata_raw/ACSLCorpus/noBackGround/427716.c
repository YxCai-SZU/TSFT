#include <stdint.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result >= -c;
    ensures \result <= a;
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b, int32_t c, int32_t k)
{
    int32_t a_cnt = a;
    int32_t b_cnt = b;
    int32_t c_cnt = c;
    int32_t k_cnt = k;
    int32_t sum = 0;

    //@ assert (0 <= (a_cnt) && 0 <= (b_cnt) && 0 <= (c_cnt) &&         1 <= (k_cnt) && (k_cnt) <= (a_cnt) + (b_cnt) + (c_cnt) && (k_cnt) <= 2000000000);

    if (a_cnt > k_cnt)
    {
        sum += k_cnt;
        k_cnt = 0;
    }
    else
    {
        sum += a_cnt;
        k_cnt -= a_cnt;
    }

    //@ assert sum == (a > k ? k : a);
    //@ assert k_cnt == (a > k ? 0 : k - a);

    if (b_cnt > k_cnt)
    {
        k_cnt = 0;
    }
    else
    {
        k_cnt -= b_cnt;
    }

    //@ assert k_cnt == (a > k ? 0 : (k - a > b ? k - a - b : 0));

    sum -= k_cnt;

    //@ assert sum == ((k) <= (a) ? (k) : (a) - ((k) - (a) <= (b) ? 0 : (k) - (a) - (b)));
    //@ assert sum >= -c;
    //@ assert sum <= a;

    return sum;
}
