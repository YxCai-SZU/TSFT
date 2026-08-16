#include <stdint.h>

/*@
    predicate valid_inputs(integer A, integer P) =
        0 <= A && A <= 100 && 0 <= P && P <= 100;

    logic integer compute_result(integer A, integer P) =
        (A * 3 + P) / 2;
*/

/*@
    requires valid_inputs(A, P);
    ensures \result == compute_result(A, P);
    assigns \nothing;
*/
uint32_t func(uint32_t A, uint32_t P)
{
    uint32_t sum;
    uint32_t result;

    //@ assert 0 <= A && A <= 100;
    //@ assert 0 <= P && P <= 100;

    sum = A * 3 + P;

    //@ assert sum <= 100 * 3 + 100;

    result = sum / 2;

    //@ assert result == compute_result(A, P);

    return result;
}
