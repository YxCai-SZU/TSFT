/*@
    requires (1 <= (K) && (K) <= (N) && (N) <= 50);
    ensures \result == N - K + 1;
    assigns \nothing;
*/
long func(long N, long K)
{
    long result;

    //@ assert (1 <= (K) && (K) <= (N) && (N) <= 50);
    //@ assert N - K + 1 >= 1;
    result = N - K + 1;
    return result;
}
