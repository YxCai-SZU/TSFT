#include <stdint.h>

/*@
    predicate bounds(integer x, integer y) =
        1 <= x && x < y && y <= 100;

    logic integer result_val(integer x, integer y) =
        x * (y - x + 1);

    lemma result_bounds:
        \forall integer x, y;
            bounds(x, y) ==> 1 <= result_val(x, y) <= 9900;
*/

/*@
    requires 1 <= x < y <= 100;
    ensures \result == x * (y - x + 1);
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    //@ assert bounds(x, y);
    //@ assert x > 0 && y > 0;
    //@ assert x < 100 && y <= 100;
    //@ assert x < y;
    //@ assert 1 <= x * (y - x + 1) <= 9900;
    return x * (y - x + 1);
}
