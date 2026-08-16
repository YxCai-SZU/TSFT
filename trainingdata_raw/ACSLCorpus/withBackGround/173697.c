#include <stdint.h>

/*@
    predicate valid_input(integer a, integer b) =
        1 <= a <= 3 && 1 <= b <= 3 && a != b;

    logic integer compute_result(integer a, integer b) =
        6 - (a + b);

    lemma result_bounds:
        \forall integer a, b;
        valid_input(a, b) ==> 1 <= compute_result(a, b) <= 3;
*/

/*@
    requires valid_input(a, b);
    ensures \result == compute_result(a, b);
    ensures 1 <= \result <= 3;
*/
int32_t func(uint32_t a, uint32_t b)
{
    uint32_t result;
    uint32_t total;
    uint32_t sum;

    result = 0;
    total = 6;
    sum = a + b;

    //@ assert 1 <= sum <= 6;
    //@ assert 0 <= total - sum <= 5;

    result = total - sum;

    //@ assert result == 6 - (a + b);

    return (int32_t)result;
}
