#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 100;
    
    logic integer square(integer x) = x * x;
    
    predicate result_condition(integer a, integer b, integer c, bool r) =
        r == (square(a) == b || square(b) == c || square(c) == a);
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C);
    ensures \result == (A * A == B || B * B == C || C * C == A);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    //@ assert A * A <= 10000;
    //@ assert B * B <= 10000;
    //@ assert C * C <= 10000;
    
    //@ assert A * A <= 10000 && B * B <= 10000 && C * C <= 10000;
    
    return (A * A == B) || (B * B == C) || (C * C == A);
}
