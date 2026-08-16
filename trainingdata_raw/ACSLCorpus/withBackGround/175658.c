/*@
    predicate valid_input(integer n, integer m) =
        1 <= n && n <= 100 &&
        1 <= m && m <= 100;

    logic integer compute_result(integer n, integer m) =
        (n - 1) * m;

    lemma bounds_lemma:
        \forall integer n_s, integer m;
        (0 <= n_s && n_s <= 99 && 1 <= m && m <= 100) ==>
        0 <= n_s * m <= 99 * 100;
*/

/*@
    requires valid_input(n, m);
    ensures \result == compute_result(n, m);
    assigns \nothing;
*/
int func(int n, int m)
{
    int n_s;
    int res;

    //@ assert valid_input(n, m);
    n_s = n - 1;
    //@ assert 0 <= n_s && n_s <= 99;
    //@ assert 1 <= m && m <= 100;
    //@ assert 0 <= n_s * m <= 99 * 100;
    res = n_s * m;
    //@ assert res == compute_result(n, m);
    return res;
}
