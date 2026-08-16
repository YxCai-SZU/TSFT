#include <stdbool.h>

/*@
    predicate condition_holds(integer k, integer x) = k * 500 >= x;
 */

/*@
    requires 1 <= k && k <= 100;
    requires 1 <= x && x <= 100000;
    ensures \result == true <==> condition_holds(k, x);
    assigns \nothing;
 */
bool func(int k, int x)
{
    int en;
    bool result;

    en = 500;

    if (k * en >= x)
    {
        //@ assert condition_holds(k, x);
        result = true;
    }
    else
    {
        //@ assert !condition_holds(k, x);
        result = false;
    }

    return result;
}
