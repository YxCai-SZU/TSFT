/*@
    predicate nonnegative(integer a, integer b, integer c) =
        a >= 0 && b >= 0 && c >= 0;

    predicate k_in_range(integer a, integer b, integer c, integer k) =
        1 <= k && k <= a + b + c;

    predicate ans_bounded(integer ans, integer k) =
        ans <= k;
*/

/*@
    requires nonnegative(a, b, c);
    requires k_in_range(a, b, c, k);
    ensures ans_bounded(\result, k);
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;

    //@ assert nonnegative(a, b, c);
    //@ assert k_in_range(a, b, c, k);

    if (a < rst)
    {
        ans += a;
        rst -= a;
    }
    else
    {
        ans += rst;
        rst = 0;
    }

    //@ assert ans_bounded(ans, k);

    if (b < rst)
    {
        rst -= b;
    }
    else
    {
        rst = 0;
    }

    ans -= rst;

    //@ assert ans_bounded(ans, k);
    return ans;
}
