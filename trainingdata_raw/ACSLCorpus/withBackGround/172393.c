#include <stdbool.h>

/*@ predicate is_valid_range(integer x) = 1 <= x <= 100; */

/*@
    requires is_valid_range(A) && is_valid_range(B) && is_valid_range(C);
    ensures \result == (C - B == B - A);
    assigns \nothing;
*/
bool func(int A, int B, int C)
{
    int AB;
    int BC;
    bool result;

    AB = B - A;
    BC = C - B;

    //@ assert AB == B - A;
    //@ assert BC == C - B;

    result = (AB == BC);
    return result;
}
