/*@
    requires 1 <= n <= 20;
    requires 1 <= m <= 20;
    ensures \result == n + m || \result == 2 * n - 1;
*/
int func(int n, int m)
{
    int ans;
    //@ assert 1 <= n <= 20 && 1 <= m <= 20;
    if (n * 2 - 1 < m)
    {
        ans = n + m;
        //@ assert ans == n + m;
    }
    else
    {
        ans = 2 * n - 1;
        //@ assert ans == 2 * n - 1;
    }
    //@ assert ans == n + m || ans == 2 * n - 1;
    return ans;
}
