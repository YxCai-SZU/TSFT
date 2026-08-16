/*@
    predicate valid_params(integer N, integer M) =
        2 <= N && N <= 100 &&
        2 <= M && M <= 100;

    logic integer compute_result(integer N, integer M) =
        (N - 1) * (M - 1);

    lemma bounds_lemma:
        \forall integer N, M;
        valid_params(N, M) ==>
        N - 1 >= 1 && N - 1 <= 99 &&
        M - 1 >= 1 && M - 1 <= 99 &&
        (N - 1) * (M - 1) <= 99 * 99;
*/

/*@
    requires valid_params(N, M);
    ensures \result == compute_result(N, M);
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int M)
{
    // Variable declarations at top of scope
    unsigned int result;

    //@ assert N > 1 && N <= 100;
    //@ assert M > 1 && M <= 100;
    //@ assert N - 1 >= 1;
    //@ assert M - 1 >= 1;
    //@ assert N - 1 <= 99;
    //@ assert M - 1 <= 99;
    //@ assert (N - 1) * (M - 1) <= 99 * 99;

    result = (N - 1) * (M - 1);
    return result;
}
