#include <stdbool.h>

/*@
    predicate is_ordered(integer a, integer b, integer c) =
        a < b && b < c;
 */

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == (A < B && B < C);
    assigns \nothing;
 */
bool func(int A, int B, int C)
{
    bool result = true;

    if (A < B)
    {
        if (B < C)
        {
        }
        else
        {
            result = false;
        }
    }
    else
    {
        result = false;
    }

    //@ assert result == (A < B && B < C);
    return result;
}
