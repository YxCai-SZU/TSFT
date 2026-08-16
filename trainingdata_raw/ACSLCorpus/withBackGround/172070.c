#include <stdbool.h>

/*@
    predicate is_triangle_sum(integer A, integer B, integer C) =
        A + B == C || A + C == B || B + C == A;
 */

/*@
    requires 1 <= A <= 100;
    requires 1 <= B <= 100;
    requires 1 <= C <= 100;
    ensures \result == (A + B == C || A + C == B || B + C == A);
    assigns \nothing;
 */
bool func(unsigned long A, unsigned long B, unsigned long C)
{
    bool result;

    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    //@ assert 1 <= C <= 100;

    result = (A + B == C) || (A + C == B) || (B + C == A);

    //@ assert result == (A + B == C || A + C == B || B + C == A);
    //@ assert result == true || result == false;
    //@ assert result == true ==> (A + B == C || A + C == B || B + C == A);
    //@ assert result == false ==> !(A + B == C || A + C == B || B + C == A);

    return result;
}
