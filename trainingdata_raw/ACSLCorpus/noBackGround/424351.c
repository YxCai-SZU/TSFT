#include <limits.h>

/*@
    requires (1 <= (a) && (a) <= 100000 &&
        1 <= (b) && (b) <= 100000 &&
        1 <= (c) && (c) <= 100000 &&
        1 <= (k) && (k) <= (a) + (b) + (c) &&
        (a) + (b) + (c) >= 1);
    ensures -1 * c <= \result <= 1 * a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int a_remaining;
    int b_remaining;
    int c_remaining;
    int result;

    k_remaining = k;

    //@ assert k_remaining == k;

    if (a < k_remaining)
    {
        a_remaining = a;
    }
    else
    {
        a_remaining = k_remaining;
    }
    k_remaining -= a_remaining;

    //@ assert 0 <= a_remaining && a_remaining <= a;

    if (b < k_remaining)
    {
        b_remaining = b;
    }
    else
    {
        b_remaining = k_remaining;
    }
    k_remaining -= b_remaining;

    //@ assert 0 <= b_remaining && b_remaining <= b;

    if (c < k_remaining)
    {
        c_remaining = c;
    }
    else
    {
        c_remaining = k_remaining;
    }
    k_remaining -= c_remaining;

    //@ assert 0 <= c_remaining && c_remaining <= c;

    //@ assert a_remaining >= 0;
    //@ assert c_remaining >= 0;
    //@ assert a_remaining - c_remaining >= -1 * c;
    //@ assert a_remaining - c_remaining <= 1 * a;

    result = a_remaining - c_remaining;
    return result;
}
