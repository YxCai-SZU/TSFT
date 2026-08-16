#include <stdint.h>

/*@
    requires (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100 && 1 <= (k) <= 3);
    ensures \result >= -100 && \result <= 100;
    ensures \result == ((k) > (a) ?
            ((k) > (a) + (b) ?
                ((k) > (a) + (b) + (c) ? (a) - (c) : (a) - ((k) - (a) - (b)))
                : (a))
            : (k));
*/
int32_t func(int32_t a, int32_t b, int32_t c, int64_t k)
{
    int32_t ans = 0;
    int64_t k_mut = k;

    //@ assert (0 <= (a) <= 100 && 0 <= (b) <= 100 && 0 <= (c) <= 100 && 1 <= (k) <= 3);
    //@ assert k_mut == k;

    if (k > (int64_t)a)
    {
        ans += a;
        k_mut -= (int64_t)a;
        //@ assert ans == a && k_mut == k - a;
    }
    else
    {
        ans += (int32_t)k;
        //@ assert ans == k && ans == ((k) > (a) ?             ((k) > (a) + (b) ?                 ((k) > (a) + (b) + (c) ? (a) - (c) : (a) - ((k) - (a) - (b)))                 : (a))             : (k));
        return ans;
    }

    if (k_mut > (int64_t)b)
    {
        k_mut -= (int64_t)b;
        //@ assert k_mut == k - a - b;
    }
    else
    {
        //@ assert ans == a && ans == ((k) > (a) ?             ((k) > (a) + (b) ?                 ((k) > (a) + (b) + (c) ? (a) - (c) : (a) - ((k) - (a) - (b)))                 : (a))             : (k));
        return ans;
    }

    if (k_mut > (int64_t)c)
    {
        ans -= c;
        k_mut -= (int64_t)c;
        //@ assert ans == a - c && k_mut == k - a - b - c;
    }
    else
    {
        ans -= (int32_t)k_mut;
        //@ assert ans == a - (k - a - b) && ans == ((k) > (a) ?             ((k) > (a) + (b) ?                 ((k) > (a) + (b) + (c) ? (a) - (c) : (a) - ((k) - (a) - (b)))                 : (a))             : (k));
    }

    //@ assert ans >= -100;
    return ans;
}
