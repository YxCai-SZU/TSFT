#include <limits.h>

/*@
    requires (0 <= (a) && 0 <= (b) && 0 <= (c) &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int a_cnt;
    int k_cnt;
    int b_cnt;
    int c_cnt;

    //@ assert 0 <= a && 0 <= b && 0 <= c && 1 <= k;
    //@ assert k <= a + b + c && k <= 2000000000;

    if (a < k)
    {
        a_cnt = a;
    }
    else
    {
        a_cnt = k;
    }

    //@ assert a_cnt <= k;
    //@ assert k - a_cnt >= 0;

    k_cnt = k - a_cnt;

    if (b < k_cnt)
    {
        b_cnt = b;
    }
    else
    {
        b_cnt = k_cnt;
    }

    k_cnt -= b_cnt;

    if (c < k_cnt)
    {
        c_cnt = c;
    }
    else
    {
        c_cnt = k_cnt;
    }

    //@ assert a_cnt - c_cnt <= k;
    return a_cnt - c_cnt;
}
