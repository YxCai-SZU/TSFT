#include <stdbool.h>

/*@
    predicate condition(integer x, integer y, integer t) =
        y >= 2 * x && t % 2 == 0 && t <= 4 * x;

    logic integer calc_t(integer x, integer y) = y - 2 * x;
*/

/*@
    requires 1 <= x <= 100;
    requires 1 <= y <= 100;
    ensures \result == (y >= 2 * x && (y - 2 * x) % 2 == 0 && (y - 2 * x) <= 4 * x);
*/
bool func(unsigned int x, unsigned int y)
{
    bool ans = false;

    if (y >= 2 * x)
    {
        unsigned int t_c = y - 2 * x;
        //@ assert t_c == calc_t(x, y);
        if (t_c % 2 == 0 && t_c <= 4 * x)
        {
            ans = true;
        }
    }

    //@ assert ans == (y >= 2 * x && (y - 2 * x) % 2 == 0 && (y - 2 * x) <= 4 * x);
    return ans;
}
