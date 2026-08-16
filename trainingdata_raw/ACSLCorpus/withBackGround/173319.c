/*@
    predicate valid_params(integer n, integer m) =
        1 <= n <= 100 && 1 <= m <= n && m <= 5;

    logic integer lower_bound(integer n, integer m) =
        100 * (n - m) + 1900 * m;

    logic integer upper_bound(integer n) =
        1900 * n;
*/

/*@
    requires valid_params(n, m);
    ensures \result >= lower_bound(n, m);
    ensures \result <= upper_bound(n);
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans = 0;
    int i = 0;
    /*@
        loop invariant 0 <= i <= m;
        loop invariant ans == 1900 * i;
        loop invariant i <= 5;
        loop assigns ans, i;
        loop variant m - i;
    */
    while (i < m)
    {
        //@ assert ans == 1900 * i;
        ans += 1900;
        i += 1;
    }
    int j = 0;
    /*@
        loop invariant 0 <= j <= n - m;
        loop invariant ans == 1900 * m + 100 * j;
        loop invariant j <= 100;
        loop invariant ans <= 1900 * n;
        loop assigns ans, j;
        loop variant n - m - j;
    */
    while (j < (n - m))
    {
        //@ assert ans == 1900 * m + 100 * j;
        ans += 100;
        j += 1;
    }
    //@ assert ans >= lower_bound(n, m);
    //@ assert ans <= upper_bound(n);
    return ans;
}
