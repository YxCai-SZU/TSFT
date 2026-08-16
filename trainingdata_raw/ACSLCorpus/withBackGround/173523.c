/*@
    predicate valid_params(integer N, integer M) =
        1 <= N && N <= 20 &&
        1 <= M && M <= 20;

    logic integer product(integer N, integer M) = N * M;

    lemma product_bounds: \forall integer N, M;
        valid_params(N, M) ==> 1 <= product(N, M) && product(N, M) <= 400;

    lemma result_range: \forall integer N, M, r;
        valid_params(N, M) && (r == product(N, M) - 1 || r == product(N, M)) ==>
        r >= 0;
*/

/*@
    requires valid_params(N, M);
    ensures \result == product(N, M) - 1 || \result == product(N, M);
    assigns \nothing;
*/
int func(int N, int M)
{
    int ans;

    //@ assert valid_params(N, M);
    //@ assert product(N, M) >= 1 && product(N, M) <= 400;
    //@ assert product(N, M) - 1 >= 0;

    ans = N * M - 1;

    //@ assert ans == product(N, M) - 1 || ans == product(N, M);

    return ans;
}
