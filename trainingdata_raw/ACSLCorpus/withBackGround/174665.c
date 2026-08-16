#include <stdint.h>

/*@
    predicate valid_inputs(integer A, integer B) =
        1 <= A <= 12 && 1 <= B <= 31;

    predicate ensures_result(integer res, integer A) =
        res <= A && res >= 1;
*/

/*@
    requires valid_inputs(A, B);
    assigns \nothing;
    ensures ensures_result(\result, A);
*/
uint32_t func(uint32_t A, uint32_t B)
{
    uint32_t ans;

    if (A <= B)
    {
        ans = A;
    }
    else
    {
        ans = B;
    }

    //@ assert ans >= 1 && ans <= A;

    return ans;
}
