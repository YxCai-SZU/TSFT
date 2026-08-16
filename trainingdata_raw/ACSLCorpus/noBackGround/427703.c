#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= a;
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t a_cnt;
    int64_t k_cnt;
    int64_t c_cnt;

    a_cnt = a;
    k_cnt = k;

    // Ticket A
    //@ assert a_cnt >= 0 && a_cnt <= a;
    if (k_cnt >= a_cnt)
    {
        k_cnt = k_cnt - a_cnt;
        //@ assert a_cnt >= 0 && a_cnt <= a;
        return a_cnt;
    }
    else
    {
        a_cnt = k_cnt;
    }

    // Ticket B
    //@ assert a_cnt >= 0 && a_cnt <= a;
    if (k_cnt >= b)
    {
        k_cnt = k_cnt - b;
    }
    else
    {
        k_cnt = 0;
    }

    // Ticket C
    //@ assert a_cnt >= 0 && a_cnt <= a;
    //@ assert k_cnt >= 0;
    if (k_cnt > c)
    {
        c_cnt = k_cnt - c;
    }
    else
    {
        c_cnt = 0;
    }

    // Final verification
    //@ assert a_cnt >= 0 && a_cnt <= a;
    //@ assert c_cnt >= 0 && c_cnt <= k_cnt;
    //@ assert a_cnt - c_cnt >= 0 && a_cnt - c_cnt <= a_cnt;

    return a_cnt - c_cnt;
}
