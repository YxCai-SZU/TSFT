#include <limits.h>

/*@
    requires (0 <= (x) && (x) <= 20 &&
        0 <= (y) && (y) <= 20 &&
        0 <= (z) && (z) <= 20);
    ensures \result >= 0;
    ensures \result == ((x) * (y) * (z));
    assigns \nothing;
*/
int func(int x, int y, int z)
{
    // Variable declarations at top of scope
    int result;

    //@ assert (0 <= (x) && (x) <= 20 &&         0 <= (y) && (y) <= 20 &&         0 <= (z) && (z) <= 20);
    //@ assert ((x) * (y) * (z)) >= 0;
    //@ assert ((x) * (y) * (z)) <= 8000;

    result = x * y * z;
    return result;
}
