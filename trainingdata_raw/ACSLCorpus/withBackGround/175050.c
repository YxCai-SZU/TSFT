#include <stdbool.h>

/*@
    predicate strict_ascending(integer A, integer B, integer C, integer D, integer E) =
        A < B && B < C && C < D && D < E;
*/

/*@
    requires 0 <= A <= 123;
    requires 0 <= B <= 123;
    requires 0 <= C <= 123;
    requires 0 <= D <= 123;
    requires 0 <= E <= 123;
    requires 0 <= K <= 123;
    requires strict_ascending(A, B, C, D, E);
    ensures \result == (E - A <= K);
*/
bool func(int A, int B, int C, int D, int E, int K)
{
    bool ans;
    //@ assert A < E;
    ans = (E - A) <= K;
    //@ assert ans == (E - A <= K);
    return ans;
}
