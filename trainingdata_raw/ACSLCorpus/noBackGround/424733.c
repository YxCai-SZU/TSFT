/*@
    requires (0 <= (A) && (A) <= 100 && 0 <= (P) && (P) <= 100);
    ensures \result >= 0;
    ensures \result <= ((A) * 3 + (P));
    ensures \result == ((A) * 3 + (P)) / 2;
*/
long func(long A, long P)
{
    long K;
    long ret;
    long temp_k;

    K = A * 3 + P;
    ret = 0;
    temp_k = K;

    /*@
        loop invariant (0 <= (temp_k) && (temp_k) <= (K) &&
        (ret) >= 0 &&
        (ret) <= (K) / 2 &&
        (temp_k) == (K) - 2 * (ret));
        loop assigns ret, temp_k;
    */
    while (temp_k >= 2)
    {
        //@ assert temp_k == K - 2 * ret;
        ret = ret + 1;
        temp_k = temp_k - 2;
        //@ assert temp_k == K - 2 * ret;
    }

    return ret;
}
