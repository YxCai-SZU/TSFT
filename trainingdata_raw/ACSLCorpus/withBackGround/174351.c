#include <stddef.h>
#include <stdint.h>

/*@
    predicate valid_params(size_t N, int64_t *B) =
        2 <= N && N <= 100 &&
        \valid(B + (0 .. N-2)) &&
        \forall integer j; 0 <= j < N-1 ==> 0 <= B[j] && B[j] <= 100000;

    logic integer ans_upper_bound(integer i, integer N) =
        (i + 2) * 100000;
*/

/*@
    requires valid_params(N, B);
    ensures \result >= 0;
    assigns \nothing;
*/
int64_t func(size_t N, const int64_t B[])
{
    int64_t ans;
    size_t i;
    int64_t b1;
    int64_t b2;

    ans = B[0] + B[N - 2];
    i = 0;

    /*@
        loop invariant 0 <= i <= N-2;
        loop invariant ans >= 0;
        loop invariant ans <= ans_upper_bound(i, N);
        loop assigns ans, i, b1, b2;
        loop variant N-2 - i;
    */
    while (i < N - 2)
    {
        b1 = B[i];
        b2 = B[i + 1];

        //@ assert 0 <= b1 && b1 <= 100000;
        //@ assert 0 <= b2 && b2 <= 100000;

        if (b1 < b2)
        {
            ans += b1;
        }
        else
        {
            ans += b2;
        }

        //@ assert ans >= 0;
        //@ assert ans <= ans_upper_bound(i+1, N);

        i += 1;
    }

    return ans;
}
