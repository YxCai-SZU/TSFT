#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 16;
    predicate sum_valid(integer x, integer y) = x + y <= 16;
    predicate result_condition(integer x, integer y) = x <= 8 && y <= 8;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    requires sum_valid(x, y);
    ensures \result == (x <= 8 && y <= 8);
*/
bool func(int x, int y)
{
    // Variable declarations at scope top
    bool result;

    //@ assert valid_range(x);
    //@ assert valid_range(y);
    //@ assert sum_valid(x, y);
    
    result = (x <= 8 && y <= 8);
    //@ assert result == (x <= 8 && y <= 8);
    
    return result;
}
