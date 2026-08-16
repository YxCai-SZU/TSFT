#include <stdbool.h>

/*@
    predicate bounds(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;
    
    predicate result_condition(integer x, integer y, bool result) =
        result == ((y - x) >= 3 && x > 0 && y > 0 && (y - x) < 20);
*/

/*@
    requires bounds(x, y);
    ensures result_condition(x, y, \result);
    assigns \nothing;
*/
bool func(int x, int y)
{
    // Variable declarations at top of scope
    bool result;
    
    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert y - x >= -99;
    //@ assert y - x <= 99;
    
    result = (y - x) >= 3 && x > 0 && y > 0 && (y - x) < 20;
    
    return result;
}
