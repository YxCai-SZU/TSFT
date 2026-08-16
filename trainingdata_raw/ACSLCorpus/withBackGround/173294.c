#include <stdint.h>

/*@
    predicate valid_input(integer A, integer B, integer C) =
        1 <= B && B <= A && A <= 20 &&
        1 <= C && C <= 20;

    logic integer compute_ans(integer A, integer B, integer C) =
        C - A + B;

    logic integer compute_max(integer ans) =
        ans > 0 ? ans : 0;
*/

/*@
    requires valid_input(A, B, C);
    ensures \result >= 0;
    ensures \result <= C;
    assigns \nothing;
*/
int32_t func(int32_t A, int32_t B, int32_t C)
{
    int32_t ans;
    int32_t max_val;

    ans = C - A + B;

    //@ assert ans == compute_ans(A, B, C);

    if (ans > 0)
    {
        max_val = ans;
        //@ assert max_val == ans;
    }
    else
    {
        max_val = 0;
        //@ assert max_val == 0;
    }

    //@ assert max_val == compute_max(ans);
    //@ assert max_val >= 0;
    //@ assert max_val <= C;

    return max_val;
}
