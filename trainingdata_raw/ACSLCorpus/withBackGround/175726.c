#include <stdbool.h>

/*@
    predicate valid_inputs(integer x, integer y) =
        1 <= x <= 16 &&
        1 <= y <= 16 &&
        x + y <= 16;

    logic integer scaled_value(integer v) = (v * 10) / 100;

    lemma arithmetic_bounds:
        \forall integer x, y;
        valid_inputs(x, y) ==>
        x * 10 <= 160 && y * 10 <= 160;
*/

/*@
    requires valid_inputs(x, y);
    ensures \result == (scaled_value(x) + scaled_value(y) <= 1);
    assigns \nothing;
*/
bool func(unsigned long x, unsigned long y)
{
    // Variable declarations at scope top
    unsigned long x_tenth;
    unsigned long y_tenth;
    bool result;

    //@ assert x * 10 <= 160;
    //@ assert y * 10 <= 160;

    x_tenth = (x * 10) / 100;
    y_tenth = (y * 10) / 100;
    result = (x_tenth + y_tenth <= 1);
    return result;
}
