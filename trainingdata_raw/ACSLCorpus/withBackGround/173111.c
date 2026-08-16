/*@
    predicate valid_params(integer N, integer M) =
        1 <= N && N <= 1000000000 &&
        1 <= M && M <= 1000000000;

    predicate post_condition(integer N, integer M, integer res) =
        (N == 1 && M == 1 ==> res == 1) &&
        ((N == 1 || M == 1) && !(N == 1 && M == 1) ==> res == 0) &&
        (N > 1 && M > 1 ==> res == (N - 2) * (M - 2));
*/

/*@
    requires valid_params(N, M);
    ensures post_condition(N, M, \result);
*/
long func(long N, long M)
{
    long res;

    //@ assert valid_params(N, M);

    if (N == 1 && M == 1) {
        res = 1;
    } else if (N == 1 || M == 1) {
        res = 0;
    } else {
        //@ assert N > 1 && M > 1;
        //@ assert N - 2 >= 0 && M - 2 >= 0;
        //@ assert (N - 2) * (M - 2) <= 1000000000 * 1000000000;
        res = (N - 2) * (M - 2);
    }

    //@ assert post_condition(N, M, res);
    return res;
}
