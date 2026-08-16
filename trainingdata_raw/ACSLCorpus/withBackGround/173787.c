#include <stdbool.h>

/*@
    predicate in_range(integer v) = 0 <= v <= 100;
    predicate valid_input(integer a, integer b, integer c) =
        in_range(a) && in_range(b) && in_range(c);
    predicate result_condition(integer a, integer b, integer c, bool r) =
        r == ((a <= c) && (c <= a + b));
*/

/*@
    requires valid_input(A, B, C);
    ensures result_condition(A, B, C, \result);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    bool result;
    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    result = (A <= C) && (C <= A + B);
    return result;
}
