#include <limits.h>

/*@
    predicate valid_params(integer N, integer K, integer X, integer Y) =
        1 <= N <= 10000 &&
        1 <= K <= 10000 &&
        1 <= Y < X <= 10000;

    logic integer answer(integer N, integer K, integer X, integer Y) =
        N <= K ? N * X : K * X + (N - K) * Y;

    lemma product_bounds:
        \forall integer N, integer X;
        1 <= N <= 10000 && 1 <= X <= 10000 ==> N * X <= 100000000;

    lemma combined_bounds:
        \forall integer N, integer K, integer X, integer Y;
        valid_params(N, K, X, Y) && N > K ==> 
            K * X <= 100000000 && (N - K) * Y <= 100000000;
*/

/*@
    requires valid_params(N, K, X, Y);
    ensures \result == answer(N, K, X, Y);
    assigns \nothing;
*/
int func(int N, int K, int X, int Y)
{
    int ans;

    //@ assert 1 <= N && N <= 10000;
    //@ assert 1 <= K && K <= 10000;
    //@ assert 1 <= Y && Y < X && X <= 10000;
    
    //@ assert N * X <= 100000000;
    //@ assert K * X <= 100000000;
    
    if (N <= K)
    {
        ans = N * X;
        //@ assert ans == N * X;
    }
    else
    {
        //@ assert (N - K) * Y <= 100000000;
        ans = K * X + (N - K) * Y;
        //@ assert ans == K * X + (N - K) * Y;
    }

    //@ assert ans == answer(N, K, X, Y);
    return ans;
}
