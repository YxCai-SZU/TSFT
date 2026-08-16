/*@
    predicate valid_params(integer N, integer M) =
        1 <= N && N <= 1000000000000 &&
        1 <= M && M <= 1000000000000;

    logic integer func_spec(integer N, integer M) =
        (2 * N < M) ? (N + ((M - 2 * N) / 4)) : (M / 2);

    lemma ans_bounds: \forall integer N, M;
        valid_params(N, M) ==> 
        func_spec(N, M) <= N + M && func_spec(N, M) >= 0;
*/

/*@
    requires valid_params(N, M);
    ensures \result == func_spec(N, M);
    ensures \result <= N + M;
    ensures \result >= 0;
*/
unsigned long long func(unsigned long long N, unsigned long long M) {
    unsigned long long ans;

    if (2 * N < M) {
        //@ assert 2 * N < M;
        ans = N + ((M - 2 * N) / 4);
        //@ assert ans == func_spec(N, M);
    } else {
        //@ assert 2 * N >= M;
        ans = M / 2;
        //@ assert ans == func_spec(N, M);
    }

    //@ assert ans <= N + M;
    //@ assert ans >= 0;
    return ans;
}
