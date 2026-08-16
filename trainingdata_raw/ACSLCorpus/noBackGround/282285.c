#include <limits.h>

/*@
    requires (2 <= (x) && (x) <= 100 &&
        2 <= (y) && (y) <= 100);
    ensures \result == ((x) * (y) - ((x) + (y)) + 1);
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int result;

    //@ assert x * y <= 10000;
    //@ assert x + y <= 200;
    //@ assert x * y - (x + y) >= -199;

    result = x * y - (x + y) + 1;
    return result;
}
