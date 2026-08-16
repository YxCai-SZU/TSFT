#include <stdbool.h>

/*@
    predicate is_valid_params(integer A, integer B, integer C) =
        1 <= A && A <= 5000 &&
        1 <= B && B <= 5000 &&
        1 <= C && C <= 100000;

    predicate condition_holds(integer A, integer B, integer C) =
        A + B >= C;
*/

/*@
    requires is_valid_params(A, B, C);
    ensures \result == true <==> condition_holds(A, B, C);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    bool ans;

    ans = false;

    //@ assert ans == false;
    if (A + B >= C)
    {
        ans = true;
        //@ assert condition_holds(A, B, C);
    }
    else
    {
        ans = false;
        //@ assert !condition_holds(A, B, C);
    }

    //@ assert ans == true <==> condition_holds(A, B, C);
    return ans;
}
