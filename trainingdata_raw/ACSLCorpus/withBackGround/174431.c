#include <limits.h>

/*@
    predicate valid_params(integer N, integer K, integer X, integer Y) =
        1 <= N <= 10000 &&
        1 <= K <= 10000 &&
        1 <= X <= 10000 &&
        1 <= Y < X;

    logic integer formula1(integer N, integer K, integer X, integer Y) =
        X * K + (N - K) * Y;

    logic integer formula2(integer N, integer X) =
        X * N;

    lemma product_bound: \forall integer X, integer N;
        1 <= X <= 10000 && 1 <= N <= 10000 ==> X * N <= 100000000;

    lemma formula1_bound: \forall integer N, integer K, integer X, integer Y;
        valid_params(N, K, X, Y) ==> formula1(N, K, X, Y) <= 100000000 + 9999 * 10000;
*/

/*@
    requires valid_params(N, K, X, Y);
    ensures \result == formula1(N, K, X, Y) || \result == formula2(N, X);
    assigns \nothing;
*/
long long func(long long N, long long K, long long X, long long Y)
{
    long long ans;

    //@ assert 1 <= X && X <= 10000;
    //@ assert 1 <= N && N <= 10000;
    //@ assert X * N <= 10000 * 10000;

    //@ assert K <= 10000 && K >= 1;
    //@ assert Y < X && Y >= 1;
    //@ assert X * K + (N - K) * Y <= 10000 * 10000 + (10000 - 1) * 10000;

    if (N <= K)
    {
        ans = X * N;
    }
    else
    {
        ans = X * K + (N - K) * Y;
    }

    return ans;
}
