#include <stdbool.h>

/*@
    predicate condition_holds(integer x) =
        x >= 2000 || (100 * (x / 100) <= x && x % 100 <= 5 * (x / 100));
 */

/*@
    requires 1 <= x <= 100000;
    ensures \result == (x >= 2000 || (100 * (x / 100) <= x && x % 100 <= 5 * (x / 100)));
    assigns \nothing;
 */
bool func(int x)
{
    int n;
    int b;
    bool res;

    n = x / 100;
    b = x % 100;

    if (x >= 2000)
    {
        //@ assert x >= 2000 || (100 * n <= x && b <= 5 * n);
        return true;
    }

    if (100 * n <= x && b <= 5 * n)
    {
        //@ assert x >= 2000 || (100 * n <= x && b <= 5 * n);
        return true;
    }
    else
    {
        //@ assert 100 * n > x || b > 5 * n;
        //@ assert !(x >= 2000 || (100 * n <= x && b <= 5 * n));
        return false;
    }
}
