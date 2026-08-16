#include <stdbool.h>

/*@
    predicate valid_range(integer x) = 1 <= x <= 13;

    logic integer sum_abc(integer a, integer b, integer c) = a + b + c;

    lemma sum_bounds:
        \forall integer a, b, c;
            valid_range(a) && valid_range(b) && valid_range(c) ==>
            3 <= sum_abc(a, b, c) <= 39;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C);
    ensures \result == (A + B + C >= 22);
    assigns \nothing;
*/
bool func(unsigned long long A, unsigned long long B, unsigned long long C)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert valid_range(A);
    //@ assert valid_range(B);
    //@ assert valid_range(C);
    //@ assert 3 <= A + B + C <= 39;

    if (A + B + C >= 22)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
