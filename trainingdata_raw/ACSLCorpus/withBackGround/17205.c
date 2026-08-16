/*@
    predicate valid_params(integer n, integer k, integer a) =
        1 <= n <= 100 &&
        1 <= k <= n &&
        1 <= a <= 1000000000;

    predicate loop_invariant(integer i, integer n, integer k, integer a, integer cnt, integer ans) =
        0 <= i <= n &&
        0 <= cnt <= i &&
        0 <= ans <= i &&
        valid_params(n, k, a);
*/

/*@
    requires valid_params(n, k, a);
    ensures 0 <= \result <= n;
    assigns \nothing;
*/
long func(long n, long k, long a)
{
    long ans;
    long cnt;
    long i;

    ans = 0;
    cnt = 0;
    i = 0;

    /*@
        loop invariant loop_invariant(i, n, k, a, cnt, ans);
        loop assigns i, cnt, ans;
        loop variant n - i;
    */
    while (i < n)
    {
        cnt = cnt + 1;

        if ((a + cnt) < k)
        {
            ans = ans + 1;
        }
        else if ((a + cnt) == k)
        {
            ans = ans + 1;
            cnt = 0;
        }
        else
        {
            cnt = 0;
        }

        i = i + 1;
    }

    return ans;
}
