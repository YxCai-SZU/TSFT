#include <stdint.h>

/*@
    predicate is_valid_range(integer x) = -10 <= x <= 10;
    
    logic integer compute_result(integer x) =
        x >= 0 ? 2 * x : -3 * x;
*/

/*@
    requires is_valid_range(x);
    ensures \result == compute_result(x);
    assigns \nothing;
*/
int64_t func(int64_t x)
{
    int64_t result;
    
    //@ assert is_valid_range(x);
    
    if (x >= 0) {
        //@ assert x >= 0;
        result = 2 * x;
        //@ assert result == 2 * x;
    } else {
        //@ assert x < 0;
        result = -3 * x;
        //@ assert result == -3 * x;
    }
    
    //@ assert result == compute_result(x);
    return result;
}
