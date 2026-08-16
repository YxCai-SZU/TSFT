/*@
    predicate valid_range(integer N) = 1 <= N <= 100;

    logic integer discount_count(integer N) = N / 15;

    logic integer final_result(integer N) = (N * 800) - (discount_count(N) * 200);

    lemma discount_count_bounds:
        \forall integer N; valid_range(N) ==> 0 <= discount_count(N) <= 6;
*/

#include <stdbool.h>

/*@
    requires valid_range(N);
    ensures \result == final_result(N);
*/
int func(int N) {
    int result;
    int i;
    int count;
    int temp_N;

    result = N * 800;
    i = 0;
    count = 0;
    temp_N = N;

    /*@
        loop invariant 1 <= N <= 100;
        loop invariant 0 <= temp_N <= N;
        loop invariant temp_N == N - 15 * count;
        loop invariant 0 <= count <= discount_count(N);
        loop invariant result == N * 800;
        loop invariant i == 0;
        loop assigns count, temp_N;
    */
    while (temp_N >= 15) {
        //@ assert temp_N >= 15;
        count += 1;
        temp_N -= 15;
        //@ assert temp_N == N - 15 * count;
    }

    //@ assert count == discount_count(N);
    result -= count * 200;
    //@ assert result == final_result(N);
    return result;
}
