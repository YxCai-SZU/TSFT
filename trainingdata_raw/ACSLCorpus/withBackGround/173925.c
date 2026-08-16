#include <stdbool.h>

/*@ predicate in_range(integer val, integer low, integer high) =
      low <= val && val <= high;
*/

/*@
    requires in_range(n, 1, 100);
    requires in_range(m, 1, 100);
    ensures \result >= 0;
    ensures \result <= n;
    assigns \nothing;
*/
int func(int n, int m)
{
    int ans;
    
    if (n < m) {
        ans = n;
    } else {
        ans = m;
    }
    
    //@ assert ans >= 0 && ans <= n;
    
    return ans;
}
