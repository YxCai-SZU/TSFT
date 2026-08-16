/*@
    requires (1 <= (n) <= 1000 &&
        1 <= (m) <= 1000 &&
        0 <= (k) <= (n) * (m));
    ensures \result == (k <= n * m - (n - 1) - (m - 1));
*/
int func(int n, int m, int k)
{
    //@ assert n * m <= 1000000;
    //@ assert n * m - (n - 1) - (m - 1) >= 1;
    
    return k <= (n * m - (n - 1) - (m - 1));
}
