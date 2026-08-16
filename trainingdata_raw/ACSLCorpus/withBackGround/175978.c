#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x && x <= 179;

    logic integer compute_result(integer x) =
        x > 180 ? 360 - x : 360 - x + 1;
*/

/*@
    requires valid_range(x);
    ensures \result >= 1 && \result <= 360;
    ensures \result == 360 - x || \result == 360 - x + 1;
    assigns \nothing;
*/
int func(int x)
{
    // Variable declarations at top of scope
    int result;

    //@ assert valid_range(x);
    
    if (x > 180) {
        result = 360 - x;
        //@ assert result == 360 - x;
    } else {
        result = 360 - x + 1;
        //@ assert result == 360 - x + 1;
    }
    
    //@ assert result >= 1 && result <= 360;
    return result;
}
