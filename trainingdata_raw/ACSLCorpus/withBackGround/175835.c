#include <limits.h>

/*@
    predicate valid_range(integer x) = 3 <= x <= 20;

    logic integer max_val(integer a, integer b) =
        a > b ? a : b;

    lemma result_property:
        \forall integer a, b, max, res;
            valid_range(a) && valid_range(b) &&
            max == max_val(a, b) &&
            (res == a + b || res == 2 * max - 1) ==>
            (res == a + b || res == 2 * a - 1 || res == 2 * b - 1);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    assigns \nothing;
*/
int func(int a, int b)
{
    int result = 0;
    int max_val = 0;

    //@ assert valid_range(a) && valid_range(b);

    if (a > b)
    {
        max_val = a;
    }
    else
    {
        max_val = b;
    }

    //@ assert max_val == max_val(a, b);
    //@ assert valid_range(max_val);

    if (max_val < 13)
    {
        result = a + b;
    }
    else
    {
        result = 2 * max_val - 1;
    }

    //@ assert result == a + b || result == 2 * max_val - 1;
    //@ assert result == a + b || result == 2 * a - 1 || result == 2 * b - 1;

    return result;
}
