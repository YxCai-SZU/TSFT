#include <stdbool.h>

/*@
    predicate is_valid_N(integer N) = 1 <= N && N <= 100;

    logic integer manual_div_15(integer N, integer count) = N - count * 15;

    lemma division_property:
        \forall integer N, count;
            N >= 0 && count >= 0 && manual_div_15(N, count) >= 15 ==>
            manual_div_15(N, count + 1) == manual_div_15(N, count) - 15;
*/

/*@
    requires is_valid_N(N);
    ensures \result == N * 800 - (N / 15) * 200;
*/
int func(int N)
{
    int result;
    int count;
    int temp_N;

    result = N * 800;
    count = 0;
    temp_N = N;

    /*@
        loop invariant 0 <= temp_N <= N;
        loop invariant 0 <= count <= N / 15;
        loop invariant temp_N == N - count * 15;
        loop assigns temp_N, count;
    */
    while (temp_N >= 15)
    {
        //@ assert temp_N == N - count * 15;
        temp_N = temp_N - 15;
        //@ assert temp_N == N - (count + 1) * 15;
        count = count + 1;
        //@ assert temp_N == N - count * 15;
    }

    //@ assert count == N / 15;
    result = result - count * 200;
    return result;
}
