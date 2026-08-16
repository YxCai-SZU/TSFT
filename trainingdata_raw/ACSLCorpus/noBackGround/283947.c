#include <stdbool.h>

/*@
    requires ((x) < (y));
    requires ((y) < (z));
    ensures \result == true;
*/
bool func(int x, int y, int z)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert ((x) < (y)) && ((y) < (z));
    //@ assert ((x) < (z));

    result = true;
    return result;
}
