#include <stdbool.h>

/*@
    predicate is_valid_range(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;

    predicate condition_holds(integer x, integer y) =
        y >= 2 * x && y <= 4 * x && y % 2 == 0;
*/

/*@
    requires is_valid_range(x, y);
    ensures \result == true <==> condition_holds(x, y);
    assigns \nothing;
*/
bool func(unsigned int x, unsigned int y)
{
    bool flg = false;

    //@ assert is_valid_range(x, y);

    if (2 * x <= y && y <= 4 * x)
    {
        if (y % 2 == 0)
        {
            flg = true;
        }
    }

    //@ assert flg == true <==> condition_holds(x, y);
    return flg;
}
