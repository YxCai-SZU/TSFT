#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 100000) && (1 <= (y) && (y) <= 100000) && (1 <= (z) && (z) <= 100000);
    requires ((y) + (z) <= (x));
    ensures \result == (x >= y && x <= y + z);
*/
bool func(int x, int y, int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert ((y) + (z) <= (x));

    result = (x >= y && x <= y + z);
    return result;
}
