/*@
    requires (1 <= (N) <= 100 &&
        0 <= (a) <= (N) * (N));
    ensures \result == ((N) * (N) - (a));
    assigns \nothing;
*/
int func(int N, int a)
{
    // Variable declarations at scope top
    int ans;

    //@ assert 0 <= N * N <= 10000;
    ans = N * N - a;
    //@ assert ans == N * N - a;
    return ans;
}
