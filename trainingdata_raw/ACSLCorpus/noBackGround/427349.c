/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (k * 500 >= x);
*/
_Bool func(int k, int x)
{
    int yen_per_coin = 500;
    int K = k;
    int total = 0;
    int i = 0;

    /*@
        loop invariant 1 <= K <= 100;
        loop invariant 1 <= x <= 100000;
        loop invariant 0 <= i <= K;
        loop invariant total == i * yen_per_coin;
        loop invariant yen_per_coin == 500;
        loop invariant total <= i * 500;
        loop assigns total, i;
    */
    while (i < K)
    {
        total += yen_per_coin;
        i += 1;
    }

    //@ assert total == K * yen_per_coin;
    return total >= x;
}
