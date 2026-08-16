#include <stdint.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 205 && 1 <= y <= 205;

    logic integer compute_result(integer x, integer y) =
        (x == 1 && y == 1) ? 1000000 :
        (x == 1 && y != 1) ? 600000 :
        (x != 1 && y == 1) ? 600000 : 0;

    lemma result_non_negative:
        \forall integer x, y; valid_input(x, y) ==> compute_result(x, y) >= 0;
*/

/*@
    requires valid_input(x, y);
    ensures \result == compute_result(x, y);
    ensures \result >= 0;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t x_local;
    uint32_t y_local;
    uint32_t x_adjusted;
    uint32_t y_adjusted;
    uint32_t result;

    x_local = x - 1;
    y_local = y - 1;

    //@ assert x_local == x - 1 && y_local == y - 1;

    if (x_local > 0)
        x_adjusted = x_local;
    else
        x_adjusted = 0;

    if (y_local > 0)
        y_adjusted = y_local;
    else
        y_adjusted = 0;

    //@ assert x_adjusted >= 0 && y_adjusted >= 0;

    if (x_adjusted == 0 && y_adjusted == 0)
    {
        result = 1000000;
        //@ assert result == 1000000;
    }
    else if (x_adjusted == 0 || y_adjusted == 0)
    {
        result = 600000;
        //@ assert result == 600000;
    }
    else
    {
        result = 0;
        //@ assert result == 0;
    }

    //@ assert result >= 0;
    return result;
}
