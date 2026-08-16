#include <stdbool.h>

/*@
    predicate is_ge_13(integer x) = x >= 13;
 */

/*@
    requires 1 <= x <= 100;
    ensures \result == (x >= 13);
    assigns \nothing;
 */
bool func(int x)
{
    bool result;
    //@ assert x >= 13 ==> x >= 13;
    //@ assert x < 13 ==> x < 13;
    result = (x >= 13);
    return result;
}
