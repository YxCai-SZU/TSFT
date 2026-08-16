#include <stdbool.h>

/*@ predicate in_range(integer v) = -100 <= v <= 100; */

/*@
    requires in_range(A) && in_range(B) && in_range(C);
    ensures \result == (A <= C && C <= B);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert in_range(A);
    //@ assert in_range(B);
    //@ assert in_range(C);
    
    result = (A <= C) && (C <= B);
    return result;
}
