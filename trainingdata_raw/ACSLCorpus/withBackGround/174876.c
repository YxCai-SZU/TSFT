#include <stdbool.h>

/*@
    predicate in_range(integer v) = 1 <= v <= 100;

    logic integer compute_sum(integer A, integer B, integer C, integer D) =
        B > A ? A + D : B + C;
*/

/*@
    requires in_range(A) && in_range(B) && in_range(C) && in_range(D);
    ensures \result == true <==> compute_sum(A, B, C, D) >= 0;
*/
bool func(int A, int B, int C, int D)
{
    int sum;

    if (B > A)
    {
        sum = A + D;
    }
    else
    {
        sum = B + C;
    }

    //@ assert sum == compute_sum(A, B, C, D);

    if (sum >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
