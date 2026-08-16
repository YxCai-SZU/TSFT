#include <stdbool.h>

/*@
    predicate all_equal(integer a, integer b, integer c) =
        a == b && a == c;
*/

/*@
    requires 1 <= A && A <= 100;
    requires 1 <= B && B <= 100;
    requires 1 <= C && C <= 100;
    ensures \result == (A == B && A == C);
    assigns \nothing;
*/
bool func(long A, long B, long C)
{
    bool ans;
    //@ ghost bool spec_ans;

    ans = (A == B && B == C);
    //@ ghost spec_ans = (A == B && A == C);

    //@ assert ans == spec_ans;

    return ans;
}
