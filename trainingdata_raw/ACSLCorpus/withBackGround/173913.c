#include <stdint.h>

/*@
    predicate valid_input(integer A, integer B) =
        1 <= A && A <= 100 &&
        1 <= B && B <= 100;

    logic integer compute_C(integer A, integer B) =
        A - (B * 2);

    predicate result_nonnegative(integer r) =
        r >= 0;

    predicate result_correct(integer A, integer B, integer r) =
        r == compute_C(A, B) || r == 0;
*/

/*@
    requires valid_input(A, B);
    ensures result_nonnegative(\result);
    ensures result_correct(A, B, \result);
*/
int64_t func(int64_t A, int64_t B)
{
    int64_t C;
    int64_t result;

    C = A - (B * 2);
    
    if (C < 0)
    {
        //@ assert C < 0;
        result = 0;
    }
    else
    {
        //@ assert C >= 0;
        result = C;
    }

    //@ assert result_nonnegative(result);
    //@ assert result_correct(A, B, result);
    return result;
}
