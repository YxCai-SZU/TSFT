#include <stdbool.h>

/*@
    predicate x_in_range(integer x) = 1 <= x < 5000;
    predicate y_in_range(integer y) = 1 <= y < 5000;
    predicate xy_ordered(integer x, integer y) = x < y;
    predicate sum_less_5000(integer x, integer y) = x + y < 5000;
*/

/*@
    requires 1 <= x < y < 5000;
    ensures \result == (x + y < 5000);
    assigns \nothing;
*/
bool func(int x, int y)
{
    bool result;
    
    //@ assert x_in_range(x);
    //@ assert y_in_range(y);
    //@ assert xy_ordered(x, y);
    
    result = (x + y) < 5000;
    
    //@ assert result == (x + y < 5000);
    return result;
}
