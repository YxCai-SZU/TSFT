#include <stdbool.h>
/*@
    predicate valid_range(integer N) = 1 <= N && N <= 100;
    logic integer division_by_subtraction(integer N, integer count) = N - 15 * count;
    logic integer final_result(integer N, integer count) = N * 800 - 200 * count;
    
    lemma division_property: \forall integer N, integer count; 
        valid_range(N) && 0 <= count && count <= N / 15 && division_by_subtraction(N, count) >= 15 ==> 
        division_by_subtraction(N, count + 1) == division_by_subtraction(N, count) - 15;
*/

/*@
    requires valid_range(N);
    ensures \result == N * 800 - 200 * (N / 15);
*/
int func(int N) {
    int result;
    int temp_N;
    int count;
    
    result = 0;
    temp_N = N;
    count = 0;
    
    /*@
        loop invariant 1 <= N <= 100;
        loop invariant 0 <= temp_N <= N;
        loop invariant temp_N == N - 15 * count;
        loop invariant count >= 0;
        loop invariant count <= N / 15;
        loop assigns temp_N, count;
    */
    while (temp_N >= 15) {
        //@ assert temp_N == N - 15 * count;
        temp_N -= 15;
        count += 1;
        //@ assert temp_N == N - 15 * count;
    }
    
    result = N * 800 - 200 * count;
    
    //@ assert result == N * 800 - 200 * (N / 15);
    
    return result;
}
