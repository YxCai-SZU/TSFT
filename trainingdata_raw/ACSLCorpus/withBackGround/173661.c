#include <stdbool.h>

/*@
    predicate is_positive(integer v) = v > 0;
    predicate is_within_limit(integer v) = v <= 1000;
    
    logic integer compute_result(integer x, integer y) =
        x > y * 2 ? x - (y * 2) : 0;
*/

/*@
    requires is_positive(x) && is_positive(y);
    requires is_within_limit(x) && is_within_limit(y);
    ensures \result >= 0;
    ensures \result == compute_result(x, y);
    assigns \nothing;
*/
int func(int x, int y)
{
    int result;
    
    //@ assert x > 0 && y > 0;
    //@ assert x <= 1000 && y <= 1000;
    
    if (x > y * 2) {
        //@ assert x > y * 2;
        result = x - (y * 2);
    } else {
        //@ assert x <= y * 2;
        result = 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == compute_result(x, y);
    
    return result;
}
