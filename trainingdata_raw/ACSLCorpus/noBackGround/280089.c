/*@
    requires (1 <= (N) <= 100);
    requires (0 <= (A) <= (N) * (N));
    ensures \result == N * N - A;
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int A)
{
    // Variable declarations at top of scope
    unsigned int ans;

    //@ assert (1 <= (N) <= 100);
    //@ assert (0 <= (A) <= (N) * (N));
    //@ assert ((N) * (N) <= 10000);
    
    ans = N * N - A;
    
    return ans;
}
