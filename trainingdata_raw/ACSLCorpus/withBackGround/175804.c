#include <stdbool.h>

/*@
    predicate is_valid_range(integer A, integer B, integer C, integer D, integer E, integer K) =
        0 <= A && A <= B && B <= C && C <= D && D <= E && E <= 123 &&
        0 <= K && K <= 123;

    predicate condition_holds(integer A, integer B, integer C, integer D, integer E, integer K) =
        (E - A <= K) || (E - B <= K) || (E - C <= K) || (E - D <= K);
*/

/*@
    requires is_valid_range(A, B, C, D, E, K);
    ensures \result == true <==> condition_holds(A, B, C, D, E, K);
    assigns \nothing;
*/
bool func(int A, int B, int C, int D, int E, int K)
{
    bool ans;
    ans = false;

    if (A > E)
    {
        ans = true;
    }
    else if (E - A <= K)
    {
        ans = true;
    }
    else if (B >= E || E - B <= K)
    {
        ans = true;
    }
    else if (C >= E || E - C <= K)
    {
        ans = true;
    }
    else if (D >= E || E - D <= K)
    {
        ans = true;
    }

    //@ assert ans == true <==> condition_holds(A, B, C, D, E, K);
    return ans;
}
