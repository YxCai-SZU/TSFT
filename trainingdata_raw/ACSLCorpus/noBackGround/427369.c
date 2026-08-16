#include <stdbool.h>

/*@
    requires 1 <= n <= 100;
    requires 1 <= m <= 100;
    ensures ((\result) >= 0);
    ensures ((\result) == (n) - 2 * (m) || (\result) == 0);
*/
int func(int n, int m)
{
    int res;
    int ans;
    
    res = n - 2 * m;
    
    if (res < 0)
    {
        ans = 0;
        //@ assert ans == 0;
    }
    else
    {
        ans = res;
        //@ assert ans == res;
    }
    
    return ans;
}
