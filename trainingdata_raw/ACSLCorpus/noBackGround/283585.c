/*@
    requires (1 <= (N) && (N) <= 100 && 0 <= (M) && (M) <= (N));
    ensures \result == N - M;
    assigns \nothing;
*/
unsigned int func(unsigned int N, unsigned int M)
{
    // Variable declarations at top of scope
    unsigned int result;
    
    //@ assert N >= M;
    //@ assert N - M <= 100;
    
    result = N - M;
    return result;
}
