#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 100;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    ensures \result == (x <= y);
    assigns \nothing;
*/
bool func(int x, int y)
{
    //@ assert valid_range(x);
    //@ assert valid_range(y);
    return x <= y;
}
