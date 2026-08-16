#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = -40 <= x <= 40;
*/

/*@
    requires is_valid_range(x);
    ensures \result == (x >= 30);
    assigns \nothing;
*/
bool func(int x)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert is_valid_range(x);
    result = (x >= 30);
    return result;
}
