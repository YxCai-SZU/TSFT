#include <stdint.h>

/*@
    predicate valid_input(integer x) = 1 <= x <= 100000;

    logic integer expected_result(integer x) =
        (x / 500) * 1000 + ((x % 500) / 5) * 5;

    lemma result_correctness:
        \forall integer x; valid_input(x) ==>
            expected_result(x) == (x / 500) * 1000 + ((x % 500) / 5) * 5;
*/

/*@
    requires valid_input(x);
    ensures \result == expected_result(x);
    assigns \nothing;
*/
uint32_t func(uint32_t x)
{
    uint32_t result;
    uint32_t temp_x;
    uint32_t x_500;
    uint32_t x_5;

    result = 0;
    temp_x = x;

    // Calculate the number of 500 units
    x_500 = temp_x / 500;
    result = result + x_500 * 1000;
    temp_x = temp_x % 500;

    // Calculate the number of 5 units
    x_5 = temp_x / 5;
    result = result + x_5 * 5;

    //@ assert result == x_500 * 1000 + x_5 * 5;
    //@ assert temp_x == x % 500;
    //@ assert x_500 == x / 500;
    //@ assert x_5 == temp_x / 5;
    //@ assert result == expected_result(x);

    return result;
}
