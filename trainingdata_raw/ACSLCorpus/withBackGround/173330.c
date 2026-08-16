#include <stdbool.h>
#include <stdint.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;

    logic integer compute_result(integer a, integer b) =
        a > (b * 2) ? a - (b * 2) : 0;

    lemma result_property:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==>
        compute_result(a, b) <= a;
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == a - (b * 2) || \result == 0;
    ensures \result <= a;
    assigns \nothing;
*/
uint32_t func(uint32_t a, uint32_t b)
{
    bool result;
    uint32_t ret_val;

    result = a > (b * 2);

    if (result)
    {
        //@ assert result == true;
        ret_val = a - (b * 2);
    }
    else
    {
        //@ assert result == false;
        ret_val = 0;
    }

    return ret_val;
}
