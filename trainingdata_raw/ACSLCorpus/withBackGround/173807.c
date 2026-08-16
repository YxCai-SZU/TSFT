#include <limits.h>

/*@
    predicate valid_range(integer v) = 1 <= v <= 10000;
*/

/*@
    requires valid_range(A) && valid_range(B) && valid_range(C) && valid_range(D);
    ensures \result == A * B || \result == C * D;
    ensures \result >= A * B && \result >= C * D;
    assigns \nothing;
*/
int func(int A, int B, int C, int D)
{
    int sa;
    int sc;
    int ans;

    //@ assert A * B <= 10000 * 10000;
    //@ assert C * D <= 10000 * 10000;

    sa = A * B;
    sc = C * D;

    if (sa > sc) {
        ans = sa;
    } else {
        ans = sc;
    }

    //@ assert ans == A * B || ans == C * D;
    //@ assert ans >= A * B && ans >= C * D;

    return ans;
}
