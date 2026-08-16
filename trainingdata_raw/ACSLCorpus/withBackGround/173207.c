/*@
    predicate valid_params(integer n, integer k) =
        1 <= n <= 100000 &&
        0 <= k <= n - 1;

    predicate loop_invariant(integer i, integer n, integer k, integer ans, integer prev) =
        0 <= i <= k + 1 &&
        1 <= n <= 100000 &&
        0 <= k <= n - 1 &&
        ans >= 0 &&
        ans <= 2147483647 &&
        prev >= 0 &&
        prev <= 2147483647;

    logic integer compute_y(integer n, integer k, integer i) =
        (n - k + 1) < i ? (n - k + 1) : i;

    logic integer compute_x(integer i, integer y) = i - y;

    logic integer compute_sum(integer x, integer k) = x + (k - x) * 2;

    lemma ans_non_negative:
        \forall integer n, k, ans, prev;
        valid_params(n, k) && loop_invariant(k+1, n, k, ans, prev) ==> ans >= 0;
*/

/*@
    requires valid_params(n, k);
    ensures \result >= 0;
    assigns \nothing;
*/
long func(long n, long k)
{
    long ans = 2147483647;
    long i = 0;
    long prev = 0;
    long y;
    long x;
    long sum;

    /*@
        loop invariant loop_invariant(i, n, k, ans, prev);
        loop assigns i, ans, prev, y, x, sum;
        loop variant k + 1 - i;
    */
    while (i < k + 1)
    {
        //@ assert 0 <= i <= k + 1;
        
        if (n - k + 1 < i)
        {
            y = n - k + 1;
        }
        else
        {
            y = i;
        }
        //@ assert y == compute_y(n, k, i);
        
        x = i - y;
        //@ assert x == compute_x(i, y);
        
        sum = x + (k - x) * 2;
        //@ assert sum == compute_sum(x, k);
        
        if (sum < ans)
        {
            ans = sum;
        }
        //@ assert ans >= 0;
        
        prev = sum;
        i += 1;
    }
    //@ assert ans >= 0;
    return ans;
}
