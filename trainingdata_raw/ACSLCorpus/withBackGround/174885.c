#include <stdint.h>

/*@
    predicate valid_inputs(integer a, integer b) =
        1 <= a <= 100 && 1 <= b <= 100;

    logic integer formula(integer a, integer b) =
        a * (b + 1) / 2;

    lemma multiplication_bound:
        \forall integer a, b;
        valid_inputs(a, b) ==> a * (b + 1) <= 100 * 101;
*/

/*@
    requires valid_inputs(a, b);
    ensures \result == formula(a, b);
    assigns \nothing;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t b_plus_1;
    uint32_t a_times_b_plus_1;
    uint32_t half_of_a_times_b_plus_1;
    int32_t result;

    b_plus_1 = b + 1;

    //@ assert b_plus_1 <= 101;
    //@ assert a <= 100;
    //@ assert a * b_plus_1 <= 100 * 101;

    a_times_b_plus_1 = a * b_plus_1;
    half_of_a_times_b_plus_1 = a_times_b_plus_1 / 2;

    //@ assert half_of_a_times_b_plus_1 == formula(a, b);

    result = (int32_t)half_of_a_times_b_plus_1;
    return result;
}
