#include <stdbool.h>

/*@
    predicate valid_range(integer N, integer M) =
        1 <= N <= 20 && 1 <= M <= 20;

    logic integer func_result(integer N, integer M) =
        (N * 2 <= M && M <= N * 4 && N > 0) ? 1 : 0;

    lemma result_property:
        \forall integer N, M;
        valid_range(N, M) ==>
        (func_result(N, M) == 1 ==> (N * 2 <= M && M <= N * 4 && N > 0)) &&
        (func_result(N, M) == 0 ==> (N * 2 > M || M > N * 4 || N <= 0));
*/

/*@
    requires 1 <= N <= 20;
    requires 1 <= M <= 20;
    ensures \result == 1 || \result == 0;
    ensures \result == 1 ==> (N * 2 <= M && M <= N * 4 && N > 0);
    ensures \result == 0 ==> (N * 2 > M || M > N * 4 || N <= 0);
*/
int func(int N, int M)
{
    int result;

    //@ assert valid_range(N, M);

    if (N * 2 > M || M > N * 4 || N <= 0)
    {
        //@ assert N * 2 > M || M > N * 4 || N <= 0;
        result = 0;
    }
    else
    {
        //@ assert N * 2 <= M && M <= N * 4 && N > 0;
        result = 1;
    }

    //@ assert result == 1 || result == 0;
    return result;
}
