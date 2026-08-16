#include <stdbool.h>

/*@
    predicate x_in_range(integer x) = 0 <= x <= 1;
    predicate y_in_range(integer y) = 0 <= y <= 1;
    predicate result_condition(bool result, integer x, integer y) = result == (x <= y);
*/

/*@
    requires x_in_range(x) && y_in_range(y);
    ensures result_condition(\result, x, y);
    assigns \nothing;
*/
bool func(long x, long y)
{
    bool result;
    
    //@ assert x_in_range(x) && y_in_range(y);
    
    if (x == y) {
        result = true;
        //@ assert result == (x <= y);
        return result;
    } else if (x == 0 && y == 1) {
        result = true;
        //@ assert result == (x <= y);
        return result;
    } else {
        //@ assert x != y && !(x == 0 && y == 1);
        result = (x <= y);
        //@ assert result == (x <= y);
        return result;
    }
}
