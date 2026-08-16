#include <limits.h>

/*@
    requires 0 <= a && 0 <= b && 0 <= c && 1 <= k;
    requires k <= a + b + c && k <= 2000000000;
    ensures \result <= k;
    ensures \result >= k - (a + b + c);
*/
int func(int a, int b, int c, int k)
{
    int ans;
    
    if (a < k)
    {
        ans = k - a;
    }
    else
    {
        ans = 0;
    }
    
    //@ assert ans == (a < k ? k - a : 0);
    //@ assert ans >= k - (a + b + c);
    
    return ans;
}
