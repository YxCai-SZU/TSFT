#include <stdbool.h>

/*@ predicate in_range(integer v) = 1 <= v <= 10; */

/*@
    requires in_range(x) && in_range(y) && in_range(z);
    ensures \result == ((x * y) <= z);
    assigns \nothing;
*/
bool check_bounds(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert x * y <= 100;
    result = (x * y) <= z;
    return result;
}
