/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= 100);
    ensures \result == ((n) * (m) - ((n) - 1) - (m) + 1);
    ensures \result >= 1;
*/
int func(int n, int m)
{
    int ans;
    //@ assert (1 <= (n) <= 100 && 1 <= (m) <= 100);
    //@ assert n * m <= 10000;
    ans = n * m - (n - 1) - m + 1;
    //@ assert ans == ((n) * (m) - ((n) - 1) - (m) + 1);
    //@ assert ans >= 1;
    return ans;
}
