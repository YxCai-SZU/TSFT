/*@
    requires (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
    ensures \result == 100 * (m - 1) || \result == 100 * m + (n - m);
*/
int func(int n, int m)
{
    int ans;
    int i;

    ans = 0;
    i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
        loop invariant ans == (100 * (i));
        loop assigns ans, i;
    */
    while (i < m)
    {
        ans += 100;
        i += 1;
    }

    i = 0;
    /*@
        loop invariant 0 <= i <= n - m;
        loop invariant (1 <= (n) <= 100 && 1 <= (m) <= (n) && (m) <= 5);
        loop invariant ans == (100 * (m) + (i));
        loop assigns ans, i;
    */
    while (i < n - m)
    {
        ans += 1;
        i += 1;
    }

    return ans;
}
