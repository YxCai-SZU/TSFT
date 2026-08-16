#include <stdint.h>

/*@
    predicate valid_input(integer A, integer B, integer C) =
        1 <= B && B <= A && A <= 20 &&
        1 <= C && C <= 20;

    logic integer compute_result(integer A, integer B, integer C) =
        C > (A - B) ? C - (A - B) : 0;
*/

/*@
    requires valid_input(A, B, C);
    ensures \result >= 0;
    ensures \result <= C;
    ensures \result == compute_result(A, B, C);
    ensures \result == C - (A - B) || \result == 0;
*/
int32_t func(int32_t A, int32_t B, int32_t C)
{
    // Variable declarations at scope top
    int32_t result;

    //@ assert C - (A - B) <= C;
    
    if (C > (A - B))
    {
        result = C - (A - B);
    }
    else
    {
        result = 0;
    }
    
    return result;
}
