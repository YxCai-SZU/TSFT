#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 1 <= x <= 100; */

/*@
    requires is_in_range(a) && is_in_range(b) && is_in_range(c);
    ensures \result == ((c - b == b - a) || (c - b == b - a + 1) || (c - b == b - a - 1));
*/
bool func(int a, int b, int c)
{
    int d;
    bool ans;

    // Variable declarations at top
    d = b - a;
    
    //@ assert d == b - a;
    
    if (c - b == d || c - b == d + 1 || c - b == d - 1)
    {
        ans = true;
    }
    else
    {
        ans = false;
    }
    
    //@ assert ans == ((c - b == b - a) || (c - b == b - a + 1) || (c - b == b - a - 1));
    
    return ans;
}
