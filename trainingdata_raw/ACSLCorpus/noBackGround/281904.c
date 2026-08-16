#include <stdbool.h>

/*@
    requires (1 <= (x) && (x) <= 20) && (1 <= (y) && (y) <= 20) && (1 <= (z) && (z) <= 20);
    ensures \result == (x * y * z <= 20);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y, unsigned int z)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert (1 <= (x) && (x) <= 20);
    //@ assert (1 <= (y) && (y) <= 20);
    //@ assert (1 <= (z) && (z) <= 20);
    //@ assert x * y <= 400;
    //@ assert x * y * z <= 8000;

    result = (x * y * z <= 20);
    return result;
}
