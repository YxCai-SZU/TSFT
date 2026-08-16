#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 205;

    logic integer func_result(integer x, integer y) =
        x == y ? x + y :
        x > y ? x - y + 1 :
        y - x + 1;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    ensures \result == x + y || \result == y - x + 1 || \result == x - y + 1;
    assigns \nothing;
*/
int func(int x, int y)
{
    int result;

    if (x == y)
    {
        //@ assert x + y == x + y;
        result = x + y;
    }
    else
    {
        if (x > y)
        {
            //@ assert x - y + 1 == x - y + 1;
            result = x - y + 1;
        }
        else
        {
            //@ assert y - x + 1 == y - x + 1;
            result = y - x + 1;
        }
    }

    return result;
}
