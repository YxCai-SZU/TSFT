#include <stdint.h>

/*@
    predicate valid_input(integer x, integer y) =
        1 <= x <= 205 && 1 <= y <= 205;

    logic integer compute_result(integer x, integer y) =
        x == 1 && y == 1 ? 1000000 :
        x == 1 && y != 1 ? 600000 - (y - 1) * 100 :
        x != 1 && y == 1 ? 600000 - (x - 1) * 100 :
        400000 - (x - 1) * 100 - (y - 1) * 100;

    lemma result_bounds:
        \forall integer x, y; valid_input(x, y) ==> compute_result(x, y) <= 1000000;

    lemma no_overflow_1:
        \forall integer x; 1 <= x <= 205 ==> (x - 1) * 100 <= 20400;

    lemma no_overflow_2:
        \forall integer x, y; 1 <= x <= 205 && 1 <= y <= 205 && x != 1 && y != 1 ==>
            400000 >= (x - 1) * 100 + (y - 1) * 100;
*/

/*@
    requires valid_input(x, y);
    ensures \result == compute_result(x, y);
    ensures \result <= 1000000;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t result;

    //@ assert valid_input(x, y);

    if (x == 1 && y == 1)
    {
        result = 1000000;
    }
    else if (x == 1)
    {
        result = 600000 - (y - 1) * 100;
    }
    else if (y == 1)
    {
        result = 600000 - (x - 1) * 100;
    }
    else
    {
        //@ assert x - 1 <= 204;
        //@ assert y - 1 <= 204;
        //@ assert 400000 >= (x - 1) * 100 + (y - 1) * 100;
        result = 400000 - (x - 1) * 100 - (y - 1) * 100;
    }

    //@ assert result <= 1000000;
    //@ assert result == compute_result(x, y);

    return result;
}
