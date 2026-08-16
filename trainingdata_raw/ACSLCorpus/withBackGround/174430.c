#include <stdint.h>

/*@
    predicate valid_range(integer x) = 2 <= x <= 100;

    logic integer expected_result(integer a, integer b) =
        (a * b) - (a + b - 1);
*/

/*@
    requires valid_range(a) && valid_range(b);
    ensures \result == expected_result(a, b);
    assigns \nothing;
*/
int32_t func(int32_t a, int32_t b)
{
    uint32_t a_unsigned;
    uint32_t b_unsigned;
    uint32_t product;
    uint32_t sum;
    int32_t result_unsigned;

    a_unsigned = (uint32_t)a;
    b_unsigned = (uint32_t)b;

    //@ assert a_unsigned >= 2 && a_unsigned <= 100;
    //@ assert b_unsigned >= 2 && b_unsigned <= 100;
    //@ assert a_unsigned * b_unsigned <= 10000;

    product = a_unsigned * b_unsigned;
    sum = a_unsigned + b_unsigned - 1;
    result_unsigned = (int32_t)product - (int32_t)sum;

    //@ assert result_unsigned == expected_result(a, b);
    return result_unsigned;
}
