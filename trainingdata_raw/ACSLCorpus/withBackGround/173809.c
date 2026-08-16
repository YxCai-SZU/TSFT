#include <stdbool.h>

/*@
    predicate valid_array(int *a) =
        \valid(a) && \valid(a+1) && \valid(a+2) &&
        1 <= a[0] && a[0] <= 100 &&
        1 <= a[1] && a[1] <= 100 &&
        1 <= a[2] && a[2] <= 100;

    predicate is_arithmetic_sequence(int *a) =
        a[1] - a[0] == a[2] - a[1];
*/

/*@
    requires valid_array(a);
    ensures \result == 1 <==> is_arithmetic_sequence(a);
    assigns \nothing;
*/
bool func(int *a)
{
    //@ assert valid_array(a);
    
    bool result;
    result = (a[1] - a[0] == a[2] - a[1]);
    
    //@ assert result == 1 <==> is_arithmetic_sequence(a);
    return result;
}
