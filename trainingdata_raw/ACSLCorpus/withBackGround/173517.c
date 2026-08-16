/*@
    predicate valid_n(integer n) = 1 <= n && n <= 100;
    
    logic integer total_earnings(integer n, integer i) = n * 800 - i * 200;
*/

/*@
    requires valid_n(n);
    ensures \result == total_earnings(n, n/15);
*/
int func(int n)
{
    int x;
    int y;
    int ans;
    int i;
    
    x = 800;
    y = 200;
    ans = 0;
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n;
        loop invariant ans == i * 800;
        loop invariant x == 800;
        loop invariant y == 200;
        loop assigns ans, i;
    */
    while (i < n)
    {
        //@ assert ans + x == (i + 1) * 800;
        ans += x;
        i += 1;
    }
    
    i = 0;
    
    /*@
        loop invariant 0 <= i <= n/15;
        loop invariant ans == total_earnings(n, i);
        loop invariant x == 800;
        loop invariant y == 200;
        loop assigns ans, i;
    */
    while (i < n / 15)
    {
        //@ assert ans - y == total_earnings(n, i + 1);
        ans -= y;
        i += 1;
    }
    
    return ans;
}
