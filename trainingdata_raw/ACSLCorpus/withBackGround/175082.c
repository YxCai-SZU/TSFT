#include <stdbool.h>

/*@
    predicate is_valid_params(integer x, integer y) =
        1 <= x <= 100 && 1 <= y <= 100;

    logic integer compute_expr(integer x, integer y) =
        (y * 2 - 1) * x;

    lemma arithmetic_bounds:
        \forall integer x, y;
        is_valid_params(x, y) ==>
        y * 2 <= 200 &&
        y * 2 - 1 <= 199 &&
        compute_expr(x, y) <= 199 * 100;
*/

/*@
    requires is_valid_params(x, y);
    ensures \result == (compute_expr(x, y) >= y);
    assigns \nothing;
*/
bool func(unsigned long long x, unsigned long long y)
{
    // Variable declarations at scope top
    bool result;
    unsigned long long temp1;
    unsigned long long temp2;
    unsigned long long temp3;

    //@ assert y * 2 <= 200;
    temp1 = y * 2;

    //@ assert temp1 - 1 <= 199;
    temp2 = temp1 - 1;

    //@ assert temp2 * x <= 199 * 100;
    temp3 = temp2 * x;

    result = (temp3 >= y);
    return result;
}
