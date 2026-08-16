#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 5000;

    logic integer sum(integer a, integer b) = a + b;

    lemma sum_bound:
        \forall integer a, b;
        valid_range(a) && valid_range(b) ==> sum(a, b) <= 10000;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C);
    ensures \result == true <==> (A + B == C || A + C == B || B + C == A);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C)
{
    unsigned int train;

    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);
    //@ assert A + B <= 10000;
    //@ assert A + C <= 10000;
    //@ assert B + C <= 10000;

    train = A + B;
    if (train == C)
    {
        return true;
    }

    train = A + C;
    if (train == B)
    {
        return true;
    }

    train = B + C;
    if (train == A)
    {
        return true;
    }

    return false;
}
