#include <stdbool.h>

/*@
    requires (1 <= (x) <= 100);
    requires (1 <= (y) <= 100);
    ensures \result == ((x) * (y));
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int result;

    //@ assert (1 <= (x) <= 100);
    //@ assert (1 <= (y) <= 100);
    //@ assert 1 <= ((x) * (y)) <= 10000;

    result = x * y;
    //@ assert result == ((x) * (y));
    return result;
}
