#include <stdbool.h>

/*@
    predicate is_square(integer x, integer y) = x * x == y;
 */

/*@
    requires 1 <= x && x <= 100;
    requires 1 <= y && y <= 100;
    ensures \result == (x * x == y);
    assigns \nothing;
 */
bool check_square(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= x && x <= 100;
    //@ assert 1 <= y && y <= 100;
    //@ assert x * x <= 10000;

    result = (x * x == y);
    return result;
}
