#include <stddef.h>

/*@ predicate is_valid_array(integer N, int *A) =
      N >= 1 && N <= 100 &&
      \valid(A + (0 .. N-1)) &&
      \forall integer i; 0 <= i < N ==> (1 <= A[i] && A[i] <= 1000);
*/

/*@ predicate loop_invariant(integer i, integer N, integer count, int *A, integer min_val) =
      0 <= i <= N &&
      0 <= count <= i &&
      \forall integer j; 0 <= j < i ==> (A[j] >= min_val);
*/

/*@ lemma count_bounds:
      \forall integer N, count;
      (0 <= count <= N) ==> (count >= 0 && count <= N);
*/

/*@ requires is_valid_array(N, A);
    assigns \nothing;
    ensures \result >= 0 && \result <= N;
*/
size_t func(size_t N, int *A) {
    int min;
    size_t count;
    size_t i;
    
    //@ assert is_valid_array(N, A);
    
    min = A[0];
    count = 0;
    i = 0;
    
    /*@ loop invariant loop_invariant(i, N, count, A, min);
        loop invariant \forall integer k; 0 <= k < i ==> (1 <= A[k] && A[k] <= 1000);
        loop invariant N >= 1 && N <= 100;
        loop invariant i <= N;
        loop assigns i, min, count;
        loop variant N - i;
    */
    while (i < N) {
        //@ assert 0 <= i < N;
        if (A[i] < min) {
            min = A[i];
            count += 1;
        }
        i += 1;
    }
    
    //@ assert count >= 0;
    return count;
}
