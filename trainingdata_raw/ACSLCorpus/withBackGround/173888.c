#include <stdbool.h>

/*@
    predicate is_valid_range(integer v) = 1 <= v <= 100;

    logic integer compute_expr(integer c, integer d) = c * (d - 1) + 1;

    lemma expr_bounds:
        \forall integer c, d;
            is_valid_range(c) && is_valid_range(d) ==>
            0 <= c * (d - 1) && compute_expr(c, d) <= 100 * 99 + 1;
*/

/*@
    requires is_valid_range(a) && is_valid_range(b);
    requires is_valid_range(c) && is_valid_range(d);
    ensures \result == (b >= c * (d - 1) + 1);
*/
bool func(int a, int b, int c, int d)
{
    //@ assert is_valid_range(c) && is_valid_range(d);
    //@ assert 0 <= c * (d - 1);
    //@ assert c * (d - 1) + 1 <= 100 * 99 + 1;

    bool result;
    if (b >= c * (d - 1) + 1)
    {
        result = true;
    }
    else
    {
        result = false;
    }
    //@ assert result == (b >= c * (d - 1) + 1);
    return result;
}
