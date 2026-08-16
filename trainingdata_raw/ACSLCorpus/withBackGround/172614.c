#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= a && a <= 10 && 1 <= b && b <= 10 && 1 <= c && c <= 10;

    predicate is_strictly_increasing(integer a, integer b, integer c) =
        a < b && b < c;
*/

/*@
    requires bounds(a, b, c);
    ensures \result == true <==> is_strictly_increasing(a, b, c);
    assigns \nothing;
*/
bool func(long a, long b, long c)
{
    bool result = false;

    //@ assert bounds(a, b, c);

    if (a < b && b < c) {
        result = true;
    }

    //@ assert result == true <==> is_strictly_increasing(a, b, c);

    return result;
}
