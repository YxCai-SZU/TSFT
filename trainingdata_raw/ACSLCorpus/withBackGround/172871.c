#include <stdbool.h>

/*@
    predicate valid_range(integer v) = 0 <= v <= 23;

    logic integer compute_result(integer x, integer y) =
        (x + y < 24) ? (x + y) : ((x + y) - 24);

    lemma result_bounds:
        \forall integer x, y;
        valid_range(x) && valid_range(y) ==>
        0 <= compute_result(x, y) <= 24;
*/

/*@
    requires valid_range(x);
    requires valid_range(y);
    ensures \result >= 0;
    ensures \result <= 24;
    assigns \nothing;
*/
int func(int x, int y)
{
    // Variable declarations at scope top
    int result;

    //@ assert x >= 0 && x <= 23;
    //@ assert y >= 0 && y <= 23;

    if (x + y < 24) {
        result = x + y;
        //@ assert result == x + y;
        //@ assert result >= 0;
        //@ assert result <= 23;
    } else {
        result = (x + y) - 24;
        //@ assert result == (x + y) - 24;
        //@ assert result >= 0;
        //@ assert result <= 24;
    }

    return result;
}
