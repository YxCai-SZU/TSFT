#include <stdbool.h>

/*@ predicate bounds(integer v) = 0 < v && v <= 8; */

/*@
    requires bounds(x) && bounds(y) && bounds(z);
    ensures \result == (x * y <= z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert bounds(x);
    //@ assert bounds(y);
    //@ assert bounds(z);
    //@ assert x * y <= 64;

    result = (x * y <= z);
    return result;
}
