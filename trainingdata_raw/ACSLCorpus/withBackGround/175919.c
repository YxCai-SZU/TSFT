#include <stdbool.h>

/*@
    predicate bounds(integer A, integer B, integer C, integer D, integer E, integer K) =
        0 <= A && A < B && B < C && C < D && D < E && E <= 123 &&
        0 <= K && K <= 123;

    logic integer distance(integer E, integer A) = E - A;
*/

/*@
    requires bounds(A, B, C, D, E, K);
    ensures \result == (distance(E, A) <= K);
    assigns \nothing;
*/
bool func(unsigned int A, unsigned int B, unsigned int C, unsigned int D, unsigned int E, unsigned int K)
{
    bool ans;

    //@ assert bounds(A, B, C, D, E, K);
    //@ assert distance(E, A) <= 123;

    if (A + K >= E)
    {
        ans = true;
        //@ assert ans == (distance(E, A) <= K);
    }
    else
    {
        ans = false;
        //@ assert ans == (distance(E, A) <= K);
    }

    //@ assert ans == (distance(E, A) <= K);
    return ans;
}
