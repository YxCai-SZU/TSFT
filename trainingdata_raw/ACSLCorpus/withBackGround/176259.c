#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 179;

    logic integer compute_result(integer x) = 360 - x;
*/

/*@
    requires valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int func(int x)
{
    int result;
    
    //@ assert 360 - x <= 360;
    //@ assert 360 - x >= 0;
    
    if (x < 360) {
        //@ assert 360 - x == 360 - x;
        result = 360 - x;
    } else {
        //@ assert x - 360 == 360 - x;
        result = x - 360;
    }
    
    return result;
}
