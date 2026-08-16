#include <stdbool.h>

/*@
    predicate is_valid_params(integer a, integer b, integer c) =
        1 <= a && a <= 100 &&
        1 <= b && b <= 100 &&
        1 <= c && c <= 100;

    predicate condition_holds(integer a, integer b, integer c) =
        a + b == c || a + c == b || b + c == a;
*/

/*@
    requires is_valid_params(A, B, C);
    ensures \result == (A + B == C || A + C == B || B + C == A);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    bool ok;

    ok = false;

    if (A + B == C)
    {
        ok = true;
    }

    if (A + C == B)
    {
        ok = true;
    }

    if (B + C == A)
    {
        ok = true;
    }

    //@ assert ok == (A + B == C || A + C == B || B + C == A);

    return ok;
}
