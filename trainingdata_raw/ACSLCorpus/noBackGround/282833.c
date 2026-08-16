#include <stdbool.h>

/*@
    requires (1 <= (a) && (a) <= 50 &&
        1 <= (b) && (b) <= 50 &&
        1 <= (c) && (c) <= 50 &&
        1 <= (k) && (k) <= 50);
    ensures (-(k) <= (\result) && (\result) <= (k));
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int k_remaining;
    int old_k_remaining;

    ans = 0;
    k_remaining = k;

    //@ assert k_remaining == k;
    //@ assert ans == 0;

    if (a < k_remaining)
    {
        ans += a;
        k_remaining -= a;
        //@ assert ans == a;
        //@ assert k_remaining == k - a;
    }
    else
    {
        ans += k_remaining;
        k_remaining = 0;
        //@ assert ans == k;
        //@ assert k_remaining == 0;
    }

    //@ assert -k <= ans && ans <= k;
    //@ assert 0 <= k_remaining && k_remaining <= k;

    old_k_remaining = k_remaining;

    if (b < k_remaining)
    {
        k_remaining -= b;
        //@ assert k_remaining == old_k_remaining - b;
    }
    else
    {
        k_remaining = 0;
        //@ assert k_remaining == 0;
    }

    //@ assert 0 <= k_remaining && k_remaining <= k;
    ans -= k_remaining;

    //@ assert -k <= ans && ans <= k;
    return ans;
}
