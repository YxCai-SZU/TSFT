#include <limits.h>

/*@
    predicate valid_range(integer N) = 1 <= N <= 100;

    logic integer div2(integer N) = N / 2;
    logic integer mod2(integer N) = N % 2;
    logic integer target_result(integer N) = div2(N) + mod2(N);

    lemma div_mod_property:
        \forall integer N; valid_range(N) ==> target_result(N) == N / 2 + N % 2;
*/

/*@
    requires valid_range(N);
    ensures \result == target_result(N);
    ensures \result == N / 2 + N % 2;
*/
int func(int N)
{
    int result;
    int temp_N;
    int count;
    int remainder;

    result = 0;
    temp_N = N;
    count = 0;

    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count <= N / 2;
        loop invariant temp_N == N - 2 * count;
        loop invariant valid_range(N);
        loop assigns temp_N, count;
        loop variant temp_N;
    */
    while (temp_N >= 2)
    {
        temp_N -= 2;
        count += 1;
    }
    result = count;

    remainder = N;
    /*@
        loop invariant 0 <= remainder <= N;
        loop invariant valid_range(N);
        loop invariant remainder == N - 2 * ((N - remainder) / 2);
        loop assigns remainder;
        loop variant remainder;
    */
    while (remainder >= 2)
    {
        remainder -= 2;
    }

    if (remainder == 1)
    {
        result += 1;
    }

    //@ assert result == N / 2 + N % 2;

    return result;
}
