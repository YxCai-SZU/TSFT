/*@
    predicate valid_params(integer N, integer M) =
        1 <= N && N <= 100 && N <= M && M <= N * 2;

    logic integer expected_result(integer N, integer M) =
        M - N + 1;
*/

/*@
    requires valid_params(N, M);
    ensures \result == expected_result(N, M);
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int M)
{
    unsigned int res;

    //@ assert M - N + 1 == M - N + 1;
    res = M - N + 1;
    return res;
}
