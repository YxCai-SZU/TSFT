/*@
    predicate valid_range(integer n, integer m) =
        2 <= n && n <= 100 &&
        2 <= m && m <= 100;

    logic integer func_spec(integer n, integer m) =
        (n - 1) * (m - 1);

    lemma bounds_lemma:
        \forall integer n, m;
        valid_range(n, m) ==>
        1 <= n - 1 && n - 1 <= 99 &&
        1 <= m - 1 && m - 1 <= 99;

    lemma product_bounds_lemma:
        \forall integer a, b;
        1 <= a && a <= 99 &&
        1 <= b && b <= 99 ==>
        1 <= a * b && a * b <= 9801;
*/

/*@
    requires valid_range(n, m);
    ensures \result == func_spec(n, m);
    assigns \nothing;
*/
long func(long n, long m)
{
    long n_minus_1;
    long m_minus_1;
    long res;

    n_minus_1 = n - 1;
    m_minus_1 = m - 1;

    //@ assert 1 <= n_minus_1 && n_minus_1 <= 99;
    //@ assert 1 <= m_minus_1 && m_minus_1 <= 99;
    //@ assert 1 <= n_minus_1 * m_minus_1 && n_minus_1 * m_minus_1 <= 9801;

    res = n_minus_1 * m_minus_1;
    return res;
}
