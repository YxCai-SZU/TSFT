/*@
    predicate valid_params(integer n, integer m) =
        1 <= n && 1 <= m && n <= 1000000000000 && m <= 1000000000000;

    logic integer func_spec(integer n, integer m) =
        m > 2 * n ? n + (m - 2 * n) / 4 : m / 2;

    lemma func_post_positive:
        \forall integer n, m; valid_params(n, m) ==> func_spec(n, m) >= 0;

    lemma func_post_bound:
        \forall integer n, m; valid_params(n, m) ==> func_spec(n, m) <= n + m / 2;
*/

/*@
    requires valid_params(n, m);
    ensures \result >= 0;
    ensures \result <= n + m / 2;
    assigns \nothing;
*/
unsigned long long func(unsigned long long n, unsigned long long m)
{
    unsigned long long s;

    if (m > 2 * n)
    {
        s = n + (m - 2 * n) / 4;
        //@ assert s == n + (m - 2 * n) / 4;
        //@ assert s <= n + m / 2;
    }
    else
    {
        s = m / 2;
        //@ assert s == m / 2;
        //@ assert s <= n + m / 2;
    }

    return s;
}
