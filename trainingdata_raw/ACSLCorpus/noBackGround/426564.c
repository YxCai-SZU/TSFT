/*@
    requires (1 <= (N) && (N) <= 100);
    ensures \result == (800 * (N) - 200 * ((N) / 15));
    assigns \nothing;
*/
int func(int N)
{
    int res;
    int count;
    int n;
    
    res = 800 * N;
    count = 0;
    n = N;
    
    /*@
        loop invariant 0 <= n <= N;
        loop invariant 0 <= count <= N / 15;
        loop invariant res == 800 * N;
        loop invariant n == N - 15 * count;
        loop invariant (1 <= (N) && (N) <= 100);
        loop assigns count, n;
        loop variant n;
    */
    while (n >= 15)
    {
        //@ assert n >= 15;
        count = count + 1;
        n = n - 15;
    }
    
    //@ assert count == N / 15;
    res = res - 200 * count;
    
    //@ assert res == (800 * (N) - 200 * ((N) / 15));
    return res;
}
