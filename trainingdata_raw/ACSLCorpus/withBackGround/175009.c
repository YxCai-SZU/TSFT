#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 9;

    predicate func_result(integer a, integer b, integer c) =
        (a == b && a != c) ||
        (a == c && a != b) ||
        (b == c && b != a);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result <==> func_result(a, b, c);
    assigns \nothing;
*/
bool func(int a, int b, int c)
{
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    return (a == b && a != c) || (a == c && a != b) || (b == c && b != a);
}
