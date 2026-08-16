#include <stdint.h>

/*@
    predicate valid_N(integer N) = 1 <= N <= 1000000000;

    logic integer div_2(integer N) = N / 2;
    logic integer div_6(integer N) = N / 6;

    lemma ans_correct:
        \forall integer N; valid_N(N) ==> div_2(N) - div_6(N) + div_6(N) == div_2(N);
*/

/*@
    requires valid_N(N);
    ensures \result == N / 2 - N / 6 + N / 6;
    ensures \result == N / 2;
*/
int64_t func(int64_t N)
{
    int64_t ans;
    int64_t temp_N;
    int64_t count_2;
    int64_t count_6;

    ans = 0;
    temp_N = N;
    count_2 = 0;

    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count_2 <= N / 2;
        loop invariant temp_N == N - 2 * count_2;
        loop assigns temp_N, count_2;
        loop variant temp_N;
    */
    while (temp_N >= 2)
    {
        temp_N -= 2;
        count_2 += 1;
    }
    ans += count_2;

    temp_N = N;
    count_6 = 0;

    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count_6 <= N / 6;
        loop invariant temp_N == N - 6 * count_6;
        loop assigns temp_N, count_6;
        loop variant temp_N;
    */
    while (temp_N >= 6)
    {
        temp_N -= 6;
        count_6 += 1;
    }

    ans -= count_6;
    ans += count_6;

    //@ assert ans == N / 2 - N / 6 + N / 6;
    return ans;
}
