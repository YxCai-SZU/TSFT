#include <stdbool.h>

/*@
    predicate is_target(integer x) = x == 7 || x == 5 || x == 3;
 */

/*@
    requires 1 <= x <= 9;
    ensures \result == (x == 7 || x == 5 || x == 3);
    assigns \nothing;
 */
bool func(unsigned int x)
{
    bool v;
    //@ assert 1 <= x <= 9;
    v = (x == 7) || (x == 5) || (x == 3);
    //@ assert v == (x == 7 || x == 5 || x == 3);
    return v;
}
