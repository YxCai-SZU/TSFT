#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 10000 &&
        1 <= (y) && (y) <= 10000 &&
        1 <= (z) && (z) <= 10000);
    ensures \result == (x * y <= z);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= x && x <= 10000;
    //@ assert 1 <= y && y <= 10000;
    //@ assert 1 <= z && z <= 10000;
    //@ assert x * y <= 10000 * 10000;

    result = (x * y) <= z;
    return result;
}
