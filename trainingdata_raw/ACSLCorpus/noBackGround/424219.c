#include <limits.h>

/*@
    requires (0 <= (a) <= 100 &&
        0 <= (b) <= 100 &&
        0 <= (c) <= 100 &&
        1 <= (k) <= 3);
    ensures \result >= -c && \result <= a;
    assigns \nothing;
*/
int func(int a, int b, int c, int k)
{
    int ans;
    int rst;
    
    ans = 0;
    rst = k;
    
    if (rst >= a)
    {
        ans += a;
        rst -= a;
    }
    else
    {
        ans += rst;
        rst = 0;
    }
    
    //@ assert ans >= 0 && ans <= a;
    
    if (rst >= b)
    {
        rst -= b;
    }
    else
    {
        rst = 0;
    }
    
    //@ assert rst >= 0;
    
    if (rst >= c)
    {
        ans -= c;
    }
    else
    {
        ans -= rst;
    }
    
    //@ assert ans >= -c && ans <= a;
    
    return ans;
}
