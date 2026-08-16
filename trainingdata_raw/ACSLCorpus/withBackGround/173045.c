#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 179; */

/*@
    requires is_valid_range(x);
    ensures \result == 180 - x;
    assigns \nothing;
*/
int func(int x)
{
    int ans;
    //@ assert is_valid_range(x);
    ans = 180 - x;
    //@ assert ans == 180 - x;
    return ans;
}
