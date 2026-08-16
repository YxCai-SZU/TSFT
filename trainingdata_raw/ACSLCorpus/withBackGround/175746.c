/*@
    predicate valid_range(integer n, integer m) =
        1 <= n && n <= 20 && 1 <= m && m <= 20;

    logic integer compute_l(integer m) = m / 2 + m % 2;

    lemma result_bounds:
        \forall integer n, m, result;
        valid_range(n, m) ==>
        (result == (m > n ? m - n + 1 : (n - compute_l(m)) * 2 + 1)) ==>
        1 <= result && result <= 40;
*/

/*@
    requires valid_range(n, m);
    ensures \result <= 40;
    ensures \result >= 1;
    assigns \nothing;
*/
unsigned int func(unsigned int n, unsigned int m)
{
    unsigned int temp;
    unsigned int l;
    unsigned int ans;

    //@ assert valid_range(n, m);

    if (n > m)
    {
        temp = m;
        m = n;
        n = temp;
    }

    l = m / 2 + m % 2;
    //@ assert l == compute_l(m);

    if (l > n)
    {
        //@ assert m - n + 1 <= 40;
        return m - n + 1;
    }
    else
    {
        ans = n - l;
        //@ assert ans * 2 + 1 >= 1;
        return ans * 2 + 1;
    }
}
