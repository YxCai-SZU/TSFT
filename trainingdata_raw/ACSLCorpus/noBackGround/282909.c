#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 &&
        1 <= (k) && (k) <= (a) + (b) + (c) && (a) + (b) + (c) <= 2000000000);
    ensures \result <= k;
    ensures \result == ((k) <= (a) ? (k) :
        (k) <= (a) + (b) ? (a) :
        (a) - ((k) - (a) - (b)));
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t ans = 0;
    int64_t k_remaining = k;

    //@ assert k_remaining == k;

    if (k_remaining <= a)
    {
        ans = k_remaining;
        //@ assert ans == k;
    }
    else
    {
        k_remaining -= a;
        ans = a;
        //@ assert ans == a && k_remaining == k - a;

        if (k_remaining <= b)
        {
            k_remaining = 0;
            //@ assert ans == a;
        }
        else
        {
            k_remaining -= b;
            //@ assert k_remaining == k - a - b;

            //@ assert k_remaining >= 0;
            //@ assert ans >= 0;
            //@ assert k_remaining <= a + b + c - a - b;
            //@ assert ans <= k;

            ans -= k_remaining;
            //@ assert ans == a - (k - a - b);
        }
    }

    //@ assert ans <= k;
    return ans;
}
