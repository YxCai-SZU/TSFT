#include <stdbool.h>

/*@
    predicate are_valid_params(integer n, integer a, integer b) =
        2 <= n && n <= 100 &&
        1 <= a && a < b && b <= n;

    predicate result_condition(integer n, integer a, integer b, bool result) =
        result == ((b - a == 1) || (b - a == n - 1));
*/

/*@
    requires are_valid_params(n, a, b);
    ensures result_condition(n, a, b, \result);
    assigns \nothing;
*/
bool func(int n, int a, int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert are_valid_params(n, a, b);
    
    if ((b - a == 1) || (b - a == n - 1)) {
        result = true;
    } else {
        result = false;
    }
    
    //@ assert result_condition(n, a, b, result);
    return result;
}
