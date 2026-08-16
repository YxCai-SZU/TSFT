#include <stdbool.h>

/*@
    predicate is_arithmetic_progression(integer a, integer b, integer c) =
        b - a == c - b;
*/

/*@
    requires 0 <= A <= 100;
    requires 0 <= B <= 100;
    requires 0 <= C <= 100;
    ensures \result == (B - A == C - B);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    int tmp1;
    int tmp2;
    bool result;

    //@ assert B - A == C - B ==> (B - A == C - B);
    tmp1 = B - A;
    tmp2 = C - B;
    result = (tmp1 == tmp2);
    return result;
}
