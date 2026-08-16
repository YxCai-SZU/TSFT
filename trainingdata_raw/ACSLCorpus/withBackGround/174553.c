#include <stdbool.h>

/*@
    predicate r_in_range(integer r) = 1 <= r && r <= 100;
    logic integer target_value(integer r) = 3 * r * r;
*/

/*@
    requires r_in_range(r);
    ensures \result == target_value(r);
    assigns \nothing;
*/
int func(int r)
{
    int ans;
    int i;
    int j;
    int k;
    
    //@ assert 1 <= r && r <= 100;
    //@ assert 3 * r * r <= 3 * 100 * 100;
    
    ans = 3 * r * r;
    
    return ans;
}
