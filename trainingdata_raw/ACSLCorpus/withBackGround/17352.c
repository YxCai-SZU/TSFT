#include <stdbool.h>

/*@
    predicate valid_range(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer compute_raw(integer a, integer b) = a - b * 2;

    predicate result_spec(integer a, integer b, integer r) =
        r >= 0 && (r == compute_raw(a, b) || r == 0);
*/

/*@
    requires valid_range(a, b);
    ensures result_spec(a, b, \result);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    //@ assert valid_range(a, b);
    result = a - b * 2;
    
    if (result < 0)
    {
        //@ assert compute_raw(a, b) < 0;
        result = 0;
        //@ assert result == 0;
    }
    //@ assert result >= 0;
    //@ assert result == compute_raw(a, b) || result == 0;
    return result;
}
