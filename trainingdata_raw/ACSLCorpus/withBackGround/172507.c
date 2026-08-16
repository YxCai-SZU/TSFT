#include <stdint.h>

/*@
    predicate valid_params(integer A, integer B, integer C) =
        1 <= B && B <= A && A <= 20 &&
        1 <= C && C <= 20;

    logic integer compute_result(integer A, integer B, integer C) =
        (C - (A - B) < 0) ? 0 : (C - (A - B));

    lemma result_properties:
        \forall integer A, B, C;
        valid_params(A, B, C) ==>
        (
            compute_result(A, B, C) >= 0 &&
            compute_result(A, B, C) <= C &&
            (
                compute_result(A, B, C) == C - (A - B) ||
                compute_result(A, B, C) == 0
            )
        );
*/

/*@
    requires valid_params(A, B, C);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == C - (A - B) || \result == 0;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B, int32_t C)
{
    int32_t diff;
    int32_t result;

    diff = A - B;
    //@ assert diff == A - B;

    if (C - diff < 0)
    {
        result = 0;
        //@ assert result == 0;
    }
    else
    {
        result = C - diff;
        //@ assert result == C - diff;
    }

    return result;
}
