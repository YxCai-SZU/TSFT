#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100;

    logic integer compute_result(integer a, integer b) =
        (a + b + 1) / 2 * 2 == (a + b) / 2 * 2 + 1 ?
        (a + b + 1) / 2 * 2 : (a + b) / 2 * 2 + 1;

    lemma result_property:
        \forall integer a, b, r;
        valid_input(a, b) && r == compute_result(a, b) ==>
        r >= 0 && r <= 2000;
*/

/*@
    requires valid_input(a, b);
    ensures \result >= 0 && \result <= 2000;
    ensures \result == (a + b + 1) / 2 * 2 || \result == (a + b) / 2 * 2 + 1;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t sum;
    uint32_t avg;
    int32_t result;

    sum = a + b + 1;
    avg = sum / 2;
    result = (int32_t)(avg * 2) - 1;

    //@ assert result == (int32_t)((a + b + 1) / 2 * 2) - 1;

    if (sum % 2 != 0)
    {
        result += 1;
        //@ assert result == (a + b + 1) / 2 * 2;
    }
    else
    {
        //@ assert result == (a + b) / 2 * 2 + 1;
    }

    return result;
}
