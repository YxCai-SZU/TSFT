#include <stdbool.h>

/*@
    predicate is_odd(integer a, integer b) = (a * b) % 2 == 1;
    predicate in_range(integer x) = 1 <= x <= 3;
 */

/*@
    requires in_range(a) && in_range(b);
    ensures \result == true <==> is_odd(a, b);
    assigns \nothing;
 */
bool func(int a, int b)
{
    bool result;

    //@ assert in_range(a) && in_range(b);
    //@ assert a * b <= 9;
    //@ assert a * b >= 1;

    if (a == 1 || b == 1 || a == 3 || b == 3) {
        if (a == 2 || b == 2) {
            result = false;
        } else {
            result = true;
        }
    } else {
        result = false;
    }

    //@ assert result == true <==> is_odd(a, b);
    return result;
}
