#include <limits.h>

/*@
    requires 1 <= n <= 1000;
    ensures \result == n / 3;
    assigns \nothing;
*/
int func(int n)
{
    int ans;
    int m;
    int divisor;
    
    ans = 0;
    m = n < 0 ? -n : n;
    divisor = 3;
    
    /*@
        loop invariant 1 <= n <= 1000;
        loop invariant ((ans) >= 0);
        loop invariant ((m) >= 0);
        loop invariant m <= 1000;
        loop invariant n == (n < 0 ? -(m + divisor * ans) : m + divisor * ans);
        loop invariant ans <= n / 3;
        loop assigns m, ans;
        loop variant m;
    */
    while (m >= divisor)
    {
        //@ assert m >= divisor;
        m -= divisor;
        ans += 1;
        //@ assert m >= 0;
    }
    
    if (n < 0)
    {
        ans = -ans;
    }
    
    //@ assert ans == n / 3;
    
    return ans;
}
