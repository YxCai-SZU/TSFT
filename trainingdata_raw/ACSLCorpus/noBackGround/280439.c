#include <stdbool.h>

/*@
    requires 1 <= k <= 100;
    requires 1 <= x <= 100000;
    ensures \result == (500 * k >= x);
    ensures ((\result) == (500 * (k) >= (x)));
 */
bool func(int k, int x)
{
    bool ans;
    
    ans = false;
    
    if (500 * k >= x)
    {
        ans = true;
    }
    
    //@ assert ans == (500 * k >= x);
    return ans;
}

