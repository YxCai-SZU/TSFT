#include <stdint.h>

/*@
    requires (1 <= (a) && (a) <= 1000000000 &&
        1 <= (b) && (b) <= 1000000000 &&
        1 <= (c) && (c) <= 1000000000 &&
        1 <= (k) && (k) <= 100000000000000000);
    ensures (-1000000000000 <= (\result) && (\result) <= 1000000000000);
    assigns \nothing;
*/
int64_t func(uint64_t a, uint64_t b, uint64_t c, uint64_t k)
{
    int64_t ans = 0;
    uint64_t temp_k = k;

    //@ assert (-1000000000000 <= (ans) && (ans) <= 1000000000000);
    //@ assert temp_k <= 100000000000000000;

    if (a > temp_k)
    {
        ans += (int64_t)temp_k;
        temp_k = 0;
    }
    else
    {
        ans += (int64_t)a;
        temp_k -= a;
    }

    //@ assert (-1000000000000 <= (ans) && (ans) <= 1000000000000);
    //@ assert temp_k <= 100000000000000000;

    if (b > temp_k)
    {
        temp_k = 0;
    }
    else
    {
        temp_k -= b;
    }

    //@ assert (-1000000000000 <= (ans) && (ans) <= 1000000000000);
    //@ assert temp_k <= 100000000000000000;

    if (c > temp_k)
    {
        //@ assert (-1000000000000 <= (ans) && (ans) <= 1000000000000);
        //@ assert temp_k <= 100000000000000000;
        ans -= (int64_t)temp_k;
        temp_k = 0;
    }
    else
    {
        //@ assert (-1000000000000 <= (ans) && (ans) <= 1000000000000);
        //@ assert c <= 1000000000;
        ans -= (int64_t)c;
        temp_k -= c;
    }

    //@ assert (-1000000000000 <= (ans) && (ans) <= 1000000000000);
    return ans;
}
