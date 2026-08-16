#include <stdbool.h>

/*@
    predicate bounds(integer a, integer b, integer c) =
        1 <= a <= 100 && 1 <= b <= 100 && 1 <= c <= 100;

    logic integer total_available(integer a, integer b) = a + b + 1;

    predicate can_pay(integer a, integer b, integer c) =
        total_available(a, b) >= c;
*/

/*@
    requires bounds(A, B, C);
    ensures \result == (total_available(A, B) >= C);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    // Variable declarations at scope top
    bool result;

    //@ assert 1 <= A <= 100;
    //@ assert 1 <= B <= 100;
    //@ assert 1 <= C <= 100;

    if (A + B + 1 < C)
    {
        //@ assert A + B + 1 < C;
        result = false;
    }
    else
    {
        //@ assert A + B + 1 >= C;
        result = true;
    }

    return result;
}
