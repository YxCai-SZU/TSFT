#include <limits.h>

/*@
    predicate valid_params(integer N, integer K, integer X, integer Y) =
        1 <= N <= 10000 &&
        1 <= K <= 10000 &&
        1 <= X <= 10000 &&
        1 <= Y < X;

    logic integer compute_ans(integer N, integer K, integer X, integer Y) =
        N <= K ? X * N : X * (K + 1) + Y * (N - K - 1);

    lemma product_bound1:
        \forall integer X, integer N;
        1 <= X <= 10000 && 1 <= N <= 10000 ==> X * N <= 100000000;

    lemma product_bound2:
        \forall integer X, integer K;
        1 <= X <= 10000 && 1 <= K <= 10000 ==> X * (K + 1) <= 10000 * 10001;

    lemma product_bound3:
        \forall integer Y, integer N, integer K, integer X;
        1 <= Y < X <= 10000 && 1 <= N <= 10000 && 1 <= K <= 10000 ==>
        Y * (N - K - 1) <= 100000000;
*/

/*@
    requires valid_params(N, K, X, Y);
    ensures \result == compute_ans(N, K, X, Y);
    ensures \result == X * N || \result == X * (K + 1) + Y * (N - K - 1);
*/
int func(int N, int K, int X, int Y)
{
    int ans;

    //@ assert 1 <= X && X <= 10000;
    //@ assert 1 <= N && N <= 10000;
    //@ assert X * N <= 100000000;

    if (N <= K)
    {
        ans = X * N;
    }
    else
    {
        //@ assert 1 <= Y && Y < X;
        //@ assert 1 <= K && K <= 10000;
        //@ assert X * (K + 1) <= 10000 * 10001;
        //@ assert Y * (N - K - 1) <= 100000000;
        ans = X * (K + 1) + Y * (N - K - 1);
    }

    return ans;
}
