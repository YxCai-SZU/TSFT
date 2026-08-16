#include <stdbool.h>

/*@
    predicate a_in_range(integer a) = 1 <= a && a <= 100;
    predicate b_in_range(integer b) = 1 <= b && b <= 100;
    predicate valid_params(integer a, integer b) = a_in_range(a) && b_in_range(b);
    
    logic integer compute_result(integer a, integer b) =
        a >= 2 * b ? a - 2 * b : 0;
*/

/*@
    requires valid_params(a, b);
    ensures \result >= 0;
    ensures \result == compute_result(a, b);
    assigns \nothing;
*/
int func(int a, int b)
{
    int result;
    
    //@ assert valid_params(a, b);
    
    if (a >= 2 * b) {
        result = a - 2 * b;
        //@ assert result == a - 2 * b;
    } else {
        result = 0;
        //@ assert result == 0;
    }
    
    //@ assert result >= 0;
    //@ assert result == compute_result(a, b);
    
    return result;
}
