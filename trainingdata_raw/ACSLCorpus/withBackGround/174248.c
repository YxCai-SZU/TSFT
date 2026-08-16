#include <stdbool.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v && v <= 100;

    logic integer abs_difference(integer x, integer y) =
        x > y ? x - y : y - x;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    ensures \result == (c - b == b - a);
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert is_valid_range(a) && is_valid_range(b) && is_valid_range(c);
    result = (c - b == b - a);
    //@ assert result == (c - b == b - a);
    return result;
}
