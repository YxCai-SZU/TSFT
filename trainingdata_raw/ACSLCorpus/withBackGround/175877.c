#include <stdbool.h>

/*@ predicate bounds(integer v) = 0 <= v < 0x100; */

/*@
    requires bounds(x) && bounds(y);
    ensures \result == (x + y < 0x100);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 0 <= x < 0x100;
    //@ assert 0 <= y < 0x100;
    //@ assert x + y < 0x200;

    result = (x + y < 0x100);
    return result;
}
