#include <stdint.h>

/*@
    requires ((a) >= 0 && (b) >= 0 && (c) >= 0 && 1 <= (k) && (k) <= (a) + (b) + (c));
    ensures \result <= k;
    ensures \result >= -c;
*/
int64_t func(int64_t a, int64_t b, int64_t c, int64_t k)
{
    int64_t r;
    int64_t k_remaining;
    int64_t b_remaining;
    int64_t c_remaining;
    int64_t s;

    //@ assert ((a) >= 0 && (b) >= 0 && (c) >= 0 && 1 <= (k) && (k) <= (a) + (b) + (c));

    if (a >= k)
    {
        r = k;
    }
    else
    {
        r = a;
    }
    //@ assert r == ((a) >= (k) ? (k) : (a));

    if (a >= k)
    {
        k_remaining = 0;
    }
    else
    {
        k_remaining = k - a;
    }
    //@ assert k_remaining == ((a) >= (k) ? 0 : (k) - (a));

    if (b >= k_remaining)
    {
        b_remaining = k_remaining;
    }
    else
    {
        b_remaining = b;
    }
    //@ assert b_remaining == ((b) >= (k_remaining) ? (k_remaining) : (b));

    if (c >= (k_remaining - b_remaining))
    {
        c_remaining = k_remaining - b_remaining;
    }
    else
    {
        c_remaining = c;
    }
    //@ assert c_remaining == ((c) >= ((k_remaining) - (b_remaining)) ? (k_remaining) - (b_remaining) : (c));

    s = r - c_remaining;
    //@ assert s == ((r) - (c_remaining));

    //@ assert s <= k;
    //@ assert s >= -c;

    return s;
}
