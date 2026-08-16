#include <limits.h>

/*@
    requires (2 <= (x) <= 100 && 2 <= (y) <= 100);
    ensures \result == ((x) * (y) - ((x) + (y)) + 1);
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int result;

    //@ assert (2 <= (x) <= 100 && 2 <= (y) <= 100);
    //@ assert x * y <= 100 * 100;

    result = x * y - (x + y) + 1;
    //@ assert result == ((x) * (y) - ((x) + (y)) + 1);
    return result;
}
