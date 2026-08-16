#include <stdbool.h>

/*@
    predicate is_valid_range(integer x) = 1 <= x <= 9;

    predicate has_pair(integer a, integer b, integer c) =
        (a == b && b != c) ||
        (a == c && a != b) ||
        (b == c && b != a);
*/

/*@
    requires is_valid_range(a);
    requires is_valid_range(b);
    requires is_valid_range(c);
    ensures \result == true <==> has_pair(a, b, c);
*/
bool func(int a, int b, int c)
{
    bool result;

    //@ assert 1 <= a <= 9;
    //@ assert 1 <= b <= 9;
    //@ assert 1 <= c <= 9;

    result = (a == b && b != c) ||
             (a == c && a != b) ||
             (b == c && b != a);

    return result;
}
