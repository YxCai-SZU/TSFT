/*@
    predicate valid_range(integer x) = 1 <= x && x <= 20;

    logic integer compute_result(integer n, integer m) =
        (n > 9 || m > 9) ? -1 : n * m;

    lemma product_bound: \forall integer n, m;
        (1 <= n && n <= 9 && 1 <= m && m <= 9) ==> n * m <= 81;
*/

/*@
    requires valid_range(n) && valid_range(m);
    ensures (n > 9 || m > 9) ==> \result == -1;
    ensures (n <= 9 && m <= 9) ==> \result == n * m;
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans;

    if (n > 9 || m > 9) {
        ans = -1;
    } else {
        //@ assert 1 <= n && n <= 9;
        //@ assert 1 <= m && m <= 9;
        //@ assert n * m <= 81;
        ans = n * m;
    }
    return ans;
}
