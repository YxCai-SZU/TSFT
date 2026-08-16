/*@
    predicate nonnegative(integer x) = x >= 0;
    predicate within_sum(integer x, integer n, integer m) = x <= n + m;
    predicate min_le(integer min_val, integer n, integer m) = min_val <= n && min_val <= m;
    logic integer min_val(integer n, integer m) = (n < m) ? n : m;
    lemma min_val_le: \forall integer n, m; min_val(n, m) <= n && min_val(n, m) <= m;
    lemma two_min_le_sum: \forall integer n, m; 1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000 && min_val(n, m) <= n && min_val(n, m) <= m ==> 2 * min_val(n, m) <= n + m;
*/

/*@
    requires 1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;
    ensures \result >= 0;
    ensures \result <= n + m;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    unsigned long long min_val;
    unsigned long long ans;

    if (n < m)
    {
        min_val = n;
    }
    else
    {
        min_val = m;
    }

    //@ assert min_val <= n && min_val <= m;

    //@ assert 2 * min_val <= n + m;

    if (2 * min_val > n + m)
    {
        ans = min_val;
    }
    else
    {
        ans = (n + m - 1) / 4 + min_val;
    }

    //@ assert ans >= 0;
    //@ assert ans <= n + m;

    return ans;
}
