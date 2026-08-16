#include <stdbool.h>

/*@ predicate is_in_range(integer x) = 3 <= x && x <= 20; */

/*@
    requires is_in_range(a) && is_in_range(b);
    ensures \result == a + b || \result == 2 * a - 1 || \result == 2 * b - 1;
    ensures \result >= 0;
    assigns \nothing;
*/
int func(int a, int b)
{
    int min_val;
    int max_val;
    int result;

    if (a < b)
    {
        min_val = a;
    }
    else
    {
        min_val = b;
    }

    if (a > b)
    {
        max_val = a;
    }
    else
    {
        max_val = b;
    }

    if (max_val - min_val == 1)
    {
        //@ assert max_val + min_val >= 0;
        result = max_val + min_val;
    }
    else
    {
        //@ assert 2 * max_val - 1 >= 0;
        result = 2 * max_val - 1;
    }

    return result;
}
