#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        (k) >= 1 && (k) <= (a) + (b) + (c) && (k) <= 2000000000);
    ensures \result <= k;
    ensures \result == ((k) >= (a) ?
            ((k) >= (a) + (b) ?
                ((k) >= (a) + (b) + (c) ? (a) - (c) : (a) - ((k) - (a) - (b)))
                : (a))
            : (k));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t a_local = a;
    int64_t k_local = k;
    int64_t ans = 0;

    // takes A
    //@ assert ((a_local) >= 0 && (b) >= 0 && (c) >= 0 &&         (k_local) >= 1 && (k_local) <= (a_local) + (b) + (c) && (k_local) <= 2000000000);
    if (k_local >= a_local)
    {
        ans += a_local;
        k_local -= a_local;
        //@ assert ans == a_local && k_local == k - a_local;
    }
    else
    {
        ans += k_local;
        //@ assert ans == k_local && ans <= k;
        return ans;
    }

    // takes B
    //@ assert ans == a_local && k_local == k - a_local;
    if (k_local >= b)
    {
        k_local -= b;
        //@ assert k_local == k - a_local - b;
    }
    else
    {
        k_local = 0;
        //@ assert k_local == 0;
    }

    // takes C
    //@ assert ans == a_local;
    if (k_local >= c)
    {
        ans -= c;
        //@ assert ans == a_local - c;
    }
    else
    {
        ans -= k_local;
        //@ assert ans == a_local - k_local;
    }

    //@ assert ans <= a_local;
    return ans;
}
