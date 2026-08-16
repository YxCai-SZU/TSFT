#include <stdbool.h>

/*@
    predicate is_condition_true(integer x) =
        x >= 2000 || (x % 200 == 0 || x % 200 < 100);
 */

/*@
    requires 1 <= x <= 100000;
    ensures \result == true <==> is_condition_true(x);
    assigns \nothing;
 */
bool func(int x)
{
    int x_mod_200;
    bool is_divisible_by_200;
    bool is_less_than_100;
    bool result;

    x_mod_200 = x % 200;
    is_divisible_by_200 = (x_mod_200 == 0);
    is_less_than_100 = (x_mod_200 < 100);

    if (x >= 2000)
    {
        //@ assert x >= 2000;
        result = true;
    }
    else if (is_divisible_by_200 || is_less_than_100)
    {
        //@ assert is_divisible_by_200 || is_less_than_100;
        result = true;
    }
    else
    {
        //@ assert !(x >= 2000 || (x % 200 == 0 || x % 200 < 100));
        result = false;
    }

    return result;
}
