/*@
    requires (1 <= (N) <= 100);
    ensures \result == N * 800 - ((N / 15) * 200);
*/
int func(int N)
{
    int result;
    int remaining;
    int count;
    
    //@ assert (1 <= (N) <= 100);
    result = 0;
    remaining = N;
    count = 0;
    
    /*@
        loop invariant 0 <= remaining <= N;
        loop invariant count <= N / 15;
        loop invariant remaining == N - count * 15;
        loop invariant (1 <= (N) <= 100);
        loop assigns remaining, count;
    */
    while (remaining >= 15)
    {
        //@ assert remaining >= 15;
        remaining -= 15;
        count += 1;
        //@ assert remaining == N - count * 15;
    }
    
    //@ assert remaining == N - count * 15;
    //@ assert count == N / 15;
    result = N * 800 - count * 200;
    return result;
}
