#include <limits.h>

/*@
    predicate non_negative(integer a, integer b, integer c, integer k) =
        a >= 0 && b >= 0 && c >= 0 && k >= 1;
    
    predicate k_within_sum(integer a, integer b, integer c, integer k) =
        k <= a + b + c;
    
    predicate sum_within_limit(integer a, integer b, integer c) =
        a + b + c <= 2000000000;
*/

/*@
    requires non_negative(a, b, c, k);
    requires k_within_sum(a, b, c, k);
    requires sum_within_limit(a, b, c);
    ensures \result <= a;
*/
int func(int a, int b, int c, int k)
{
    int ans = 0;
    int rst = k;
    
    //@ assert ans <= a;
    
    if (a < rst)
    {
        ans += a;
        rst -= a;
    }
    else
    {
        ans += rst;
        rst = 0;
    }
    
    //@ assert rst >= 0;
    
    if (b < rst)
    {
        rst -= b;
    }
    else
    {
        rst = 0;
    }
    
    if (rst > c)
    {
        ans -= (rst - c);
    }
    
    return ans;
}
