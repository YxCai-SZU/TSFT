#include <stdbool.h>

/*@
    predicate valid_range(integer N, integer M) =
        1 <= N <= 16 &&
        1 <= M <= 16 &&
        N + M <= 16;

    logic integer double_N(integer N) = N * 2;
    logic integer quadruple_N(integer N) = N * 4;

    lemma double_bound: \forall integer N; 1 <= N <= 16 ==> double_N(N) <= 32;
    lemma quadruple_bound: \forall integer N; 1 <= N <= 16 ==> quadruple_N(N) <= 64;
*/

/*@
    requires valid_range(N, M);
    ensures \result == (double_N(N) <= M && M <= quadruple_N(N) && N > 0);
*/
bool func(unsigned long N, unsigned long M)
{
    // Variable declarations at top of scope
    bool result;

    //@ assert 1 <= N <= 16;
    //@ assert 1 <= M <= 16;
    //@ assert N + M <= 16;

    //@ assert double_N(N) <= 32;
    //@ assert quadruple_N(N) <= 64;

    if ((N * 2) <= M && M <= (N * 4) && N > 0)
    {
        result = true;
    }
    else
    {
        result = false;
    }

    return result;
}
