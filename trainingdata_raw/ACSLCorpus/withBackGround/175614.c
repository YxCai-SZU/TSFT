#include <limits.h>

/*@
    predicate non_negative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate k_in_range(integer k, integer a, integer b, integer c) =
        1 <= k && k <= a + b + c;

    predicate sum_bounded(integer a, integer b, integer c) =
        a + b + c <= 2000000000;

    logic integer compute_ans(integer a_rem, integer k_rem) =
        a_rem - k_rem;

    lemma ans_bound:
        \forall integer a_rem, k_rem, k;
        a_rem <= k && k_rem >= 0 ==> compute_ans(a_rem, k_rem) <= k;
*/

/*@
    requires non_negative(a, b, c);
    requires k_in_range(k, a, b, c);
    requires sum_bounded(a, b, c);
    ensures \result <= k;
*/
int func(int a, int b, int c, int k)
{
    int k_remaining;
    int a_remaining;
    int b_remaining;
    int c_remaining;
    int ans;

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

    //@ assert a_remaining <= k;

    if (b < k_remaining)
    {
        b_remaining = b;
    }
    else
    {
        b_remaining = k_remaining;
    }
    k_remaining -= b_remaining;

    //@ assert b_remaining <= k;

    if (c < k_remaining)
    {
        c_remaining = c;
    }
    else
    {
        c_remaining = k_remaining;
    }
    k_remaining -= c_remaining;

    //@ assert c_remaining <= k;
    //@ assert k_remaining >= 0;

    ans = a_remaining - k_remaining;

    //@ assert ans == compute_ans(a_remaining, k_remaining);
    //@ assert ans <= k;

    return ans;
}
