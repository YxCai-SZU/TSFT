#include <stdbool.h>

/*@
    predicate is_commutative(integer a, integer b) =
        (a & b) == (b & a);
 */

/*@
    requires a < 0x10000 && b < 0x10000;
    ensures \result == true <==> is_commutative(a, b);
    assigns \nothing;
 */
bool func(unsigned int a, unsigned int b)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (a & b) == (b & a);
    result = true;
    return result;
}
