#include <stdbool.h>
#include <limits.h>

/*@
    requires x >= INT_MIN && x <= INT_MAX;
    requires y >= INT_MIN && y <= INT_MAX;
    requires z >= INT_MIN && z <= INT_MAX;
    ensures \result == (x < y && y < z);
    assigns \nothing;
*/
bool func(int x, int y, int z)
{
    bool result;

    //@ assert x < y && y < z ==> (x < y && y < z);
    result = (x < y && y < z);
    return result;
}
