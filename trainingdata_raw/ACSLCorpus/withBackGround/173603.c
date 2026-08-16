/*@
    predicate valid_range(integer N, integer M) =
        2 <= N <= 100 && 2 <= M <= 100;

    logic integer compute_result(integer N, integer M) =
        (N - 1) * (M - 1);

    lemma bounds_lemma:
        \forall integer N, M;
        valid_range(N, M) ==> 1 <= compute_result(N, M) <= 99 * 99;
*/

/*@
    requires valid_range(N, M);
    ensures \result == compute_result(N, M);
    assigns \nothing;
*/
long func(long N, long M)
{
    long ans;
    //@ assert valid_range(N, M);
    //@ assert 1 <= N - 1 <= 99;
    //@ assert 1 <= M - 1 <= 99;
    //@ assert 1 <= (N - 1) * (M - 1) <= 99 * 99;
    ans = (N - 1) * (M - 1);
    //@ assert ans == compute_result(N, M);
    return ans;
}
