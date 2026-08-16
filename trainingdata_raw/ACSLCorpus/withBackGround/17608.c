#include <limits.h>

/*@
    predicate is_in_range(integer x) = -1000 <= x <= 1000;
    predicate square_in_range(integer x) = -1000000 <= x * x <= 1000000;
    predicate cube_in_range(integer x) = -1000000000 <= x * x * x <= 1000000000;
*/

/*@
    requires is_in_range(x);
    ensures \result == x * x * x;
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top of scope
    int result;

    //@ assert -1000 <= x && x <= 1000;
    //@ assert -1000000 <= x * x && x * x <= 1000000;
    //@ assert -1000000000 <= x * x * x && x * x * x <= 1000000000;
    
    result = x * x * x;
    return result;
}
