#include <stdint.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 205;

    logic integer func_spec(integer x, integer y) =
        (x == 1 && y == 1) ? 1000000 :
        (x == 1 && y == 2) ? 600000 :
        (x == 1) ? 300000 :
        (x == 2 && y == 1) ? 600000 :
        (x == 2 && y == 2) ? 400000 :
        (x == 3 && y == 1) ? 300000 : 0;

    lemma result_bounds:
        \forall integer x, y;
        valid_range(x) && valid_range(y) ==>
        0 <= func_spec(x, y) <= 1000000;
*/

/*@
    requires 1 <= x <= 205;
    requires 1 <= y <= 205;
    ensures \result <= 1000000;
    ensures \result >= 0;
    assigns \nothing;
*/
uint32_t func(uint32_t x, uint32_t y)
{
    uint32_t result = 0;

    if (x == 1)
    {
        if (y == 1)
        {
            return 1000000;
        }
        else if (y == 2)
        {
            result += 600000;
        }
        else
        {
            result += 300000;
        }
    }
    else if (x == 2)
    {
        if (y == 1)
        {
            result += 600000;
        }
        else if (y == 2)
        {
            result += 400000;
        }
    }
    else if (x == 3)
    {
        if (y == 1)
        {
            result += 300000;
        }
    }

    //@ assert result <= 1000000;

    return result;
}
