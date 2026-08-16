/*@
    predicate valid_inputs(integer N, integer M) =
        1 <= N && 1 <= M && N <= 1000000000000 && M <= 1000000000000;

    logic integer upper_bound(integer N, integer M) = N + M / 2;
*/

/*@
    requires valid_inputs(N, M);
    ensures \result >= 0;
    ensures \result <= upper_bound(N, M);
*/
unsigned long long func(unsigned long long N, unsigned long long M)
{
    unsigned long long ans;
    unsigned long long local_N;
    unsigned long long local_M;

    ans = 0;
    local_N = N;
    local_M = M;

    if (local_N * 2 < local_M)
    {
        ans += local_N;
        local_M -= local_N * 2;
        ans += (local_M / 4);
        //@ assert ans >= 0;
        //@ assert ans <= upper_bound(N, M);
    }
    else
    {
        ans += local_M / 2;
        //@ assert ans >= 0;
        //@ assert ans <= upper_bound(N, M);
    }

    return ans;
}
