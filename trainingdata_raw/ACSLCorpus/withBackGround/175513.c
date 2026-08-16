#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 9;

    predicate func_result(integer a, integer b, integer c) =
        (a == b + 1 && c == a + 1) ||
        (a == b + 2 && c == b + 1) ||
        (a == b - 1 && c == b - 2) ||
        (a == b - 2 && c == a - 1) ||
        (a == c + 1 && b == a + 1) ||
        (a == c + 2 && b == c + 1) ||
        (a == c - 1 && b == c - 2) ||
        (a == c - 2 && b == a - 1);
*/

/*@
    requires valid_range(a);
    requires valid_range(b);
    requires valid_range(c);
    ensures \result == true <==> func_result(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;
    //@ assert valid_range(a);
    //@ assert valid_range(b);
    //@ assert valid_range(c);
    
    result = (a == b + 1 && c == a + 1) ||
             (a == b + 2 && c == b + 1) ||
             (a == b - 1 && c == b - 2) ||
             (a == b - 2 && c == a - 1) ||
             (a == c + 1 && b == a + 1) ||
             (a == c + 2 && b == c + 1) ||
             (a == c - 1 && b == c - 2) ||
             (a == c - 2 && b == a - 1);
    
    //@ assert result == true <==> func_result(a, b, c);
    return result;
}
